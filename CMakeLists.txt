cmake_minimum_required(VERSION 3.10.2)
project (volumesource)

set(SOURCES 
	src/main/main.cpp
	src/main/Options.cpp
	src/calc/VolumeCalc.cpp
	src/calc/Translate.cpp
	src/formats/stl/StlAsciiParser.cpp
	)


add_executable(volumesource ${SOURCES})
target_include_directories(volumesource PRIVATE src)