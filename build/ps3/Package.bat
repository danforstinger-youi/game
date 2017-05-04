@echo off
if [%1]==[] (set BUILD_TYPE=PS3_Debug) else (set BUILD_TYPE=%1)
call ..\..\..\..\AppCommon\build\ps3\package.bat HelloWorld %BUILD_TYPE%
