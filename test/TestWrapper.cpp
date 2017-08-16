#include "TestWrapper.h"
#include "libopi/SysInfo.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestWrapper);

void TestWrapper::testSerialNumber()
{
    string serial;
    serial = SerialNumber();
    printf("\nSERIAL: %s\n",serial.c_str());
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.SerialNumber(),serial);
}


void TestWrapper::testSysType()
{
    string res;
    res = SysTypeText();
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.SysTypeText[OPI::sysinfo.Type()],res);

}

void TestWrapper::testStorageDevice()
{
    string res;
    res = StorageDevice();
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.StorageDevice(),res);

}

void TestWrapper::testStorageDeviceBlock()
{
    string res;
    res = StorageDeviceBlock();
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.StorageDeviceBlock(),res);

}

void TestWrapper::testStorageDevicePartition()
{
    string res;
    res = StorageDevicePartition();
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.StorageDevicePartition(),res);

}

