#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "define.h"

void game();
void p_init(player p[]);
void t_init(main_tower mt[], sub_tower st[]);
void f_init(int field[][WIDTH], player p[], int entry, main_tower mt[], sub_tower st[]);
void field_disp(int field[][WIDTH], int player);
void dice(player p[],int entry);
int walk(player p[], int field[][WIDTH], int player, int key, sub_tower st[]);
int tower_wall(int field[][WIDTH]);
int attack(player p[], int field[][WIDTH], int player, int key);
int win_loss_judgement(main_tower mt[]);

int main(void)
{
  srand((unsigned)time(NULL));
  
  game();

  return 0;
}

void game()
{
  int i;
  int key;
  int field[HIEGHT][WIDTH];
  int entry;
  int flag = FALSE;
  int flag_action = FALSE;
  int dice_num;
  int count;
  int dummy;

  player p[MAX];
  main_tower mt[M_TOWER_NUM];
  sub_tower st[S_TOWER_NUM];

  entry = MAX;

  p_init(p);
  t_init(mt, st);
  f_init(field, p, entry, mt, st);

  system("clear");

  while (flag == FALSE) {
    dice(p, entry);
    for (i = 0; i < entry; i++) {
      for (dice_num = p[i].dice_num; dice_num > 0; dice_num--) {
	flag_action = FALSE;
	message(p, i, dice_num);
	field_disp(field, i);
	while (flag_action != TRUE) {
	  scanf("%d", &key);
	  if (key == ATTACK)
	    flag_action = attack(p, field, i, key);
	  else
	    flag_action = walk(p, field, i, key, st);
	}
	//tower_wall(field);
	//flag = win_loss_judgment(mt);
	system("clear");
      }
    }
  }

}

void p_init(player p[])
{
  int i;
  int r1, r2;
  int keep;
  
  for (i = 0; i < MAX; i++) {
    p[i].num = i + 1;
    switch (i)
      {
      case 0 :
	p[i].x = 0;
	p[i].y = 1;
	break;
      case 1 :
	p[i].x = 0;
	p[i].y = 3;
	break;
      case 2:
	p[i].x = WIDTH - 1;
	p[i].y = 1;
	break;
      case 3:
	p[i].x = WIDTH - 1;
	p[i].y = 3;
	break;
      }
    p[i].pow_up = EMPTY;
    p[i].pow_down = EMPTY;
    p[i].dice_num = 0;
    p[i].helth = DEFHP;
    if(MAX/2 > i){
      p[i].team = ALPHA;
    }
    else {
      p[i].team = BETA;
    }
  }
  
}

void t_init(main_tower mt[], sub_tower st[])
{
  int i;

  //main tower position
  mt[0].x = 0;
  mt[1].x = WIDTH - 1;
  mt[0].y = mt[1].y = HIEGHT / 2;
  //HP and Team
  mt[0].helth = mt[1].helth = M_HELTH;
  mt[0].team = ALPHA;
  mt[1].team = BETA;

  //sub tower position
  for (i = 0; i < S_TOWER_NUM; i++) {
    if (i < S_TOWER_NUM / 2) {
      st[i].x = (WIDTH / (S_TOWER_NUM + 1))*(i + 1);
    }
    else {
      st[i].x = (WIDTH / (S_TOWER_NUM + 1))*(i + 1) + 1;
    }
    st[i].y = HIEGHT / 2;
    st[i].helth = S_HELTH;
    if (i < S_TOWER_NUM / 2) {
      st[i].team = ALPHA;
    }
    else {
      st[i].team = BETA;
    }
  }
}

void f_init(int field[][WIDTH], player p[], int entry, main_tower mt[], sub_tower st[])
{
  int i, j;

  for (i = 0; i < HIEGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      field[i][j] = EMPTY;
    }
  }
  
  //Player set
  for (i = 0; i < entry; i++) {
    field[p[i].y][p[i].x] = p[i].num;
  }
  //Tower set
  for (i = 0; i < M_TOWER_NUM; i++) {
    field[mt[i].y][mt[i].x] = M_TOWER;
  }
  for (i = 0; i < S_TOWER_NUM; i++) {
    field[st[i].y][st[i].x] = S_TOWER;
  }
  
}

void dice(player p[], int entry)
{
  int i;

  for (i = 0; i < entry; i++) {
    p[i].dice_num = rand() % 6 + 1;
  }
}

int walk(player p[], int field[][WIDTH], int player, int key, sub_tower st[])
{
  int error = TRUE;
  int x, y;
  int keep_x, keep_y;
  
  x = keep_x = p[player].x;
  y = keep_y = p[player].y;
  
  switch (key)
    {
    case RIGHT://Right move
      y--;
      if (y >= 0) { error = FALSE; }
      break;
    case DOWN://Down move
      y++;
      if (y < HIEGHT) { error = FALSE; }
      break;
    case LEFT://Left move
      x--;
      if (x >= 0) { error = FALSE; }
      break;
    case UP://Up move
      x++;
      if (x < WIDTH) { error = FALSE; }
      break;
    default:
      break;
    }
    
  //Move Error
  if (field[y][x] != EMPTY) {
    error = TRUE;
  }

  if (error == TRUE) {
    return FALSE;//action NO
  }
  else {
    //Player position update
    field[keep_y][keep_x] = EMPTY;
    p[player].x = x;
    p[player].y = y;
    field[y][x] = p[player].num;
    return TRUE;//action OK
  }
}

int tower_wall(int field[][WIDTH], sub_tower st[])
{
  int i,j;
  
  for(i=0;i<S_TOWER_NUM;i++){
    switch(st.team[i])
      {
      case ALPHA:
	if(st.health[i] > 0){
	  for(j=0;j<HIEGHT;j++){
	    field[j][st.x[i]] = ALPHA_WALL;
	}
	break;
      case BETA:

	break;
      }
  }

}

int attack(player p[], int field[][WIDTH], int player, int key)
{
  printf("Attack!!\n");
}

int win_loss_judgement(main_tower mt[])
{
  // return Win team(ALPHA or BETA)
  

}
