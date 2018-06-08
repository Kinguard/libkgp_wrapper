#include "libopi_wrapAuthServer.h"
#include <string.h>

using namespace OPI;

/*  Auth Server */
int Login(char *buf)
{
    Json::Value ret;
    Json::Value authresponse;
    int resultcode;
    string unit_id;
    SysConfig sysConfig;


    try
    {
        unit_id = sysConfig.GetKeyAsString("hostinfo","unitid");
    }
    catch (runtime_error e)
    {
        // no use to try validation without unitid
        return 0;
    }

    AuthServer auth(unit_id,{"https://auth.openproducts.com/",sysConfig.GetKeyAsString("hostinfo","syspubkey"),sysConfig.GetKeyAsString("hostinfo","sysauthkey")});
    try
    {
        tie(resultcode,authresponse) = auth.Login();
        if ( resultcode == 200 )
        {
            strcpy(buf,authresponse["token"].asString().c_str());
        }
    }
    catch (exception& e)
    {
        // Try again with keys stored on file, secop might not be running
        try
        {
            tie(resultcode,authresponse) = auth.Login(true);
            if ( resultcode == 200 )
            {
                strcpy(buf,authresponse["token"].asString().c_str());
            }
        }
        catch(exception& e)
        {
            //printf("EXC: %s\n",e.what());
            resultcode = 500;
        }
    }

    return resultcode;
}
