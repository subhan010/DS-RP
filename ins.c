#include <stdlib.h>
#include "header.h"

Screen* initialize_screen()
{

    Screen* screen;

    screen=(Screen *)malloc(sizeof(Screen));
    screen->current_show=0;
    screen->total_shows=NUMBER_OF_SHOWS;
    screen->show=(Show *)malloc(sizeof(Show));


    // screen->vip=(int *)malloc(sizeof(int)*vip);
    // screen->gold=(int *)malloc(sizeof(int)*gold);
    // screen->silver=(int *)malloc(sizeof(int)*silver);

    return screen;

}

Show * initialize_show(Screen *screen)
{
   if(screen->current_show==NUMBER_OF_SHOWS)
   {
    return NULL;
   }
   (screen->show+screen->current_show)->show_id=screen->current_show;
   (screen->show+screen->current_show)->gold_seat_number=GOLD;
   (screen->show+screen->current_show)->silver_seat_number=SILVER;
   (screen->show+screen->current_show)->vip_seat_number=VIP;
   //(screen->show+screen->current_show)->vip=(int *);

}

UserData* initialize(int initial_size)
{

   UserData* userdata;

   userdata=(UserData *)malloc(sizeof(UserData));
   userdata->c_size=0;
   userdata->users_data_size=initial_size;
   userdata->user=(User *)malloc(sizeof(User));


   return userdata;

   

}

int insertUser(UserData *ud, int phone)
{

    if(ud->c_size==ud->users_data_size)
    {
        return 0;
    }
    
    (ud->user+ud->c_size)->phone=phone;
    (ud->user+ud->c_size)->ticket_record_size=10;
    (ud->user+ud->c_size)->ticket_booking_history=(int *)malloc(sizeof(int)*10);
    (ud->user+ud->c_size)->user_record_c_size=0;
    (ud->user+ud->c_size)->reserve_ticket->c_size=0;
    (ud->user+ud->c_size)->reserve_ticket->t_size=RESERVE_SEATS_DATA_SIZE;
   

    return 1;
}

