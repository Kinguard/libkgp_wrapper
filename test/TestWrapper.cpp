#include "TestWrapper.h"
#include "libopi/SysInfo.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestWrapper);



void TestWrapper::testSysType()
{

    CPPUNIT_ASSERT_EQUAL(SysTypeText(), OPI::sysinfo.SysTypeText[OPI::sysinfo.Type()]);

}

void TestWrapper::testStorageDevice()
{

    CPPUNIT_ASSERT_EQUAL(StorageDevice(), OPI::sysinfo.StorageDevice());

}

void TestWrapper::testStorageDeviceBlock()
{

    CPPUNIT_ASSERT_EQUAL(StorageDeviceBlock(), OPI::sysinfo.StorageDeviceBlock());

}

void TestWrapper::testStorageDevicePartition()
{

    CPPUNIT_ASSERT_EQUAL(StorageDevicePartition(), OPI::sysinfo.StorageDevicePartition());

}

void TestWrapper::testSerialNumber()
{

    CPPUNIT_ASSERT_EQUAL(SerialNumber(), OPI::sysinfo.SerialNumber());

}
