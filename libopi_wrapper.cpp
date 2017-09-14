#include "libopi_wrapper.h"
#include "libutils/FileUtils.h"
#include <libutils/ConfigFile.h>
#include <json/json.h>

using namespace OPI;

int SysTypeText(char *buf)
{
    strcpy(buf,sysinfo.SysTypeText[sysinfo.Type()].c_str());
    return 1;
}

int StorageDevice(char *buf)
{
    strcpy(buf,sysinfo.StorageDevice().c_str());
    return 1;
}

int StorageDeviceBlock(char *buf)
{
    strcpy(buf,sysinfo.StorageDeviceBlock().c_str());
    return 1;
}

int StorageDevicePartition(char *buf)
{
    strcpy(buf,sysinfo.StorageDevicePartition().c_str());
    return 1;
}

int SerialNumber(char *buf)
{
    strcpy(buf,sysinfo.SerialNumber().c_str());
    return 1;
}

int NetworkDevice(char *buf)
{
    strcpy(buf,sysinfo.NetworkDevice().c_str());
    return 1;
}

bool isPC()
{
    return sysinfo.isPC();
}

bool isArmada()
{
    return sysinfo.isArmada();
}

bool isOpi()
{
    return sysinfo.isOpi();
}

bool isXu4()
{
    return sysinfo.isXu4();
}

bool isOlimexA20()
{
    return sysinfo.isOlimexA20();
}


/*  Auth Server */
int Login(char *buf)
{
    Json::Value ret;
    Json::Value authresponse;
    int resultcode;
    string unit_id,token;

    if( Utils::File::FileExists(SYSCONFIG_PATH))
    {
        Utils::ConfigFile c(SYSCONFIG_PATH);

        unit_id = c.ValueOrDefault("unit_id");

    }
    AuthServer auth(unit_id);
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
        resultcode=500;
    }

    return resultcode;
}
