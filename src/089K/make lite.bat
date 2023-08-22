

set GBDK_PATH=C:\gbdk2020\bin
set GBDK_FLAGS=-Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG
set OUTPUT_FILE_NAME_MBC1=game_mbc1.gb
set OUTPUT_FILE_NAME_MBC5=game_mbc5.gb

set COMPILER=%GBDK_PATH%\lcc %GBDK_FLAGS%

%COMPILER% -c -o main.o main.c 

REM %COMPILER% -Wf-ba0 -c -o BaterySave.o BaterySave.c



REM %COMPILER% -Wf-bo4 -c -o  bo4.o bo4.c


REM %COMPILER%  -Wf-bo8 -c -o  musical_mice.o musical_mice.c


REM %COMPILER% -Wf-bo3 -c -o  npc_control.o npc_control.c

%COMPILER%  -c -o sample_bank15.o sample\samples_bank15.c
%COMPILER%  -c -o sample_bank16.o sample\samples_bank16.c

%COMPILER%  -c -o sample_player.o sample\sample_player.c

pause

%COMPILER%  -Wl-yt0x03 -Wl-yo32 -Wl-ya4  -o %OUTPUT_FILE_NAME_MBC1% *.o 

%COMPILER%  -Wl-yt0x1b -Wl-yo32 -Wl-ya4  -o %OUTPUT_FILE_NAME_MBC5% *.o

del *.map
del *.sym
del *.asm
del *.noi
del *.ihx
del *.cdb
del *.lst

pause
