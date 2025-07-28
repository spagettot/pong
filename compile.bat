@echo off
setlocal enabledelayedexpansion

set SOURCES=
for %%f in (src\*.c) do (
    set SOURCES=!SOURCES! %%f
)

echo compiling ....

gcc -Iinclude -Llib !SOURCES! -o main.exe -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows

echo,
echo compilation finished
