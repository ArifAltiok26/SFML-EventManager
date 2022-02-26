@ECHO OFF
PUSHD %~dp0
IF EXIST build RD /S /Q build
MKDIR build && CD build
CALL cmake .. -DSFML_DIR=../../SFML-2.5.1 -A Win32
CALL cmake --build . --config release
POPD