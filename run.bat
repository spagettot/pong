@echo off
setlocal enabledelayedexpansion

set SOURCES=
for %%f in (src\*.c) do (
    set SOURCES=!SOURCES! %%f
)

echo compiling ....

gcc -O3 -Iinclude -Llib !SOURCES! -o pong.exe -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows
start main.exe

echo,
echo compilation finished
