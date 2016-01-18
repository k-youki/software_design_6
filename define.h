#define TRUE 1
#define FALSE 0
//Field size
#define WIDTH 32
#define HIEGHT 5
//player num
#define MAX 4
//Field States
//1~4 already use player number
#define EMPTY 0
#define M_TOWER -1
#define S_TOWER -2
#define ALPHA_WALL -3
#define BETA_WALL -4
//Player States
#define DOUBLE 1
#define DEFHP 40
//Team
#define ALPHA 0
#define BETA 1
//Tower Num
#define M_TOWER_NUM 2
#define S_TOWER_NUM 4
//Tower State
#define M_HELTH 20
#define S_HELTH 10
//Player Action
#define UP 6
#define DOWN 2
#define RIGHT 8
#define LEFT 4
#define ATTACK 5

typedef struct {
	int num;
	int x;
	int y;
	int pow_up;
	int pow_down;
	int dice_num;
	int helth;
        int team;
} player;

typedef struct {
	int x;
	int y;
	int helth;
	int team;
} main_tower;

typedef struct {
	int x;
	int y;
	int helth;
	int team;
} sub_tower;

//extern void init_curses(void);

extern void field_disp(int field[][WIDTH], int player);

extern void message(player p[], int i, int dice_num);
