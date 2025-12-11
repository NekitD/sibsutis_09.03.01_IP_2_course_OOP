#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

int main()
{
    srand(time(NULL));
    int **mas, size = 10, string_sizes[size];
    mas = (int **)malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++)
    {
        int str_size = rand() % 11 + 1;
        string_sizes[i] = str_size;
        mas[i] = (int *)malloc(str_size * sizeof(int));
        for (int j = 0; j < str_size; j++)
        {
            mas[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < string_sizes[i]; j++)
        {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < size; i++)
    {
        free(mas + i);
    }
}
