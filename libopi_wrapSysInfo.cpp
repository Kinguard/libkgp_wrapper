#include "libopi_wrapSysInfo.h"
#include "libutils/FileUtils.h"
#include <libutils/ConfigFile.h>
#include <json/json.h>
#include <string.h>

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

int BackupRootPath(char *buf)
{
    strcpy(buf,sysinfo.BackupRootPath().c_str());
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

