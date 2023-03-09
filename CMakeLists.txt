cmake_minimum_required(VERSION 3.12)

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

configure_file(version.h.in version.h)

add_executable(${MAIN_APP_NAME} src/ip_filter.cpp)
add_library(addrv4 include/Address.h src/Address.cpp)

set_target_properties(${MAIN_APP_NAME} addrv4 PROPERTIES
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

install(TARGETS ${MAIN_APP_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
