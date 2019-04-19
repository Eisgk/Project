#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include<stdio.h>
using namespace std;


void mainmenu();
int choice; 
bool cinfail; 
int confirmation; 
string username, password, password2;

void writetofile(string username){
    ofstream writefile;
    string file = "test.txt";
    writefile.open(file.c_str());
    writefile << username << "  ";
    writefile << password << '\n'; 
    writefile.close();
    mainmenu();
    
 }

void login(){
    cout << "============= LOGIN =============" << endl ;
    cout << "Please enter your username: " << endl;
    getline(cin, username);
    cout << "Please enter your password: " << endl;
    getline(cin,password);
    cout << "You are being logged in!";

}

void registerpassword(){
    cout << "Please enter the password:" << endl;
    cin >> password;
    cout << "Please renter your password:" << endl;
    cin >> password2;
    if (password == password2){
        cin.clear();
        cin.ignore(10000,'\n');
        writetofile(username);
        exit(1);
    }
    else;{
        cout << "Sorry invalid" << endl;
        registerpassword();
    }

}

void registerme(){
    cout << "Please enter your username: " << endl;
    getline(cin, username);
    cout << "\nUsername -  \""<< username << "\"\nConfirm? \n\n[1] Yes\n[2] No" << endl;
    cin >> confirmation;
    if (confirmation == 1){
        registerpassword();
    }

    else; {
        cout << "Sorry invalid input, Please try again" << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        registerme();
    }

}

void money(){
    double amount=0;
    double add=0;
    cout << "\nChoose your choice\n[1] Check your balance\n[2] Add your balance\n[3] Exit" << '\n';
    cout << "Your choice : ";
    cin >> choice;
    if (choice==1)
        {
            cout <<"\nYour current balance is: " << amount;
        }
        else if (choice==2)
        {
            cout << "\nEnter the amount you want to deposit: ";
            cin >> add;
            
            amount=amount+add;
            
            cout << "\nYour current balance is: " << amount;
        }
        
        else if (choice==3)
        {
            cout << "\n----- THANK YOU -----";
        }
    
    else if (choice==0)
    {
        cout  << "\nPlease try again.";
    }
    
    money();
}

void checkSeat(){

}

void exit(){
    exit(0);
}

void mainmenu(){ 
    cout << "Would you like to log in or not ?\n\n[1] Login.\n[2] Register.\n[3] Balance.\n[4] Check Seat.\n[5] Exit." <<endl; 
    cout << "Your choice : " ;
    cin >> choice; 
    do{
    cinfail = cin.fail();
    cin.clear();
    cin.ignore(10000,'\n');

    }
    while(cinfail == true);{

        switch(choice){
            case 1:
                login();
                break;

            case 2:
                registerme();
                break;
            case 3:
                money();
                break;
            case 4:
                checkSeat();
            case 5:
                exit();
        }
    }

} 

int main(){ 
    mainmenu(); 
}
