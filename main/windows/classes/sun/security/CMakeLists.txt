#machine generated

add_subdirectory("krb5")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" windows-classes.sun.security_SRCS)
file(GLOB windows-classes.sun.security_HEADERS *.h *.hpp)
source_group("Include" FILES ${windows-classes.sun.security_HEADERS}) 
list(LENGTH windows-classes.sun.security_SRCS windows-classes.sun.security_SRCS_LENGTH)
if(windows-classes.sun.security_SRCS_LENGTH)
	add_library(windows-classes.sun.security OBJECT "${windows-classes.sun.security_SRCS}" "${windows-classes.sun.security_HEADERS}")
	jcpp_enable_bigobj(windows-classes.sun.security)
endif()