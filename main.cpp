#include <iostream>
#include<time.h>

class Matrix
{
private:
    int n;
    int m;
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
    int swaprow(int, int);
    int quickSort(int);
    void randFill();
    void keyboardFill();
    int negCount_row(int);
};

void Matrix::setElement(int a, int b, double c)
{
    if (a < n && b < m)
    {
        arr[a][b] = c;
    }
}

int Matrix::getN() const
{
    return n;
}

int Matrix::getM() const
{
    return m;
}

double Matrix::getElement(int a, int b) const
{
    return arr[a][b];
}

int Matrix::swapstr(int a, int b)
{
    if (a < n and b < n)
    {
        double* tmp = new double[n];
        tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
        delete[] tmp;
        return 0;
    }
    else return -1;
}

int Matrix::swaprow(int a, int b)
{
    if (a < m and b < m)
    {
        for (int k = 0; k < m; k++)
        {
            double tmp = arr[k][a];
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
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != nullptr) delete[] arr[i];
        }
        delete[] arr;
    }
    n = 0;
    m = 0;
    arr = nullptr;
}

Matrix::Matrix(int k, int p)
{
    n = k;
    m = p;
    arr = new double* [k];
    for (int i = 0; i < k; i++)
    {
        arr[i] = new double[p];
        for (int j = 0; j < p; j++) arr[i][j] = 0;
    }
}

void Matrix::create(int k, int p)
{
    n = k;
    m = p;
    arr = new double* [k];
    for (int i = 0; i < k; i++)
    {
        arr[i] = new double[p];
        for (int j = 0; j < p; j++) arr[i][j] = 0;
    }
}

void Matrix::printMas() const
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%.5lf ", arr[i][j]);
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
            printf("%.5lf ", arr[i][j]);
        }
        printf("\n");
    }
}

void Matrix::randFill()
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 1 + rand() % 200 - 100;
        }
    }
    printf("\n");
}

void Matrix::keyboardFill() 
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Вводим " << i + 1 << " строку\n";
        for (int j = 0; j < m; j++)
        {
            printf("Введите целое число: ");
            std::cin >> arr[i][j];
        }
    }
    printf("\n");
}

int Matrix::quickSort(int size)
{
    if (arr != nullptr)
    {
        int i = 0;
        int j = size-1;
        int k1 = 0, k2 = 0;

        int mid = negCount_row(arr[n][size / 2]);
        for (int k = 0; k < n; k++)
        {
            do
            {
                while (arr[n][i] < mid)
                {
                    k1 = negCount_row(i);
                    i++;
                }
                while (arr[n][j] > mid)
                {
                    k2 = negCount_row(j);
                    j--;
                }
                if (k2 >= k1)
                {
                    swaprow(i, j);

                    i++;
                    j--;
                }
            } while (i <= j);
            if (j > 0)
            {
                quickSort(j + 1); // Левый кусок
            }
            if (i < size)
            {
                quickSort(size-i); // Правый кусок
            }
        }
    }
    else return -3;
}

int Matrix::negCount_row(int a)
{
    if (a < m)
    {
        double c = 0;
        for (int j = 0; j < n; j++) 
        {
            if (arr[j][a] < 0) c += 1;
        }
        return c;
    }
}

int main()
{
    std::cout << "Hello World!\n";
}
