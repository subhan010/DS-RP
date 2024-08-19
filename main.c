#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    Screen * shows;
    shows=hardcoded_shows();
    UserData *userdata;
    userdata=initialize_user(NUMBER_OF_USERS);
    int current_position;
   

    
    printf("Enter your mobile number to login/signup\n");
    char temp[11];
    scanf("%10s",temp);

  
    //insert_user(userdata,temp);
    insert_user(userdata,"1234567891");
    insert_user(userdata,"1234567892");
   
    if(user_present(userdata,temp,&current_position)==0)
    {
          current_position=(userdata->c_size); 
          insert_user(userdata,temp);

          printf("Signed up successfully\n");
    }
    else
    {
        printf("User already present. Logged in successfully\n");
    }
       
    char opt;
   
    while(1)
    {
        printf("Enter the option \n");
        printf("1. Book Ticket\n");
        printf("2. Reserve Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Show seats\n");
        printf("5. Show booking history\n");
        printf("Press any other key to exit\n");
        
       
        scanf(" %c",&opt);
        if(opt>'5' ||  opt<'1')
        {
            break;
        }


        switch (opt)
        {
               
        case '1':
            /* book ticket */
            printf("Choose the show timinigs\n");
            int timimg_option;
           while(1)
           {
            
            printf("1. 10:00 AM \n 2. 1:00 PM \n3. 7:00 PM \n9. Exit");
            scanf(" %d",&timimg_option);
            if(timimg_option<= 3 && timimg_option>=1)
            {
              seat_layout(shows,timimg_option);
              printf("Enter the class option\n");
              printf("1.VIP 2.GOLD 3.SilLVER\n");
              int cls;
              int seat_no;
              scanf(" %d",&cls);
              printf("Enter seat number\n");
              scanf("%d",&seat_no);
              int ten=book_ticket(userdata,shows,current_position,timimg_option,cls,seat_no);


            }
            else
            {
                break;
                // if(timimg_option=='9')
                // {
                //     break;
                // }
                // printf("choosed worng option , choose correct option or press 9 to exit\n");
            }
           
            

           }
            break;
        case '2':
            /* code */
            printf("not implemented yet\n");
            break;
        case '3':
            
            cancel_ticket(userdata, shows,current_position);

            break;
        case '4':
            /* code */
            int tp;
            printf("1. 10:00 AM \n 2. 1:00 PM \n3. 7:00 PM \n");
            scanf(" %d",&tp);
            seat_layout(shows,tp);
            break;
        case '5':
            /* code */
           
           
            show_booking_history(userdata,current_position);
            break;
        
        default:
            break;
        }
      
   
    }

   


}