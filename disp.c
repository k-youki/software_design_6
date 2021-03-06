#include <stdio.h>
#include "define.h"

#define c(x) \e[xm

/*
This source file used escape command
\e[m0  is setting color Black
\e[m31 is setting color Red
\e[m32 is setting color Green
\e[m34 is setting color Blue
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
}


void field_disp(int field[][WIDTH], int player)
{
  int i, j;

  printf("  ");
  for(i=0; i<16; i++){
    printf("\e[32m%x ",i);
  }
  for(i=0; i<16; i++){
    printf("\e[31m%x ",i);
  }
  printf("\n  ");
  for(i=0; i<64; i++){
    printf("\e[0m-");
  }
  printf("\n");
  
  for (i = 0; i < HEIGHT; i++) {
    printf("\e[0m%d|",i);
    for (j = 0; j < WIDTH; j++) {
      switch (field[i][j])
	{
	case EMPTY :
	  printf("\e[0mo ");
	  break;
	case 1 :
	  if(player == 0) printf("\e[31m1 ");
	  else   	  printf("\e[0m1 ");
	  break;
	case 2:
	  if(player == 1) printf("\e[31m2 ");
	  else  	  printf("\e[0m2 ");
	  break;
	case 3:
	  if(player == 2) printf("\e[31m3 ");
	  else	          printf("\e[0m3 ");
	  break;
	case 4:
	  if(player == 3) printf("\e[31m4 ");
	  else	          printf("\e[0m4 ");
	  break;
	case M_TOWER :
	  printf("\e[32mT ");
	  break;
	case S_TOWER :
	  printf("\e[34mi ");
	  break;
	case ALPHA_WALL :
	  printf("\e[34mA ");
	  break;
	case BETA_WALL :
	  printf("\e[34mB ");
	  break;
	case ALPHA_MINE :
	  printf("\e[0mX ");
	  break;
	case BETA_MINE :
	  printf("\e[0mY ");
	  break;
	default:
	  break;
	}
    }
    printf("\n");
  }
}

void winner(int win)
{
  if(win == ALPHA)
    printf("ALPHA team Win\n");
  else if(win == BETA)
    printf("BETA team Win\n");
}

