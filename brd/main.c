#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define xmap 30
#define ymap 10

int addMapObject(int Y,int X,int symbol,int* ptr_map)
{
        char(*map)[xmap]=ptr_map;
        map[Y][X]=symbol;
}

int bot(int* vragY,int* vragX,int* ptr_map )
{
        char(*map)[xmap]=ptr_map;
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

void gameover(int vragY,int vragX,int playery,int playerx,bool* gamestutas)
{
        if(vragY==playery && vragX==playerx)
                {
                        printf("\033[0d\033[2J");
                        printf("game over\n");
                        
                        *gamestutas=False;
                }
}
int main(void)
{       
        bool gamestutas=true;

    int map[ymap][xmap]={{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                         {'#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                         {'#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                         {'#',' ','#','#',' ',' ',' ',' ','#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                         {'#',' ',' ',' ',' ','#','#','#','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                         {'#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ','#'},
                         {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                         {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                         {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                         {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};

        
        srand(time(NULL));
        char playerData=0;
        int capY=5,capX=25,cap='$';
        int twitch='!',twitchX=3,twitchY=7;
        int playerY=1, playerX=1, player='@';
        
        while(gamestutas)
        {     
                
                //добовление объектов на карту перед отрисовкой
                addMapObject(capY,capX,cap,map);
                addMapObject(playerY,playerX,player,map);
                addMapObject(twitchY,twitchX,twitch,map);
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

                
                

                //управление персонажем
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
                bot(&twitchY,&twitchX,map);
                gameover(twitchY,twitchX,playerY,playerX,&gamestutas);

                bot(&capY,&capX,map);
                gameover(capY,capX,playerY,playerX,&gamestutas);
                
        } 
        
        return 0;
}
