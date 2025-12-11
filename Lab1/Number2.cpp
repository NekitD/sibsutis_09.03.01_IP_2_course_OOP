#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

int **genRandMatrix(int size, int maxValue);
void printMatrix(int **arr, int size);

int main()
{
    srand(time(NULL));
    int size = rand() % 10, string_sizes[size];
    int maxValue = 100;
    int **arr = genRandMatrix(size, maxValue);
    printMatrix(arr, size);
    for (int i = 0; i < size; i++)
    {
        delete[] (arr + i);
    }
}

int **genRandMatrix(int size, int maxValue)
{
    int **arr = new int *[size];
    for (int i = 0; i < size; i++)
    {
        int s = rand() % 10;
        arr[i] = new int[s + 1];
        arr[i][0] = s;
        for (int j = 1; j < arr[i][0] + 1; j++)
        {
            arr[i][j] = rand() % (maxValue + 1);
        }
    }
    return arr;
}

void printMatrix(int **arr, int size)
{
    cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i][0] << ": ";
        for (int j = 1; j < arr[i][0] + 1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
