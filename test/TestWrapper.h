#include <cppunit/extensions/HelperMacros.h>
#include <libopi_wrapper.h>

using namespace CppUnit;

Json::Reader reader;


class TestWrapper : public TestFixture
{
    CPPUNIT_TEST_SUITE(TestWrapper);
    CPPUNIT_TEST(testSysType);
    CPPUNIT_TEST(testStorageDevice);
    CPPUNIT_TEST(testStorageDeviceBlock);
    CPPUNIT_TEST(testStorageDevicePartition);
    CPPUNIT_TEST(testSerialNumber);

    CPPUNIT_TEST_SUITE_END();

public:
    void testSysType();
    void testStorageDevice();
    void testStorageDeviceBlock();
    void testStorageDevicePartition();
    void testSerialNumber();
};
