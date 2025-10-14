#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.security.jgss.sp_4_SRCS)
file(GLOB classes.sun.security.jgss.sp_4_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.security.jgss.sp_4_HEADERS}) 
list(LENGTH classes.sun.security.jgss.sp_4_SRCS classes.sun.security.jgss.sp_4_SRCS_LENGTH)
if(classes.sun.security.jgss.sp_4_SRCS_LENGTH)
	add_library(classes.sun.security.jgss.sp_4 OBJECT "${classes.sun.security.jgss.sp_4_SRCS}" "${classes.sun.security.jgss.sp_4_HEADERS}")
	jcpp_enable_bigobj(classes.sun.security.jgss.sp_4)
endif()