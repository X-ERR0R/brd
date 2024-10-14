#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>

#define ymap 10
#define xmap 30

#ifdef xmap
#else
#error undefined data
#error code=3
#error xmap is not define
#endif

#ifdef ymap
#else
#error undefined data
#error code=3
#error ymap is not defined
#endif

int game_over(int Xplayer,int Yplayer,int Xenemy,int Yenemy)
{
        if(Xenemy == Xenemy && Yplayer == Yenemy)
        return -2;
}

int entity_new(int input,int *Yentity,int* Xentity,int (*map)[xmap])
{

        switch(input)
                {
                case 0:
                        if(map[*Yentity-1][*Xentity]!='#')
                        *Yentity-=1;
                break;

                case 1:
                        if(map[*Yentity+1][*Xentity]!='#')
                        *Yentity+=1;
                break;

                case 2:
                        if(map[*Yentity][*Xentity-1]!='#')
                        *Xentity-=1;
                break;

                case 3:
                        if(map[*Yentity][*Xentity+1]!='#')
                        *Xentity+=1;
                break;
                    
                                    
                }
    return 0;
}

int player_control(int *input,int *Yplayer,int* Xplayer,int (*map)[xmap])
{
        scanf(" %c",(char*)input);

        switch(*input)
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
                    
                case 'x':
                        return -1;
                break;                    
                }
    return 0;
}

int add_map_object(int Y,int X,int object,int (*map)[xmap])
{
        map[Y][X]=object;
    return 0;
}

int delete_map_object(int Y,int X,int (*map)[xmap])
{
        map[Y][X]=' ';
    return 0;
}

int render(int (*map)[xmap],int point/*кол-во аргументов далее*/,.../*symbol,Y,X*/)
{
        va_list ptr;
        va_start(ptr,point);
            
        if((point%3)!=0)
        return 1;

        for(int i=0;i<point;)
        {
                int symbol=va_arg(ptr,int);
                i++;
                int Y=va_arg(ptr,int);
                i++;
                                        
                int X=va_arg(ptr,int);
                                        
                i++;
                if (Y < 1 || Y > (ymap-1) || X < 1 || X > (xmap-1)){return 2;}
                add_map_object(Y,X,symbol,map);
        }
         printf("exit l\n");
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
                delete_map_object(Y,X,map);
        }


        return 0;

}


int main(void)
{       
        //const data
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
        
        srand(time(NULL));

        //game entity
        int
        playerData=0,
        player='@',
        Xplayer=1,
        Yplayer=1;

        int
        cap='*',
        Xcap=1,
        Ycap=8;

        while(true)
        {       
                //render
                char codeExit=render(map,6,player,Yplayer,Xplayer,cap,Ycap,Xcap);
                if(codeExit==1){printf("error render\ncode=1\ninvalid input data");return 1;}
                else if(codeExit==2){printf("error render\ncode=2\nleaving the playing field");return 2;}
                
                //player
                if(player_control(&playerData,&Yplayer,&Xplayer,map)==-1){printf("exit game");return -1;}

                //entity
                entity_new((rand()%4),&Ycap,&Xcap,map);

                
                //game over
                if(game_over(Xplayer,Yplayer,Xcap,Ycap)==-2){printf("game over");return -2;}

                
                
                //end
                printf("\033[0d\033[2J");
        }
        return 0;
    return 0;
}