# EntityBug's NotePad  
A light text editor.
## Build with CMake and Ninga
1.clone the repository:  
```
git clone https://github.com/EntityBug/Notepad.git
```
2.Edit CMakeLists.txt  
line 14:
```
if (APPLE)
    set(CMAKE_PREFIX_PATH "/Your/Qt/Path/QtVersion/macos/lib/cmake")
elseif(WIN32)
    set(CMAKE_PREFIX_PATH "Your:/Qt/Path/QtVersion/msvc2019_64/lib/cmake")
endif()
```
add elseif if you need.  
3.build:  
first, make build dir:  
```
cd Notepad
mkdir build && cd build
```
then, run cmake:  
```
# Debug:
cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja ..
# Release:
cmake -DCMAKE_BUILD_TYPE=Release -G Ninja ..
```
finally, run:  
```
ninga -v
```
You can also open the Notepad dir in Clion and build with Clion.  
