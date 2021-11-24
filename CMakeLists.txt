project(opi_wrapper)
cmake_minimum_required(VERSION 2.8)

include( FindPkgConfig )
pkg_check_modules ( LIBOPI REQUIRED libopi>=1.6.60 )
find_package(nlohmann_json 3.2.0 REQUIRED)

set (VERSION_MAJOR 1)
set (VERSION_MINOR 18)
set (VERSION_PATCH 0)
set (VERSION "${VERSION_MAJOR}.${VERSION_MINOR}")
set (VERSION_FULL "${VERSION}.${VERSION_PATCH}")

set (WRAPPER_APP_NAME "lib${PROJECT_NAME}")

set (APP_PATH "${PROJECT_BINARY_DIR}")
set (SRC_PATH "${PROJECT_SOURCE_DIR}")

if(APP_BUILD MATCHES deb)
		set ( APP_BUILD_PACKAGE 1 )
else()
		set ( APP_BUILD_LOCAL 1 )
endif()

add_definitions( -std=c++11 )

include_directories("${PROJECT_BINARY_DIR}")

configure_file (
	"${PROJECT_SOURCE_DIR}/Config.h.in"
	"${PROJECT_BINARY_DIR}/Config.h"
)

configure_file(
        "${PROJECT_SOURCE_DIR}/lib${PROJECT_NAME}.pc.in"
        "${PROJECT_BINARY_DIR}/lib${PROJECT_NAME}.pc"
        @ONLY
)

set( headers
	libopi_wrapSysInfo.h
	libopi_wrapSysConfig.h
	libopi_wrapDnsServer.h
	libopi_wrapAuthServer.h
	)
	
# Set source list for wrapper 
set( src
	libopi_wrapSysInfo.cpp
	libopi_wrapSysConfig.cpp
	libopi_wrapDnsServer.cpp
	libopi_wrapAuthServer.cpp
   )

add_library( ${PROJECT_NAME}_static STATIC ${src} )
add_library( ${PROJECT_NAME} SHARED ${src} )


target_link_libraries(${PROJECT_NAME} ${LIBOPI_LDFLAGS} )


add_subdirectory( test )
enable_testing()
add_test( NAME TestApp COMMAND testapp )

set_target_properties( ${PROJECT_NAME} PROPERTIES
                VERSION ${VERSION_FULL}
                SOVERSION ${VERSION_MAJOR}
        )

set_target_properties( ${PROJECT_NAME}_static PROPERTIES
                OUTPUT_NAME ${PROJECT_NAME}
        )

install( FILES ${headers} DESTINATION include/lib${PROJECT_NAME} )
install(FILES "${PROJECT_BINARY_DIR}/lib${PROJECT_NAME}.pc" DESTINATION lib/pkgconfig)
install(FILES "${PROJECT_BINARY_DIR}/lib${PROJECT_NAME}.pc" DESTINATION share/pkgconfig)
install( TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_static DESTINATION lib )

