#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

        int Choose;
        string ID  ,Password ;
        string ID_Register = "123",Password_Register = "123";
        double Money;
        string Name = "__A__";
        bool Open_Programe = true;


void GUI(int X);
void Menu_Account(int Y);
void Choose_Menu_Account(int Ch_MN_AC);
void Choose_Theatre(int Ch_Th);
void Totol(int T_O);

int main(){
    int x = 0;
    bool Open_Programe = true;
        GUI(x);
        while(Open_Programe != false){
            cin >> x;
            GUI(x);
            }
            return 0;
        }
        

void GUI(int x){
        int Choose;
        double Money;
        string ID,Password ;
        string ID_Register ="123" ,Password_Register ="123" ;
        string Name = "__A__";
        if(x == 0){
        cout << "             -----------------------------------------------------------------        " << endl ;
        cout << "                           ---------------------------------------                    " << endl ;
        cout << "                                    Welcome To Cinima                                 " << endl ;
        cout << "                           ---------------------------------------                    " << endl ;
        cout << "             -----------------------------------------------------------------        " << endl ;
        cout << "                Login[1]        Register[2]           Guest[3]         Exit[4]        " << endl ;
        cout << "You Select : " ;
        }else if(x == 1){                   
                    do{
                        cout << "             -----------------------------------------------------------------        " << endl ;
                        cout << setw(40)<<"ID : ";
                        cin >> ID;
                        cout << setw(40)<<"PassWord ; ";
                        cin >> Password;
                    }while(ID != ID_Register || Password != Password_Register);
                    GUI(3);
        }else if(x == 2){
                            cout << "Your ID ";
                            cin >> ID_Register;
                            cout << "You Name ";
                            cin >> Name;
                            cout << "Your Password ";
                            cin >> Password_Register;
                            cout << "You Want to Home Page or You want to login "<<endl;
                            cout << "[0] Home]  [1] Login"<<endl;
                            cin >> x;
                            GUI(x);
        }else if(x == 3){
            Menu_Account(0);
        }else if(x == 4){
                cout << "Thank_You";
                Open_Programe = false;
        }else if(x < 0 || x > 4){
            cout << "Not Select" << endl;
            GUI(0);
        }
}


void Menu_Account(int y){
        if(y == 0){
        int Ch_MN_AC;
        cout << "--------------------------------------------------" << endl;
        cout << "ID : " << ID << endl;
        cout << "Name : " << Name <<endl;
        cout << "My Money : " << Money <<endl;
        cout <<  "--------------------------------------------------" << endl;
        cout << "Movie " << setw(15) << "[1]"<<endl;
        cout << "Food  " << setw(15) << "[2]"<<endl;
        cout << "Promoion " << setw(12) << "[3]"<<endl;
        cout << "Logout" << setw(15)<< "[4]" << setw(2) << "Exit" << setw(15) << "[5]"<<endl; 
        cout <<  "--------------------------------------------------" << endl;
        cout <<  "You Select : " ;
        cin >> Ch_MN_AC;
        Choose_Menu_Account(Ch_MN_AC);
        }
}

void Choose_Menu_Account(int Ch_MN_AC){
        int Movie;
        string Food_list,Movie_List,Promoion_list;
        if(Ch_MN_AC == 1){
                cout <<  "--------------------------------------------------" << endl;
                cout << "Movie" << setw(30) << " Cost " ;
                //Movie_list

                
        }else if(Ch_MN_AC == 2){
                cout <<  "--------------------------------------------------" << endl;
                cout << "Food" << setw(30) << " Cost " ;
                //Food_List
        }else if(Ch_MN_AC == 3){
                cout <<  "--------------------------------------------------" << endl;
                cout << "Promoion" << setw(30) << " Cost " ;
        }else if(Ch_MN_AC == 4){
                GUI(1);
        }else if(Ch_MN_AC == 5){
                cout << "ThankYou";
        }
}

void Choose_Theatre(int Ch_Th){

}


void Totol(int T_O){


}
