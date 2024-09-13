#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "func title.h"

int main(void)
{
        int* map=mapp();
        
        srand(time(NULL));
        char playerData=0;
        int capY=5,capX=25,cap='$';
        int twitch='!',twitchX=3,twitchY=7;
        int playerY=1, playerX=1, player='@';
        
        while(gamestutas)
        {     
                
                //добовление объектов на карту перед отрисовкой
                addMapObject(capY,capX,cap);
                addMapObject(playerY,playerX,player);
                addMapObject(twitchY,twitchX,twitch);
                //отрисовка
                printf("\033[0d\033[2J");
                for(int i=0;i<(sizeof(map)/sizeof(map[0]));i++)
                {
                        for(int j=0;j<(sizeof(map[0])/sizeof(map[0][0]));j++){
                                printf("%c",map[i][j]);
                        }
                        printf("\n");
                }
                
                

                scanf(" %c",&playerData);//считавание стрелочки
                
                //очистака масива
                map[playerY] [playerX]=' ';

                
                

                //управление персонажемmodf.
                switch (playerData)
                {
                case 'w':
                if(map[playerY-1][playerX]!='#')
                {
                        playerY-=1;
                }
                break;

                case 's':
                if(map[playerY+1][playerX]!='#')
                {
                        playerY+=1;
                }
                break;

                case 'a':
                if(map[playerY][playerX-1]!='#')
                {
                        playerX-=1;
                }
                break;

                case 'd':
                if(map[playerY][playerX+1]!='#')
                {
                        playerX+=1;
                }
                break;
                }

                //управдение NPC
                bot(&twitchY,&twitchX);
                gameover(twitchY,twitchX,playerY,playerX);

                bot(&capY,&capX);
                gameover(capY,capX,playerY,playerX);
                
        } 
        
        return 0;
}
