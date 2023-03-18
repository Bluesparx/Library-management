#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include<string.h>

using namespace std;

char authorN[50], bookN[50];
char user[50];
char pass[50];


class Login
{
public:
    int initial();
    int login();
    void regis();
    void exit(){
        exit();
    }
};

int Login::initial(){
    initi:
        system("cls");
        string init;
        cout << "\n\n\t\t\t* * * * * * * * * * * * * * * * *\n";
        cout << "\n\t\t\t|  LIBRARY  MANAGEMENT  SYSTEM  |\n";
        cout << "\n\t\t\t* * * * * * * * * * * * * * * * *\n";
        cout << "\n\n\t\t\tDo you have an account? \n\t\t\tyes or no: ";
        cin >> init;
        if (init == "yes"){
            return 1;
        }
        else if (init =="no"){
            return 0;
        }
    else
    goto initi;
}

int Login::login(){
    checkin:
    system("cls");
        string usr;
        string pss;
        cout << "\n\t\t* * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "\n\t\t\tEnter username: ";
        cin >> usr;
        cout << "\n\t\t\tEnter password: ";
        cin >> pss;
        fstream check("regis.txt");
        bool checkb;
        while (check >> user >> pass)
        {
            if (usr == user && pss == pass)
            {
                if (usr == "admin")
                {
                    checkb = true;
                    return 1;
                    break;
                }
                else{
                checkb = true;
                return 0;
                break;
                }
            }
        }
        checkb=false;
        if (checkb = false)
        {
            return -1;
        }
    }

void Login::regis(){
    system("cls");
        cout<<"\t\t\tNEW USER REGISTRATION   \n";
        cout << "\n\t\t* * * * * * * * * * * * * * * * * * * * * \n";
        cout << "\t\t\tEnter new username: ";
        cin >> user;
        cout << "\t\t\tEnter new password: ";
        cin >> pass;
        fstream users;
        users.open("regis.txt", ios::app);
        users<<user<<"\t"<<pass<<"\n";
}

class database{
public:
    void addBook();
    void delBook();
    void displayBooks();
    void issuedBooks();
};

void database::addBook(){
    fstream db;
    system("cls");
    cout<<"\n\t\t* * * * * * * * * * * * * * * * * * * * * * * * \n";
    cout << "\n\t\t\tEnter name of book: ";
    cin>>bookN;
    cout << "\n\t\t\tEnter name of author: ";
    cin>>authorN;
    db.open("book.txt", ios::app);
    db << bookN <<"  "<< authorN<<"\n";
    cout << "\n\t\t   * * * * New book added successfully! * * * *\n\n\t\t";
    system("pause");
    db.close();
}

void database::delBook(){
    system("cls");
    ifstream file("book.txt");
    ofstream file1("temp.txt");
    int count = 0;
    string bname1;
    bool found = false;
    cout << "\n\t\t* * * * * * * * * * * * * * * * * * * * * * * * * \n";
    cout << "\n\n\t\t\tEnter name of book to delete: ";
    cin >> bname1;
    while (file >> bookN >> authorN){
        if (bname1 == bookN){
            count++;
            found = true;
        }
        else{
            file1 << bookN << " " << authorN << endl;
        }
    }
    if (!found){
        cout << "\n\n\t\tBook Not Found...";
    }
    else if (count > 0){
        cout << "\n\n\t\t  * * * * Book Deleted Successfully * * * *\n\n";
    }
    file.close();
    file1.close();
    remove("book.txt");
    rename("temp.txt","book.txt");
    system("pause");
}

void database::displayBooks(){
    fstream books;
    books.open("book.txt", ios::in);
    system("cls");
    cout<<"\n\n\t\t\tLIST OF ALL BOOKS";
    cout<<"\n\t--------------------------------------------------------------";
    cout<<"\n\t\tNAME \t\t\t AUTHOR";
    cout<<"\n\t--------------------------------------------------------------\n";
    if(!books){
        cout<<"\n\tNo book data available.";
        system("pause");
        books.close();
    }
    else{
        while(books>>bookN>>authorN){
        cout<<"\t\t"<<bookN<<"\t\t\t"<<authorN<<"\n";
        };
        cout<<"\n\t\t";
        system("pause");
        books.close();
    }
}

