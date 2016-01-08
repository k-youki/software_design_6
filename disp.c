#include <stdio.h>
#include "define.h"

/*
  void init_curses(void)
  {
  initscr();
  start_color();
  assume_default_colors(COLOR_BLACK,COLOR_WHITE);
  init_pair(2,COLOR_RED,COLOR_BLACK);
  }
*/

void message(player p[],int i,int dice_num)
{
  printf("Player %d Turn\n", i+1);
  printf("Your helth is %d\n",p[i].helth);
  printf("Your remaining num : %d\n",dice_num);
  /*
    printw("Player %d Turn\n", i+1);
    printw("Your helth is %d\n",p[i].helth);
    printw("Your remaining num : %d\n",dice_num);
  */
}


void field_disp(int field[][WIDTH], int player)
{
  int i, j;

  for (i = 0; i < HIEGHT; i++) {
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
	    printf("\e[0mT ");
	    /*
	      attrset(0);
	      printw("T ");
	    */
	    break;
	  case S_TOWER :
	    printf("\e[0mi ");
	    /*
	      attrset(0);
	      printw("i ");
	    */
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
