@echo off

set START_DIR=%cd%

set BIN_DIR="%~dp0"
echo BIN_DIR=%BIN_DIR%


cd %BIN_DIR%
cd ..
set TOP_DIR=%cd%
echo TOP_DIR=%TOP_DIR%

cd ..
set PROJ_DIR=%cd%
echo PROJ_DIR=%PROJ_DIR%

cd %TOP_DIR%

set BUILD_DIR=build
del /S /Q %BUILD_DIR%
mkdir %BUILD_DIR%
cd %BUILD_DIR%
echo %cd%

REM Ninja build
REM cmake -G Ninja %TOP_DIR%
REM ninja 

cmake -G "Visual Studio 15 2017 Win64" -DBOOST_ROOT="%PROJ_DIR%\boost\1.67.0\boost_1_67_0" %TOP_DIR%

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat"
cd %TOP_DIR%
echo TOP_DIR=%TOP_DIR%
cd %BUILD_DIR%
echo CWD=%cd%

devenv volumesource.sln /build

cd %START_DIR%


pause


