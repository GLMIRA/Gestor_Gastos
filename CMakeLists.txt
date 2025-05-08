cmake_minimum_required(VERSION 3.14)

# Definir o caminho para o vcpkg dentro do projeto
set(CMAKE_TOOLCHAIN_FILE "${PROJECT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

project(Gestor_Gastos)

set(CMAKE_CXX_STANDARD 17)

# Incluir diretórios de cabeçalhos
include_directories(
    ${PROJECT_SOURCE_DIR}/app
    ${PROJECT_SOURCE_DIR}/app/back_end
    ${PROJECT_SOURCE_DIR}/app/front_end
    ${PROJECT_SOURCE_DIR}/app/dados
)

# Fontes do projeto principal
set(SOURCES
    app/main.cpp
    app/back_end/back_end.cpp
    app/front_end/front_end.cpp
    app/dados/dados.cpp
)

# Encontrar o pacote do Google Test
find_package(GTest REQUIRED)

# Executável principal
add_executable(Gestor_Gastos ${SOURCES})

# ---------- Testes ----------

# Arquivos de teste
set(TEST_SOURCES
    app/back_end/test/test_validate_cpf.cpp  # <- adicionado aqui
    app/back_end/test/test_validate_salary.cpp
    app/back_end/test/test_validate_birthdate.cpp
    app/back_end/test/test_validate_name.cpp
)

# Executável de testes
add_executable(test_gestor_gastos ${TEST_SOURCES}
    app/back_end/back_end.cpp               # <- inclui a função que será testada
)

# Vincular GoogleTest aos testes
target_link_libraries(test_gestor_gastos GTest::GTest GTest::Main)

# Habilitar e registrar os testes
enable_testing()
add_test(NAME AllTests COMMAND test_gestor_gastos)
