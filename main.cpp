#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Matrix
{
private:
    int str;
    int col;
    double** arr = nullptr;
public:
    void setElement(int a, int b, double c);

    int getN() const;
    int getM() const;
    double getElement(int, int) const;

    void clean();
    void create(int, int);
    Matrix(int, int);

    void printMas() const;
    void printMas(int, int, int) const;

    int swapstr(int, int);
    int swapcol(int, int);
    void randFill();
    void keyboardFill();
};

void Matrix::setElement(int a, int b, double c)
{
    if (a < str && b < col)
    {
        arr[a][b] = c;
    }
}

int Matrix::getN() const
{
    return str;
}

int Matrix::getM() const
{
    return col;
}

double Matrix::getElement(int a, int b) const
{
    return arr[a][b];
}

int Matrix::swapstr(int a, int b)
{
    if (a < str and b < str)
    {
        double* tmp = new double[str];
        tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
        delete[] tmp;
        return 0;
    }
    else return -1;
}

int Matrix::swapcol(int a, int b)
{
    double tmp = 0;
    if (a < col and b < col)
    {
        for (int k = 0; k < str; k++)
        {
            tmp = arr[k][a];
            arr[k][a] = arr[k][b];
            arr[k][b] = tmp;
        }
    }
    else return -1;
}

void Matrix::clean()
{
    if (arr != nullptr)
    {
        for (int i = 0; i < str; i++)
        {
            if (arr[i] != nullptr) delete[] arr[i];
        }
        delete[] arr;
    }
    str = 0;
    col = 0;
    arr = nullptr;
}

Matrix::Matrix(int k, int p)
{
    str = k;
    col = p;
    arr = new double* [k];
    for (int i = 0; i < k; i++)
    {
        arr[i] = new double[p];
        for (int j = 0; j < p; j++) arr[i][j] = 0;
    }
}

void Matrix::create(int k, int p)
{
    str = k;
    col = p;
    arr = new double* [k];
    for (int i = 0; i < k; i++)
    {
        arr[i] = new double[p];
        for (int j = 0; j < p; j++) arr[i][j] = 0;
    }
}

void Matrix::printMas() const
{
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%7.2lf ", arr[i][j]);
        }
        printf("\n");
    }
}

void Matrix::printMas(int a, int b, int rad) const
{
    for (int i = a; i < a + rad; i++)
    {
        for (int j = b; j < b + rad; j++)
        {
            printf("%7.2lf ", arr[i][j]);
        }
        printf("\n");
    }
}

void Matrix::randFill()
{
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = (1 + rand() % 400 - 200)*0.1;
        }
    }
    printf("\n");
}

void Matrix::keyboardFill() 
{
    for (int i = 0; i < str; i++)
    {
        cout << "Вводим " << i + 1 << " строку\n";
        for (int j = 0; j < col; j++)
        {
            printf("Введите целое число: ");
            cin >> arr[i][j];
        }
    }
    printf("\n");
}

void quickSort(Matrix& M,int* Keys, int left, int right)
{
        int i = left;
        int j = right;
        int tmp = 0;
        int k1 = 0, k2 = 0;
        int mid = Keys[(right+left) / 2];
            do
            {
                while (Keys[i] > mid && i<right)
                {
                    i++;
                }
                while (Keys[j] < mid && j>left)
                {
                    j--;
                }
                if (i <= j)
                {
                    tmp = Keys[i];
                    Keys[i] = Keys[j];
                    Keys[j] = tmp;
                    M.swapcol(i, j);
                    i++;
                    j--;
                }
            } while (i <= j);
            if (left < i)
            {
                quickSort(M, Keys, left,j); // Левый кусок
            }
            if (i < right)
            {
                quickSort(M, Keys, i,right); // Правый кусок
            }
}

void Sort(Matrix& M)
{
    int n = M.getN();
    int m = M.getM();
    int* Keys = new int[m];
    int i = 0, j = 0;
    for (j = 0; j < m; j++)
    {
        Keys[j] = 0;
        for (i = 0; i < n; i++)
        {
            if (M.getElement(i, j) < 0) Keys[j]++;
        }
    }
    for (i=0; i < m; i++) cout << Keys[i];
    printf("\n");
    quickSort(M, Keys, 0,m-1);
    for (i=0; i < m; i++) cout << Keys[i];
    printf("\n");
    delete[] Keys;
}

void get()
{
    if (!cin)
    { 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void menu()
{
    printf("Введите число для выбора функции, чтобы:\n");
    printf("1: Создать матрицу.\n");
    cout << "2: Заполнить массив с клавиатуры.\n";
    cout << "3: Заполнить массив случайными числами.\n";
    cout << "4: Быстро вывести массив.\n";
    cout << "5: Отсортировать столбцы по неубыванию отрицательных элементов.\n";
    cout << "6: Поменять строки местами\n";
    cout << "7: Поменять столбцы местами\n";
    cout << "8: Задать элемент по индексу\n";
    printf("Введите exit для окончания раоботы\n");
    printf("Введите clear для очистки экрана\n");
}

int main()
{
    setlocale(LC_ALL, "Rus");
    string fill = "*";
    bool flag = true;
    int n = 0;
    int m = 0;
    Matrix matrix(n, m);
    while (flag)
    {
        menu();
        cin >> fill;
        if (fill == "1")
        {
            matrix.clean();
            do
            {
                cout << "Введите размеры матрицы ";
                cin >> n >> m;
                get();
                printf("\n");
            } while (n <= 0 || m <= 0);
            matrix.create(n, m);            
        }
        if (fill == "2") 
        {
            if (n!=0 || m!=0)
            matrix.keyboardFill();          
        }
        if (fill == "3") {
            srand(time(NULL));
            if (n!=0 || m!=0)
            matrix.randFill();           
        }
        if (fill == "4")
        {
            matrix.printMas();
            printf("\n");         
        }
        if (fill == "5") {
            
            if (n != 0 || m != 0) 
            {
                Sort(matrix);
                matrix.printMas();
                printf("\n");
            }
            else
            {
                cout << "Матрица пуста\n";
            }
        }
        if (fill == "clear")
        {
            system("cls");
        }
        if (fill == "exit")
        {
            printf("Спасибо за использование программы!\n");
            flag = false;
        }
        if (fill == "6") 
        {
            int a=0, b=0;
            cout << "Введите строки которые вы хотите поменять местами: ";
            cin >> a >> b;
            if (abs(a) < n && abs(b) < n) matrix.swapstr(a - 1, b - 1);
            else cout << "Не правильный номер строки";
        }
        if (fill == "7")
        {
            int a = 0, b = 0;
            cout << "Введите столбцы которые вы хотите поменять местами: ";
            cin >> a >> b;
            if (abs(a) < m && abs(b) < m) matrix.swapcol(a - 1, b - 1);
            else cout << "Не правильный номер стобца";
        }
        if (fill == "8")
        {
            int a = 0, b = 0;
            cout << "Введите индекс элемента, который вы хотите поменять: ";
            cin >> a >> b;
            int c = 0;
            cout << "\nВведите элемент: ";
            int ok = scanf("%d", &c);
            if (ok) matrix.setElement(a + 1, b + 1,c);
        }
    }
    return 0;
}
