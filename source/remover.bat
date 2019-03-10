@ECHO OFF

title Charpoka Remover
echo               Removed shortcut viruses from any drive
echo               Enter the letter of the drive:

:START
set/p "d="

if EXIST %d%:\ goto DO
if NOT EXIST %d%:\ goto DONOT

:DO
echo please wait...

attrib -s -h -a /s /d %d%:\*.*
del /a /q /s %d%:\*.lnk


echo .
echo .
echo ******************************************************
echo .
echo Done!!!!
ECHO Successfully removed from drive %d%
ECHO All files recovered from drive %d%
echo .
echo .
ECHO ******************************************************
echo .
ECHO CharpokaRemover
echo .
echo ******************************************************
echo ******************************************************
ECHO Press any key to close...
set/p "k="
goto END

:DONOT
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
echo Not found any drive
echo Please check your drive & try again:
goto START
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
:END
