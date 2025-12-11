#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

class Figure
{
public:
    Figure(string);
    Figure(string, float, float);
    ~Figure();
    void setCor();
    void getCor() const;

protected:
    string name;
    float x;
    float y;
};

Figure::~Figure()
{
    delete this;
}

Figure::Figure(string name_p) : name(name_p)
{
    x = rand() % 101;
    y = rand() % 101;
}

Figure::Figure(string name_p, float x_p, float y_p) : name(name_p)
{
    x = x_p;
    y = y_p;
}

void Figure::setCor()
{
    cout << "Input " << name << " coordinates: ";
    cin >> x >> y;
    cout << endl;
}

void Figure::getCor() const
{
    cout << name << " coordinates: (" << x << ", " << y << ")" << endl;
}

class Line : public Figure
{
public:
    Line(string);
    Line(string, float, float, float, float);
    ~Line();
    void setCor();
    void getCor() const;
    void getLen() const;

protected:
    void Len();
    float x2;
    float y2;
    float length;
};

Line::~Line()
{
    delete this;
}

Line::Line(string name_p) : Figure(name_p)
{
    x2 = x + rand() % 51 - 50;
    y2 = y + rand() % 51 - 50;
    Len();
}

Line::Line(string name_p, float x_p, float y_p, float x2_p, float y2_p) : Figure(name_p, x_p, y_p)
{
    x2 = x2_p;
    y2 = y2_p;
    Len();
}

void Line::setCor()
{
    Figure::setCor();
    cout << "Input " << name << " end coordinates: ";
    cin >> x2 >> y2;
    cout << endl;
    Len();
}

void Line::getCor() const
{
    Figure::getCor();
    cout << name << " end coordinates: (" << x2 << ", " << y2 << ")" << endl;
}

void Line::Len()
{
    length = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
}

void Line::getLen() const
{
    cout << name << " length = " << length << endl;
}

class Square : public Line
{
public:
    Square(string);
    Square(string, float, float, float, float);
    ~Square();
    void setCor();
    void setRCor();
    void getCor() const;
    void getLen() const;
    void getPerimeter() const;
    void getArea() const;

protected:
    string name;
    void Perimeter();
    void Area();
    float P;
    float S;
};

Square::~Square()
{
    delete this;
}
Square::Square(string name_p) : Line(name_p), name(name_p)
{
    Perimeter();
    Area();
}
Square::Square(string name_p, float x_p, float y_p, float x2_p, float y2_p) : Line(name_p, x_p, y_p, x2_p, y2_p), name(name_p)
{
    Perimeter();
    Area();
}

void Square::setCor()
{
    Line::setCor();
    Perimeter();
    Area();
}

void Square::setRCor()
{
    x = rand() % 101;
    y = rand() % 101;
    x2 = x + rand() % 51 - 50;
    y2 = y + rand() % 51 - 50;
    Len();
    Perimeter();
    Area();
}

void Square::getCor() const
{
    Line::getCor();
}

void Square::getLen() const
{
    Line::getLen();
}

void Square::Perimeter()
{
    P = length * 4;
}

void Square::Area()
{
    S = length * length;
}

void Square::getPerimeter() const
{
    cout << name << " perimeter = " << P << endl;
}

void Square::getArea() const
{
    cout << name << " area = " << S << endl;
}

class Rectangle : public Square
{
public:
    Rectangle();
    Rectangle(float, float, float, float, float, float);
    ~Rectangle();
    void setCor();
    void setRCor();
    void getCor() const;
    void getLen2() const;

protected:
    void Len2();
    void Perimeter();
    void Area();
    float x3;
    float y3;
    float length2;
};

Rectangle::~Rectangle()
{
    delete this;
}

Rectangle::Rectangle() : Square("Rectangle")
{
    x3 = x2 + rand() % 51 - 50;
    y3 = y2 + rand() % 51 - 50;
    Len2();
}

Rectangle::Rectangle(float x_p, float y_p, float x2_p, float y2_p, float x3_p, float y3_p) : Square("Rectangle", x_p, y_p, x2_p, y2_p)
{
    x3 = x3_p;
    y3 = y3_p;
    Len2();
}

