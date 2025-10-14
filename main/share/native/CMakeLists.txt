#machine generated

if(JCPP_OS MATCHES "macosx")
	include_directories("../../macosx/native")
endif()

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" native_SRCS)
file(GLOB native_HEADERS *.h *.hpp)
source_group("Include" FILES ${native_HEADERS}) 
list(LENGTH native_SRCS native_SRCS_LENGTH)
if(native_SRCS_LENGTH)
	add_library(native OBJECT "${native_SRCS}" "${native_HEADERS}")
	jcpp_enable_bigobj(native)
endif()