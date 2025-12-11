#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename Type>
class Matrix
{
public:
    Matrix() : m(0), n(0), M(NULL)
    {
    }
    Matrix(int m_p, int n_p)
    {
        m = m_p;
        n = n_p;
        M = new Type *[m];
        for (int i = 0; i < m; i++)
        {
            M[i] = new Type[n];
            for (int j = 0; j < n; j++)
            {
                M[i][j] = 0;
            }
        }
    }
    Matrix(const Matrix &O)
    {

        m = O.m;
        n = O.n;
        M = new Type *[m];
        for (int i = 0; i < m; i++)
        {
            M[i] = new Type[n];
            for (int j = 0; j < n; j++)
            {
                M[i][j] = O.M[i][j];
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < m; i++)
        {
            delete[] M[i];
        }
        delete[] M;
    }

    Matrix &operator=(const Matrix &O)
    {
        if (this != &O)
        {
            if (M != NULL)
            {
                for (int i = 0; i < m; i++)
                {
                    delete[] M[i];
                }
                delete[] M;
            }
            m = O.m;
            n = O.n;
            M = new Type *[m];
            for (int i = 0; i < m; i++)
            {
                M[i] = new Type[n];
                for (int j = 0; j < n; j++)
                {
                    M[i][j] = O.M[i][j];
                }
            }
        }
        return *this;
    }

    void GetM()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << M[i][j] << " ";
            }
        }
    }
    void SetM(int i, int j, Type value)
    {
        M[i][j] = value;
    }
    void Print(string Name)
    {
        cout << "Object " << Name << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << M[i][j] << "    ";
            }
            cout << "\n"
                 << endl;
        }
    }

private:
    Type **M;
    int m;
    int n;
};

int main()
{
    Matrix<int> M(3, 4);
    M.Print("M");

    cout << "\n\n";

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            M.SetM(i, j, i + j);
        }
    }
    M.Print("M");

    cout << "\n\n";

    Matrix<int> M1 = M;
    M1.Print("M1");

    cout << "\n\n";

    Matrix<int> M2 = M;
    M2.Print("M2");

    cout << "\n\n";

    Matrix<int> M3;
    M3 = M2 = M1 = M;
    M3.Print("M3");

    //-----------------------------------
    cout << "\n\n";

    Matrix<double> Md(3, 4);
    Md.Print("Md");

    cout << "\n\n";

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            Md.SetM(i, j, (i + j) * 0.5);
    }
    Md.Print("Md");

    cout << "\n\n";

    Matrix<double> Md1 = Md;
    Md1.Print("Md1");

    cout << "\n\n";
    Matrix<double> Md2;
    Md2 = Md;
    Md2.Print("Md2");

    cout << "\n\n";
    Matrix<double> Md3;
    Md3 = Md2 = Md1 = Md;
    Md3.Print("Md3");
}
