# EntityBug's NotePad  
A light text editor.
## Build
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
add elseif if you need  
3.build:
```
# Debug:
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=/path/to/ninja -G Ninja Notepad
# Release:
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM=/path/to/ninja -G Ninja Notepad
```