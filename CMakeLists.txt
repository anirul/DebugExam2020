cmake_minimum_required(VERSION 3.3)
project(SAE920)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)

include_directories(include ${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SAE918_SRC src/*.cpp include/*.h)

set_property(GLOBAL PROPERTY USE_FOLDERS On)
SET_SOURCE_FILES_PROPERTIES( ${SAE918_SRC} PROPERTIES
                FOLDER "${CMAKE_SOURCE_DIR}/src" )
#SFML
set(SFML_DIR ${EXTERNAL_DIR}/SFML)
#set(SFML_BUILD_EXAMPLES FALSE)
SET(BUILD_SHARED_LIBS FALSE CACHE INTERNAL "")
add_subdirectory(${SFML_DIR})
include_directories(${SFML_DIR}/include ${SFML_DIR}/src)
LIST(APPEND SAE918_LIBRARIES
	sfml-system
	sfml-window
	sfml-graphics
	sfml-audio
	sfml-network)


if(APPLE)
	set(boost_min_ver 1.50.0)
	set(boost_libs system filesystem)
	find_package(Boost ${boost_min_ver})

	if(Boost_FOUND)
		find_package(Boost ${boost_min_ver} COMPONENTS ${boost_libs})
	endif()
	include_directories(${Boost_INCLUDE_DIRS})
	LIST(APPEND SAE918_LIBRARIES
	  ${Boost_LIBRARIES})
endif(APPLE)

#MISCELLANEOUS UTILITIES
set(UTILITIES_DIR ${EXTERNAL_DIR}/utilities/)
include_directories(${UTILITIES_DIR})


#SAE918_COMMON
if(NOT APPLE AND UNIX)
	LIST(APPEND SAE918_LIBRARIES
		stdc++fs)
ENDIF()
add_library(SAE918_COMMON STATIC ${SAE918_SRC})
include_directories(include/)
target_link_libraries(SAE918_COMMON PUBLIC ${SAE918_LIBRARIES})
set_property(TARGET SAE918_COMMON PROPERTY CXX_STANDARD 17)

if(APPLE)
set_target_properties(SAE918_COMMON PROPERTIES
ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}
ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})
ENDIF(APPLE)

SET(SAE918_MAIN_DIR ${CMAKE_SOURCE_DIR}/main/)

add_executable(ExamDebug1 ${SAE918_MAIN_DIR}/ExamDebug1.cpp)
add_executable(ExamDebug2 ${SAE918_MAIN_DIR}/ExamDebug2.cpp)
add_executable(ExamDebug3 ${SAE918_MAIN_DIR}/ExamDebug3.cpp)
target_link_libraries(ExamDebug3 SAE918_COMMON)

#SAE918
file(COPY data/ DESTINATION ${CMAKE_BINARY_DIR}/data/)

