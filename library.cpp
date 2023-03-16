#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <ctime>
#include <fstream>

using namespace std;


string authorN, bookN;
int ids;

class Login
{
private:
    char user[20];
    char pass[20];

public:
    int check()
    {
    checkin:
        string usr;
        string pss;
        cout << "\n* * * * * * * * * * * * * *" << endl;
        cout << "Enter username: ";
        cin >> usr;
        cout << "Enter password: ";
        cin >> pss;
        ifstream check("regis.txt");
        bool checkb = false;
        while (check >> user >> pass)
        {
            if (usr == user && pss == pass)
            {
                if (usr == "admin")
                {
                    return 1;
                }
                else
                    return 0;
                checkb = true;
                break;
            }
        }
        if (checkb = false)
        {
            cout << "\nUser credentials do not match or exist.\n";
            goto checkin;
        }
    }
    void regis()
    {
        cout << "\n* * * * * * * * * * * * * *\n"
             << endl;
        cout << "Enter new username ";
        cin >> user;
        cout << "\nEnter new password: ";
        cin >> pass;
        ofstream users("regis.txt");
        users << user << "  " << pass << "\n";
    }
    void exit()
    {
        exit();
    }
    int initial()
    {
    initi:
        string init, yes, no;
        yes = "yes";
        no = "no";
        cout << "\n* * * * * * * * * * * * * *\n";
        cout << "\nDo you have an account? yes or no. ";
        cin >> init;
        if (init == yes)
        {
            return 1;
        }
        else if (init == no)
        {
            return 0;
        }
        else
            goto initi;
    }
};

void addBook()
{
    ofstream db("stu.txt", ios::app);
    system("cls");
    cout << "\n\t\tEnter name of book: ";
    getline(cin, bookN);
    cout << "\n\t\tEnter name of author: ";
    getline(cin, authorN);
    db.is_open();
    db << bookN << "\t" << authorN;
    system("cls");
    cout << "\n\t\t\t* New book added successfully! *";
    db.close();
}
void delBook();

class Student
{
    string stu_name;
    int stu_id;
    string book;

public:
    void add()
    {
        string abook;
        system("cls");
        cout << "\n\n* * * * * * * * * * * * * * *\n";
        cout << "\t\tEnter name of book you want: ";
        getline(cin, abook);
        this->book = abook;
        addB.is_open();
        bool found = false;
        ifstream myfile("db.txt");
        while (myfile >> bookN >> authorN)
        {
            if (abook == bookN)
            {
                system("cls");
                cout << "\n\t\t\t\tBOOK DETAILS\n\n";
                cout << "Book name: " << bookN << "\nAuthor name: " << authorN;
                found = true;
                break;
            }
        }
        if (found == false)
        {
            cout << "\n\t\t\tTHIS BOOK IS NOT AVAILABLE.";
        }
    }

    int edit()
    {
        string temp;
        int choice;
        cout << "\n\n* * * * * * * * * * * * * * *\n";
        cout << "Enter ID ";
        cin >> stu_id;
        cout << "\nReturn book: ";
        getline(cin, temp);
        cout << "\nDo you want to issue new book? 1(yes) or 0(no). ";
        cin >> choice;
        if (choice == 1)
        {
            return 1;
        }
        else
            return 0;
    }
    void details();
};

int main()
{
    Login student;
    Login admin;
initi:
    if (student.initial())
    {
        if (student.check() == 0)
        {
            cout << "You are logged in.\n";
            Student stu;
            int input;
        contents:
            cout << "\n* * * * * * * * * * * * * * * *\n";
            cout << "\t1. Issue a new book. \n\t2. Return a book.\n\t3. See list of issued books.\n\t4. Check details.\n\t5. Exit.";
            cout << "\n\nPlease enter a number from the given options: ";
            cin >> input;

            switch (input)
            {
            case 1:
                stu.add();
                break;
            case 2:
                stu.edit();
                break;
            // case 3:
            //     stu.see_all();
            //     break;
            // case 4:
            //     stu.details();
            //     break;
            case 5:
                exit(0);
            default:
                cout << "\nEnter a valid number!";
            }
            goto contents;
        }
        else if (student.check() == 1)
        {
            system("cls");
            cout << "\n\n\t\t\t--------Logged in as admin--------\n";
            cout << "\n\t1. Add a book. \n\t2. Delete a book. \n\t3. See list of all books.\n\t4. See list of issued books";
        }
    }
    else
    {
        student.regis();
        cout << "\nYou can now login :)\n";
        goto initi;
    }

    return 0;
}
