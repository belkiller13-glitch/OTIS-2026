@echo off
setlocal

if not exist "%~dp0CMakeLists.txt" (
    echo ERROR CMakeLists not found in this folder
    pause
    exit /b 1
)

cd /d "%~dp0"

echo STARTING BUILD PROCESS

echo STAGE 1 Configuration
cmake -S . -B build
if errorlevel 1 goto error

echo STAGE 2 Compilation
cmake --build build --config Release
if errorlevel 1 goto error

echo SUCCESS Build completed successfully
echo Executable files are in build Release folder
pause
goto end

:error
echo ERROR Build failed
pause
exit /b 1

:end
endlocal
