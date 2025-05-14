# Como Configurar o CMake para o Projeto

Esse tutorial vai te guiar pelos passos necessários para instalar e configurar o CMake no seu projeto de forma correta.

## 1. Instalar o CMake

### Para sistemas baseados em Debian (como Ubuntu):

```bash
sudo apt update
sudo apt install cmake
```

### Para Arch Linux:

```bash
sudo pa-S cmake
```cman 

### Para Fedora:

```bash
sudo dnf install cmake
```

## 2. Verificar a Instalação do CMake

Após a instalação, é importante verificar se o CMake foi instalado corretamente. Execute o seguinte comando:

```bash
cmake --version
```

Se tudo estiver certo, você verá a versão do CMake instalada.

## 3. Configurar o Ambiente

Agora que o CMake está instalado, você pode configurar o seu projeto para utilizar o CMake da seguinte maneira.

### Criar o arquivo CMakeLists.txt(NESSE CASO ELE JA ESTA NO PROJETO)

Crie o arquivo `CMakeLists.txt` na raiz do seu projeto.

Este arquivo deve conter as instruções de como compilar o seu projeto. Um exemplo básico é:

```cmake
cmake_minimum_required(VERSION 3.14)

project(Gestor_Gastos)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${PROJECT_SOURCE_DIR}/app
    ${PROJECT_SOURCE_DIR}/app/back_end
    ${PROJECT_SOURCE_DIR}/app/front_end
    ${PROJECT_SOURCE_DIR}/app/dados
)

set(SOURCES
    app/main.cpp
    app/back_end/back_end.cpp
    app/front_end/front_end.cpp
    app/dados/dados.cpp
)

add_executable(Gestor_Gastos ${SOURCES})
```

### Configuração do CMake no VSCode

#### IMPORTANTE se não fizer não vai funcionar

Se estiver utilizando o VSCode, configure o arquivo `settings.json` para apontar para o CMake. Aqui está um exemplo de como fazer isso:

Vá até o diretório `.vscode` e edite o arquivo `settings.json`:

se não existir esse diretorio crie ele na pasta raiz do seu projeto com o nome 
`.vscode` IMPORTANTE tem que ter o ( . ) antes ok ???

após isso crie um arquivo com o nome de `settings.json`

```json
{
    "cmake.configureOnOpen": true,
    "cmake.generator": "Unix Makefiles",
    "cmake.toolchainFile": "/home/seu_usuario/projeto/vcpkg/scripts/buildsystems/vcpkg.cmake"
}
```

### Crie tambem 

crie um arquivo chamado `c_cpp_properties.json`
```json
{
    "configurations": [
      {
        "name": "Linux",
        "includePath": [
          "${workspaceFolder}/app",
          "${workspaceFolder}/app/dados",
          "${workspaceFolder}/app/back_end",
          "${workspaceFolder}/app/front_end",
          "${workspaceFolder}/**"
        ],
        "defines": [],
        "compilerPath": "/usr/bin/g++",     //| info do meu compilador edite para se adequar ao seu
        "cStandard": "c11",                 //| info do meu compilador edite para se adequar ao seu
        "cppStandard": "c++17",             //| info do meu compilador edite para se adequar ao seu
        "intelliSenseMode": "linux-gcc-x64" //| info do meu compilador edite para se adequar ao seu
      }
    ],
    "version": 4
  }
```



## 4. Gerar os Arquivos de Construção

Com o CMake configurado, é hora de gerar os arquivos de construção. Execute o seguinte comando na raiz do seu projeto:

```bash
cmake .
```

Este comando criará os arquivos necessários para a construção do projeto.

## 5. Compilar o Projeto

Agora que o ambiente está configurado, você pode compilar o seu projeto com o comando:

```bash
make
```

Isso irá compilar o projeto de acordo com as instruções no `CMakeLists.txt`.

## 6. Instalar o Google Test (opcional)

Caso esteja utilizando o Google Test, você pode instalar o pacote com o vcpkg como mostrado nos passos anteriores e então, vincular no seu `CMakeLists.txt`.

Exemplo:

```cmake
find_package(GTest REQUIRED)

target_link_libraries(Gestor_Gastos GTest::GTest GTest::Main)
```

Agora o seu ambiente está pronto para compilar e testar o projeto com o CMake! Se tiver qualquer dúvida, sinta-se à vontade para perguntar.
