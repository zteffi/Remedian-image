cmake_minimum_required (VERSION 3.14)
project (RemedianImage CXX)

find_package(OpenCV REQUIRED PATHS OPENCV_PATH)

#set(MSVC_RUNTIME "STATIC")

set (OpenCV_SHARED OFF)

file (GLOB SOURCE_FILES
	"*.hpp"
	"*.cpp"	
)

add_executable(RemedianImage
	${SOURCE_FILES}
)


target_link_libraries(RemedianImage 
	${OpenCV_LIBS}
)
