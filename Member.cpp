#include<iostream>

using namespace std;
const int Row = 8;
const int Column = 9;


void Show_Sitting(int S_S);

int main(){
    Show_Sitting(0);
    return 0;

}
    
void Show_Sitting(int S_S){
    int x ,y,z;
    int Sit[Row][Column] = {};

    // ID no link
    // Name no link
    // Money  no link 
    if(x = 0){
        for(int M = 0; M < Row; M++){
            for(int N = 0; N < Column; N++){
                Sit[M][N] = 0;
            }
        }
    }for(int M = 0; M < Row; M++){
            for(int N = 0; N < Column; N++){
                cout << "\t"<< Sit[M][N];
        }
        cout << endl;
    }
    do{
    cout << "Please choose a seat[Column]"<< endl;
    cin >> x ;
    cout << "Please choose a seat[Row]"<< endl;
    cin >> y;
    
                for(int M = 0; M < Row; M++){
                for(int N = 0; N < Column; N++){
                    Sit[M][N] = 0;
                    Sit[x][y] = 1;
                    }
            }for(int M = 0; M < Row; M++){
                for(int N = 0; N < Column; N++){
                    cout << "\t"<< Sit[M][N];
                }
            cout << endl;
            }
            cout << "Are you confirm [0] Confirm [1] No" << endl;
            cin >> z;
        }while(z != 0);
        // Link ชำระเงิน
        // ปัญหาคือมันจะทับค่าลงไปเลยไม่สามารถจองได้หลายอัน
    }