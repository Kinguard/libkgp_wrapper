#include "libopi_wrapper.h"
#include "libutils/FileUtils.h"
#include <libutils/ConfigFile.h>
#include <json/json.h>

using namespace OPI;

const char* SysTypeText()
{
    return sysinfo.SysTypeText[sysinfo.Type()].c_str();
}

const char* StorageDevice()
{
    return sysinfo.StorageDevice().c_str();
}

const char* StorageDeviceBlock()
{
    return sysinfo.StorageDeviceBlock().c_str();
}

const char* StorageDevicePartition()
{
    return sysinfo.StorageDevicePartition().c_str();
}

const char* SerialNumber()
{
    return sysinfo.SerialNumber().c_str();
}

const char* NetworkDevice()
{
    return sysinfo.NetworkDevice().c_str();
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
const char* Login()
{
    Json::Value ret;
    Json::Value authresponse(Json::objectValue);
    int resultcode;
    string unit_id;
    Json::FastWriter writer;

    if( Utils::File::FileExists(SYSCONFIG_PATH))
    {
        Utils::ConfigFile c(SYSCONFIG_PATH);

        unit_id = c.ValueOrDefault("unit_id");

    }
    printf("UNIT ID: %s\n",unit_id.c_str());
    AuthServer auth(unit_id);
    printf("STEP 2\n");
    tie(resultcode,ret) = auth.Login();
    printf("STEP 3\n");

    if( resultcode != 200 )
    {
        throw runtime_error("Unable to authenticate with backend server");
    }
    authresponse["status"] = resultcode;

    if (resultcode == 200)
    {
        authresponse["auth"] = ret;
    }

    return writer.write(authresponse).c_str();
}
