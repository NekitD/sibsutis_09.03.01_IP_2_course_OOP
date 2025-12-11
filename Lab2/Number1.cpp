#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

void print(unsigned char *mas, int size);
void filling(unsigned char **mas, int size);
void refillingRight(unsigned char *one, unsigned char **dab, int size);
void refillingLeft(unsigned char *one, unsigned char **dab, int size);
void spiralCenter(unsigned char *one, unsigned char **dab, int size);
void spiralLeft(unsigned char *one, unsigned char **dab, int size);
void deleting(unsigned char **mas, int size);

void printMatrix(unsigned char **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << (int)arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n"
         << endl;
}

int main()
{
    srand(time(NULL));
    unsigned char **mas, *one;
    int size = 4;
    mas = (unsigned char **)malloc(size * sizeof(unsigned char *));
    one = (unsigned char *)malloc(size * size * sizeof(unsigned char));
    for (int i = 0; i < size; i++)
    {
        mas[i] = (unsigned char *)malloc(size * sizeof(unsigned char));
    }

    filling(mas, size);

    printMatrix(mas, size);

    spiralCenter(one, mas, size);
    print(one, size * size);
    deleting(mas, size);
    free(one);
}

void print(unsigned char *mas, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        cout << (int)mas[i] << " ";
        count++;
    }
    // cout << "\n"
    //      << count;
}
void filling(unsigned char **mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mas[i][j] = rand() % (99 - 10 + 1) + 10;
        }
    }
}

void refillingRight(unsigned char *one, unsigned char **dab, int size)
{
    int position = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        int t = 0, j = i;
        while (j <= size - 1 && t <= size - 1)
        {
            one[position] = dab[t][j];
            t++;
            j++;
            position++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        int t = i + 1, j = 0;
        while (j <= size - 1 && t <= size - 1)
        {
            one[position] = dab[t][j];
            t++;
            j++;
            position++;
        }
    }
}

void refillingLeft(unsigned char *one, unsigned char **dab, int size)
{
    int position = 0;
    for (int i = 0; i < size; i++)
    {
        int t = 0, j = i;
        while (j >= 0 && t <= size - 1)
        {
            one[position] = dab[t][j];
            t++;
            j--;
            position++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        int t = i + 1, j = size - 1;
        while (j >= 0 && t <= size - 1)
        {
            one[position] = dab[t][j];
            t++;
            j--;
            position++;
        }
    }
}

void spiralCenter(unsigned char *one, unsigned char **dab, int size)
{
    int position_one = 0, pos_x = (size - 1) / 2, pos_y = pos_x, side = 1, side_x = 1, side_y = 1;
    one[0] = dab[pos_y][pos_x];
    for (int step = 1; step < size; step++)
    {
        for (int f = 0; f < 2; f++)
        {
            if (side == 0)
            {
                if (side_y == 0)
                {
                    for (int j = 1; j <= step; j++)
                    {
                        pos_y--;
                        position_one++;
                        one[position_one] = dab[pos_y][pos_x];
                    }
                }
                else if (side_y == 1)
                {
                    for (int j = 1; j <= step; j++)
                    {
                        pos_y++;
                        position_one++;
                        one[position_one] = dab[pos_y][pos_x];
                    }
                }
            }
            else if (side == 1)
            {
                if (side_x == 0)
                {
                    for (int j = 1; j <= step; j++)
                    {
                        pos_x--;
                        position_one++;
                        one[position_one] = dab[pos_y][pos_x];
                    }
                }
                else if (side_x == 1)
                {
                    for (int j = 1; j <= step; j++)
                    {
                        pos_x++;
                        position_one++;
                        one[position_one] = dab[pos_y][pos_x];
                    }
                }
            }
            side = 1 - side;
        }
        side_y = 1 - side_y;
        side_x = 1 - side_x;
    }

    if (side == 0)
    {
        if (side_y == 0)
        {
            for (int j = 1; j < size; j++)
            {
                pos_y--;
                position_one++;
                one[position_one] = dab[pos_y][pos_x];
            }
        }
        else if (side_y == 1)
        {
            for (int j = 1; j < size; j++)
            {
                pos_y++;
                position_one++;
                one[position_one] = dab[pos_y][pos_x];
            }
        }
    }
    else if (side == 1)
    {
        if (side_x == 0)
        {
            for (int j = 1; j < size; j++)
            {
                pos_x--;
                position_one++;
                one[position_one] = dab[pos_y][pos_x];
            }
        }
        else if (side_x == 1)
        {
            for (int j = 1; j < size; j++)
            {
                pos_x++;
                position_one++;
                one[position_one] = dab[pos_y][pos_x];
            }
        }
    }
}

void spiralLeft(unsigned char *one, unsigned char **dab, int size)
{
    int step = size, pos_x = 0, pos_y = 0, pos_one = 0, direction = 1;
    for (int i = 0; i < step - 1; i++)
    {
        one[pos_one] = dab[pos_y][pos_x];
        pos_x += direction;
        pos_one++;
    }
    for (int i = 0; i < step - 1; i++)
    {
        one[pos_one] = dab[pos_y][pos_x];
        pos_y += direction;
        pos_one++;
    }
    direction = -direction;
    for (int i = 0; i < step - 1; i++)
    {
        one[pos_one] = dab[pos_y][pos_x];
        pos_x += direction;
        pos_one++;
    }
    step--;
    while (step > 0)
    {
        for (int i = 0; i < step - 1; i++)
        {
            one[pos_one] = dab[pos_y][pos_x];
            pos_y += direction;
            pos_one++;
        }
        direction = -direction;
        for (int i = 0; i < step - 1; i++)
        {
            one[pos_one] = dab[pos_y][pos_x];
            pos_x += direction;
            pos_one++;
        }
        step--;
    }
}

void deleting(unsigned char **mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(mas[i]);
    }
}
