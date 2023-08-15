#include "movie_booking.h"

using namespace std;
int main()
{
    prnt_once=0;
    movie_booking obj[4];
    while(1)
    {
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"|                                                                                                                      |\n";
    cout<<"|                                                                                                                      |\n";
    cout<<"|                                                                                                                      |\n";
    cout<<"|                                                WELCOME!                                                              |\n";
    cout<<"|                                                   TO                                                                 |\n";
    cout<<"|                                          Cinema Booking System                                                       |\n";
    cout<<"|                                                                                                                      |\n";
    cout<<"|                                                                                                                      |\n";
    cout<<"|                                                                                                                      |\n";
    cout<<"|                                                                                                                      |\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Press 1 to book a ticket in Kuala Lumpur\n";
    cout<<"Press 2 to book a ticket in Johor Bahru\n";
    cout<<"Press 3 to book a ticket in Penang\n";
    cout<<"Press 4 to book a ticket in Ipoh\n";
    cout<<"Press 5 to exit the booking system!\n";
    cin>>obn;
    switch(obn)
    {
        case 1:
            cout<<"Kuala Lumpur is selected\n";
        obj[0].first();
        break;
        case 2:
            cout<<"Johor Bahru is selected\n";
        obj[1].first();
        break;
        case 3:
             cout<<"Penang is selected\n";
        obj[2].first();
        break;
        case 4:
            cout<<"Ipoh is selected\n";
        obj[3].first();
        break;
        case 5:
                goto bye;
                break;
        default:
        cout<<"Please enter a valid number!\n";
        goto bye;
                break;
    }


    }



bye:
     cout<<"Thank you for visiting our Cinemas\n";
     system("clear");
 return 0;
}

