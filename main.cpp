#include <iostream>

class Matrix
{
private:
    int n;
    int m;
    double** arr = nullptr;
public:
    void setN(int);
    void setM(int);
    void setElement(int a, int b, double c);
    
    int getN() const;
    int getM() const;
    double getElement(int,int) const;

    void clean();
    double create(int, int);

    void printMas() const;
    void printMas(int, int, int) const;

    int swapstr(int, int);
    int QuickSort(double*, int);
    void randfill();
    void fillKeyboard();
};

void Matrix::setN(int k)
{
    n = k;
}

void Matrix::setM(int k)
{
    m = k;
}

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
    if (a < n and b < m)
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

void Matrix::clean()
{
    if (arr != nullptr) {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != nullptr) delete[] arr[i];
        }
        delete[] arr;
    }
}

double Matrix::create(int k, int p)
{
    clean();

    n = k;
    m = p;
    arr = new double*[k];
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

void Matrix::randfill()
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

void Matrix::fillKeyboard()
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

int Matrix::QuickSort(double* mas, int size)
{
    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];

    do 
    {
        while (mas[i] < mid) 
        {
            i++;
        }
        while (mas[j] > mid) 
        {
            j--;
        }
        if (i <= j) 
        {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) 
    {
        QuickSort(mas, j + 1); // Левый кусок
    }
    if (i < size) 
    {
        QuickSort(&mas[i], size - i); // Правый кусок
    }
}

int main()
{
    std::cout << "Hello World!\n";
}
