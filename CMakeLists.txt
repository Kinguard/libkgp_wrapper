project(opi_wrapper)
cmake_minimum_required(VERSION 2.8)

include( FindPkgConfig )
pkg_check_modules ( LIBOPI REQUIRED libopi )
pkg_check_modules ( LIBJSONCPP REQUIRED jsoncpp )

set (WRAPPER_VERSION_MAJOR 1)
set (WRAPPER_VERSION_MINOR 0)
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
include_directories ( "${LIBJSONCPP_INCLUDE_DIRS}" )

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
	libopi_wrapper.h
	)
	
# Set source list for wrapper 
set( src
	libopi_wrapper.cpp
   )

add_library( ${PROJECT_NAME}_static STATIC ${src} )
add_library( ${PROJECT_NAME} SHARED ${src} )


target_link_libraries(${PROJECT_NAME} ${LIBOPI_LDFLAGS} )


add_subdirectory( test )
enable_testing()
add_test( NAME TestApp COMMAND testapp )



#find_program(PYTHON "python3")

#if (PYTHON)
#    set(SETUP_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in")
#    set(SETUP_PY    "${CMAKE_CURRENT_BINARY_DIR}/setup.py")
#    set(DEPS        "${CMAKE_CURRENT_SOURCE_DIR}/pylibopi.py")
#    set(OUTPUT      "${CMAKE_CURRENT_BINARY_DIR}/build")

#    configure_file(${SETUP_PY_IN} ${SETUP_PY})

#    add_custom_command(
#      OUTPUT ${OUTPUT}
#      COMMAND ${PYTHON} setup.py build
#      DEPENDS ${DEPS}
#    )

#    add_custom_target(target ALL DEPENDS ${OUTPUT})

#    install(CODE "execute_process(COMMAND ${PYTHON} ${SETUP_PY} install)")
#endif()


install( FILES ${headers} DESTINATION include/lib${PROJECT_NAME} )
install(FILES "${PROJECT_BINARY_DIR}/lib${PROJECT_NAME}.pc" DESTINATION lib/pkgconfig)
install(FILES "${PROJECT_BINARY_DIR}/lib${PROJECT_NAME}.pc" DESTINATION share/pkgconfig)
install( TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_static DESTINATION lib )
