rem
rem
title NAME batch
:menue
@echo off
cls
color 9F
@echo.
@echo ********************************************
@echo *********     NAME  (DOS-BATCH) ************
@echo Datum: %date% -- Zeit:%time%
@echo Home: %homepath%
@echo Computer: %computername%
@echo Link:http://www.antonis.de/dos/batchtut/pittipla/index.htm
@echo Link:https://www.script-example.com/themen/Windows_Batch.php
@echo File:readme-dos-batch.pdf
@echo ********************************************
@echo.
@echo.
@echo 1) Backup fsst1
@echo --------------------------
@echo 2) Zeige aufgaben.txt
@echo 3) Was ist heute zu tun?
@echo 4) Lösche alle Aufgaben
@echo 5) Neue Aufgabe erfassen
@echo --------------------------
@echo 6) Edit Hello.java
@echo 7) compile Hello.java
@echo 8) Run Hello
@echo --------------------------
@echo 0) exit
@echo.
@echo.
set /p choice="what todo? "


rem --------------------------------------------
if "%choice%"=="1" (
@echo 1) Backup fsst1
@echo --------------------------
@echo "Heute ist: %date% -- %time%"

set /p quelle="(c:\users\ahofmann\fsst1)?"
set /p ziel="(e:\backup\ahofmann\fsst1)?"
@echo xcopy %quelle% %ziel%

REM =============== ENTER CODE =================

set /p weiter="weiter mit enter ..."
goto :menue
)


rem --------------------------------------------
if "%choice%"=="2" (
@echo "you entered %choice%"

REM =============== ENTER CODE =================

set /p weiter="weiter mit enter ..."
goto :menue
)




REM =============== ENTER CODE =================







rem --------------------------------------------
if "%choice%"=="0" (
@echo "you entered %choice%"
goto :ende
)

goto :menue

rem --------------------------------------------
:ende
rem ISO-Datum für nach Dateiname sortierbarer zeitlicher Reihenfolge
@echo *** Auf Wiedersehen ***
echo %DATE:~6%-%DATE:~3,2%-%DATE:~0,2%
color
exit /b
