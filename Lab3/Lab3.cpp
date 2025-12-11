#include <iostream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

class Matrix
{
public:
    Matrix(int x, int y);
    Matrix(int s = 0);
    ~Matrix();
    void set();
    void randSet(int min = 0, int max = 100);
    void print();
    void sumCount();
    void LineCol();

private:
    int x_size;
    int y_size;
    int **matrix;
    int sum;
};

int main()
{
    Matrix M1;
    Matrix M2(3);
    Matrix M3(3, 4);
    Matrix M4(2, 3);

    M1.print();

    cout << "\n\nM2 before LineCol:\n";
    M2.print();
    cout << endl;
    M2.LineCol();
    cout << "\nM2 before LineCol:\n";
    M2.print();
    cout << endl;

    cout << "\nM3:\n";
    M3.randSet();
    M3.print();
    cout << "\nSum M3: ";
    M3.sumCount();
    cout << endl;

    cout << "\nM4:\n";

    cout << endl;

    M4.set();

    M4.print();

    M1.~Matrix();
    M2.~Matrix();
    M3.~Matrix();
    M4.~Matrix();
}

Matrix::Matrix(int x, int y)
{
    x_size = x;
    y_size = y;
    matrix = new int *[y_size];
    for (int i = 0; i < y_size; i++)
    {
        matrix[i] = new int[x_size];
    }
}

Matrix::Matrix(int s)
{
    x_size = s;
    y_size = s;
    matrix = new int *[y_size];
    for (int i = 0; i < s; i++)
    {
        matrix[i] = new int[x_size];
    }
    int one_x = 0, one_y = 0;
    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            if ((i == one_x) && (j == one_y))
            {
                matrix[i][j] = 1;
                one_x++;
                one_y++;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < y_size; i++)
    {
        delete[] matrix[i];
    }
    delete matrix;
}

void Matrix::set()
{
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            cout << "Input (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
            cout << endl;
        }
    }
}

void Matrix::randSet(int min, int max)
{
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            matrix[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void Matrix::print()
{
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::sumCount()
{
    sum = 0;
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            sum += matrix[i][j];
        }
    }
    cout << sum;
}

void Matrix::LineCol()
{
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            matrix[i][j] = i * j;
        }
    }
}
