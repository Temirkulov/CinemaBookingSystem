#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#ifndef MOVIE_BOOKING_H
#define MOVIE_BOOKING_H

using namespace std;

int obn; //to store the option of Cinema
int ext; //to store the option of exit
int prnt_once; //to print once the term user found
int dir_customer=0; //to check if the user directly goes to user instead of manager

int m=0,*p;
int sn; //sn is variable for show number in manager function N m is for number of shows in a day
int arg,arg2; //arg is for movie number and arg2 is for show number
int no_of_tkt; //no_of_tkt is to count the no.of tickets to be booked by customer
int tkt_pr; //tkt_pr is to print the no.of tickets to be booked
int nt=0; //nt is the number of timings of a particular movie
int sti;//sti is for showtime input in manager func
int foundu=0;//foundu to storevalue if user exists
int foundp=0; //foundp to storevalue if password is correct
int pas_chk=0; //stores the value like if the password was matched or not.
int mv_str=0; // To run the loop when data is being brought from file to compiler.
int data_store=0; // To make sure that the data is successfully stored in file.
double cost=0;
int  pas_rak=0;//to store the return value of function password_check()
char cus_in; //cus_in is for storing if customer is new or existing
//st is for showtime check the seat_disp func
//nt is the number of timings of a particular movie
string name[100],tkt_pnt,pass,cus_id,cus_pas,user,hall_name;//pass is to save the password
//hall_name to store the hall name
//cus_id for storing customer id
//cus_pas is for storing customer password
//tkt_pnt[100] to print the movie name in ticket
int ar[100][100][100][12][18],tkt_row[12],tkt_col[18],str_tim[100];//last two array r to be used to print ticket
//str_tim is saving the no.of show of a particular movie
/*in the array ar
1st arg is for movie no.
2nd arg is for particular showtime of particular movie
3rd arg is for rows
4th arg is for columns*/
string tim[100][100];
/*ITS THE string array to store the timings of a particular movie
1st argument is for movie number and and argument is for no.timings that
particular runs*/
string timing[100];//to store various timings of movie in file

class movie_booking
{

public:
    void first();
    void show_seat_frm_file();
    void show();
    void seatdisp(int z,int wt);
    void book(int z,int wt ,int a);
    void seatin(int z,int wt);
    void manager();
    void ticket_print();
    void pass_proctect();
    void data_str();
    int password_check();
    void hal_name()
    {
        switch(obn)
        {
            case 1:
            hall_name="Kuala Lumpur";
            break;
             case 2:
            hall_name="Johor Bahru";
            break;
             case 3:
            hall_name="Penang";
            break;
             case 4:
            hall_name="Ipoh";
            break;
        }

    }

};


void movie_booking::first()
{
    int i;
    char in='c',ind,cus;//cus is customer and ind is manager input
    cout<<"To enter as a Manager, press m/M, else press anything else to continue as Customer\n";
    cin>>ind;
    int pas_count=0;
    if((ind=='m')||(ind=='M'))
    {
        while(pas_count<3)
        {
            (*this).pass_proctect();
        if(pass=="Admin")
        {
            (*this).manager();//the manager mode to set the number of seats available for booking
            pas_count=3; 
        }

        else
        {
        cout<<"Entered Password is Wrong!"<<" You have "<<2-pas_count<<" atempts remaining!\n";//pas_count is to count no. of attempts left
            pas_count++;
        }

    }
    }

    system("clear");
    cout<<"To book Seats as a Customer press y/Y\n";
    cin>>cus;
    //Here the Customer Login Starts
     if((cus=='y')||(cus=='Y'))//the customer part starts here
     {  cout<<"Are you a Registered Customer? Press y/Y for yes and n/N for no\n";
        cin>>cus_in;
        if(cus_in=='N'||cus_in=='n')
        (*this).data_str();
        else
        {
            cout<<"Welcome Back Returning Customer!\n";
           pas_rak=(*this).password_check(); 

        }

//cout<<"+++++++++++"<<pas_rak<<"--------"<<data_store<<endl;to check the values
        cout<<"Press any key to continue\n";
// CLEAR();
 system("clear");
         if(pas_rak!=0||data_store!=0)
         {  cout<<"\n\nTHE SEATS AVAILABLE ARE:\n";
                 while((in=='c')||(in=='C'))
    {
        cost=0;
       (*this).show_seat_frm_file();
            cout<<"\n\nPlease enter the Movie Number to Book a Seat/Ticket\n";
            cin>>arg;
            ifstream fin;//this part is for retrieving moive name from file
fin.open("movie_list.csv");
   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');
    fin.close();
             cout<<"\nPlease choose the number that corresponds to the timing of the Selected Movie :-"<<endl;
            cout<<name[i]<<endl;
            cin>>sti;

            tkt_pnt=name[i];
               // cout<<"THE ARGUMENT IS ="<<arg<<endl;
            (*this).seatdisp(arg,sti);
            (*this).seatin(arg,sti);
            system("clear");
            (*this).seatdisp(arg,sti);
            system("clear");

            (*this).ticket_print();
    cout<<"\n\nPress 'C' or 'c' if you want to book Seats again. Otherwise press anything else.\n";
    cin>>in;



    }
         }

else{cout<<"\n\n You entered the Wrong Password\n";
    cout<<"\n\n Exiting Program...\n";
        cout<<"\n\n You entered the Wrong Password\n";}

     }
}

