#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define string(x) char x[]

bool gamestutas=true;

        int map[10][30]={{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                          {'#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ','#','#',' ',' ',' ',' ','#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ',' ',' ',' ','#','#','#','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
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
int main(void)
{
        
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
                bot(&twitchY,&twitchX);
                gameover(twitchY,twitchX,playerY,playerX);

                bot(&capY,&capX);
                gameover(capY,capX,playerY,playerX);
                
        } 
        
        return 0;
}
