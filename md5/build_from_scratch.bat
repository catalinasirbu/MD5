del /f /s /q Build 1>nul
rmdir /s /q Build
cmake -S . -B Build
cmake --build build
cd Build && ctest --output-on-failure
pause