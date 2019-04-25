#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<fstream>
#include<cstdlib>
//#include"GUI.h"

using namespace std;

int input,Iseat;
char name[20] = "77";
char xname[20] = "77";
char password[20];
bool pass = false;
bool run = true;
bool seat[8][9] = {0};
int popS = 0;
int popM = 0;
int popL = 0;
int colaS = 0;
int colaM = 0;
int colaL = 0;
int cost = 0;
char format[] = "%s %s %d %d %d %d %d %d %d %d";

void asset();
void GUI(int);
void Show();
int MainMenu();
void refresh();
void login();
void ChooseSeat();
void change();
void check();

int main(){
    while(run){
        input = MainMenu();
        GUI(input);
    }
}

void ChooseSeat(){
    Show();
    int tempseat;        
    int j,i;
    bool ava;
    int count = 0;
    do{
        if(count>0) cout << "Please try again.\n";
        cout << "Choose your seat: ";
        cin >> tempseat;
        j = tempseat%10;
        i = tempseat/10;
        if(seat[i][j]){
            cout << "This seat not avalible...";
            ava = false;
        }
        else ava = true;
        count++;
    }
    while(i<0||i>7||j<0||j>8||!ava);
    seat[i][j] = true;
    if(Iseat==99) cost += 100;
    Iseat = tempseat;
    change();
}

void login(){

    string a,b;
    int seat;

    cout << "          -----------------------------------------------------------------        " << endl ;
    cout <<"FirstName: ";
    cin >> a;
    cout <<"PassWord: ";
    cin >> b;    
    
    ifstream source("member.txt");
    string line;    

	while(getline(source,line)){
        const char *tt = line.c_str();
        const char *A = a.c_str();
        const char *B = b.c_str();
        sscanf(tt,format,&name,&password,&Iseat,&popS,&popM,&popL,&colaS,&colaM,&colaL,&cost);
        if(*name == *A && *password == *B){
            pass = true;
            break;
        }
	}
    if(!pass){
        cout << "\nID or Password was worng... Return to main menu...\n";
    }
    else{
        const char *A = a.c_str();
        *name = *A;
        const char *B = b.c_str();
        *password = *B;
        ChooseSeat();
    }
}

void GUI(int x){
    if(input==0){
        check();
    }
    else if(input==1){
        login();
    }
    else if(x == 2){                            // Register
        string ID_Register,Password_Register,Name;
        char ag;
        do{
            cout << "You FirstName: ";
            cin >> Name;
            cout << "Your Password: ";
            cin >> Password_Register;
            cout << "\nFirstName: " << Name << "\nPassword: " << Password_Register << "\nDo you want to fill again? (y/n): ";
            cin >> ag;
            while(ag!='y'&&ag!='n'){
                cout << "\nDo you want to fill again? (y/n): ";
                cin >> ag;
            }
        }
        while(ag=='y');

        ofstream dest("member.txt",ios::app);
        dest << "\n" << Name << " " << Password_Register << " 99 0 0 0 0 0 0 0";
	    dest.close();
    }
    else if(x == 3){
        asset();
    }
    else if(x == 4){                    // Exit
        change();
        cout << "Thank_You!!";
        run = false;
    }
}

int MainMenu(){
        cout << "             -----------------------------------------------------------------        " << endl ;
        cout << "                           ---------------------------------------                    " << endl ;
        cout << "                                    Welcome To Cinema                                 " << endl ;
        cout << "                           ---------------------------------------                    " << endl ;
        cout << "             -----------------------------------------------------------------        " << endl ;
        if(*name != *xname){
            cout << "                     Log in as " << name << " -> Spend " << cost << "                " << endl ;
            cout << "             Check[0]     Login[1]     Register[2]     Food&Drnk[3]     Exit[4]          " << endl ;
        }
        else cout << "                Login[1]        Register[2]       Food&Drnk[3]       Exit[4]          " << endl ;
        cout << "Select : " ;
        int x;
        cin >> x;
        if(x<0||x>4) x = MainMenu();
        return x;
}

void Show(){
    refresh();
    cout << "\n========================= SCREEN =========================\n";
    for(int i=0;i<8;i++){
        cout << "            ";
        for(int j=0;j<9;j++){
            if(seat[i][j]){
                cout << "++  ";
            }
            else{
                cout << i << j << "  ";
            }
                
        }
        cout << "\n";
    }
    cout << "****** 100 THB / Person ******\n";
}

void refresh(){
    for(int i=0;i<8;i++){
        for(int j=0;j<9;j++){
            seat[i][j] = false;                        
        }
    }
    ifstream source("member.txt");
    string line;
    char a[20];
    char b[20];
    int s;
	while(getline(source,line)){
        const char *tt = line.c_str();
        sscanf(tt,format,&a,&b,&s,&popS,&popM,&popL,&colaS,&colaM,&colaL,&cost);
        int j,i;
        j = s%10;
        i = s/10;
        seat[i][j] = true;
	}
}

