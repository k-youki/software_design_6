#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "define.h"

typedef struct {
  int num;
  int x;
  int y;
  int pow_up;
  int pow_down;
  int dice_num;
  int helth;
} player;

void game();
void p_init(player p[]);
void f_init(int field[][WIDTH], player p[], int entry);
void field_disp(int field[][WIDTH], int player);
void dice(player p[],int entry);
void walk(player p[], int field[][WIDTH], int player);

int main(void)
{
  srand((unsigned)time(NULL));
  
  game();

  return 0;
}

void game()
{
  int i;
  int field[HIEGHT][WIDTH];
  int entry;
  int flag = FALSE;
  int dice_num;
  int count;
  int dummy;

  player p[MAX];

  /*
    printf("Number of entry (MAX:4) : ");
    scanf("%d", &entry);
  */

  entry = MAX;
  
  p_init(p);
  f_init(field,p,entry);

  system("clear");
  
  while (flag != TRUE) {
    dice(p, entry);
    for (i = 0; i < entry; i++) {
      for (dice_num = p[i].dice_num; dice_num > 0; dice_num--) {
	//message(p,i,dice_num);
	printf("Player%d Turn\n", i+1);
	printf("Your helth is %d\n",p[i].helth);
	printf("Your remainig num : %d\n",dice_num);
	field_disp(field,i);
	walk(p,field,i);
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
  }
  
}

void f_init(int field[][WIDTH], player p[], int entry)
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
  
}

void dice(player p[], int entry)
{
  int i;

  for (i = 0; i < entry; i++) {
    p[i].dice_num = rand() % 6 + 1;
  }
}

void walk(player p[], int field[][WIDTH], int player)
{
  
  int key;
  int error = TRUE;
  int x, y;
  
  x = p[player].x;
  y = p[player].y;
  
  field[y][x] = EMPTY;
  
  while (error == TRUE) {
    x = p[player].x;
    y = p[player].y;
    scanf("%d", &key);
    
    switch (key)
      {
      case 8://Right move
	y--;
	if (y >= 0) { error = FALSE; }
	break;
      case 2://Down move
	y++;
	if (y < HIEGHT) { error = FALSE; }
	break;
      case 4://Left move
	x--;
	if (x >= 0) { error = FALSE; }
	break;
      case 6://Up move
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
  }
  
  p[player].x = x;
  p[player].y = y;
  
  //Player position update
  field[y][x] = p[player].num;
  
}
