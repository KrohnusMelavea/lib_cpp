::rd /s /q build
::md build
cmake -DCMAKE_CXX_FLAGS="/std:c++latest" -S . -B build
cmake --build build

call bin\debug\sandbox.exe