void Rectangle::setCor()
{
    Square::setCor();
    cout << "Input " << name << " second end coordinates: ";
    cin >> x3 >> y3;
    cout << endl;
    Len2();
    Perimeter();
    Area();
}

void Rectangle::setRCor()
{
    Square::setRCor();
    x3 = x2 + rand() % 25 - 25;
    y3 = y2 + rand() % 25 - 25;
    Len2();
    Perimeter();
    Area();
}

void Rectangle::Len2()
{
    length2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
}

void Rectangle::getLen2() const
{
    cout << name << " length2 = " << length2 << endl;
}

void Rectangle::getCor() const
{
    Square::getCor();
    cout << name << " second end coordinates: (" << x3 << ", " << y3 << ")" << endl;
}

void Rectangle::Perimeter()
{
    P = (length + length2) * 2;
}

void Rectangle::Area()
{
    S = length * length2;
}

class Circle : public Figure
{
};

class Ellips : public Circle
{
};

int main()
{
    srand(time(NULL));
    Figure F1("F1"), F2("F2", 23, 24);
    cout << "Figure 1 - rand constructor:\n"
         << endl;
    F1.getCor();
    cout << endl;
    cout << "Figure 2 - parameter constructor:\n"
         << endl;
    F2.getCor();
    cout << endl;
    cout << "Figure 1 - setted constructor:\n"
         << endl;
    F1.setCor();
    cout << endl;
    F1.getCor();
    cout << endl;
    cout << "\n"
         << endl;
    Line L1("L1"), L2("L2", 10, 10, 20, 20);
    cout << "Line 1 - rand constructor:\n"
         << endl;
    L1.getCor();
    L1.getLen();
    cout << "\n"
         << endl;
    cout << "Line 2 - parameter constructor:\n"
         << endl;
    L2.getCor();
    L2.getLen();
    cout << "\n"
         << endl;
    cout << "Line 2 - setted constructor:\n"
         << endl;
    L2.setCor();
    L2.getCor();
    L2.getLen();
    cout << "\n"
         << endl;

    Square S1("S1"), S2("S2", 10, 10, 20, 20);
    cout << "Square 1 - rand constructor:\n"
         << endl;
    S1.getCor();
    S1.getLen();
    S1.getPerimeter();
    S1.getArea();
    cout << "\n"
         << endl;
    cout << "Square 2 - parameter constructor:\n"
         << endl;
    S2.getCor();
    S2.getLen();
    S2.getPerimeter();
    S2.getArea();
    cout << "\n"
         << endl;
    cout << "Square 1 - setted constructor:\n"
         << endl;
    S1.setCor();
    S1.getCor();
    S1.getLen();
    S1.getPerimeter();
    S1.getArea();

    Rectangle R1, R2(10, 10, 20, 10, 20, 20);
    cout << "Rectangle 1 - rand constructor:\n"
         << endl;
    R1.getCor();
    R1.getLen();
    R1.getLen2();
    R1.getPerimeter();
    R1.getArea();
    cout << "\n"
         << endl;
    cout << "Rectangle 2 - parameter constructor:\n"
         << endl;
    R2.getCor();
    R2.getLen();
    R2.getLen2();
    R2.getPerimeter();
    R2.getArea();
    cout << "\n"
         << endl;
    cout << "Rectangle 1 - setted constructor:\n"
         << endl;
    R1.setCor();
    R1.getCor();
    R1.getLen();
    R1.getLen2();
    R1.getPerimeter();
    R1.getArea();
    cout << "\n"
         << endl;
    cout << "Rectangle 2 - rand setted constructor:\n"
         << endl;
    R2.setRCor();
    R2.getCor();
    R2.getLen();
    R2.getLen2();
    R2.getPerimeter();
    R2.getArea();
    cout << "\n"
         << endl;

    Rectangle *recs = new Rectangle[3];
    recs[0] = Rectangle(0, 0, 4, 0, 4, 4);
    recs[1] = Rectangle(0, 5, 0, 10, 10, 10);
    recs[2] = Rectangle(2, 2, 2, 5, 5, 6);

    for (int i = 0; i < 3; i++)
    {
        recs[i].getCor();
        recs[i].getLen();
        recs[i].getLen2();
        recs[i].getPerimeter();
        recs[i].getArea();
        cout << endl;
    }
    delete[] recs;
}
