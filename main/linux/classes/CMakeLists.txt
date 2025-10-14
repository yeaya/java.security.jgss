#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" linux-classes_SRCS)
file(GLOB linux-classes_HEADERS *.h *.hpp)
source_group("Include" FILES ${linux-classes_HEADERS}) 
list(LENGTH linux-classes_SRCS linux-classes_SRCS_LENGTH)
if(linux-classes_SRCS_LENGTH)
	add_library(linux-classes OBJECT "${linux-classes_SRCS}" "${linux-classes_HEADERS}")
	jcpp_enable_bigobj(linux-classes)
endif()