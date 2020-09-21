cmake_minimum_required(VERSION 3.1)
project(a2)

add_subdirectory(src/ext)

# include directories
include_directories(${PROJECT_SOURCE_DIR}/src
                    ${PROJECT_SOURCE_DIR}/src/ext
                    ${PROJECT_SOURCE_DIR}/src/ext/stb
)

set(ext_stb_srcs
    src/ext/stb/stb_image_write.h
    src/ext/stb/stb_image.h
)

add_definitions(-DDATA_DIR=R\"\(${PROJECT_SOURCE_DIR}/data\)\")

set(common_srcs
    src/array3D.h
    src/exceptions.h
    src/floatimage.cpp
    src/floatimage.h
    src/utils.h
)

# Compile common library
add_library(common_lib STATIC
    ${common_srcs}
    ${ext_stb_srcs}
)
SOURCE_GROUP("src\\ext\\stb" FILES ${ext_stb_srcs})

set(a2_srcs   src/a2_main.cpp src/a2.cpp)                                   # a2
add_executable(a2 ${a2_srcs})                                               # a2
target_link_libraries(a2 common_lib)                                        # a2
SOURCE_GROUP("src" FILES ${a2_srcs})                                        # a2
                                                                            # a2

# Create the output data directory
add_custom_command(TARGET a2 POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_SOURCE_DIR}/data/output") # a2