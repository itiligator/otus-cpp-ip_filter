cmake_minimum_required(VERSION 3.14)

file(READ "version.h.in" ver)

string(REGEX MATCH "PROJECT_VERSION_MAJOR ([0-9]*)" _ ${ver})
set(VERSION_MAJOR ${CMAKE_MATCH_1})
string(REGEX MATCH "PROJECT_VERSION_MINOR ([0-9]*)" _ ${ver})
set(VERSION_MINOR ${CMAKE_MATCH_1})
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")

set(MAIN_APP_NAME "ip_filter")
set(PROJECT_NAME "ip_filter")

set(PROJECT_VESRION ${VERSION_MAJOR}.${VERSION_MINOR}.${PATCH_VERSION})

project(${PROJECT_NAME} VERSION ${PROJECT_VESRION})

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

configure_file(version.h.in version.h)

include_directories(include)

add_executable(${MAIN_APP_NAME} src/ip_filter.cpp)
add_library(addrv4 include/Address.h src/Address.cpp)

enable_testing()

add_executable(
        address_test
        tests/address_test.cc
)
target_link_libraries(
        address_test
        GTest::gtest_main
        addrv4
)

set_target_properties(${MAIN_APP_NAME} addrv4 address_test PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        )


target_link_libraries(${MAIN_APP_NAME} PRIVATE
        addrv4
        )


target_compile_options(${MAIN_APP_NAME} PRIVATE
        -Wall -Wextra -pedantic
        )
target_compile_options(addrv4 PRIVATE
        -Wall -Wextra -pedantic -Werror
        )



include(GoogleTest)
gtest_discover_tests(address_test)


install(TARGETS ${MAIN_APP_NAME} RUNTIME DESTINATION bin COMPONENT application)

set(CPACK_GENERATOR DEB)
set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
set(CPACK_COMPONENTS_ALL application)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
