#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "define.h"

void game();
void p_init(player p[]);
void t_init(main_tower mt[], sub_tower st[]);
void f_init(int field[][WIDTH], player p[], int entry, main_tower mt[], sub_tower st[]);
void field_disp(int field[][WIDTH], int player);
int attack(player p[], int field[][WIDTH], main_tower mt[], sub_tower st[], int player);
player dice(player p);
void dise_num_disp(player p);
int walk(player p[], int field[][WIDTH], int player, int key, sub_tower st[]);
int tower_wall(int field[][WIDTH], sub_tower st[]);
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
    for (i = 0; i < entry; i++) {
      p[i] = dice(p[i]);
      for (dice_num = p[i].dice_num; dice_num > 0; dice_num--) {
	flag_action = FALSE;
	message(p, i, dice_num);
	field_disp(field, i);
	while (flag_action != TRUE) {
	  scanf("%d", &key);
	  if (key == ATTACK)

	    flag_action = attack(p, field, mt, st, i);

	  /*test command*/
	  else if(key == 7) mt[0].health -= 30;
	  else if(key == 9) mt[1].health -= 30;
	  /*end*/
	  
	  else
	    flag_action = walk(p, field, i, key, st);
	  printf("base1=%d,base2=%d\n",mt[0].health,mt[1].health);
	}
	//tower_wall(field);
	flag = win_loss_judgement(mt);
	system("clear");
      }
    }
  }
  winner(flag);
  
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
    p[i].health = DEFHP;
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
  mt[0].health = mt[1].health = M_HEALTH;
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
    st[i].health = S_HEALTH;
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

player dice(player p)
{
  char c;
  
  system("clear");
  printf("dice roll ?\n");

  scanf("%c",&c);
  getchar();
  
  p.dice_num = rand() % 6 + 1;
  printf("dice_num : %d\n",p.dice_num);
  dise_num_disp(p);
  sleep(1);
  system("clear");
    
  return p;
}

void dise_num_disp(player p)
{
  if(p.dice_num == 1){
    printf("                          /|\n");
    printf("                           |\n");
    printf("                           |\n");
    printf("                          _|_\n");
  }
  else if(p.dice_num == 2){
    printf("                          ____\n");
    printf("                         |    |\n");
    printf("                          ____|\n");
    printf("                         |\n");
    printf("                         |____\n");
  }
  else if(p.dice_num == 3){
    printf("                         _____\n");
    printf("                              |\n");
    printf("                         _____|\n");
    printf("                              |\n");
    printf("                         _____|\n");
  }
  else if(p.dice_num == 4){
    printf("                           /|\n");
    printf("                          / |\n");
    printf("                         /  |\n");
    printf("                        /___|__\n");
    printf("                            |\n");
    printf("                            |\n");
  }
  else if(p.dice_num == 5){
    printf("                          _____\n");
    printf("                         |     \n");
    printf("                         |_____\n");
    printf("                               |\n");
    printf("                          _____|\n");
  }
  else if(p.dice_num == 6){
    printf("                          _____\n");
    printf("                         |\n");
    printf("                         |_____\n");
    printf("                         |     |\n");
    printf("                         |_____|\n");
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
    switch(st[i].team)
      {
      case ALPHA:
	if(st[i].health > 0){
	  for(j=0;j<HIEGHT;j++){
	    if(field[j][st[i].x] == EMPTY || field[j][st[i].x] == ALPHA_WALL)
	      field[j][st[i].x] = ALPHA_WALL;
	  }
	}
	else{
	  for(j=0;j<HIEGHT;j++){
	    if(field[j][st[i].x] == ALPHA_WALL)
	      field[j][st[i].x] = EMPTY;
	  }
	}
	break;
      case BETA:
	if(st[i].health > 0){
	  for(j=0;j<HIEGHT;j++){
	    if(field[j][st[i].x] == EMPTY || field[j][st[i].x] == BETA_WALL)
	      field[j][st[i].x] = BETA_WALL;
	  }
	}
	else{
	  for(j=0;j<HIEGHT;j++){
	    if(field[j][st[i].x] == BETA_WALL)
	      field[j][st[i].x] = EMPTY;
	  }
	}
	break;
      }
  }

}

int attack(player p[],int field[][WIDTH], main_tower mt[], sub_tower st[], int player)
{
  int i, x, y;
  x = p[player].x;
  y = p[player].y;

  //main tower attack
  if(player / 2 != 0) {
    if(x <= mt[0].x + 1 && (mt[0].y - 1 <= y && y <= mt[0].y + 1)) {
      printf("Attack!!\n");
      mt[0].health--;
      return TRUE;
    }
  }
  else {
    if(x >= mt[1].x - 1 && (mt[1].y - 1 <= y && y <= mt[1].y + 1)) {
      printf("Attack!!!\n");
      mt[1].health--;
      return TRUE;
    }
  }
  
  //sub tower attack
  if(player / 2 != 0) {
    if(x == st[1].x + 1 && (st[1].y - 1 <= y && y <= st[1].y + 1)) {
      printf("st1 Attack!!\n");
      st[1].health--;
      return TRUE;
    }
    else if(x == st[0].x + 1 && (st[0].y - 1 <= y && y <= st[0].y + 1)) {
      printf("st0 Attack!!\n");
      st[0].health--;
      return TRUE;
    }
  }
  else {
    if(x == st[3].x - 1 && (st[3].y - 1 <= y && y <= st[3].y + 1)) {
      printf("st3 Attack!!\n");
      st[3].health--;
      return TRUE;
    }
    else if(x == st[2].x - 1 && (st[2].y - 1 <= y && y <= st[2].y + 1)) {
      printf("st2 Attack!!!\n");
      st[2].health--;
      return TRUE;
    }

  }
  
  return FALSE; //action NO
}

int win_loss_judgement(main_tower mt[])
{
  if(mt[0].health <= 0)
    return BETA;
  else if(mt[1].health <= 0)
    return ALPHA;
  else
    return FALSE;
}
