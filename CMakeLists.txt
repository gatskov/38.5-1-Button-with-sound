cmake_minimum_required(VERSION 3.18.4)

set(CMAKE_CXX_STANDARD 17)

project(Sbutton VERSION 0.1.0)

if (CMAKE_COMPILER_IS_GNUCXX)
message ("Compiler set options...")
	add_compile_options(
        -Werror
        -pedantic-errors
        -Wall
        -Wextra
        -Wpedantic        
        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wctor-dtor-privacy
        -Wduplicated-branches
        -Wduplicated-cond
        -Wextra-semi
        -Wfloat-equal
        -Wlogical-op
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-conversion
        -Wsign-promo
        )
else ()
	message ("Unknown compiler")
endif ()

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)