void database::issuedBooks(){
    system("cls");
    cout<<"\n\n\t\t\tLIST OF ISSUED BOOKS\n";
    cout<<"\n\t------------------------------------------------------------------------";
    cout<<"\n\t\tSTUDENT\t\tBOOK \t\t DATE OF ISSUE";
    cout<<"\n\t------------------------------------------------------------------------\n";
    fstream issu;
    issu.open("issues.txt", ios::in);
    if(!issu){
        cout<<"\n\tNo book data available.";
        system("pause");
        issu.close();
    }
    else{
        string line;
        while(getline(issu, line)){
        cout<<"\n" << line;
        }
        cout<<"\n\n\t\t";
        issu.close();
        system("pause");
    }
}

class Student
{
public:
    int add();
    int edit();
    void record();
    void mydet();
};

int Student::add(){
    string abook;
    time_t now=time(0);
    char* date = ctime(&now);
    char stud[50];

    system("cls");
    cout << "\n\n\n\t\t\t* * * * * * * * * * * * * * * * * *\n";
    cout << "\t\t\tEnter name of book you want: ";
    cin>>abook;
    bool found = false;
    fstream myfile("book.txt");
    while (myfile>>bookN>>authorN)
    {
        if (abook == bookN){
            cout << "\n\n\t\t\t\tBOOK DETAILS\n";
            cout << "\n\t\t\t* * * * * * * * * * * * * * * * * *\n";
            cout << "\t\t\t| Book name: " << bookN << "\n\t\t\t| Author name: " << authorN;
            found = true;
            cout<<"\n\t\t\t| Date and time of issue: "<<date<<"\n\n\t\t";
            strcpy(stud,user);
            fstream records;
            fstream issues;
            records.open("records.txt", ios::out|ios::app);
            issues.open("issues.txt", ios::out|ios::app);
            // date1= date;
            records<<"\t\t"<<abook<<"\t\t\t"<<date;
            issues<<"\t\t"<<stud<<"\t\t"<<abook<<"\t\t"<<date;
            records.close();
            issues.close();
            system("pause");
            return 1;
            break;
        }
    }

    if (found == false){
        cout << "\n\n\t\t\tTHIS BOOK IS NOT AVAILABLE.\n\n\t\t";
        system("pause");
        return 0;
    }
}

int Student::edit(){
    system("cls");
    string temp;
    int choice;
    ifstream rec("records.txt");
    ifstream issu("issues.txt");
    ofstream file1("temp.txt");
    ofstream file2("temp2.txt");
    int count = 0;
    bool found = false;
    cout << "\n\t\t * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "\n\n\t\t\tEnter name of book to return: ";
    cin >> temp;
    string recc, a, b, c, d, e, f;
    while (rec>>recc>>a>>b>>c>>d>>e){
        if (temp == recc){
            found = true;
        }
        else{
            file1 <<recc<< " " <<a<<"\t"<<b<<" "<<c<<" "<<d<<" "<<e<< endl;
        }
    }
    rec.close();
    file1.close();
    while (issu>>recc>>a>>b>>c>>d>>e>>f){
        if (temp == recc){
            count++;
        }
        else{
            file2 <<recc<< "\t" <<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<< endl;
        }
    }
    issu.close();
    file2.close();
    time_t now=time(0);
    char* date = ctime(&now);
    remove("records.txt");
    remove("temp2.txt");
    rename("temp.txt","records.txt");
    rename("temp2.txt","issues.txt");
    if (!found){
        cout << "\n\n\t\t\tYou have not issued this book...\n\n\t\t\t";
        system("pause");
    }
    else{
        cout << "\n\n\t\t\t\tBOOK DETAILS";
        cout << "\n\t\t\t----------------------------------------\n";
        cout << "\t\t\t| Book name: " << bookN<< "\n\t\t\t| Author name: " << authorN;
        found = true;
        cout<<"\n\t\t\t| Date and time of return: "<<date<<"\n\n\t\t";
        cout << "\t--------Book Returned Successfully--------\n\n";
        cout << "\n\t\t\tDo you want to issue new book? 1(yes) or 0(no). ";
        cin >> choice;
        if (choice == 1){
            return 1;
        }
        else
            return 0;
    }
}

