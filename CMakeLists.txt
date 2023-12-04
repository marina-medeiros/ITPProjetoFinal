cmake_minimum_required(VERSION 3.26)

project(ITPProjetoFinal C)

set(CMAKE_C_STANDARD 11)

include_directories(heading)

file(GLOB_RECURSE SOURCES "funcs/*.c" "utils/*.c" "heading/*.h")

add_library(mylib ${SOURCES})

# Adiciona o diretório 'include' ao caminho de inclusão para a biblioteca 'mylib'.
target_include_directories(mylib PUBLIC include)

# Cria um executável chamado 'main' com o arquivo de origem especificado.
add_executable(main utils/main.c)

# Vincula a biblioteca 'mylib' ao executável 'main'.
target_link_libraries(main mylib)

#target_link_libraries(main gcc)