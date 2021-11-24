#include "libopi_wrapAuthServer.h"

#include <libutils/HttpStatusCodes.h>
#include <libutils/Logger.h>
#include <cstring>

using namespace OPI;
using namespace Utils;
using namespace Utils::HTTP;


bool isLocked()
{
	Secop::State st = Secop::Unknown;

	try
	{
		Secop s;
		st  = s.Status();
	}
	catch( runtime_error& e)
	{
		logg << Logger::Notice << "wrapper: Failed to check status: "<<e.what()<<lend;
	}
	return (st == Secop::Uninitialized) || (st == Secop::Unknown);
}

/*  Auth Server */
int Login(char *buf)
{
	json ret;
	json authresponse;
	int resultcode = 0;
	string unit_id;
	SysConfig sysConfig;

	try
	{
		unit_id = sysConfig.GetKeyAsString("hostinfo","unitid");
	}
	catch (runtime_error& e)
	{
		// no use to try validation without unitid
		logg << Logger::Notice << "wrapper: Missing unit id" << lend;
		return 0;
	}

	AuthServer auth(unit_id,{"https://auth.openproducts.com/",sysConfig.GetKeyAsString("hostinfo","syspubkey"),sysConfig.GetKeyAsString("hostinfo","sysauthkey")});
	try
	{
		tie(resultcode,authresponse) = auth.Login();

		if( resultcode != Status::Ok )
		{
			// Try again with keys on file
			tie(resultcode,authresponse) = auth.Login(true);
		}

		if ( resultcode == Status::Ok )
		{
			strcpy(buf,authresponse["token"].get<string>().c_str());
		}
		else
		{
			logg << Logger::Error << "wrapper: Login failed both from file and secop " << resultcode << lend;
		}
	}
	catch (exception& e)
	{
		// Try again with keys stored on file, secop might not be running
		logg << Logger::Notice << "Caugth exception while trying to login " << e.what() << lend;

		try
		{
			tie(resultcode,authresponse) = auth.Login(true);
			if ( resultcode == Status::Ok )
			{
				strcpy(buf,authresponse["token"].get<string>().c_str());
			}
			else
			{
				logg << Logger::Notice << "wrapper: Login with keys on file failed with " << resultcode << lend;
			}
		}
		catch(exception& e)
		{
			logg << Logger::Error << "wrapper: Failed with " << e.what() << lend;
			resultcode = Status::InternalServerError;
		}
	}

	return resultcode;
}
