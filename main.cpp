#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
using namespace std;


int main(){
    bool flag=1;
    int choice=0;
    cout<<"Welcome to matrix calculator. "<<endl; 
    while(flag==1){   
        cout<<"1:Matrix addition/subtraction"<<endl;   
        cout<<"2:Finding matrix product"<<endl;  
        cout<<"3:Finding inverse of a matrix"<<endl;  
        cout<<"4:Finding RREF of a matrix"<<endl;  
        cout<<"5:Quit"<<endl;  
        cout<<"Enter the corresponding index to start the function: "; 
        cin>>choice;
        switch(choice){
            case 1:{}
            case 2:{}
            case 3:{}
            case 4:{}
            case 5:{
                flag=0;
                break;
            }

            default:{
                cout<<"Invalid input,Please enter again.";
                break;
            }


        }

    }

    return 0;

} 
