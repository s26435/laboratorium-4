//Jan Wolski 20.11.2021
#include <iostream>

using namespace std;

void createTab(int *tab, short n) //wpisywanie liczb do tablicy jednowymiarowej
{
    int x = 0;
    cout << "Tworzenie tablicy" << endl;
    for (short i = 0; i < n; i++)
    {
        cout << "Tab[" << i << "] = ";
        cin >> x;
        tab[i] = x;
    }
}

void writeTab(int* tab, short n) //wypisywanie tablicy
{
    cout << "Wypisuje tablice" << endl;
    for (short i = 0; i < n; i++)
    {
        cout << "Tab[" << i << "] = " << tab[i] << endl;
    }
}

void zadanie1(int* tab, short n)
{
    int temp = 0;
    int temp2;
    for (short i = 0; i < n; i++)
    {
        if(temp<tab[i])
        {
            temp = tab[i];
            temp2 = i;
        }
    }
    cout << "Najwieksza wartosc w tablicy to " << temp << " dla i = " << temp2 << endl;
}

void zadanie2(int* tab, short n)
{
    int temp, trueTemp, temp2;
    temp2 = 0;
    for (short i = 0; i < n; i++)
    {
        temp = 1;
        for (short j = i+1; j < n; j++)
        {
            if(tab[i]==tab[j]) temp++;
        }

        if(temp2<temp)
        {
            temp2 = temp;
            trueTemp = tab[i];
        }
    }
    if(temp2<2)cout << "Kazda liczba wystepuje dokladnie jeden raz!" << endl;
    else cout << "Najwiecej wystapien ma liczba " << trueTemp << " i wystepuje " << temp2 << " razy" << endl;
}

int **create(int m, int n) //tworzenie tablicy dwuwymiarowej
{
    int **matrix;
    matrix = new int *[m];
    for(int j=0; j <m; j++)
    {
        matrix[j] = new int [n];
    }
    return matrix;
}

void show(int **matrix, int m, int n) //wypisywanie tablicy dwuwymiarowej
{
    cout << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void zadanie3()
{
    int **table = create(10, 10);
    for(int i =0; i < 10; i++)
    {
        table[i][0] = i;
    }

    for(int i =0; i < 10; i++)
    {
        table[i][1] = i + i;

    }

    for(int i =0; i < 10; i++)
    {
        table[i][2] = i*i;
    }

    for(int i =0; i < 10; i++)
    {
        table[i][3] = i-4;
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 4; j < 10; j++)
        {
            table[i][j] = 0;
        }
    }
    show(table, 10, 10);
}


int main()
{
    int *tab;
    short n;
    cout << "Podaj wielkosc tablicy ";
    cin >> n;
    tab = new int[n];
    createTab(tab, n);
    cout << "--------------- Zadanie 1 ------------------" << endl;
    zadanie1(tab, n);
    cout << "--------------- Zadanie 2 ------------------" << endl;
    zadanie2(tab, n);
    cout << "--------------- Zadanie 3 ------------------" << endl;
    zadanie3();
    delete[] tab;
    return 0;
}
