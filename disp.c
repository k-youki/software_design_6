#include <stdio.h>
#include "define.h"

/*
  void init_curses(void)
  {
  initscr();
  start_color();
  assume_default_colors(COLOR_BLACK,COLOR_WHITE);
  init_pair(2,COLOR_RED,COLOR_BLACK);
  init_pair(3,COLOR_GREEN,COLOR_WHITE);
  init_pair(4,COLOR_BLUE,COLOR_WHITE);

  }
*/

void message(player p[],int i,int dice_num,main_tower mt[],sub_tower st[])
{
  int j;
  printf("Player %d Turn\n", i+1);
  if(i<2) printf("Your team is 'ALPHA'\n");
  else    printf("Your team is 'BETA'\n");
  printf("Your health is %d\n",p[i].health);
  printf("Your remaining num : %d\n",dice_num);
  for(j=0;j<2;j++)
    printf("Mt%d Health = %d,",j,mt[j].health);
  printf("\n");
  for(j=0;j<4;j++)
    printf("St%d Health = %d,",j,st[j].health);
  printf("\n\n");
  /*
    printw("Player %d Turn\n", i+1);
    printw("Your helth is %d\n",p[i].helth);
    printw("Your remaining num : %d\n",dice_num);
  */
}


void field_disp(int field[][WIDTH], int player)
{
  int i, j;

  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      switch (field[i][j])
	{
	case EMPTY :
	  printf("\e[0mo ");
	  // printw("o ");
	  break;
	case 1 :
	  if(player == 0){
	    printf("\e[31m1 ");
	    /*
	      attrset(COLOR_PAIR(2));
	      printw("1 ");
	    */
	  }
	  else{
	    printf("\e[0m1 ");
	    /*
	      attrset(0);
	      printw("1 ");
	    */
	  }
	  break;
	case 2:
	  if(player == 1){
	    printf("\e[31m2 ");
	    /*
	      attrset(COLOR_PAIR(2));
	      printw("2 ");
	    */
	  }
	  else{
	    printf("\e[0m2 ");
	    /*
	      attrset(0);
	      printw("2 ");
	    */
	    break;
	  case 3:
	    if(player == 2){
	      printf("\e[31m3 ");
	      /*
		attrset(COLOR_PAIR(2));
		printw("3 ");
	      */
	    }
	    else{
	      printf("\e[0m3 ");
	      /*
		attrset(0);
		printw("3 ");
	      */
	    }
	    break;
	  case 4:
	    if(player == 3){
	      printf("\e[31m4 ");
	      /*
		attrset(COLOR_PAIR(2));
		printw("4 ");
	      */
	    }
	    else{
	      printf("\e[0m4 ");
	      /*
		attrset(0);
		printw("4 ");
	      */
	    }
	    break;
	  case M_TOWER :
	    printf("\e[32mT ");
	    /*
	      attrset(COLOR_PAIR(3));
	      printw("T ");
	    */
	    break;
	  case S_TOWER :
	    printf("\e[34mi ");
	    /*
	      attrset(COLOR_PAIR(4));
	      printw("i ");
	    */
	    break;
	  case ALPHA_WALL :
	    printf("\e[34mA ");
	    break;
	  case BETA_WALL :
	    printf("\e[34mB ");
	    break;
	  default:
	    break;
	  }
	}
    }
    printf("\n");
    //printw("\n");
  }
}

void winner(int win)
{
  if(win == ALPHA)
    printf("ALPHA team Win\n");
  else if(win == BETA)
    printf("BETA team Win\n");
}

