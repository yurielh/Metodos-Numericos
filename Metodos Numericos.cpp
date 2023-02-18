#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

#define n 2
#define z 4

// cout<<setprecision(2)<<a[i][j];

using namespace std;

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

double A[n][n], B[n][n], I[n][n], R[n][n];
double I1[n][n], I2[n][n], R1[n][n], R2[n][n];
double V[n], X[n];

void leermatriz(double a[n][n], char x)
{
    int i, j;
    gotoxy(7, 0);
    cout << "Matriz" << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            gotoxy(j * 5, i);
            cout << " ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}
void leervector(double v[n], char x)
{
    int i, f;
    for (i = 1, f = 1; i <= n; i++, f++)
    {
        cout << "Vector " << f << "= ";
        cin >> v[i];
    }
}

void escribirmatriz(double a[n][n], int x, int y)
{

    int i, j, col, fil;
    col = x;
    fil = y;
    gotoxy(col + 2, fil - 1);
    cout << "Matriz" << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            gotoxy(col, fil);
            cout << setprecision(3) << a[i][j];
            col = col + 5;
        }
        fil = fil + 1;
        col = x;
    }
}
void escribirvector(double v[n], int x, int y)
{
    int i, j, col, fil;
    col = x;
    fil = y;
    gotoxy(col - 3, fil - 1);
    cout << " Vector " << endl;
    for (i = 1; i <= n; i++)
    {
        gotoxy(col, fil);
        fflush(stdin);
        cout << setprecision(1) << v[i];
        fil = fil + 1;
        fflush(stdin);
    }
}

void extendermatriz(double f[n][n], char v)
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            f[i][j] = 0;
            if (i == j)
            {
                f[i][j] = 1;
            }
        }
    }
}
void gauss(double r[n][n], double g[n][n], double w[n][n])
{
    float aux, pivot;
    int i, j, k;

    for (i = 1; i <= n; i++)
    {
        pivot = r[i][i];
        // convertir el pivote a 1, aplicar operacion sobre toda la fila
        for (k = 1; k <= n; k++)
        {
            r[i][k] = r[i][k] / pivot;
            fflush(stdin);
            g[i][k] = g[i][k] / pivot;
        }
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                aux = r[j][i];
                for (k = 1; k <= n; k++)
                {
                    r[j][k] = r[j][k] - aux * r[i][k];
                    fflush(stdin);
                    g[j][k] = g[j][k] - aux * g[i][k];
                }
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            w[i][j] = g[i][j];
            fflush(stdin);
        }
    }
}

void mult(double r[n][n], double h[n], double s[n])
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        X[i] = 0;
        for (j = 1; j <= n; j++)
        {
            s[i] = s[i] + r[i][j] * h[j];
        }
    }
}

void det33(double q[n][n], int x, int y)
{
    int col, fil;
    double det;
    col = x;
    fil = y;

    det = (q[1][1] * q[2][2] * q[3][3] + q[1][2] * q[2][3] * q[3][1] +
           q[1][3] * q[2][1] * q[3][2]) -
          (q[1][3] * q[2][2] * q[3][1] +
           q[1][2] * q[2][1] * q[3][3] + q[1][1] * q[2][3] * q[3][2]);

    gotoxy(col, fil);
    cout << setprecision(2) << "Det=" << det;
}

void multm(double a[n][n], double b[n][n], double c[n][n])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = 0;
            for (int k = 1; k <= n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void det(double w[n][n], int x, int y)
{ /* Caso 1: Calcula y muestra */

    int L, d, m, i, j, g, col, fil;
    double r[n][n], h, p, suma, dete;
    suma = 0;
    for (m = 1; m <= n; m++)
    {
        for (i = 2; i <= n; i++)
        {
            L = 1;
            for (j = 1; j <= n; j++)
            {
                if (j != m)
                {
                    r[i - 1][L] = w[i][j];
                    L = L + 1;
                }
            } /* for j */
        }     /* for i */
        g = 1;
        for (d = 1; d <= 1 + m; d++)
        {
            g = (-1) * g;
        } /* for d */
        p = w[1][m];
        dete = 0;
        h = p * g * dete;
        suma = suma + h;
    }
    col = x;
    fil = y;
    gotoxy(col, fil);
    cout << setprecision(3) << suma;
}

int main()
{
    int opc;
    do
    {
        cout << "---Bienvenido al sistema---" << endl;

        cout << "-Menu de Opciones-" << endl;
        cout << "1. Determinar si Det((A*B)-1) es igual o no a Det((B*A)-1)" << endl;
        cout << "2. Dado un sistema de Ecuaciones, muestre la solucion" << endl;
        cout << "3. Inversa de una matriz" << endl;
        cout << "4. Salir del sistema" << endl;
        cout << "> ";

        fflush(stdin);
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("cls");
            leermatriz(A, 'a');
            system("cls");
            fflush(stdin);
            leermatriz(B, 'b');
            system("cls");
            fflush(stdin);
            escribirmatriz(A, 0, 1);
            escribirmatriz(B, 0, 10);

            multm(A, B, R1);
            escribirmatriz(R1, 22, 1);
            multm(B, A, R2);
            escribirmatriz(R2, 22, 10);
            fflush(stdin);

            extendermatriz(I, 'i1');
            gauss(A, I, I1);
            fflush(stdin);
            escribirmatriz(I1, 50, 1);
            extendermatriz(I, 'i2');
            gauss(B, I, I2);
            fflush(stdin);
            escribirmatriz(I2, 50, 10);
            fflush(stdin);
            det(I1, 75, 2);
            fflush(stdin);
            det(I2, 75, 11);

            gotoxy(0, 15);
            fflush(stdin);
            system("pause");
            system("cls");

            break;

        case 2:
            system("cls");
            fflush(stdin);
            leermatriz(A, 'a');
            system("cls");
            leervector(V, 'v');
            system("cls");
            escribirmatriz(A, 1, 1);
            escribirvector(V, 20, 1);
            extendermatriz(I, 'i');
            gauss(A, I, R);
            mult(R, V, X);
            escribirvector(X, 10, 10);

            gotoxy(0, 15);
            fflush(stdin);
            system("pause");
            system("cls");
            break;

        case 3:

            break;
        case 4:
            cout << "Hasta luego..." << endl;
            system("pause");
            break;

        default:
            cout << "Respuesta invalida...\n";
            system("pause");
            system("cls");
        }
    } while (opc != 4);

    return 0;
}