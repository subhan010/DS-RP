#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include <string.h>



UserData* initialize_user(int initial_size)
{

   UserData* userdata;

   userdata=(UserData *)malloc(sizeof(UserData));
   userdata->c_size=0;
   userdata->users_data_size=initial_size;
   userdata->user=(User *)malloc(sizeof(User));


   return userdata;

   

}

int insert_user(UserData *ud, char* phone)
{
    User user;
    if(ud->c_size==ud->users_data_size)
    {
        return 0;
    }
    user.phone=phone;
    user.ticket_record_size=10;
    user.user_record_c_size=0;
    user.ticket_booking_history = (Ticket*)malloc(user.ticket_record_size * sizeof(Ticket));
      for (int i = 0; i < user.ticket_record_size; i++) {
        user.ticket_booking_history[i].ticket = NULL; 
    }

    
   

    
    *(ud->user+ud->c_size)=user;
   

   
        ud->c_size++;
    return 1;
}

int user_present(UserData *ud, char* phone,int *cur_pos)
{
    for(int i=0;i<ud->c_size;i++)
    {
        
       if(strcmp((ud->user+i)->phone,phone)==0)
       {
        printf("%d found\n",i);
        printf("\n%s\n",phone);
        printf("%s\n",(ud->user+i)->phone);
        printf("%d found\n",i);
        *cur_pos=i;
        return 1;
       }

    }

    return 0;
}
int add_ticket_history(UserData *ud,char *ticket,int cur)
{
    
    (ud->user+cur)->ticket_booking_history[(ud->user+cur)->user_record_c_size].ticket=ticket;
    (ud->user+cur)->user_record_c_size++;
   
    return 1;
}
int show_booking_history(UserData *ud,int current_positon)
{
    printf("%d %d ",current_positon,ud->c_size);
    printf("%s\n",(ud->user+current_positon)->phone);
    printf("Ticket booking history table\n");
    for(int i=0;i<(ud->user+current_positon)->user_record_c_size;i++)
    {
        
        printf("%s\n",((ud->user+current_positon)->ticket_booking_history[i].ticket));
    }
     printf("Ticket booking history table ends\n");

    return 0;
}

