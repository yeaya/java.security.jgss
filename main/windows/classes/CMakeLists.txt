#machine generated

add_subdirectory("sun")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" windows-classes_SRCS)
file(GLOB windows-classes_HEADERS *.h *.hpp)
source_group("Include" FILES ${windows-classes_HEADERS}) 
list(LENGTH windows-classes_SRCS windows-classes_SRCS_LENGTH)
if(windows-classes_SRCS_LENGTH)
	add_library(windows-classes OBJECT "${windows-classes_SRCS}" "${windows-classes_HEADERS}")
	jcpp_enable_bigobj(windows-classes)
endif()