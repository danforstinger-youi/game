@echo off
if [%1]==[] (set BUILD_TYPE=ORBIS_Debug) else (set BUILD_TYPE=%1)
if [%PATH_TO_YOUIENGINE%]==[] (set PATH_TO_YOUIENGINE=..\..\..\..)

call %PATH_TO_YOUIENGINE%\AppCommon\build\ps4\package.bat HelloWorld %BUILD_TYPE%
