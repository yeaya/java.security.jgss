#machine generated

add_subdirectory("javax")
add_subdirectory("org")
add_subdirectory("sun")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes_SRCS)
file(GLOB classes_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes_HEADERS}) 
list(LENGTH classes_SRCS classes_SRCS_LENGTH)
if(classes_SRCS_LENGTH)
	add_library(classes OBJECT "${classes_SRCS}" "${classes_HEADERS}")
	jcpp_enable_bigobj(classes)
endif()