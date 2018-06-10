@echo off

set BIN_DIR="%~dp0"
echo BIN_DIR=%BIN_DIR%


cd %BIN_DIR%
cd ..
echo %cd%
set TOP_DIR=%cd%

set BUILD_DIR=build\Release

%BUILD_DIR%\volumesource.exe tests\block100.stl

%BUILD_DIR%\volumesource.exe tests\bottle.stl

%BUILD_DIR%\volumesource.exe tests\humanoid.stl

%BUILD_DIR%\volumesource.exe tests\magnolia.stl

%BUILD_DIR%\volumesource.exe tests\Mario_20170209.STL

%BUILD_DIR%\volumesource.exe tests\shoe.stl

%BUILD_DIR%\volumesource.exe tests\sphere.stl

%BUILD_DIR%\volumesource.exe tests\teapot.stl



cd %BIN_DIR%
pause


