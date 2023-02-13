#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);

}

void leermatriz(double w[][4], char x){
    int i,j,f;
    for (i = 1; i <= 3 ; i++){
    	cout<<"Ecuacion#"<<i<<endl;
        for (j = 1,f=1; j <= 3; j++,f++){
            cout<<"x"<<f<<":";
            cin>>w[i][j];                     
        } 
        cout<<endl;
            
    }
}
void leervector(double v[4], char x){
    int i,f;
    for ( i = 1, f = 1 ; i <=3; i++, f++){
        cout<<"Vector "<<f<<".: ";
        cin>>v[i];
    }
}

void escribirmatriz(double a[][4], int colin, int filin){

    int i,j,col,fil;
    col = colin;
    fil = filin;
    gotoxy(col+9,fil-2);
    cout<<"---Matriz---";
    for ( i = 1; i <=3 ; i++){
        for (j = 1; j <=3; j++){
            gotoxy(col,fil);
            cout<<"\t"<<a[i][j];
            col = col + 9;
        }
        fil = fil + 2;
        col = colin;
    }
    

}
void escribirvector(double b[], int colin, int filin){
    int i, col, fil;
    col = colin;
    fil = filin;
    gotoxy(col-2,fil-2);
    cout<<"---Vector---";
    for (i = 1; i <=3 ; i++){
        gotoxy(col,fil);
        cout<<"\t"<<b[i];
        fil= fil + 2;        
    }
    col = col + 2;
    col = colin;
}

void extendermatriz(double w[][4], double r[][7]){
    int i,j;
    for ( i = 1; i <=3 ; i++){
        for ( j = 1; j <=3 ; j++){
            r[i][j] = w[i][j];
        }   
    }
    for ( i = 1; i <=3 ; i++){
        for ( j = 4; j <= 6; j++){
            if (i+3 == j){
                r[i][j] = 1;
                } else{
                    r[i][j] = 0;
                }
         }
    }
    
}

void gauss(double r[][7], double ai[][4]){
    int m,i,j;
    double g,q;
    for ( i = 1; i <= 3; i++){
        for ( m = 1; m <= 3; m++){
            g = r[m][m];
            if (g != 0){
                for ( j = 1; j <=6 ; j++){
                    r[m][j] = r[m][j] / g ; 
                }
                {if ( i != m){
                q = r[i][m];
                for (j = 1; j <= 6 ; j++){
                    r[i][j] = r[i][j] - r[m][j]*q;
                    }
                }
            }  
            } /*for g!=0 */
        } /*for m*/

        for (i = 1; i <=3 ; i++){               //atencion
            for ( j = 4; j <=6 ; j++)
            {
                ai[i][j-3] = r[i][j];           //atencion
            }
            
        }
    }
}

void multv(double f[][4], double b[], double x[]){
    int i,j;
    for ( i = 1; i <= 3; i++){
        x[i] = 0;
        for ( j = 1; j <= 3; j++){
            x[i] = x[i] + f[i][j] * b[j];
        }
    }
}

int main(){
    double A[4][4], B[4], X[4];
    double aext[4][7], ai[4][4];
	leermatriz(A,'a');
    leervector(B,'b');
    extendermatriz(A,aext);
    gauss(aext,ai);
    multv(ai,B,X);

    system("cls");
	escribirmatriz(A,10,2);
    fflush(stdin);

    escribirvector(B,45,2);
    fflush(stdin);
    
    escribirvector(X,30,14);
    

    return 0;    
}