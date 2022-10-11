#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

int admin_view();
int student_view();
int student_login();
int check_credentials(string username, string password);
int get_all_students_by_rollno();
int delete_all_students();
int delete_student_by_rollno();
int check_list_of_students_registered();
int check_list_of_all_students_registered();
int check_presence_count_by_rollno();
int get_list_of_students_with_their_presence_count();
int register_student();
int admin_login();
int register_student();
int mark_my_attendance(string username);
int count_my_attendance(string username);
int delay();

int delay()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<20000;j++)
        {
            for(int k=0;k<20000;k++)
            {

            }
        }
    }
    cout<<"\n Exiting Now.....";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<20000;j++)
        {
            for(int k=0;k<20000;k++)
            {

            }
        }

    }
    return 0;
}

int admin_view()
{
    int goBack = 0;
    while(1)
    {
        system("cls");
        cout<<"\n 1 Register a student";
        cout<<"\n 2 Delete all student name registered";
        cout<<"\n 3 Delete student by roll number";
        cout<<"\n 4 Check list of student registered by username";
        cout<<"\n 5 Check presence count of any student by roll no";
        cout<<"\n 6 Get list of student with their attendance count";
        cout<<"\n 0 Go Back <-\n";
        int choice;
        cout<<"\n Enter your choice: ";
        cin>>choice;

        cout<<"\n Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            register_student();
            break;
        case 2:
            delete_all_students();
            break;
        case 3:
            delete_student_by_rollno();
            break;
        case 4:
            check_list_of_all_students_registered();
            break;
        case 5:
            check_presence_count_by_rollno();
            break;
        case 6:
            get_list_of_students_with_their_presence_count();
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout<<"\n Invalid choice. Enter again";
            getchar();
        }
        if(goBack==1)
        {
            break;
        }
    }
    return 0;
}

int student_login()
{
    system("cls");
    cout<<"\n----------- Student Login ---------------";
    student_view();
    delay();
    return 0;
}

int admin_login()
{
    system("cls");
    cout<<"\n------------ Admin Login -------------";
    string username, password;
    cout<<"\n Enter username: ";
    cin>>username;
    cout<<"\n Enter password: ";
    cin>>password;

    if(username=="admin" && password == "admin@2")
    {
        admin_view();
        getchar();
        delay();
    }
    else
    {
        cout<<"\n Error! Invalid Credentials....";
        cout<<"\n Press any key for main menu ";
        getchar();
        getchar();
    }
    return 0;
}

int check_students_credentials(string username, string password)
{
    ifstream read;
    read.open("db.dat");
    if(read)
    {
        int recordFound=0;
        string line;
        string temp = username + password + ".dat";
        cout<<"\n file name is: "<<temp;
        while(getline(read, line))
        {
            if(line==temp)
            {
                recordFound = 1;
                break;
            }
        }
        if(recordFound==0)
            return 0;
        else
            return 1;
    }
    else
    {
        return 0;
    }
}

