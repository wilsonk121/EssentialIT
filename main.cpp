#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int start(){
    int choice;
    cout << "1:Matrix addition/subtraction" << endl;   
    cout << "2:Matrix multiplication" << endl;  
    cout << "3:Inverse matrix" << endl;  
    cout << "4:Reduced row echelon form" << endl;  
    cout << "5:Rank" << endl;  
    cout << "6:System of equation" << endl;
    cout << "7:Exit" << endl;  
    cout << "Enter the corresponding index to start the function: "; 
    cin >> choice;
    return choice;
}

void display(int M[][10],int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void addition(int M1[][10], int M2[][10], int result[][10], int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            result[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

void subtraction(int M1[][10], int M2[][10], int result[][10], int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            result[i][j] = M1[i][j] - M2[i][j];
        }
    }
}

int main(){
    bool flag=1;
    int choice=0;
    cout<<"Welcome to matrix calculator. "<<endl; 
    while(flag==1){
        choice = start();
        switch(choice){
            case 1:{
                int rows=1, columns;
                cout << "Enter the number of rows: ";
                cin >> rows;
                while (rows < 1 || rows > 10){
                    cout << "Invalid input,Please enter again." << endl;
                    cin >> rows;
                }
                cout << "Enter the number of columns: ";
                cin >> columns;
                while (columns < 1 || columns > 10){
                    cout << "Invalid input,Please enter again." << endl;
                    cin >> columns;
                }
                int M1[rows][10], M2[rows][10], result[rows][10];
                cout << "Enter the elements of Matrix 1:" << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        cin >> M1[i][j];
                    }
                }
                cout << "Enter the elements of Matrix 2:" << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        cin >> M2[i][j];
                    }
                }
                cout << "\nMatrix 1:" << endl;
                display(M1, rows, columns);
                cout << "\nMatrix 2:" << endl;
                display(M2, rows, columns);
                cout << "\nAddition of Matrix 1 and Matrix 2:" << endl;
                addition(M1, M2, result, rows, columns);
                display(result, rows, columns);
                cout << "\nSubtraction of Matrix 1 and Matrix 2:" << endl;
                subtraction(M1, M2, result, rows, columns);
                display(result, rows, columns);
            }
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
