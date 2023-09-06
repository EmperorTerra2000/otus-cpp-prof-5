cmake_minimum_required(VERSION 3.15)

set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(design VERSION ${PROJECT_VESRION})

set(CMAKE_BUILD_TYPE Debug)

add_executable(design src/main.cpp)

target_include_directories(design PRIVATE include)

set_target_properties(design PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(design PRIVATE
        /W4
    )
else ()
    target_compile_options(design PRIVATE
        -Wall -Wextra -pedantic
    )
endif()

install(TARGETS design RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)