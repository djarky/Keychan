#!/bin/bash

GBDK_FLAGS="-Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG"

OUTPUT_FILE_NAME_MBC1="game_mbc1.gb"
OUTPUT_FILE_NAME_MBC5="game_mbc5.gb"

COMPILER="lcc"

# Compilar archivos
$COMPILER $GBDK_FLAGS -c -o main.o main.c

$COMPILER $GBDK_FLAGS -Wf-ba0 -c -o BaterySave.o BaterySave.c

$COMPILER $GBDK_FLAGS -Wf-bo2 -c -o player_control.o player_control.c

$COMPILER $GBDK_FLAGS -Wf-bo3 -c -o npc_control.o npc_control.c

$COMPILER $GBDK_FLAGS -Wf-bo4 -c -o bo4.o bo4.c

$COMPILER $GBDK_FLAGS -Wf-bo5 -c -o sprites.o sprites.c

$COMPILER $GBDK_FLAGS -Wf-bo6 -c -o bitmaps1.o bitmaps1.c

$COMPILER $GBDK_FLAGS -Wf-bo8 -c -o musical_mice.o musical_mice.c

$COMPILER $GBDK_FLAGS -Wf-bo10 -c -o compo_invaders.o minigame/compo_invaders.c

$COMPILER $GBDK_FLAGS -Wf-bo12 -c -o bank12.o bank12.c
$COMPILER $GBDK_FLAGS -Wf-bo13 -c -o bank13.o bank13.c
$COMPILER $GBDK_FLAGS -Wf-bo14 -c -o bank14.o bank14.c

$COMPILER $GBDK_FLAGS -c -o music_output.o assets/music/music_output.c

$COMPILER $GBDK_FLAGS -c -o gbt_player.o gbt_player.s

$COMPILER $GBDK_FLAGS -c -o gbt_player_bank1.o gbt_player_bank1.s

$COMPILER $GBDK_FLAGS -c -o sample_bank15.o sample/samples_bank15.c

$COMPILER $GBDK_FLAGS -c -o sample_bank16.o sample/samples_bank16.c

$COMPILER $GBDK_FLAGS -c -o sample_player.o sample/sample_player.c


# Crear ROM MBC1
$COMPILER $GBDK_FLAGS \
    -Wl-yt0x03 \
    -Wl-yo32 \
    -Wl-ya4 \
    -o "$OUTPUT_FILE_NAME_MBC1" \
    *.o

# Crear ROM MBC5
$COMPILER $GBDK_FLAGS \
    -Wl-yt0x1b \
    -Wl-yo32 \
    -Wl-ya4 \
    -o "$OUTPUT_FILE_NAME_MBC5" \
    *.o


# Limpiar archivos temporales
rm -f *.map
rm -f *.sym
rm -f *.asm
rm -f *.noi
rm -f *.ihx
rm -f *.cdb
rm -f *.lst
rm -f *.o

echo
echo "================================"
echo " Build terminado correctamente"
echo "================================"
echo "MBC1: $OUTPUT_FILE_NAME_MBC1"
echo "MBC5: $OUTPUT_FILE_NAME_MBC5"
