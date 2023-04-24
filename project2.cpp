#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;
void registration();
void login();
void changepassword();
void forgotpassword();

enum IN {
    IN_BACK = 8,
    IN_RET = 13
  
};
  
string takePasswdFromUser(
    char sp = '*')
{
    string passwd = "";
    char ch_ipt;
  
    while (true) {
  
        ch_ipt = getch();
  
        if (ch_ipt == IN::IN_RET) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() != 0) {
            passwd.pop_back();
  
            cout << "\b \b";
  
            continue;
        }
  
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() == 0) {
            continue;
        }
  
        passwd.push_back(ch_ipt);
        cout << sp;
    }
}
void registration()
{

    string age, secnum, username, password, ans;
    cout << "____________________________________" << endl
         << endl;
    cout << "|-------------Register-------------|" << endl;
    cout << "|__________________________________|" << endl
         << endl;
    cout << "Please Enter username:- ";
    cin >> username;
    cout << "Please Enter password:- ";
    //cin >> password;
    password = takePasswdFromUser();
    cout << "Please Enter your age:- ";
    cin >> age;
    cout << endl
         << "Choose a security question" << endl;
    cout << "1.Fav Pet" << endl;
    cout << "2.Fav Food" << endl;
    cout << "3.Fav Language" << endl;
    cin >> secnum;
    cout << "Enter Answer:- ";
    cin >> ans;
    ofstream file;
    file.open(username);
    if (file.is_open())
    {
        file << username << "\n";
        file << password << "\n";
        file << age << "\n";
        file << secnum << "\n";
        file << ans << "\n";
        cout << "Registration Successful";
    }
}
void login()
{
    int i = 0;
    string age, secnum, username, password, text, word, ans, check[5];
    cout << "____________________________________" << endl
         << endl;
    cout << "|--------------Login---------------|" << endl;
    cout << "|__________________________________|" << endl
         << endl;
    ifstream file;
    cout << "Please Enter username:- ";
    cin >> username;
    cout << "Please Enter password:- ";
   // cin >> password;
    password = takePasswdFromUser();
    file.open(username);
    if (file.is_open())
    {
        while (!file.eof())
        {
            while (getline(file, text))
            {
                istringstream iss(text);
                iss >> word;
                check[i] = word;
                i++;
            }
            if (username == check[0] && password == check[1])
            {
                cout << "|---------Login Successfull--------|" << endl
                     << endl;
                cout << " Details: " << endl;
                cout << "Username ->" << username << endl;
                cout << "Password ->" << password << endl;
                cout << "Age ->" << check[2] << endl;
            }
            else
            {
                cout << endl
                     << endl;
                cout << "Incorrect Credentials" << endl;
                cout << "|---------Press 2 to Login---------|" << endl;
                cout << "|-----Press 3 to Change Password---|" << endl;
                cout << "|-----Press 4 to Forgot Password---|" << endl;
            }
        }
    }
    else
    {
        cout << "USERNAME doesn't exist"<<endl;
    }
}
void changepassword()
{
    int i = 0;
    string newpass1, newpass2, username, password, word, text, check[5];
    cout << "____________________________________" << endl
         << endl;
    cout << "|------------Change Password-------|" << endl;
    cout << "|__________________________________|" << endl
         << endl;
    cout << "Please Enter username:- ";
    cin >> username;
    cout << "Please Enter old password:- ";
    //cin >> password;
    password = takePasswdFromUser();
    ifstream file;
    file.open(username);
    if (file.is_open())
    {
        while (!file.eof())
        {
            while (getline(file, text))
            {
                istringstream iss(text);
                iss >> word;
                check[i] = word;
                i++;
            }
            if (password == check[1])
            {
                cout << "Enter New Password:- ";
                //cin >> newpass1;
                newpass1 = takePasswdFromUser();
                cout << "Enter Again:- ";
                //cin >> newpass2;
                newpass2 = takePasswdFromUser();
                if (newpass1 == newpass2)
                {
                    ofstream file;
                    file.open(username);
                    file << check[0] << "\n";
                    file << newpass1 << "\n";
                    file << check[2] << "\n";
                    file << check[3] << "\n";
                    file << check[4] << "\n";
                    cout << "Password Change Successful";
                }
            }
            else
            {
                cout << endl
                     << endl;
                cout << "Incorrect Password" << endl;
                cout << "|---------Press 2 to Login---------|" << endl;
                cout << "|-----Press 3 to Change Password---|" << endl;
                cout << "|-----Press 4 to Forgot Password---|" << endl;
            }
        }
    }
    else
    {
        cout << "USERNAME doesn't exist"<<endl;
    }
}
void forgotpassword()
{
    int i = 0;
    string newpass1, newpass2, username, password, word, text, check[5], ans, secnum;
    cout << "____________________________________" << endl
         << endl;
    cout << "|------------Forgot Password-------|" << endl;
    cout << "|__________________________________|" << endl
         << endl;
    cout << "Please Enter username:- ";
    cin >> username;
    cout << "That was your security question" << endl;
    cout << "1.Fav Pet" << endl;
    cout << "2.Fav Food" << endl;
    cout << "3.Fav Language" << endl;
    cin >> secnum;
    cout << "Enter Answer:- ";
    cin >> ans;
    ifstream file;
    file.open(username);
    if (file.is_open())
    {
        while (!file.eof())
        {
            while (getline(file, text))
            {
                istringstream iss(text);
                iss >> word;
                check[i] = word;
                i++;
            }
            if (secnum == check[3] && ans == check[4])
            {
                cout << "Enter New Password:- ";
                //cin >> newpass1;
                newpass1 = takePasswdFromUser();
                cout << "Enter Again:- ";
                //cin >> newpass2;
                newpass2 = takePasswdFromUser();
                if (newpass1 == newpass2)
                {
                    ofstream file;
                    file.open(username);
                    file << check[0] << "\n";
                    file << newpass1 << "\n";
                    file << check[2] << "\n";
                    file << check[3] << "\n";
                    file << check[4] << "\n";
                    cout << "Password Change Successful";
                }
            }
            else
            {
                cout << endl
                     << endl;
                cout << "Incorrect Answer Or Question" << endl;
                cout << "|---------Press 2 to Login---------|" << endl;
                cout << "|-----Press 3 to Change Password---|" << endl;
                cout << "|-----Press 4 to Forgot Password---|" << endl;
            }
        }
    }
    else
    {
        cout << "File with this USERNAME doesn't exist"<<endl;
    }
}
//secure password



int main()
{
    int a;
    cout << "\t   Security System" << endl;
    cout << "____________________________________" << endl
         << endl;
    cout << "|            1.Register            |" << endl;
    cout << "|            2.Login               |" << endl;
    cout << "|        3.Change Password         |" << endl;
    cout << "|        4.Forgot Password         |" << endl;
    cout << "|__________5.End Program___________|" << endl
         << endl;
    do
    {
        cout << endl
             << endl;
        cout << "Enter Your Choice:- ";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            registration();
            break;
        }
        case 2:
        {
            login();
            break;
        }
        case 3:
        {
            changepassword();
            break;
        }
        case 4:
        {
            forgotpassword();
            break;
        }
        case 5:
        {
            cout << "_____________ThankYou_______________" << endl;
            break;
        }
        default:
            cout << "Enter a valid choice";
        }
    } while (a != 5);
    return 0;
}