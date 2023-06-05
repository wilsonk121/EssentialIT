#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main(){
    bool flag=1;
    int choice=0;
    cout<<"Welcome to matrix calculator. "<<endl; 
    while(flag==1){   
        cout<<"1:Matrix addition/subtraction"<<endl;   
        cout<<"2:Matrix multiplication"<<endl;  
        cout<<"3:Inverse matrix"<<endl;  
        cout<<"4:Reduced row echelon form"<<endl;  
        cout<<"5:Rank"<<endl;  
        cout<<"6:System of equation"<<endl;
        cout<<"7:Exit"<<endl;  
        cout<<"Enter the corresponding index to start the function: "; 
        cin>>choice;
        switch(choice){
            case 1:{}
            case 2:{}
            case 3:{}
            case 4:{}
            case 5:{}
            case 6:{}
            case 7:{
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
