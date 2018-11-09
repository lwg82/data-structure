# cmake needs this line
cmake_minimum_required(VERSION 2.8)

project(data-structure)


SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)


add_subdirectory(chapter2)
add_subdirectory(chapter3)
add_subdirectory(chapter4)
add_subdirectory(chapter5)

# mkdir -p build 
# cmake -E chdir build cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_BUILD_TYPE=debug ../
