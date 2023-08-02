#include<stdio.h>
#include<gb/gb.h>
#include<stdlib.h>
#include<rand.h>

#include"assets/map/templates.c"

extern unsigned char temp_ram[];
extern unsigned char temp_ram2[];


//prestado de qeqe xd 


#include"assets/map/ladrillos.c"
#include"assets/map/Tiles_maps.c"

// prestado de mirrow chip
#include"assets/PSY_BKG.c"


extern unsigned char hash;

extern unsigned char i;
extern unsigned char k;


#include"mylibs/draw_map.c"
#include"mylibs/generator.c"
#include"mylibs/map_manager.c"


#include"mylibs/level_manager.c"