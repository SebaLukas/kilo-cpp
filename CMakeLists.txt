cmake_minimum_required(VERSION 3.15)

project(kilo
    VERSION 0.1
    DESCRIPTION "text editor in cpp version"
	LANGUAGES CXX
)

add_executable(kilo src/kilo.cpp)

target_compile_options(kilo PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_compile_features(kilo PRIVATE cxx_std_20)
