cmake_minimum_required(VERSION 3.9.4)
project (volumesource)

set(Boost_DEBUG OFF)
find_package(Boost 1.67.0 COMPONENTS program_options system filesystem)
if(Boost_FOUND)
  message(STATUS "Found BOOST: ${Boost_VERSION}")
  include_directories(${Boost_INCLUDE_DIRS})
  message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
  message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
  message(STATUS "Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
endif()

set(SOURCES 
	src/main/main.cpp
	src/main/Options.cpp
	src/calc/VolumeCalc.cpp
	src/calc/Translate.cpp
	src/formats/stl/StlAsciiParser.cpp
	src/server/connection.cpp
	src/server/connection_manager.cpp
	src/server/mime_types.cpp
	src/server/reply.cpp
	src/server/request_handler.cpp
	src/server/request_parser.cpp
	src/server/server.cpp
	src/server/RequestPathParser.cpp
	src/service/VolumeCalculator.cpp
	)

link_directories(${Boost_LIBRARY_DIRS})
add_executable(volumesource ${SOURCES})
target_include_directories(volumesource PRIVATE src)
if (UNIX)
  target_link_libraries(volumesource ${Boost_LIBRARIES} pthread)
endif (UNIX)
