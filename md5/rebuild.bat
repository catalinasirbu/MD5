cmake -S . -B Build
cmake --build build
cd Build && ctest --verbose
pause