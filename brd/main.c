#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>
#define xmap 30
#define ymap 10

void controlplayer(int* playerdata,int *Yplayer,int* Xplayer,int (*map)[xmap])
{
        scanf(" %c",playerdata);

        switch(*playerdata)
                {
                case 'w':
                        if(map[*Yplayer-1][*Xplayer]!='#')
                        *Yplayer-=1;
                break;

                case 's':
                        if(map[*Yplayer+1][*Xplayer]!='#')
                        *Yplayer+=1;
                break;

                case 'a':
                        if(map[*Yplayer][*Xplayer-1]!='#')
                        *Xplayer-=1;
                break;

                case 'd':
                        if(map[*Yplayer][*Xplayer+1]!='#')
                        *Xplayer+=1;
                break;
                }
}

void addmapobject(int Y,int X,int object,int (*map)[xmap])
{
        map[Y][X]=object;
}

void deletemapobject(int Y,int X,int (*map)[xmap])
{
        map[Y][X]=' ';
}

int render(int (*map)[xmap],int point/*кол-во аргументов далее*/,.../*symbol,Y,X*/)
{
        va_list ptr;
        va_start(ptr,point);
        
        if(point%3!=0)
        return 1;

        for(int i=0;i<point;)
        {
                int symbol=va_arg(ptr,int);
                i++;
                int Y=va_arg(ptr,int);
                i++;
                int X=va_arg(ptr,int);
                i++;
                addmapobject(Y,X,symbol,map);
        }

        for(int i=0;i<ymap;i++)
        {
                for(int j=0;j<xmap;j++)
                {
                        printf("%c",map[i][j]);
                }
        printf("\n");
        }

        va_start(ptr,point);

        for(int i=0;i<point;)
        {
                int symbol=va_arg(ptr,int);
                i++;
                int Y=va_arg(ptr,int);
                i++;
                int X=va_arg(ptr,int);
                i++;
                deletemapobject(Y,X,map);
        }

        
        return 0;

}


int main(void)
{
        int map[ymap][xmap]={
                             {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                             {'#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                             {'#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                             {'#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                             {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                             {'#',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#'},
                             {'#',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#'},
                             {'#',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#'},
                             {'#',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#'},
                             {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
                            };
        int
        playerData=0,
        player='@',
        Xplayer=1,
        Yplayer=1;

        while(true)
        {       
                
                if(render(map,3,player,Yplayer,Xplayer)!=0){printf("error render");return 1;}

                controlplayer(&playerData,&Yplayer,&Xplayer,map);
                
                system("clear");

                
        }
}