int get_all_students_by_name()
{
    cout<<"\n list of all students by their name\n";
    cout<<"\n Please press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int get_all_students_by_rollno()
{
    cout<<"\n List of all students by their roll no\n";
    cout<<"\n Please press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int delete_student_by_rollno()
{
    cout<<"\n Delete any student by their roll no \n";
    cout<<"\n Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int check_presence_count_by_rollno()
{
    cout<<"\n Check presence count of any student by roll no\n";
    cout<<"\n Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int check_all_presence_count_by_rollno()
{
    cout<<"\n Check presence count of all student by roll no\n";
    cout<<"\n Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int student_view()
{
    cout<<"-----------Student Login---------";
    string username, password;
    cout<<"\n Enter username: ";
    cin>>username;
    cout<<"\n Enter password: ";
    cin>>password;

    int res = check_students_credentials(username, password);
    if(res == 0)
    {
        cout<<"\n Invalid credentials!!";
        cout<<"\n Press any key for main menu...";
        getchar();
        getchar();
        return 0;
    }
    int goBack=0;
    while(1)
    {
        system("cls");
        cout<<"\n 1 Marks Attendance for today";
        cout<<"\n 2 Count My Attendance";
        cout<<"\n 0. Go Back <-\n";
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            mark_my_attendance(username);
            break;
        case 2:
            count_my_attendance(username);
            break;
        case 0:
            goBack=1;
            break;
        default:
            cout<<"\n Invalid choice.. Enter again";
            getchar();
        }
        if(goBack==1)
        {
            break;
        }
    }
}

int mark_my_attendance(string username)
{
    cout<<"\n Mark attendance for today";
    cout<<"\n Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int count_my_attendance(string username)
{
    cout<<"\n Count my attendance for today";
    cout<<"\n Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int delete_all_students()
{
    cout<<"\n In delete all students!!";
    cout<<"\n Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int check_list_of_all_students_registered()
{
    cout<<"\n List of all students registered!! ";
    cout<<"\n Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int get_list_of_students_with_their_presence_count()
{
    cout<<"\n Check list of student registered by username";
    ifstream read;
    read.open("db.dat");

    if(read)
    {
        int recordFound = 0;
        string line;
        while(getline(read, line))
        {
            char name[100];
            strcpy(name, line.c_str());
            char onlyname[100];
            strncpy(onlyname, name, (strlen(name)-4));
            cout<<"\n"<<onlyname;
        }
        read.close();
    }
    else
    {
        cout<<"\n No Record Found!!";
    }
    cout<<"\n Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int register_student()
{
    cout<<"\n -----------Form to Register Student-------------";
    string name, username, password, rollno, address, father, mother;
    cout<<"\n Enter Name: ";
    cin>>name;
    cout<<"\n Enter Username: ";
    cin>>username;
    cout<<"\n Enter password: ";
    cin>>password;
    cout<<"\n Enter rollno: ";
    cin>>rollno;
    getchar();
    char add[100];
    cout<<"\n Enter Address: ";
    cin.getline(add,100);
    cout<<"\n Enter Father's name: ";
    cin>>father;
    cout<<"\n Enter Mother's name: ";
    cin>>mother;

    ifstream read;
    read.open("db.dat");
    if(read)
    {
        int recordFound=0;
        string line;
        while(getline(read,line))
        {
            if(line==username+".dat")
            {
                recordFound==1;
                break;
            }
        }
        if(recordFound==1)
        {
            cout<<"\n Username already registered. Please choose another username";
            getchar();
            getchar();
            delay();
            read.close();
            return 0;
        }
    }
    read.close();
    ofstream out;
    out.open("db.dat",ios::app);
    out<<username+".dat"<<"\n";
    out.close();

    ofstream out1;
    string temp = username+".dat";
    out1.open(temp.c_str());
    out1<<name<<"\n"; out1<<username<<"\n"; out1<<password<<"\n";
    out1<<rollno<<"\n"; out1<<add<<"\n"; out1<<father<<"\n";
    out1<<mother<<"\n";
    out1.close();

    cout<<"\n Student Registered successfully!!";
    cout<<"\n Press any key to continue..";
    getchar();
    getchar();
    return 0;
}
int main(int argc, char** argv)
{
    while(1)
    {
        system("cls");
        cout<<"\n Attendance Management System \n";
        cout<<"--------------------------------------\n";
        cout<<"1.Student Login\n";
        cout<<"2. Admin Login\n";
        cout<<"0. Exit\n";
        int choice;
        cout<<"\n Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            student_login();
            break;
        case 2:
            admin_login();
            break;
        case 0:
            while(1)
            {
                system("cls");
                cout<<"\n Are you sure, you want to exit? (Y/N): ";
                char ex;
                cin>>ex;
                if(ex=='y'||ex=='Y')
                {
                    exit(0);
                }
                else if(ex=='n'||ex=='N')
                {
                    break;
                }
                else
                {
                    cout<<"\n Invalid choice!!!";
                    getchar();
                }
            }
            break;

        default:
            cout<<"\n Invalid choice. Enter again";
            getchar();
        }
    }
    return 0;
}
