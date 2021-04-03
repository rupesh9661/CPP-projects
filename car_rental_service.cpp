// program for car retal services
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
int ch, ent, wish;
;

void prevpage();

class car
{

public:
    char bn[10], cl[10];
    void addcar();
    void show();
    void store();
    void delcar();

    void view();
    void update();
};
// code for registration

class registeration
{
    int age;
    char n[20], p[10], cn[11], uid[10];

public:
    void new_account();
    void store();
    void login();
    void show();
    void viewcustomers();
};

// code for new account
void registeration::new_account()
{
    system("cls");
    int i, count = 0;
    cin.ignore();
    cout << " enter your name : ";
    gets(n);

    cout << " enter your age : ";
    cin >> age;

phone: // level for enter contact again
    cin.ignore();
    cout << " Enter contact number :";
    gets(cn);

    for (i = 0; cn[i] != '\0'; i++)
    {

        count++;
    }
    //  cout<<count;
    if (count != 10)
    {
        cout << " \t\n Invalid contact number , please Try again  " << endl;
        count = 0;
        goto phone;
    }

    else
        cout << "  create user id : ";
    gets(uid);
    cout << " create password : ";
    gets(p);
    cout << "\n \nyour details have been saved successfully " << endl;
}

void registeration::store()
{
    ofstream fout;
    fout.open("login.txt", ios::app | ios::binary);
    fout.write((char *)this, sizeof(*this));
}
// code for view profile for customers
void registeration::show()
{
    char id[10];
    cin.ignore();
    cout << " Enter Your User id : ";
    gets(id);
    ifstream fin;
    fin.open("login.txt", ios::in | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (!fin.eof())
    {
        if (!strcmp(id, uid))
            cout << " \n Name : " << n << "\n Age : " << age << "year \n Contact Number : " << cn << "\n User id : " << uid << endl;
        fin.read((char *)this, sizeof(*this));
    }
}
// code for view customers profile for employee

void registeration::viewcustomers()
{
    
    cin.ignore();
   
    ifstream fin;
    fin.open("login.txt", ios::in | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (!fin.eof())
    {
       
            cout << " \n Name : " << n << "\n Age : " << age << "year \n Contact Number : " << cn << "\n User id : " << uid << endl;
        fin.read((char *)this, sizeof(*this));
    }
}
// code for login
void registeration::login()
{
    int i = 0;
    char u[10], pas[10];
    cin.ignore();
    cout << " Enter user id : ";
    gets(u);
    cout << " Enter password : ";
    gets(pas);
    ifstream fin;
    fin.open("login.txt", ios::in | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (!fin.eof())
    {
        if (!strcmp(u, uid))
        {
            if (!strcmp(pas, p))
            {
                i++;
            }
        }
        fin.read((char *)this, sizeof(*this));
    }
    if (i == 0)
    {
        system("color 40");
        cout << " \n\n INCORRECT USER ID OR PASSWORD ! try again ";
    }
    else
    {
        system("color 10");
        cout << " \n\t LOGIN SUCCESSFUL";
    }
}

// code for function of login and registeration
void function()
{
    registeration r;
    int uid;
    char c, pas[10];
    system("color 4f");
    cout << " \n****************Welcome to car rental service****************";
    cout << " \n\n 1: Register as a customer \t 2: customer Login \t 3: Employee Login  " << endl;

    cout << " ENTER YOUR CHOICE : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("cls");
        system("color 1f");
        r.new_account();
        r.store();
      cout<<" \n\nYOUR REGISTRATION SUCCESSFULL "<<endl;
      cout<<" \n\n\tif you want to go on login in page press p otherwise press e to exit : ";
      cin>>c;
      if(c=='p')
      {
          system("cls");
        system("color 60");
        r.login();
      }
      else 
      cout << "\n\n\t ************Thanks for visitng us**************** ";

        break;

    case 2:
        system("cls");
        system("color 60");
        r.login();

        break;

    case 3:
        system("cls");
    emp: // level for employee login again
        cin.ignore();
        cout << " ENTER USER ID : ";
        cin >> uid;

        if (uid < 100 && uid > 0)
        {
            cin.ignore();
            cout << " ENTER PASSWORD : ";
            gets(pas);
            if (!strcmp(pas, "carrental"))
                cout << " \n\t LOGIN SUCCESSFUL " << endl;
            break;
        }
        else
            cout << " \n\t USER ID OR PASSWORD IS INCORRECT , try again ";
        goto emp; // login again
        break;
    }
}

// code for dashboard
void dashboard()
{
    switch (ch)
    {
        case 1: 
        system("cls");
        system("color 40");
        cout << "\n\n  1: view our cars     2: rent a car    3: view your booking    4:view your profile    5: logut " << endl;
        break;

    case 2:
        system("cls");
        system("color 40");
        cout << "\n\n  1: view our cars     2: rent a car    3: view your booking    4:view your profile    5: logut " << endl;
        break;

    case 3:
        system("cls");
        system("color 40");
        cout << "\n\n 11: Add a car   12: delete a car   13: view cars  14: view bookings   15: view customers   16: logout  " << endl;
        break;
    }
}

// code for add a car

void car::addcar()
{
    cin.ignore();
    cout << " \n\n\t.Enter car details............ " << endl;
    cout << " Enter CAR Brand Name : ";
    gets(bn);
    cout << " Enter class : ";
    gets(cl);

    cout << "\n\t car datails have been saved successfully :" << endl;
}

// code for show
void car::show()
{
    cout << " Brand name : " << bn << endl;
}

// code for store
void car::store()
{
    ofstream fout;
    fout.open("carstock.txt", ios::app | ios::binary);
    fout.write((char *)this, sizeof(*this));
    fout.close();
}

// code for view
void car ::view()
{
    int wish;

    cout << " \n ...........please choose class of car........... " << endl;
    cout << " \n\n\t 1: VIP CAR  \t 2: SIMPLE CAR \t 3: SPORTS CAR " << endl;
    cin >> wish;
    system("cls");
    ifstream fin;
    fin.open("carstock.txt", ios::in | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (!fin.eof())
    {
        switch (wish)
        {
        case 1:
            if (!strcmp("VIP", cl))
            {
                show();
            }

            break;

        case 2:
            fin.read((char *)this, sizeof(*this));
            if (!strcmp("SIMPLE", cl))
            {
                show();
            }

            break;

        case 3:
            fin.read((char *)this, sizeof(*this));
            if (!strcmp("SPORTS", cl))
            {
                show();
            }

            break;
        default:
            cout << " \n\t INVALID CREDENTIAL " << endl;
            break;
        }
        fin.read((char *)this, sizeof(*this));
    }

    fin.close();
}
// code for delete a car
void car::delcar()
{
    char b[10];
    cin.ignore();
    cout << " Enter car Brand name : ";
    gets(b);
    ifstream fin;
    ofstream fout;
    fin.open("carstock.txt", ios::in | ios::binary);
    fout.open("temp.txt", ios::app | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (!fin.eof())
    {
        if (strcmp(b, bn))
            fout.write((char *)this, sizeof(*this));
        fin.read((char *)this, sizeof(*this));
    }
    cout<<"\n\n\t CAR details deleted successfully "<<endl;
    fin.close();
    fout.close();
    remove("carstock.txt");
    rename("temp.txt", "carstock.txt");
}
//code for rent
class customer : public car
{
    char name[20], dl[20], al[20];
    int age, booking_id, car_no;
    float fare, distance;

public:
    void booking();
    void rent();
    void rent_confirmation();
    void store();
    void view_booking();
    void update();

} cust;

void customer::booking()
{

    cin.ignore();
    system("cls");
    system("color 8f");
    cout << " Enter Departure location : ";
    gets(dl);
    cout << " Enter Arrival location : ";
    gets(al);
    srand(time(0));
    distance = rand() % 50; // i want to use location feature instead of this logic

    cout << "\n\tDistance = " << distance << "km" << endl;
}

void customer::rent()
{

    system("color 62");
    cout << "\n\n please choose  Brand of car : " << endl;
    cout << " \n\n 1: BMW   2: MERCEDES   3: HUNDAI   4: AUDI   5: JAGUAR   6: MARUTI SUZUKI   7: TESLA " << endl;
    cin >> wish;
    system("cls");
    switch (wish)
    {
    case 1:
        system("cls");
        booking();
        fare = 700 * distance;
        cout << " \n\tFare = Rs " << fare;
        rent_confirmation();
        break;

    case 2:
        system("cls");
        booking();
        fare = 500 * distance;
        cout << " \n\tFare = Rs " << fare;
        rent_confirmation();
        break;

    case 3:
        booking();
        fare = 20 * distance;
        cout << " \n\tFare = Rs " << fare;
        rent_confirmation();
        break;

    case 4:
        booking();
        fare = 600 * distance;
        cout << " \n\tFare = Rs " << fare;
        rent_confirmation();
        break;

    case 5:
        booking();
        fare = 800 * distance;
        cout << " \n\tFare = Rs " << fare;
        rent_confirmation();
        break;

    case 6:
        booking();
        fare = 35 * distance;
        cout << " \n\tFare = Rs " << fare;
        rent_confirmation();
        break;

    case 7:
        booking();
        fare = 400 * distance;
        cout << " \n\tFare = Rs " << fare;
        rent_confirmation();
        break;

    default:

        break;
    }
}

//rent_confirmation function
void customer::rent_confirmation()

{

    cout << " \n \t please confirm your booking \n\t 1: YES \t 2: NO " << endl;
    cin >> ent;
    system("cls");
    switch (ent)
    {
    case 1:

        cout << " \n\n \t ***********your booking is confirmed********** \n Our Driver will reach to you soon ";
        break;

    case 2:
        cout << "\n\n\t ************Thanks for visitng us**************** ";
        break;
    }
}

// code for store customer information
void customer::store()
{
    srand(time(0));
    booking_id = rand() % 100;
    car_no = rand() % 10000;
    ofstream fout;
    fout.open("cust.txt", ios::app | ios::binary);
    fout.write((char *)this, sizeof(*this));
    fout.close();
}

// code for view booking

void customer::view_booking()
{

    ifstream fin;
    fin.open("cust.txt", ios::in | ios::binary);
    fin.read((char *)this, sizeof(*this));
    cout << " \n*************your bookings****************" << endl;
    while (!fin.eof())
    {

        cout << " \n\n Booking id : " << booking_id << "\n Car no : " << car_no << "\n Travel : from " << dl << " to " << al << " \n Distance : " << distance << " km \n Fare : Rs" << fare << endl;
        fin.read((char *)this, sizeof(*this));
    }
}

// code for stock update

void car::update()
{
    ifstream fin;
    ofstream fout;
    fin.open("carstock.txt", ios::in | ios::binary);
    fout.open("temp.txt", ios::app | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (!fin.eof())
    {
        switch (wish)
        {
        case 1:
            if (strcmp("BMW", bn))

                fout.write((char *)this, sizeof(*this));
            break;

        case 2:
            if (strcmp("MERCEDES", bn))

                fout.write((char *)this, sizeof(*this));
            break;

        case 3:
            if (strcmp("HUNDAI", bn))
                fout.write((char *)this, sizeof(*this));
            break;

        case 4:
            if (strcmp("AUDI", bn))
                fout.write((char *)this, sizeof(*this));
            break;

        case 5:
            if (strcmp("JAGUAR", bn))
                fout.write((char *)this, sizeof(*this));
            break;

        case 6:
            if (strcmp("MARUTI SUZUKI", bn))
                fout.write((char *)this, sizeof(*this));
            break;

        case 7:
            if (strcmp("TESLA", bn))
                fout.write((char *)this, sizeof(*this));
            break;
        }
        fin.read((char *)this, sizeof(*this));
    }

    fin.close();
    fout.close();

    remove("carstock.txt");

    rename("temp.txt", "carstock.txt");
}
// code for functionallity
void allfunction()
{
    int key;
    car c;
    registeration r1;
    char letter;
    cout << " \n\n\t Please choose any option : ";
    cin >> key;
    switch (key)
    {
    case 1:
        system("cls");
        c.view();
        cout << " \n\n press p to go on previous page : ";
        cin >> letter;
        if (letter == 'p')
            prevpage();
        else
            cout << " invalid credential ";
        break;

    case 2:
        system("cls");
        cust.rent();
        cust.store();
        c.update();
        cout << " \n\n press p to go on previous page : ";
        cin >> letter;
        if (letter == 'p')
            prevpage();
        else
            cout << " invalid credential ";
        prevpage();
        break;

    case 3:
        system("cls");
        system("color 10");
        cust.view_booking();
        cout << " \n\n press p to go on previous page : ";
        cin >> letter;
        if (letter == 'p')
            prevpage();
        else
            cout << " invalid credential ";
        prevpage();
        break;

    case 4:
        system("cls");
        system("color 40");
        r1.show();
        break;

    case 5:
        system("cls");

        cout << "\n\n ********Thank you for visiting us ************" << endl;
        break;

    case 11:
        system("cls");
        c.addcar();
        c.store();
        cout << " \n\n press p to go on previous page : ";
        cin >> letter;
        if (letter == 'p')
            prevpage();
        else
            cout << " invalid credential ";

        prevpage();
        break;

    case 12:
        system("cls");
        system("color 20");
        c.delcar();
        cout << " \n\n press p to go on previous page : ";
        cin >> letter;
        if (letter == 'p')
            prevpage();
        else
            cout << " invalid credential ";

        prevpage();
        break;

    case 13:

        system("cls");
        c.view();
        cout << " \n\n press p to go on previous page : ";
        cin >> letter;
        if (letter == 'p')
            prevpage();
        else
            cout << " invalid credential ";
        break;

    case 14:
        system("cls");
        system("color 10");
        cust.view_booking();
        cout << " \n\n press p to go on previous page : ";
        cin >> letter;
        if (letter == 'p')
            prevpage();
        else
            cout << " invalid credential ";
        prevpage();
        break;

    case 15:
      system("cls");
     system("color 10");
     r1.viewcustomers();
        cout << " \n\n press p to go on previous page : ";
        cin >> letter;
        if (letter == 'p')
            prevpage();
        else
            cout << " invalid credential ";
        prevpage();
        break;
    

    case 16:
        system("cls");
        cout << "\n\n ********Thank you for visiting us ************" << endl;
        break;
    }
}

// code for previous page
void prevpage()
{
    system("cls");

    dashboard();
    allfunction();
}

int main()
{
    system("cls");
    function();
    dashboard();

    allfunction();
    return 0;
}