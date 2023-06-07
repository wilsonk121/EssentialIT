#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

const int max_number = 10;
int start(){
    int choice;
    cout << "1:Matrix addition/subtraction" << endl;   
    cout << "2:Matrix multiplication" << endl;  
    cout << "3:Determinant" << endl;  
    cout << "4:Inverse Matrix" << endl;  
    cout << "5:Transpose" << endl; 
    cout << "6:Reduced row echelon form and Rank" << endl;
    cout << "7:System of equation" << endl;
    cout << "8:Exit" << endl;  
    cout << "Enter the corresponding index to start the function: "; 
    cin >> choice;
    return choice;
}

//Display the matrix
void display(double M[][max_number],int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

//Addition of two matrices
void addition(double M1[][max_number], double M2[][max_number], double result[][max_number], int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            result[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

//Subtraction of two matrices
void subtraction(double M1[][max_number], double M2[][max_number], double result[][max_number], int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            result[i][j] = M1[i][j] - M2[i][j];
        }
    }
}

//Mulitplication of two matrices
void multiplication(double M1[][max_number], double M2[][max_number], double result[][max_number], int rows, int columns1, int columns2){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                result[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}

//Calculate the determinant of squared matrix
double determinant(double M[max_number][max_number], int size){
    double det = 0;
    if (size == 1){
        det = M[0][0];
        return det;
    } 
    else if (size == 2){
        det = M[0][0] * M[1][1] - M[0][1] * M[1][0];
        return det;
    }
    else{
        det = 0;
        for (int i = 0; i < size; i++){
            double subM[max_number][max_number];
            int subrow = 0;
            int subcolumn = 0;
            for (int j = 1; j < size; j++){
                subcolumn = 0;
                for (int k = 0; k < size; k++){
                    if (k != i){
                        subM[subrow][subcolumn] = M[j][k];
                        subcolumn++;
                    }
                }
                subrow++;
            }
            int subdeterminant = determinant(subM, size - 1);
            if (i % 2 == 0){
                det += M[0][i] * subdeterminant;
            }
            else{
                det -= M[0][i] * subdeterminant;
            }
        }
    }
    return det;
}

//Transpose of the squared matrix
void transpose(double M[][max_number], int size){
        double result[max_number][max_number];
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                result[i][j] = M[j][i];
            }
        }
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                M[i][j] = result[i][j];
            }
        }
}

// RREF and Rank
void calRREFnRank() { 
    float matrix[3][3]; 
    
    //entering the matrix
    auto enterMatrix=[](float matrix[][3], int rows, int cols) { 
        for (int i=0; i<rows; i++) { 
            for (int j=0; j<cols; j++) { 
                cout << matrix[i][j] << " "; 
            } 
            cout<<endl; 
        } 
    }; 
  
    //row operations  
    auto RowOperations=[](float matrix[][3], int pRow, int pCol, int rows, int cols) { 
        float pElement=matrix[pRow][pCol]; 
        for (int j=0; j<cols; j++) { 
            matrix[pRow][j]/= pElement; 
        }   
        for (int i=0; i<rows; i++) { 
            if (i!=pRow) { 
                float multiplier=matrix[i][pCol]; 
                for (int j=0; j<cols; j++) { 
                    matrix[i][j]-=multiplier*matrix[pRow][j]; 
                } 
            } 
        } 
    }; 

    //RREF 
    auto calRREF=[&RowOperations](float matrix[][3], int rows, int cols) { 
        int pRow=0; 
        int pCol=0; 
  
        while (pRow < rows && pCol < cols) { 
            int maxindex=pRow; 
            float maxvalue=abs(matrix[pRow][pCol]); 
            for (int i= pRow + 1; i< rows; i++) { 
                if (abs(matrix[i][pCol])>maxvalue) { 
                    maxindex= i; 
                    maxvalue= abs(matrix[i][pCol]); 
                } 
            } 
  
            if (maxindex!=pRow) { 
                for (int j=0; j<cols;j++) { 
                    float temp=matrix[pRow][j]; 
                    matrix[pRow][j]=matrix[maxindex][j]; 
                    matrix[maxindex][j]=temp; 
                } 
            } 
  
            RowOperations(matrix, pRow, pCol, rows, cols); 
            pRow++; 
            pCol++; 
        } 
    }; 
  
    //rank
    auto calRank=[](float matrix[][3], int rows, int cols) { 
        int rank=0; 
  
        for (int i=0;i<rows; i++) { 
            bool zerorow=true; 
            for (int j=0; j<cols; j++) { 
                if (matrix[i][j] != 0) { 
                    zerorow=false; 
                    break; 
                } 
            } 
            if (!zerorow) { 
                rank++; 
            } 
        } 
  
        return rank; 
    }; 
  
    cout<< "Please enter the elements of the 3x3 matrix (row, column):\n"; 
    for(int i=0; i<3; i++) { 
        for (int j=0; j<3; j++) { 
            cout<<"Enter element at position ("<<i+1<< "," <<j+1<<"):"; 
            cin>>matrix[i][j]; 
        } 
    } 
  
    cout<<"\nThe original matrix:\n"; 
    enterMatrix(matrix, 3, 3); 
    calRREF(matrix, 3, 3); 
    cout<<"\nThe RREF:\n"; 
    enterMatrix(matrix, 3, 3); 
    int rank=calRank(matrix, 3, 3); 
    cout<<"\nThe rank of the matrix: "<<rank<<endl; 
} 

