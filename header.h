#define VIP 10
#define GOLD 20
#define SILVER 30
#define USER_DATA_SIZE 10
#define RESERVE_SEATS_DATA_SIZE 3
#define BOOK_HISTORY_DATA_SIZE 10
#define NUMBER_OF_SHOWS 3
#include <time.h>



struct _screen_ 
{
    int total_shows;
    int current_show;
    Show *show;


};
typedef struct _screen_ Screen;




struct _show_
{
   int show_id; 
   int *vip;
   int *gold;
   int *silver;
   int vip_seat_number;
   int gold_seat_number;
   int silver_seat_number;
   time_t show_timinings;

};
typedef struct _show_ Show;


struct _userdata_
{
    int users_data_size;
    int c_size;
    User *user;

};
typedef struct _userdata_ UserData;

typedef struct _user_ 
{
     int phone;
     int *ticket_booking_history;
     int ticket_record_size;
     int user_record_c_size;
     Reserve_seats *reserve_ticket;
     
}User;

struct _reserve_seats_
{
    int c_size;
    int t_size;
    int ticket_number;
    time_t *reserved_ticket_time;
};

typedef struct _reserve_seats_ Reserve_seats;

Screen* initialize_screen(int , int, int);
Show* initialize_show(Screen *,int);
UserData* initialize(int );

int insert_user(UserData *, int);
int book_ticket(int ,int);
int reserve_ticket(int,int);
void show_layout();
















