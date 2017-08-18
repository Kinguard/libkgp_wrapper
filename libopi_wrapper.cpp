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
