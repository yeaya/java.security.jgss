#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax.security.auth._0_SRCS)
file(GLOB classes.javax.security.auth._0_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax.security.auth._0_HEADERS}) 
list(LENGTH classes.javax.security.auth._0_SRCS classes.javax.security.auth._0_SRCS_LENGTH)
if(classes.javax.security.auth._0_SRCS_LENGTH)
	add_library(classes.javax.security.auth._0 OBJECT "${classes.javax.security.auth._0_SRCS}" "${classes.javax.security.auth._0_HEADERS}")
	jcpp_enable_bigobj(classes.javax.security.auth._0)
endif()