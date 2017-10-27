#include "TestWrapper.h"
#include "libopi/SysInfo.h"
#include "string.h"
#include <iostream>
#include <iomanip>

CPPUNIT_TEST_SUITE_REGISTRATION(TestWrapper);

#define NUMCHARS 0x10
void HexDump(const void* data, int len){
        const unsigned char* buf = static_cast<const unsigned char*>( data );

        std::cout << "---------------- Hexdump "<< std::dec <<len << " ("<< std::hex << len<<") bytes ----------------"<<std::endl;

        for( int i = 0; i < len; i+= NUMCHARS){
                std::cout << std::setw(6) << std::setfill('0') << std::hex << i << ": ";

                for( int j = 0; j < NUMCHARS; j++){
                        if( i + j < len ){
                                std::cout << std::setw(2) << std::setfill('0') << std::hex << (int) buf[i+j]<<" ";
                        }else{
                                std::cout << "  ";
                        }
                }

                std::cout << " ";
                for( int j = 0; j < NUMCHARS; j++){
                        if( i + j < len ){
                                if( isprint( buf[ i + j ]) ){
                                        std::cout << buf[ i + j ];
                                }else{
                                        std::cout << ".";
                                }
                        }
                }
                std::cout << std::endl;
        }


    }


void TestWrapper::testSerialNumber()
{

    char serialbuf[100];
    SerialNumber(serialbuf);
    string serial(serialbuf,0,100);

    HexDump( serial.c_str(), serial.length() );
    //string t = SerialNumber();
    //HexDump(t.c_str(), t.length() );
    //serial = SerialNumber();
    printf("\nSERIAL: %s\n",serial.c_str());
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.SerialNumber(),serial);
    //CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.SerialNumber().c_str(),SerialNumber());
}


void TestWrapper::testSysType()
{
    int res;
    char buf[100];
    res = SysTypeText(buf);
    printf("\nSysTypeText: %s\n",buf);
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.SysTypeText[OPI::sysinfo.Type()],string(buf,0,100));

}

void TestWrapper::testStorageDevice()
{
    int res;
    char buf[100];
    res = StorageDevice(buf);
    printf("\nStorageDevice: %s\n",buf);
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.StorageDevice(),string(buf,0,100));

}

void TestWrapper::testStorageDeviceBlock()
{
    int res;
    char buf[100];
    res = StorageDeviceBlock(buf);
    printf("\nStorageDeviceBlock: %s\n",buf);
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.StorageDeviceBlock(),string(buf,0,100));

}

void TestWrapper::testStorageDevicePartition()
{
    int res;
    char buf[100];
    res = StorageDevicePartition(buf);
    printf("\nStorageDevicePartition: %s\n",buf);
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.StorageDevicePartition(),string(buf,0,100));

}

void TestWrapper::testNetworkDevice()
{
    int res;
    char buf[100];
    res = NetworkDevice(buf);
    printf("\nNetwork Device: %s\n",buf);
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.NetworkDevice(),string(buf,0,100));

}

void TestWrapper::testType()
{
    printf("\nSystem type is: %s\n",OPI::sysinfo.SysTypeText[OPI::sysinfo.Type()].c_str() );

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

void TestWrapper::testLogin()
{
    // How can we test this on PC?
    char buf[100];
    int status;
    status = Login(buf);
    printf("Expect Fail here since we most likely do not have secop/authproxy running");
    CPPUNIT_ASSERT_EQUAL(500,status);

}

void TestWrapper::testBackupRootPath()
{
    int res;
    char buf[100];
    res = BackupRootPath(buf);
    printf("\nBackupRootPath: %s\n",buf);
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.BackupRootPath(),string(buf,0,100));
}
