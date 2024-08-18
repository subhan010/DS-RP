#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include <time.h>

void add_shows(Screen *shows)
{
    
    Show data;
    data.show_id=1;
    data.vip_c_seat=0;
    data.gold_c_seat=0;
    data.silver_c_seat=0;
    data.vip_t_seat=VIP;
    data.gold_t_seat=GOLD;
    data.silver_t_seat=SILVER;
    data.gold=(int*)calloc(GOLD,sizeof(int));
    data.silver=(int*)calloc(SILVER,sizeof(int));
    data.vip=(int*)calloc(VIP,sizeof(int));

    char * showtime[3]={"10:00 AM","1:00 PM","7:00 PM" };
   
    int time_count=0;
    while(shows->current_show<shows->total_shows)
    {
       data.show_timinings=showtime[time_count];
       *(shows->show+shows->current_show)=data;
       time_count++;
       shows->current_show++;
      
    }

}

Screen*  hardcoded_shows()
{
    Screen * shows;
    shows=(Screen *)malloc(sizeof(Screen));

    if(shows==NULL)
    {
        return MEMORY_ALLOC_FAIL;
    }

    shows->current_show=0;
    shows->total_shows=3;
    shows->show=(Show *)malloc(sizeof(Show)*3);
    add_shows(shows);

    return shows;
 
}

void seat_layout(Screen *shows,int time)
{
   
    
    time=time-1;
   
    printf("%s\n",(shows->show+time)->show_timinings);
    printf("\t\t\t\tVIP\n");
    for(int i=0;i<(shows->show+time)->vip_t_seat;i++)
    {
       
        printf("%d|%d\t",*((shows->show+time)->vip+i),i+1);
         if(((i+1)%10==0))
        {
            printf("\n");
        }
    }
    printf("\n");
    printf("\t\t\t\tGOLD\n");
    for(int i=0;i<(shows->show+time)->gold_t_seat;i++)
    {
       
        printf("%d|%d\t",*((shows->show+time)->gold+i),i+1);
         if(((i+1)%10==0))
        {
            printf("\n");
        }
    }
     printf("\n");
    printf("\t\t\t\tSILVER\n");
    for(int i=0;i<(shows->show+time)->silver_t_seat;i++)
    {
        
        printf("%d|%d\t",*((shows->show+time)->silver+i),i+1);
         if(((i+1)%10==0))
        {
            printf("\n");
        }
    }
    
   
    
    
}
int book_ticket(UserData* ud,Screen* shows, int cur,int time,int cls, int seat_no)
{
    
   char temp[5];
    time=time-1;
     printf("%d ntfs\n",cls);
    if(cls==1)
    {
       *((shows->show+time)->vip+(seat_no-1))=1;
      
    }
    else if(cls==2)
    { 
        *((shows->show+time)->gold+(seat_no-1))=1;

    }
    else if(cls==3)
    {
         *((shows->show+time)->silver+(seat_no-1))=1;
    }
    
    snprintf(temp, sizeof(temp), "%d%d%02d\0", time,cls,seat_no-1);
     

     printf("%s\n",temp);

    add_ticket_history(ud,temp,cur);
   // (ud->user+cur)->user_record_c_size++;
    return 1;

}



