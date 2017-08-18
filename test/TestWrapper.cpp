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

void TestWrapper::testNetworkDevice()
{
    string res;
    res = NetworkDevice();
    //printf("\nNetwork Device: %s\n",res.c_str());
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.NetworkDevice(),res);

}

void TestWrapper::testType()
{

    switch( OPI::sysinfo.Type() )
    {
    case OPI::SysInfo::TypeArmada:
        CPPUNIT_ASSERT( isArmada() );
        CPPUNIT_ASSERT( ! isOpi() );
        CPPUNIT_ASSERT( ! isXu4() );
        CPPUNIT_ASSERT( ! isOlimexA20() );
        CPPUNIT_ASSERT( ! isPC() );
        break;
    case OPI::SysInfo::TypeOlimexA20:
        CPPUNIT_ASSERT( ! isArmada() );
        CPPUNIT_ASSERT( ! isOpi() );
        CPPUNIT_ASSERT( ! isXu4() );
        CPPUNIT_ASSERT( isOlimexA20() );
        CPPUNIT_ASSERT( ! isPC() );
        break;
    case OPI::SysInfo::TypeOpi:
        CPPUNIT_ASSERT( ! isArmada() );
        CPPUNIT_ASSERT( isOpi() );
        CPPUNIT_ASSERT( ! isXu4() );
        CPPUNIT_ASSERT( ! isOlimexA20() );
        CPPUNIT_ASSERT( ! isPC() );
        break;
    case OPI::SysInfo::TypePC:
        CPPUNIT_ASSERT( ! isArmada() );
        CPPUNIT_ASSERT( ! isOpi() );
        CPPUNIT_ASSERT( ! isXu4() );
        CPPUNIT_ASSERT( ! isOlimexA20() );
        CPPUNIT_ASSERT( OPI::SysInfo::isPC() );
        break;
    case OPI::SysInfo::TypeXu4:
        CPPUNIT_ASSERT( ! isArmada() );
        CPPUNIT_ASSERT( ! isOpi() );
        CPPUNIT_ASSERT( isXu4() );
        CPPUNIT_ASSERT( ! isOlimexA20() );
        CPPUNIT_ASSERT( ! isPC() );
        break;
    default:
        CPPUNIT_FAIL("Unknown system type");
    }

}
