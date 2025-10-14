#machine generated

add_subdirectory("ietf")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.org_SRCS)
file(GLOB classes.org_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.org_HEADERS}) 
list(LENGTH classes.org_SRCS classes.org_SRCS_LENGTH)
if(classes.org_SRCS_LENGTH)
	add_library(classes.org OBJECT "${classes.org_SRCS}" "${classes.org_HEADERS}")
	jcpp_enable_bigobj(classes.org)
endif()