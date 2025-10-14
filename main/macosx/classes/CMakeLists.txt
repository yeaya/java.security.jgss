#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" macosx-classes_SRCS)
file(GLOB macosx-classes_HEADERS *.h *.hpp)
source_group("Include" FILES ${macosx-classes_HEADERS}) 
list(LENGTH macosx-classes_SRCS macosx-classes_SRCS_LENGTH)
if(macosx-classes_SRCS_LENGTH)
	add_library(macosx-classes OBJECT "${macosx-classes_SRCS}" "${macosx-classes_HEADERS}")
	jcpp_enable_bigobj(macosx-classes)
endif()