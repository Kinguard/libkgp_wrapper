#include "TestWrapper.h"
#include "libopi/SysInfo.h"
#include "libopi/SysConfig.h"
#include <cstring>
#include <iostream>
#include <iomanip>

#include <libutils/String.h>

CPPUNIT_TEST_SUITE_REGISTRATION(TestWrapper);

void TestWrapper::setUp()
{
}

void TestWrapper::testSerialNumber()
{

    char serialbuf[100];
    SerialNumber(serialbuf);
    string serial(serialbuf,0,100);

	Utils::HexDump( serial.c_str(), serial.length() );
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
    char buf[100];
    int status;
    printf("Running Auth\n");
    status = Login(buf);
    if( OPI::sysinfo.isPC() && ( status == 500 ) )
    {
		CPPUNIT_ASSERT_EQUAL_MESSAGE("Is secop available?",200,status);
    }
    else
    {
        CPPUNIT_ASSERT_EQUAL(200,status);
    }
}

void TestWrapper::testIsLocked()
{
    printf("Checking if secop is unlocked\n");
    bool expectLocked=false;
    string msg = "Expecting secop to be running, is it not?";;
	/* secop is needed to run on PC as well now... */
	/*
    if (OPI::sysinfo.isPC() )
    {
        // running on PC, do not expect secop to be running.
        expectLocked=true;
        msg = "Not expecting secop to be running, is it?";
    }
	*/
    CPPUNIT_ASSERT_EQUAL_MESSAGE(msg,expectLocked,isLocked());
}

void TestWrapper::testDnsUpdate()
{
    bool status;
    printf("Running DNS update\n");
    status = UpdateDns();
    if( OPI::sysinfo.isPC() )
    {
		CPPUNIT_ASSERT_MESSAGE("Do you have a valid set of login-keys / secop available?",status);
    }
    else
    {
        CPPUNIT_ASSERT(status);
    }
}


void TestWrapper::testBackupRootPath()
{
    int res;
    char buf[100];
    res = BackupRootPath(buf);
    printf("\nBackupRootPath: %s\n",buf);
    CPPUNIT_ASSERT_EQUAL(OPI::sysinfo.BackupRootPath(),string(buf,0,100));
}

void TestWrapper::testGetConfigKeyString()
{
    int res;
    char buf[100];
	OPI::SysConfig sysConfig(true);
	string scope = "testscope";
	string key = "mystring";
	string val = "teststring";
	sysConfig.PutKey(scope,key,val);

    char *c_scope = new char[scope.length() + 1];
    strcpy(c_scope, scope.c_str());

    char *c_key = new char[key.length() + 1];
    strcpy(c_key, key.c_str());

    res = GetKeyAsString(c_scope,c_key,buf);
	printf("\nConfig %s '%s': %s\n",scope.c_str(),key.c_str(),buf);
	CPPUNIT_ASSERT_EQUAL(val,string(buf,0,100));
}

void TestWrapper::testGetConfigKeyInt()
{
	OPI::SysConfig sysConfig(true);
	string scope = "testscope";
	string key = "myint";
	int i = 10;
	sysConfig.PutKey(scope,key,i);

	int res;
    bool status;

    char *c_scope = new char[scope.length() + 1];
    strcpy(c_scope, scope.c_str());

    char *c_key = new char[key.length() + 1];
    strcpy(c_key, key.c_str());


    status = GetKeyAsInt(c_scope,c_key,&res);
	printf("\nConfig %s '%s': %d\n", scope.c_str(), key.c_str(), res);
	CPPUNIT_ASSERT_EQUAL(i,res);
}

void TestWrapper::testGetConfigKeyBool()
{
    int res;
    bool status;

	OPI::SysConfig sysConfig(true);

	string s_res="true";
	string scope = "testscope";
    string key_false = "myfalse";
    string key_true = "mytrue";

	sysConfig.PutKey(scope,key_false,false);
	sysConfig.PutKey(scope,key_true,true);

    char *c_scope = new char[scope.length() + 1];
    strcpy(c_scope, scope.c_str());

    char *c_key_false = new char[key_false.length() + 1];
    strcpy(c_key_false, key_false.c_str());

    char *c_key_true = new char[key_true.length() + 1];
    strcpy(c_key_true, key_true.c_str());

    status = GetKeyAsBool(c_scope,c_key_false,&res);
    if(! res) {
        s_res="false";
    }
	printf("\nConfig %s '%s': %s\n",scope.c_str(),key_false.c_str(),s_res.c_str());
    CPPUNIT_ASSERT(! res);

    s_res="false";
    status = GetKeyAsBool(c_scope,c_key_true,&res);
    if(res) {
        s_res="true";
    }
	printf("\nConfig %s '%s': %s\n",scope.c_str(),key_true.c_str(),s_res.c_str());

}
