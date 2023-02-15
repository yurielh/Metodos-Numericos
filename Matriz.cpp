#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>

#define n 3

//cout<<setprecision(2)<<a[i][j];

using namespace std;

void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);

}


double A[n][n],I[n][n],B[n][n],T[n][n];
double V[n], X[n];

void leermatriz(double a[n][n], char x){
    int i,j;
    gotoxy(7,0);
	cout<<"Matriz"<<endl;
        for (i = 1; i <= n ; i++){
            for (j = 1; j <= n; j++){
                gotoxy(j*5,i);
                cout<<" ";
                cin>>a[i][j]; 				                    
            } 
            cout<<endl;            
        }
    
}
void leervector(double v[4], char x){
    int i,f;
    for ( i = 1, f = 1 ; i <=3; i++, f++){
        cout<<"Vector."<<f<<"= ";
        cin>>v[i];
    }
}

void escribirmatriz(double a[n][n], int x, int y){

    int i,j,col,fil;
    col = x;
    fil = y;    
	//gotoxy(col,fil);
    //cout<<"Matriz"<<endl;
    for ( i = 1; i <=n ; i++){
        for (j = 1; j <=n; j++){
            gotoxy(col,fil);
            cout<<setprecision(2)<<a[i][j];
            col = col + 3;
        }
        fil = fil+1;
        col = x;   
    }

 
}
void escribirvector(double v[n], int x, int y){
    int i,j,col,fil;
    col = x;
    fil = y;
    //gotoxy(col+5,fil);
    //cout<<" Vector "<<endl;
    for ( i = 1; i <=n ; i++){
        gotoxy(col,fil);
        fflush(stdin);
        cout<<setprecision(2)<<v[i];
        fil = fil + 1;
        fflush(stdin);
         
    }
 
}

void extendermatriz(double f[n][n], char v){
    int i,j;
    
    for ( i = 1; i <= n ; i++){
        for ( j = 1; j <=n ; j++){
            I[i][j] = 0;
            if (i==j){
                I[i][j]=1;
            }
        }   
    }
}
void gauss(double r[n][n], double g[n][n], double w[n][n]){
    float aux, pivot;
    int i, j ,k;

    for ( i = 1; i <= n; i++){
        pivot = A[i][i];
        //convertir el pivote a 1, aplicar operacion sobre toda la fila
        for ( k = 1; k <=n; k++){
            A[i][k] = A[i][k] / pivot;
            fflush(stdin);
            I[i][k] = I[i][k] / pivot;
        }
        for (j = 1; j <= n; j++){
            if ( i != j){
                aux = A[j][i];
                for (k = 1; k <= n; k++){
                    A[j][k] = A[j][k] - aux*A[i][k];
                    fflush(stdin);
                    I[j][k] = I[j][k] - aux*I[i][k];
                }
            }
        }
        
    }
    
    for (i = 1; i <=n ; i++){
        for (j = 1; j <=n; j++){
            B[i][j] = I[i][j];
            fflush(stdin);
        }
        
    }

}

void transpuesta(double a[n][n], double t[n][n]){
    int i,j;
    
    //cout<<" Transpuesta "<<endl;
    for (i = 1; i <=n ; i++){
        for (j = 1; j <=n; j++){
            T[i][j]= A[j][i];
            fflush(stdin);
        }
        
    }

}


void mult(double r[n][n], double h[n], double s[n]){
    int i,j;
    for ( i = 1; i <=n; i++)
    {
        X[i]= 0;
        for ( j = 1 ; j <=n ; j++)
        {
            s[i] = s[i] + r[i][j]*h[j];
        }   
    }

}

void det33 (double q[n][n], int x, int y){
    int col,fil;
    double det;
    col = x;
    fil = y;

    det = (q[1][1]*q[2][2]*q[3][3] + q[1][2]*q[2][3]*q[3][1] +
         q[1][3]*q[2][1]*q[3][2]) - (q[1][3]*q[2][2]*q[3][1] + 
         q[1][2]*q[2][1]*q[3][3] + q[1][1]*q[2][3]*q[3][2]);
    
    gotoxy(col,fil);
    cout<<setprecision(2)<<"Det="<<det;

}






int main (){
    int opc;   
    do{
    cout<<"---Bienvenido al sistema---"<<endl;
    
    cout<<"-Menu de Opciones-"<<endl;
    cout<<"1. Transpuesta"<<endl;
    cout<<"2. Determinante de una matriz"<< endl;
    cout<<"3. Inversa de una matriz"<<endl;
    cout<<"4. Sistema Ec"<<endl;
    cout<<"5. Salir del sistema"<<endl;
    cout<<"> ";
    
    fflush(stdin);
    cin>>opc;

    switch (opc){
    case 1:
        system("cls");
        leermatriz(A,'a');
        system("cls");
        fflush(stdin);
        escribirmatriz(A,1,1);
        fflush(stdin);
        transpuesta(A,T);
        escribirmatriz(T,1,9);
        gotoxy(0,15);
        fflush(stdin);
        system("pause");
        system("cls");

        break;
    case 2:
        system("cls");
        leermatriz(A,'a');
        fflush(stdin);
        system("cls");
        escribirmatriz(A,1,1);
        det33(A,15,2);
        fflush(stdin);

        gotoxy(0,15);
		system("pause");
        system("cls");

        break;

    case 3:
        system("cls");
        leermatriz(A,'a');
        system("cls");
        fflush(stdin);
        escribirmatriz(A,1,1);
        extendermatriz(I,'m');
        escribirmatriz(I,15,1);
        fflush(stdin);
        gauss(A,I,B);
        escribirmatriz(B,30,1);
        fflush(stdin);

		gotoxy(0,15);        
        system("pause");
        system("cls");

        break;

    case 4:
        system("cls");
        leermatriz(A,'a');
        leervector(V,'v');
        fflush(stdin);
        
        system("cls");
        escribirmatriz(A,1,1);
        escribirvector(V,20,1);
        extendermatriz(I,'m');
        gauss(A,I,B);
        mult(B,V,X);
        
        
        
        escribirvector(X,1,8);
        fflush(stdin);

        gotoxy(0,20); 
        system("pause");
        system("cls");
        break;

    case 5:
        cout<<"Hasta luego..."<<endl;
        system("pause");
        break;

    default:
        cout<<"Respuesta invalida...\n";
        system("pause");
        system("cls");

    }
    } while (opc != 5);

    return 0;

}