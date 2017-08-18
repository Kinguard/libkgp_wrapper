#include "libopi_wrapper.h"
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