void Student::record(){
    cout<<"\n\t\tBOOK NAME\t\t\tDATE AND TIME OF ISSUE";
    cout<<"\n-----------------------------------------------------------------------------------\n";
    fstream recordss;
    recordss.open("records.txt", ios::in);
    string line, a, b, c, d, e, f;
    while(recordss>>line>>a>>b>>c>>d>>e){
        cout <<"\t\t"<<line<< "\t\t\t" <<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<< endl;
    };
    cout<<"\n\t\t";
    recordss.close();
    system("pause");
}

void Student::mydet(){
  system("cls");
  cout<<"\n\t\t\t\tUSER DETAILS"<<endl;
  cout<<"\t\t\t  ----------------------"<<endl;
  cout<<"\t\t\t  | Username:"<<setw(10)<<user<<" |"<<endl;
  cout<<"\t\t\t  | Password:"<<setw(10)<<pass<<" |"<<endl;
  cout<<"\t\t\t  ----------------------"<<"\n\n";
  cout<<"\t\t\t";
  system("pause");
}

int main()
{
    Login student;
    database db;
    initi:
    if (student.initial())
    {
        int login_value=student.login();
        if (login_value== 0)
        {
            cout << "You are logged in.\n";
            contents:
            Student stu;
            int input;
        system("cls");
            cout << "\n\t\t\t* * * * * * * * * * * * * * * *\n";
            cout << "\t\t1. Issue a book. \n\t\t2. Return a book.\n\t\t3. See list of previously issued books.\n\t\t4. Check my details.\n\t\t5. Log Out.";
            cout << "\n\n\t\tPlease enter a number from the given options: ";
            cin >> input;

            switch (input)
            {
            case 1:
                stu.add();
                break;
            case 2:{
                int returnn= stu.edit();
                if (returnn==1){
                    stu.add();
                }
                break;
            }
            case 3:
                stu.record();
                break;
            case 4:
                stu.mydet();
                break;
            case 5:
                goto initi;
                break;
            default:
                cout << "\nEnter a valid number! ";
                system("pause");
                break;
            }
            goto contents;
        }
        else if(login_value==1)
        {
            int choicea;
            adminCon:
            system("cls");
            cout << "\n\n\t\t\t--------Logged in as admin--------\n";
            cout << "\n\t\t\t1. Add a book. \n\t\t\t2. Delete a book. \n\t\t\t3. See list of all books.\n\t\t\t4. See list of all issued books.\n\t\t\t5. Logout.";
            cout<<"\n\t\t\t6. TERMINATE.";
            cout<<"\n\n\t\t\tEnter a number : ";
            cin>>choicea;
            switch(choicea){
            case 1:
                db.addBook();
                break;
            case 2:
                db.delBook();
                break;
            case 3:
                db.displayBooks();
                break;
            case 4:
                db.issuedBooks();
                break;
            case 5:
            system("cls");
            goto initi;
            case 6:
                exit(0);
                break;
            }
            goto adminCon;
        }
        else{
        cout<<"\n\t\t|  User credentials do not match or exist  |\n\t\t\n\t\t|  ";
        system("pause");
        goto initi;
        }
    }
    else
    {
        student.regis();
        cout << "\n\n\t\t\tYou can now login :)\n";
        cout<<"\n\t\t* * * * * * * * * * * * * * * * * * * * * \n\n\t\t";
        system("pause");
        goto initi;
    }
    return 0;
}

