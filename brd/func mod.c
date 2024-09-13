#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#include "func title.h"


int addMapObject(int Y,int X,int symbol)
{
        map[Y][X]=symbol;
}

int bot(int* vragY,int* vragX )
{
        map[(*vragY)][(*vragX)]=' ';
        switch ((rand()%4))
                {
                case 1:
                if(map[(*vragY)-1][(*vragX)]!='#')
                {
                        (*vragY)-=1;
                }
                break;

                case 2:
                if(map[(*vragY)+1][(*vragX)]!='#')
                {
                        (*vragY)+=1;
                }
                break;

                case 3:
                if(map[(*vragY)][(*vragX)-1]!='#')
                {
                        (*vragX)-=1;
                }
                break;

                case 0:
                if(map[(*vragY)][(*vragX)+1]!='#')
                {
                        (*vragX)+=1;
                }
                break;
                }
}

void gameover(int vragY,int vragX,int playery,int playerx)
{
        if(vragY==playery && vragX==playerx)
                {
                        printf("\033[0d\033[2J");
                        printf("game over\n");
                        
                        gamestutas=False;
                }
}