void movie_booking::show_seat_frm_file()
{int i=0,j;
    system("clear");//after the input is being over the screen is cleared and data is displayed
cout<<"\n\nThe currently available movies are:\n\n";
ifstream fin;
fin.open("movie_list.csv");
if(dir_customer==0)
    m=20;
while(i<m)
{
     cout<<"\n";

    getline(fin,name[i],',');
    cout<<"Movie :\t"<<i+1<<"\t"<<name[i]<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t";
    cout<<"THE TIMINGS OF THE MOVIE : "<<name[i]<<" :-  "<<endl; //to display the timings of the movie
    int j=0;

   getline(fin,tim[i][j],'\n');
        cout<<"\t\t\t\t\t\t\t";
        cout<<tim[i][j]<<endl<<endl;

i++;//to access the different movie names
}

}
void movie_booking::show()//this function is for entering the number of movie running in hall
{
    int i,j;
    p=(int*)(malloc(sizeof(int)));
    cout<<"\n\nEnter the number of Movies running in the Cinema\n";
    cin>>m;
    (*p)=m;
     ofstream fout;
    fout.open("movie_list.csv",ios::app);
for(i=0;i<m;i++)//m is the total no of movies running in that hall
{   fflush(stdin);
    cout<<"\n\nPlease enter the name of the movie"<<i+1<<endl;
    getline(cin,name[i]);
    fflush(stdin);
    fout<<name[i]<<",";//movie name writing in file
    cout<<"\n\nEnter the number of Shows of "<<name[i]<<" daily: ";
    cin>>nt;
    str_tim[i]=nt;
    //here a function is to be added to save the show timings
    cout<<"\n\nEnter the timings you would like to add: "<<name[i]<<endl;
    for(j=0;j<nt;j++)
    {   fflush(stdin);
        getline(cin,tim[i][j]);// this is the function for collecting the show timings
        fout<<tim[i][j]<<",";

    }
    fout<<endl;

}
 fout.close();
 //FILE HANDLING 100% CORRECT TILL HERE
 m=m+13;//as already is csv file there 13 movies
(*this).show_seat_frm_file();
}


void movie_booking::seatdisp(int z,int wt)
//1st argument to display the seats of that particular movie
//2nd arg is for the particular movie time
{
    arg=z;
    sti=wt;
    int i,j;
    char ch='A',st;
    system("clear");
    cout<<"\n\nCost of Vip Seat: MYR 100/-\n";
      cout<<"Cost OF Deluxe Seat: MYR 50/-\n";
    cout<<"Cost of Regular Seat: MYR 20/-\n";
ifstream fin;//this part is for retrieving movie name from file
fin.open("movie_list.csv");
   cout<<"\n\nSeats that are Booked are marked with an [x]\n\n";
   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');
   cout<<"\n\nThis is the seating arrangement for the movie: "<<name[i]<<"\n\n"; //this is for displaying the movie name and time 262
    fin.close();
    for(i=0;i<13;i++)
    {
        ch='A';
        ch=ch+i;
        cout<<"\t";
     for(j=0;j<18;j++)
        {
            if(ar[obn][arg][sti][i][j]==1)
            cout<<"["<<" X"<<"]";
            else
            {
                cout<<"["<<ch<<j+1<<"]";
            }

            cout<<" ";//1 white spaces given
                      //the seat would be displayed in format[A1]

            if(j==4||j==12)
                cout<<"\t";

        }
        cout<<"\n\n";
 if(i==12)
    {
        cout<<"\n\n\t\t\t\t\t\t Screen on this Side\n";
        cout<<"\t______________________________________________________________________________________________________________";
    }

    }

}




