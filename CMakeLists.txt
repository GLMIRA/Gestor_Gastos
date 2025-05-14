cmake_minimum_required(VERSION 3.14)
project(Gestor_Gastos)

# Linguagem e compile_commands.json
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Detectar vcpkg se estiver no projeto
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND EXISTS "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

# Include directories (headers)
include_directories(
    ${PROJECT_SOURCE_DIR}/app
    ${PROJECT_SOURCE_DIR}/app/back_end
    ${PROJECT_SOURCE_DIR}/app/front_end
    ${PROJECT_SOURCE_DIR}/app/dados
)

# For GTest via vcpkg inside IDEs (like VSCode)
set(GTest_DIR "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-linux/share/gtest")
find_package(GTest CONFIG REQUIRED)

# ICU via vcpkg
find_package(ICU REQUIRED COMPONENTS uc i18n data)

# GTest via vcpkg
enable_testing()
find_package(GTest CONFIG REQUIRED)

# ======= APP PRINCIPAL =======
add_executable(Gestor_Gastos
    app/main.cpp
    app/back_end/back_end.cpp
    app/front_end/front_end.cpp
    app/dados/dados.cpp
)

target_link_libraries(Gestor_Gastos PRIVATE
    ICU::uc
    ICU::i18n
    ICU::data
)

# ======= TESTES =======
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    "app/back_end/test/*.cpp"
)

add_executable(test_gestor_gastos
    ${TEST_SOURCES}
    app/back_end/back_end.cpp
)

target_link_libraries(test_gestor_gastos PRIVATE
    ICU::uc
    ICU::i18n
    ICU::data
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME AllTests COMMAND test_gestor_gastos)