//solving system of equations
void solveSOE() {
    float matrix[3][3];
    float vector[3];
    float solution[3];

    cout<<"Enter the elements of the 3x3 matrix (row, column):\n";
    for(int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout<<"Enter element at position(" << i+1<< ","<<j+1<<"):";
            cin>>matrix[i][j];
        }
    }

    cout<<"Please enter the elements of the vector:\n";
    for(int i=0;i<3;i++) {
    cout<<"Please enter element at position("<< i+1<< "): ";
    cin>>vector[i];
    }

    float determinant=matrix[0][0]*(matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1])
                    -matrix[0][1]*(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0])
                    +matrix[0][2]*(matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]);

    if (determinant==0) {
        cout<<"The system of equations has no unique solution." << endl;
        return;
    }

    float inverse[3][3];
    inverse[0][0]= (matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1])/ determinant;
    inverse[0][1]=-(matrix[0][1]*matrix[2][2]-matrix[0][2]*matrix[2][1])/ determinant;
    inverse[0][2]= (matrix[0][1]*matrix[1][2]-matrix[0][2]*matrix[1][1])/ determinant;
    inverse[1][0]=-(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0])/ determinant;
    inverse[1][1]= (matrix[0][0]*matrix[2][2]-matrix[0][2]*matrix[2][0])/ determinant;
    inverse[1][2]=-(matrix[0][0]*matrix[1][2]-matrix[0][2]*matrix[1][0])/ determinant;
    inverse[2][0]= (matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0])/ determinant;
    inverse[2][1]=-(matrix[0][0]*matrix[2][1]-matrix[0][1]*matrix[2][0])/ determinant;
    inverse[2][2]= (matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0])/ determinant;

    for (int i=0; i< 3; i++) {
        solution[i]=inverse[i][0]*vector[0]+inverse[i][1]*vector[1]+inverse[i][2]*vector[2];
    }

    cout<<"The solution of the system of equations:\n";
    for (int i=0; i<3; i++) {
        cout<<"x" << i+1<<" = "<< solution[i]<< endl;
    }
}

int main(){
    bool flag=1;
    int choice=0;
    cout << "Welcome to matrix calculator. " << endl; 
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
                double M1[rows][10], M2[rows][10], result[rows][10];
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
                break;
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
                double M1[rows1][max_number], M2[rows2][max_number], result[rows1][max_number];
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
                break;
            }
            case 3:{
                int size;
                double M[max_number][max_number];
                cout << "Enter the size of the square matrix: ";
                cin >> size;
                if (size <= 0 || size > max_number) {
                    cout << "Error: Invalid matrix size." << endl;
                    return 0;
                }
                cout << "Enter the elements of the matrix:" << endl;
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        cin >> M[i][j];
                    }
                }
                cout << "\nThe matrix you entered:" << endl;
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        cout << M[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "\nThe determinant of the matrix is: " << determinant(M, size) << endl;
                break;
            }
            case 4:{
            }
            case 5:{
                double M[max_number][max_number];
                int size;
                cout << "Enter the size of matrix: ";
                cin >> size;
                cout << "Enter the elements of the matrix:\n";
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        cin >> M[i][j];
                    }
                }
                cout << "The matrix you entered:" << endl;
                display(M,size,size);
                cout << "Transpose of the matrix:" << endl;
                transpose(M,size);
                display(M,size,size);        
                break;
            }
            case 6:{
                calRREFnRank(); 
                break; 
            }
            case 7:{
                solveSOE();
                break;
            }
            case 8:{
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
