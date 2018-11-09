# Define project name
project(chapter5)

set(HEADER_FILES
	binary_tree.h)

set(SOURCE_FILES
	main.cpp)

# Declare the executable target built from your sources
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# Link your application with OpenCV libraries
#target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
