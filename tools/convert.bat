
set SOUND=keychan




z_snd2gbw  %SOUND%.raw %SOUND%.gbw
REM z_bin2gbdk %SOUND%.gbw %SOUND%.c

bin2c -o %SOUND%.c %SOUND%.gbw



pause