void movie_booking::book(int z,int wt ,int a)//first argument is for the movie number and 3rd argument for manager mode
//2nd arg is for show time
{int i,j,num,al,n,col,stor,arg;
arg=z;
sti=wt;
    arg2=a;
    if(arg2==100)
    {
      cout<<"\n\nADMIN ENTER THE SEATS WHICH WONT BE AVAILABLE FOR BOOKING\n";
    }

else
{
 cout<<"\n\nCustomer Booking\n";
}

        (*this).seatdisp(arg,sti);
    char ch='A',chr;
    cout<<"\n\nPlease Enter the Seat Numbers\t";

        cin>>chr>>col;
        stor=chr-65;
        col=col-1;

        if(ar[obn][arg][sti][stor][col]==0)
        {
            ar[obn][arg][sti][stor][col]=1;

            tkt_col[no_of_tkt]=col;
            tkt_row[no_of_tkt]=stor;


        }
        else
        {

            while(ar[obn][arg][sti][stor][col]!=0)
            {
                if(arg2==100)
                {
                  cout<<"\n\n Dear Admin, You have already booked this seat, please book another seat\n";
                }

           else
           {
            cout<<"\n\nThe Seat you selected is already occupied, please enter a new seat that is not marked with [x]\n";
           }
                cin>>chr>>col;
                stor=chr-65;
                col=col-1;
            }
            ar[obn][arg][sti][stor][col]=1;
           tkt_col[no_of_tkt]=col;
            tkt_row[no_of_tkt]=stor;
        }

}

void movie_booking::seatin(int z,int wt)//1st argument for the particular movie seat booking
//2nd arg is for particular show time of particular movie
{

     int n,i;
    arg=z;
    sti=wt;
    //cout<<"THE ARGUMENT IS nest="<<arg<<endl;
     cout<<"\n\nAll the reserved/Booked seats are marked with [x]\n";
     cout<<"\n\nHow many seats would you like to Book?"<<endl;
     ifstream fin;//this part is for retrieving movie name from file
fin.open("movie_list.csv");

   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');

            cout<<"Movie Name="<<name[i]<<endl;
           fin.close();
            cout<<"Number of Seats: ";
    cin>>n;
    tkt_pr=n;
       for(no_of_tkt=0;no_of_tkt<n;no_of_tkt++)//loop for booking the desired no. of tickets as input by user
{
     (*this).book(arg,sti,20);
     cout<<"Loop running successfully\n";
       system("clear");
  (*this).seatdisp(arg,sti);

}
cout<<"\n\nPress any key to continue.\n";
// CLEAR();
 system("clear");

}




void movie_booking::manager()
{   char mov='c',in='c';
    (*this).show();
    while((mov=='c')||(mov=='C'))//this loop is for entering the seats that are booked for different movies
    {
        cout<<"\n\nENTER THE SHOW NUMBER WHOSE SEATS U WANT TO ASSIGN FOR BOOKING\n";
    cin>>sn;
      cout<<"\n\n ENTER THE NUMBER CORRESPONDING TO THE TIME TO BOOK TICKET\n";
    cin>>sti;
    tkt_pnt=name[sn];

    while((in=='c')||(in=='C'))
    {
      (*this).book(sn,sti,100);
      system("clear");
      (*this).seatdisp(sn,sti);
    cout<<"\n\nPress 'C' or 'c' If you want to book more Seats\n";
    cin>>in;
    }

    cout<<"\n\nPress 'C' or 'c' if you want to book seats for other Movies\n";
    cin>>mov;
    in='c';
    }
    mv_str++;

}

