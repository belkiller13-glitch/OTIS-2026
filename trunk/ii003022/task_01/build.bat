@echo off
title Build task_01


echo ============================================   
echo  [1/3] Configure project (cmake configure)
echo ============================================
cmake -S src -B build -G "MinGW Makefiles"
if %errorlevel% neq 0 goto error

echo.
echo ============================================
echo  [2/3] Compile (cmake build)
echo ============================================
cmake --build build --config Release
if %errorlevel% neq 0 goto error

echo.
echo ============================================
echo  [3/3] Run program
echo ============================================
if exist build\Release\task1_ii003018.exe (
    build\Release\task1_ii003018.exe
) else (
    build\task1_ii003018.exe
)

echo.
pause
exit /b 0

:error
echo.
echo *** BUILD ERROR! ***
pause
exit /b 1