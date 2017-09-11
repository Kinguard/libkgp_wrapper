pkg_check_modules( CPPUNIT cppunit>=1.12.1 )

set( testapp_src
	test.cpp
        TestWrapper.cpp
    )

add_definitions( -std=c++11 )
add_executable( testapp ${testapp_src} )
include_directories(
    "${PROJECT_SOURCE_DIR}"
    "${LIBOPI_INCLUDE_DIRS}"
    )

target_link_libraries( testapp opi_wrapper ${CPPUNIT_LDFLAGS} ${LIBOPI_LDFLAGS} )

