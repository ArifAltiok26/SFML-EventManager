@ECHO OFF
PUSHD %~DP0
CALL build.bat
cd build/release
SFML_EventManager
POPD