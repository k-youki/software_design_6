#include <stdio.h>
#include "define.h"

void message(player p[],int i,int dice_num)
{
  printf("Player%d Turn\n", i+1);
  printf("Your helth is %d\n",p[i].helth);
  printf("Your remainig num : %d\n",dice_num);
}


void field_disp(int field[][WIDTH], int player)
{
  int i, j;

  for (i = 0; i < HIEGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      switch (field[i][j])
	{
	case EMPTY :
	  printf("\e[0mE");
	  break;
	case 1 :
	  if(player == 0) printf("\e[31m‚P");
	  else	          printf("\e[0m‚P");
	  break;
	case 2:
	  if(player == 1) printf("\e[31m‚Q");
	  else	          printf("\e[0m‚Q");
	  break;
	case 3:
	  if(player == 2) printf("\e[31m‚R");
	  else	          printf("\e[0m‚R");
	  break;
	case 4:
	  if(player == 3) printf("\e[31m‚S");
	  else	          printf("\e[0m‚S");
	  break;
	case M_TOWER :
		printf("Ÿ");
		break;
	case S_TOWER :
		printf("ž");
		break;
	default:
	  break;
	}
    }
    puts("");
  }
}
