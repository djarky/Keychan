UBYTE rand_rot(void){
switch(rand()%4){
case 0:return J_UP;
case 1:return J_DOWN;
case 2:return J_LEFT;
case 3:return J_RIGHT;
}
return J_UP;
}

UBYTE rand_pos_x(void){
return (rand()%6)+2;
}

UBYTE rand_pos_y(void){
return (rand()%5)+2;
}

UBYTE rand_r(UBYTE min, UBYTE max) {
return (rand()%max)+min;
} 