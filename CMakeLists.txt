cmake_minimum_required(VERSION 3.23)
project(JeuAllumettes C)

set(CMAKE_C_STANDARD 99)

add_executable(JeuAllumettes main.c informations.c informations.h gameplay.c gameplay.h main.h utils.c utils.h)