void change(){
    //step 1  make temp
    ifstream source("member.txt");
    ofstream dest("temp.txt");
    string line;
	while(getline(source,line)){        
        dest << line << "\n";
	}
    dest.close();

    //step 2
    ifstream so("temp.txt");
    ofstream d("member.txt");
    char a[20];
    char b[20];
    int s, c, f[6];
	while(getline(so,line)){
        const char *tt = line.c_str();
        sscanf(tt,format,&a,&b,&s,&f[0],&f[1],&f[2],&f[3],&f[4],&f[5],&c);
        if(*name == *a && *password == *b){
            d << name << " " << password << " " << Iseat << " " << popS << " " << popM << " " << popL << " " << colaS << " " << colaM << " " << colaL << " " << cost << "\n";
        }
        else{
            d << line << "\n";
        }        
	}
    d.close();

    cout << "Saved Success!!\n";
}

void asset(){
    int type = 1;
    do{
        if(type<1||type>3) cout << "    Please try again...\n";
        cout << "    -----------------------------------------------------------------        " << endl ;
        cout << "    [1]Promption [2]Food [3]Drink\n";
        cout << "    -----------------------------------------------------------------        " << endl ;        
        cin >> type;
    }
    while(type<1||type>3);
    if(type==1){
        int menu = 1;
        do{
            if(menu<1||menu>5) cout << "    Please try again...\n";
            cout << "    -----------------------------------------------------------------        " << endl ;
            cout << "    [1][A] Popcorn size S + Cola size S [ 90 ? ] \n";
            cout << "    [2][B] Popcorn size M + Cola size M [ 120 ? ] \n";
            cout << "    [3][C] Popcorn size L + Cola size S(x2) [ 220 ? ] \n"; 
            cout << "    [4][COUPLE] Popcorn size M(x2) + Cola size S(x2) [ 200 ? ] \n";
            cout << "    [5][COMBO] Popcorn size M(x3) + Cola size M(x3) [ 350 ? ] \n";
            cout << "    -----------------------------------------------------------------        " << endl ;
            cin >> menu;
        }
        while(menu<1||menu>5);
        switch (menu)
        {
            case 1:
                cost += 90;
                popS++;
                colaS++;
                break;
            case 2:
                cost += 120;
                popM++;
                colaM++;
                break;
            case 3:
                cost += 220;
                popL++;
                colaS += 2;
                break;
            case 4:
                cost += 200;
                popM += 2;
                colaS += 2;
                break;
            case 5:
                cost += 350;
                popM += 3;
                colaM += 3;
                break;
        }
    }
    else if(type==2){
        int menu = 1;
        do{
            if(menu<1||menu>3) cout << "    Please try again...\n";
            cout << "    -----------------------------------------------------------------        " << endl ;
            cout << "    [1] Popcorn size S [ 60 ? ] \n";
            cout << "    [2] Popcorn size M [ 80 ? ] \n";
            cout << "    [3] Popcorn size L [ 100 ? ] \n";
            cout << "    -----------------------------------------------------------------        " << endl ;
            cin >> menu;
        }
        while(menu<1||menu>3);
        switch (menu)
        {
            case 1:
                cost += 60;
                popS++;
                break;
            case 2:
                cost += 80;
                popM++;
                break;
            case 3:
                cost += 100;
                popL++;
                break;
        }
    }
    else if(type==3){
        int menu = 1;
        do{
            if(menu<1||menu>3) cout << "    Please try again...\n";
            cout << "    -----------------------------------------------------------------        " << endl ;
            cout << "    [1] Cola size S [ 30 ? ] \n";
            cout << "    [2] Cola size M [ 50 ? ] \n";
            cout << "    [3] Cola size L [ 70 ? ] \n";
            cout << "    -----------------------------------------------------------------        " << endl ;
            cin >> menu;
        }
        while(menu<1||menu>3);
        switch (menu)
        {
            case 1:
                cost += 30;
                colaS++;
                break;
            case 2:
                cost += 50;
                colaM++;
                break;
            case 3:
                cost += 70;
                colaL++;
                break;
        }
    }
}

void check(){
    cout << "    -----------------------------------------------------------------        " << endl ;
    cout << "    Name: " << name << "\n" << "    Seat: " << Iseat << "\n";
    if(popS>0) cout << "    Popcorn S: " << popS << "\n";
    if(popM>0) cout << "    Popcorn M: " << popM << "\n";
    if(popL>0) cout << "    Popcorn L: " << popL << "\n";
    if(colaS>0) cout << "    Cola S: " << colaS << "\n";
    if(colaM>0) cout << "    Cola M: " << colaM << "\n";
    if(colaL>0) cout << "    Cola L: " << colaL << "\n";
    cout << "    Cost: " << cost << "\n";
    cout << "    -----------------------------------------------------------------        " << endl ;
}
