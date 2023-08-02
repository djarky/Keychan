
UBYTE jump_height = 0x00;

//player posision
unsigned char player_pos_x = 0x05;
unsigned char player_pos_y = 0x05;
unsigned char player_rot   = J_UP;

//platform moves 
#define BACK_WAY  J_LEFT
#define FRONT_WAY J_RIGHT
unsigned char player_dir =  BACK_WAY;



unsigned char player_pos_x_abs =80;
unsigned char player_pos_y_abs =8;

unsigned char player_col=0;


unsigned char tile_index=0;

unsigned char player_hp = 0xFF;


void player_inputt(UBYTE joy,UBYTE mapa[]);
void player_init();
void player_scrollex(BYTE x_pos,BYTE y_pos);