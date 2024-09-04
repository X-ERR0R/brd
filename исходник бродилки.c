#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define string(x) char x[]


int main(void)
{
        srand(time(NULL));
        char playerData=0;
        char capY=5,capX=25,cap='$';
        char playerY=1, playerX=1, player='@';
        char map[10][30]={{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                          {'#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ','#','#',' ',' ',' ',' ','#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ',' ',' ',' ','#','#','#','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                          {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};

        while(true)
        {     
                

                main:
                //отрисовка
                printf("\033[0d\033[2J");
                map[capY][capX]=cap;
                map[playerY][playerX]=player;
                for(int i=0;i<(sizeof(map)/sizeof(map[0]));i++)
                {
                        for(int j=0;j<(sizeof(map[0])/sizeof(map[0][0]));j++){
                                printf("%c",map[i][j]);
                        }
                        printf("\n");
                }
                
                if(capY==playerY && capX==playerX)
                {
                        printf("game over");
                        return 0;
                }
                scanf(" %c",&playerData);//считавание стрелочки
                
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

                //управдение cap
                map[capY] [capX]=' ';

                switch ((rand()%4))
                {
                case 1:
                if(map[capY-1][capX]!='#')
                {
                        capY-=1;
                }
                break;

                case 2:
                if(map[capY+1][capX]!='#')
                {
                        capY+=1;
                }
                break;

                case 3:
                if(map[capY][capX-1]!='#')
                {
                        capX-=1;
                }
                break;

                case 0:
                if(map[capY][capX+1]!='#')
                {
                        capX+=1;
                }
                break;
                }
                
        } 
        
        return 0;
}
