@echo off
mkdir build
cd build
rem Generate VS2019 project.
cmake -G "Visual Studio 16 2019" -A "x64" -B build "-DCMAKE_TOOLCHAIN_FILE=E:/vcpkg/scripts/buildsystems/vcpkg.cmake" ..
pause