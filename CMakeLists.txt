cmake_minimum_required (VERSION 2.8)
project (eglew)
set (eglew_VERSION_MAJOR 1)
set (eglew_VERSION_MINOR 0)
option ( ENABLE_TEST "enable building the unittest" OFF )

INCLUDE(CheckTypeSize)
CHECK_TYPE_SIZE (size_t SIZE_T_SIZE)

IF(${SIZE_T_SIZE} EQUAL 4)
	SET(EGLEW_ARCHITECTURE "32bit")
else()
	SET(EGLEW_ARCHITECTURE "64bit")
ENDIF()


    SET(POWERVR_SDK_ROOT "C:\\Imagination\\PowerVR\\GraphicsSDK\\SDK_3.0\\Builds\\")
	#SET(POWERVR_SDK_ROOT "C:\\Imagination\\PowerVR\\GraphicsSDK\\SDK_3.1\\Builds\\")
	SET(GL_INCLUDE ${POWERVR_SDK_ROOT}/OGLES2/Include)
	
	IF(${EGLEW_ARCHITECTURE} STREQUAL "32bit")
		SET(GL_LIBS_PATH  ${POWERVR_SDK_ROOT}Windows/x86_32/Lib)
	ELSEIF(${EGLEW_ARCHITECTURE} STREQUAL "64bit")
		SET(GL_LIBS_PATH  ${POWERVR_SDK_ROOT}Windows/x86_64/Lib)
	ENDIF()
	SET(EGL_LIB ${GL_LIBS_PATH}/libEGL.lib)
	
	SET(GLES_LIB ${GL_LIBS_PATH}/libGLES_CM.lib)
	
	SET(eglew_INCLUDE_DIR ${GL_INCLUDE} )

	list(APPEND eglew_LIBS ${EGL_LIB})
	list(APPEND eglew_LIBS ${GLES_LIB})



enable_testing()
include_directories ("${PROJECT_SOURCE_DIR}/include" ${GL_INCLUDE})
message("${PROJECT_SOURCE_DIR}/include")
add_library(eglew src/eglew.c include/eglew.h)


if(${ENABLE_TEST})
    add_executable (eglewTest WIN32 unittest/test.c)
    target_link_libraries (eglewTest  eglew ${eglew_LIBS})
    
    add_test (eglewTestRun eglewTest)
    set_tests_properties (eglewTestRun  PROPERTIES FAIL_REGULAR_EXPRESSION "has not received an address")
endif()

install (TARGETS eglew DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install (FILES include/eglew.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

# build a CPack driven installer package
#include (InstallRequiredSystemLibraries)
#set (CPACK_RESOURCE_FILE_LICENSE  "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
#set (CPACK_PACKAGE_VERSION_MAJOR "${eglew_VERSION_MAJOR}")
#set (CPACK_PACKAGE_VERSION_MINOR "${eglew_VERSION_MINOR}")
#include (CPack)

