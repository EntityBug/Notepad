# EntityBug's NotePad  
A light text editor.
## Build with CMake and Ninga
1.Clone the repository:  
```
git clone https://github.com/EntityBug/Notepad.git && cd Notepad
```
2.Build:  
First, make build dir:  
```
mkdir build && cd build
```
Then, run cmake:  
```
# Debug:
cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja ..
# Release:
cmake -DCMAKE_BUILD_TYPE=Release -G Ninja ..
```
Finally, run:  
```
ninga -v
```
You can also open the Notepad dir in Clion and build with Clion.  
