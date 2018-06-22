# volumesource
A simple web service which given an STL will produce a pricing quote for a 3D printed part

## Assumptions 

1. The STL surface is not checked for closeness

2. For speed the STL vertices are duplicated, i.e. 

3. The web server is based on Boost asio http server example

4. A 15% margin has been added to the volume at the end.

5. The web server returns just plain text for now. Needs to formated to JSON in future

6. The STL files need to be uploaded to `volumesource\tests`

7. Server port is hard coded to [http://178.79.141.54:8080](http://178.79.141.54:8080)


## Building

* The project is only C++11 

* It depends on Boost 1.67.0 and **cmake** 1.11

* It was built with cross platform in mind. It is currently built on Windows with Visual Studio 2017, but should work on Linux with minor changes.

* To build on windows look at __bin/build.bat__ and adapt it for your setup

* Download boost binaries `boost_1_67_0-msvc-14.1-64.exe` at same level as `volumesource` in `boost\1.67.0`.

* To build
```
cd volumesource
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64" -DBOOST_ROOT="<path to boost installation>\boost\1.67.0\boost_1_67_0" 
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat"
cd path\to\build
devenv volumesource.sln /build
```

## Running

```
cd volumesource
build\Release\volumesource.exe tests\block100.stl
```

Open browser and enter [http://localhost/volume?filename=block100.stl](http://localhost/volume?filename=block100.stl)



