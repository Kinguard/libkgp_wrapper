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

    char *strc = strdup( SerialNumber() );
    string serial = strc;
    free(strc);
    HexDump( serial.c_str(), serial.length() );
    string t = SerialNumber();
    HexDump(t.c_str(), t.length() );
    //serial = SerialNumber();
    printf("\nSERIAL: %s\n",serial.c_str());
    printf("\nSERIAL: %s\n",SerialNumber());
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.SerialNumber(),serial);
    //CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.SerialNumber().c_str(),SerialNumber());
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
    printf("\nStorageDevice: %s\n",res.c_str());
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.StorageDevice(),res);

}

void TestWrapper::testStorageDeviceBlock()
{
    string res;
    res = StorageDeviceBlock();
    printf("\nStorageDeviceBlock: %s\n",res.c_str());
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.StorageDeviceBlock(),res);

}

void TestWrapper::testStorageDevicePartition()
{
    string res;
    res = StorageDevicePartition();
    printf("\nStorageDevicePartition: %s\n",res.c_str());
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.StorageDevicePartition(),res);

}

void TestWrapper::testNetworkDevice()
{
    string res;
    res = NetworkDevice();
    printf("\nNetwork Device: %s\n",res.c_str());
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.NetworkDevice(),res);

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
    printf("Test login");
    printf("Returned JSON: %s",Login());
}
