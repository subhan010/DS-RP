#define VIP 10
#define GOLD 20
#define SILVER 30
#define USER_DATA_SIZE 10
#define RESERVE_SEATS_DATA_SIZE 10
#define BOOK_HISTORY_DATA_SIZE 10
#define NUMBER_OF_SHOWS 3
#define SUCCESS 1
#define FAILURE
#define MEMORY_ALLOC_FAIL NULL
#define NUMBER_OF_USERS 10



struct _ticket_
{
  char* ticket;
};
typedef struct _ticket_ Ticket;

struct _show_
{
   int show_id; 
   int *vip;
   int *gold;
   int *silver;
   int vip_c_seat;
   int vip_t_seat;
   int gold_t_seat;
   int gold_c_seat;
   int silver_t_seat;
   int silver_c_seat;
  char* show_timinings;

};
typedef struct _show_ Show;

struct _screen_ 
{
    int total_shows;
    int current_show;
    Show *show;


};
typedef struct _screen_ Screen;


struct _user_ 
{
     char* phone;
     Ticket* ticket_booking_history;
     int ticket_record_size;
     int user_record_c_size;
    
     
} ;
typedef struct _user_ User;

struct _userdata_
{
    int users_data_size;
    int c_size;
    User *user;

};
typedef struct _userdata_ UserData;



struct _reserve_seats_
{
    int c_size;
    int t_size;
    int *phone;
    int *ticket_number;
    
};

typedef struct _reserve_seats_ Reserve_seats;

Screen* initialize_screen(int , int, int);
Show* initialize_show(Screen *,int);
UserData* initialize_user(int );
int add_screen(Screen *,int);
int add_show(Show *,int);
int insert_user(UserData *, char*);
int book_ticket(UserData * ,Screen*,int,int,int,int);
int reserve_ticket(int,int);
int cancel_ticket(UserData* ,Screen*, int);
void seat_layout(Screen *,int);
int user_present(UserData *,char*,int *);
int show_booking_history(UserData *, int);
int add_ticket_history(UserData *,char* ,int);



//Screen data hardcoded
Screen* hardcoded_shows();



















