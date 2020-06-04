
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(HEADER_FILES
	"${HEADER_DIR}/GL/gl3w.h" 
	"${HEADER_DIR}/GL/glcorearb.h" 
	"${HEADER_DIR}/KHR/khrplatform.h" 
)

set(SOURCE_FILES
    "${SOURCE_DIR}/gl3w.c"
    )

message(${SOURCE_FILES})

add_library(gl3w STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(gl3w PRIVATE include/)
target_link_libraries(gl3w dl)


