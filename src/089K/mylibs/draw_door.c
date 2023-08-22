
void draw_door_rot(UBYTE X, UBYTE Y, UBYTE door_rot) {

switch(door_rot){
		case J_UP:    set_bkg_tiles(X,Y-1,2,3,door_up);      break;
		case J_DOWN:  set_bkg_tiles(X,Y,2,3,door_down);    break;
		case J_LEFT:  set_bkg_tiles(X-1,Y,3,2,door_left);    break;
		case J_RIGHT: set_bkg_tiles(X,Y,3,2,door_right);   break;
	  }



} 


void draw_door(UBYTE X,UBYTE Y,UBYTE U,UBYTE mapa[]){

	UBYTE door_index_t =  (mapa[U]-0x10);



	if(Doors[door_index_t].in_door.x_pos == X && Doors[door_index_t].in_door.y_pos == Y){
	   draw_door_rot(X*2,Y*2,Doors[door_index_t].in_door.rot) ;
	}



	if(Doors[door_index_t].out_door.x_pos == X && Doors[door_index_t].out_door.y_pos == Y){
	draw_door_rot(X*2,Y*2,Doors[door_index_t].out_door.rot);   
	}


}


void draw_doors(UBYTE mapa[]){
for(i=0;i<90;i++){
 if(mapa[i]>0x0F){draw_door(i%10,i/10,i,mapa);}
}
}