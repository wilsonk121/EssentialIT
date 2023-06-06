#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int max_number = 10;
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

void display(int M[][max_number],int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void addition(int M1[][max_number], int M2[][max_number], int result[][max_number], int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            result[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

void subtraction(int M1[][max_number], int M2[][max_number], int result[][max_number], int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            result[i][j] = M1[i][j] - M2[i][j];
        }
    }
}

void multiplication(int M1[][max_number], int M2[][max_number], int result[][max_number], int rows, int columns1, int columns2){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                result[i][j] += M1[i][k] * M2[k][j];
            }
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
            case 2:{
                int rows1, rows2, columns1, columns2;
                cout << "Enter the number of rows of Matrix 1: ";
                cin >> rows1;
                cout << "Enter the number of columns of Matrix 1: ";
                cin >> columns1;
                cout << "Enter the number of rows of Matrix 2: ";
                cin >> rows2;
                cout << "Enter the number of columns of Matrix 2: ";
                cin >> columns2;
                int M1[rows1][max_number];
                int M2[rows2][max_number];
                int result[rows1][max_number];
                if (columns1 != rows2) {
                    cout << "Error: The number of columns of Matrix 1 must be equal to the number of rows of Matrix 2." << endl;
                    return 0;
                }
                cout << "Enter the elements of Matrix 1:" << endl;
                for (int i = 0; i < rows1; i++) {
                    for (int j = 0; j < columns1; j++) {
                        cin >> M1[i][j];
                    }
                }
                cout << "Enter the elements of Matrix 2:" << endl;
                for (int i = 0; i < rows2; i++) {
                    for (int j = 0; j < columns2; j++) {
                        cin >> M2[i][j];
                    }
                }
                cout << "\nMatrix 1:" << endl;
                display(M1, rows1, columns1);
                cout << "\nMatrix 2:" << endl;
                display(M2, rows2, columns2);
                cout << "\nMultiplication of Matrix 1 and Matrix 2:" << endl;
                multiplication(M1, M2, result, rows1, columns1, columns2);
                display(result, rows1, columns2);
            }
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
