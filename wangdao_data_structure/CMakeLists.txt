# Define project name
project(wangdao_data_structure)

set(HEADER_FILES
	chapter2.h
	chapter22.h
)

set(SOURCE_FILES
	chapter2.cpp
	chapter22.cpp
	main.cpp)

# Declare the executable target built from your sources
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# Link your application with OpenCV libraries
#target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
