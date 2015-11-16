void field_disp(int field[][WIDTH], int player)
{
  int i, j;

  for (i = 0; i < HIEGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      switch (field[i][j])
	{
	case EMPTY :
	  printf("\e[0m¡¦");
	  break;
	case 1 :
	  if(player == 0) printf("\e[31m£±");
	  else	          printf("\e[0m£±");
	  break;
	case 2:
	  if(player == 1) printf("\e[31m£²");
	  else	          printf("\e[0m£²");
	  break;
	case 3:
	  if(player == 2) printf("\e[31m£³");
	  else	          printf("\e[0m£³");
	  break;
	case 4:
	  if(player == 3) printf("\e[31m£´");
	  else	          printf("\e[0m£´");
	  break;
	default:
	  break;
	}
    }
    puts("");
  }
}