void movie_booking::ticket_print()
{    int i,a=0,b=0,d=0;
    char c;
    string time;//time to store the movie timing

    for(i=0;i<tkt_pr;i++)//this loop is for printing the total cost of ticket
        {


             if(tkt_row[i]==0||tkt_row[i]==1)
            {
                cost=cost+100;
                a++;
            }
            else if(tkt_row[i]>1&&tkt_row[i]<7)
            {
                cost=cost+50;
                b++;
            }
            else{cost=cost+20;d++;}


        }
           cout<<"\n\n\nCost : "<<endl;
           if(a!=0)
           cout<<a<<" * 100"<<endl;
           if(b!=0)
           cout<<"+"<<b<<" * 50"<<endl;
           if(c!=0)
           cout<<"+"<<d<<" * 20"<<endl;
       cout<<"GST 6% = "<<cost*0.06<<endl;
       cost=cost+cost*(0.18);
        cout<<"\n\n\n\nThe total cost of the ticket = MYR "<<cost<<"/-"<<endl;
        cout << "\n\nHow would you like to pay? Press 'x' or 'X' to pay now or press anything to pay in Person\n";
        int fee;
        char pay;
        cin>>pay;
        if((pay=='x')||(pay=='X'))//Payment Method requirement
        {  
        cout<<"Please enter your fee!\n";
        cin>>fee;
        if(fee<cost)
        {
            cout<<"Sorry, your fee is not enough!\n";
            cout<<"Please enter your fee!\n";
            cin>>fee;

            
        }
        else
        {
            cout<<"Your change is "<<fee-cost<<endl;
            cout<<"Thank you for your Payment!\n";
        }
        }
        else
        {
            cout<<"Please pay at the counter upon arrival!\n";
        }

    //    CLEAR();
  system("clear"); 

         system("clear");
         ifstream fin;//this part is for retrieving movie name from file
fin.open("movie_list.csv");

   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');
         for(int j=0;j<sti;j++)
   {
    getline(fin,time,',');
   }
   fin.close();
    (*this).hal_name();
cout<<"________________________________________________________________________\n";
cout<<"|                                                                       |\n";
cout<<"|   Dear Customer,                                                      |\n";
cout<<"|                      Congratulation!! Your tickets has been booked.   |\n";
cout<<"|                                                                       |\n";
cout<<"|          Details:                                                     |\n";
cout<<"|           Movie Hall: "<<hall_name<<"                                     |\n";
cout<<"|           Movie Name: "<<name[i]<<"                                           |\n";
cout<<"|           The Movie starts at:"<<time<<"                              |\n";
cout<<"|                 Number of Tickets Booked: "<<tkt_pr<<"                |\n";
cout<<"|                 The Seats selected are: ";for(i=0;i<tkt_pr;i++)
                                            {   c=tkt_row[i]+65;
                                                cout<<c<<tkt_col[i]+1;
                                                if(i<no_of_tkt-1)
                                                {
                                                    cout<<",";
                                                }
                                            };
                                            cout<<"                            |\n";                                  
cout<<"|                                                     Unique Code       |\n"; //purely for decoration purposes
cout<<"|                                                       ..++>>>         |\n"; //serves no real purpose
cout<<"|                                                       ..__***         |\n";
cout<<"|                                                       &%^>>>>         |\n";
cout<<"|                                                       :::::::         |\n";
cout<<"|_______________________________________________________________________|\n";

                                                cout<<"Cinema Booking System Created by"<<endl;
                                                cout<<"Mirkamol Temirkulov"<<endl;
                                                cout<<"Asim Murtada"<<endl;
                                                cout<<"Eyu Boon Fu"<<endl;
                                                cout<<"Oscar Tan Wei Jiang"<<endl;
                                                cout<<"in collaboration with StarReel Organization."<<endl;
}

void movie_booking::pass_proctect()//to protect the password
{

        int ps=0,star=0;// to count the characters in password

        //star is to print the password in * format
         cout<<"\n\nEnter the Manager Password\n";

                cin>>pass;
               ps=pass.length();
                system("clear");
                while(star<ps)
                {   if(star==0)
                {
                    cout<<"\n\nPlease enter the Manager Account Password.\n\n";

                }

                    cout<<" * ";
                    star++;
                }

}

void movie_booking::data_str()
{
 ofstream fout;
    fout.open("users.csv",ios::app);
    string name,gender,age,preference,usr_id,usr_psd;
    /*format to be save is 1st name,gender,movie preference,age,password*/
    fflush(stdin);


 cout<<"Please enter your Name\n";
        fflush(stdin);
        getline(cin,name);
         cout<<"Please enter your Gender\n";
         fflush(stdin);
        getline(cin,gender);
        cout<<"Please enter your age\n";
         fflush(stdin);
        getline(cin,age);
         cout<<"Please enter your movie genre preference\n";
         fflush(stdin);
        getline(cin,preference);
        cout<<"Please choose a user ID\n";
         fflush(stdin);
        getline(cin,usr_id);
         cout<<"Please enter your user password\n";
         fflush(stdin);
        getline(cin,usr_psd);
         fout<<name<<","<<gender<<","<<age<<","<<preference<<","<<usr_id<<","<<usr_psd<<endl;

fout.close();
data_store=1;
}
int movie_booking::password_check()
{
     cout<<"\n\nPlease Enter your User ID\n";
            fflush(stdin);

            cin>>cus_id;
 ifstream myfile;
            myfile.open("users.csv");
                while(!myfile.eof())
            {
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,pass,'\n');
                fflush(stdin);

                fflush(stdin);
                if(user==cus_id||pass==cus_id)
                {
                   foundu++;
                   prnt_once++;
                   if(prnt_once==1)
                   cout<<"\n\nUser ID has been found\n";
                }


            }

            if(foundu==0)
            {cout<<"\n\nYour User ID could not be found\n";
             myfile.close();
            }
              else
              {
                 myfile.close();
                              cout<<"\n\nEnter Your Account Password"<<user<<"\n";
            fflush(stdin);
            cin>>cus_pas;
 myfile.open("users.csv");
                while(!myfile.eof())
            {
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,pass,'\n');
                fflush(stdin);

                fflush(stdin);
                if(pass==cus_pas)
                {
                   foundp++;
                   cout<<"\n\nPassword is Correct\n";
                   cout<<"\n\nWelcome Back"<<user<<"\n";
                }


            }

              }

            if(foundp==0)
               cout<<"\n\nWrong Password!\n";


             myfile.close();
             return foundp;


}

#endif // MOVIE_BOOKING_H_INCLUDED
