#include "libopi_wrapper.h"
using namespace OPI;

string SysTypeText()
{
    return sysinfo.SysTypeText[sysinfo.Type()];
}


string StorageDevice()
{
    return sysinfo.StorageDevice();
}

string StorageDeviceBlock()
{
    return sysinfo.StorageDeviceBlock();
}

string StorageDevicePartition()
{
    return sysinfo.StorageDevicePartition();
}

string SerialNumber()
{
    return sysinfo.SerialNumber();
}
