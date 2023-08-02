C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o main.o main.c

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-ba0 -c -o BaterySave.o BaterySave.c

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo2 -c -o  player_control.o player_control.c

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo3 -c -o  npc_control.o npc_control.c

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo4 -c -o  bo4.o bo4.c

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo5 -c -o  sprites.o sprites.c

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo6 -c -o  bitmaps1.o bitmaps1.c

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo8 -c -o  musical_mice.o musical_mice.c

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo10 -c -o  compo_invaders.o compo_invaders.c

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo12 -c -o  bank12.o bank12.c
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo13 -c -o  bank13.o bank13.c
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo14 -c -o  bank14.o bank14.c

C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o music_output.o assets/music/music_output.c
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o gbt_player.o gbt_player.s
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o gbt_player_bank1.o gbt_player_bank1.s


C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wl-yt0x03 -Wl-yo16 -Wl-ya4 -Wl-yp0x143=0x00 -o game_mbc1.gb main.o BaterySave.o music_output.o gbt_player.o gbt_player_bank1.o player_control.o npc_control.o bo4.o sprites.o bitmaps1.o musical_mice.o compo_invaders.o bank12.o bank13.o bank14.o
C:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wl-yt0x1b -Wl-yo16 -Wl-ya4 -Wl-yp0x143=0x00 -o game_mbc5.gb main.o BaterySave.o music_output.o gbt_player.o gbt_player_bank1.o player_control.o npc_control.o bo4.o sprites.o bitmaps1.o musical_mice.o compo_invaders.o bank12.o bank13.o bank14.o

del *.map
del *.sym
del *.asm
del *.noi
del *.ihx
del *.cdb
del *.lst

pause
