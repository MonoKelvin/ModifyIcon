@echo off
set third_party_dir=%1
set target_dir=%2
set configuration=%3
set dll_file_suffix=*.dll

if not exist %target_dir% (
    md %target_dir%
)

rem *.dll files
pushd %third_party_dir%
    if "%configuration%"=="Debug" (
        set dll_file_suffix=*d.dll
    )
    for /r %%a in (%dll_file_suffix%) do (
       xcopy /s /y /i "%%a" "%target_dir%"
    )
popd
