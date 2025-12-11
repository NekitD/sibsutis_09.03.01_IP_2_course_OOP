#include <iostream>
#include <cmath>
#include <ctime>

#define Pi 3.14

using namespace std;

class Figure
{
public:
    Figure();
    Figure(float, float);
    virtual ~Figure() {};
    void setCor();
    void getCor() const;
    virtual void getPerimeter() const = 0;
    virtual void getArea() const = 0;

protected:
    virtual void Perimeter() = 0;
    virtual void Area() = 0;
    float x;
    float y;
};

Figure::Figure()
{
    x = rand() % 101;
    y = rand() % 101;
}

Figure::Figure(float x_p, float y_p)
{
    x = x_p;
    y = y_p;
}

void Figure::setCor()
{
    cout << "Input coordinates: ";
    cin >> x >> y;
    cout << endl;
}

void Figure::getCor() const
{
    cout << "Figure coordinates: (" << x << ", " << y << ")" << endl;
}

class Line : public Figure
{
public:
    Line();
    Line(float, float, float, float);
    ~Line();
    void setCor();
    void getCor() const;
    void getLen() const;
    void getCount() const;
    void getPerimeter() const override {};
    void getArea() const override {};

protected:
    void Perimeter() override {};
    void Area() override {};
    void Len();
    float x2;
    float y2;
    float length;

private:
    static int count;
    static int made;
};

int Line::count = 0;
int Line::made = 0;

void Line::getCount() const
{
    cout << "There're " << count << " lines exist." << endl;
    cout << "There're " << made << " lines made." << endl;
}

Line::~Line()
{
    count--;
    // delete this;
}

Line::Line() : Figure()
{
    x2 = x + rand() % 51 - 50;
    y2 = y + rand() % 51 - 50;
    Len();
    count++;
    made++;
}

Line::Line(float x_p, float y_p, float x2_p, float y2_p) : Figure(x_p, y_p)
{
    x2 = x2_p;
    y2 = y2_p;
    Len();
    count++;
    made++;
}

void Line::setCor()
{
    Figure::setCor();
    cout << "Input end coordinates: ";
    cin >> x2 >> y2;
    cout << endl;
    Len();
}

void Line::getCor() const
{
    Figure::getCor();
    cout << "Figure end coordinates: (" << x2 << ", " << y2 << ")" << endl;
}

void Line::Len()
{
    length = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
}

void Line::getLen() const
{
    cout << "length = " << length << endl;
}

class Square : public Line
{
public:
    Square();
    Square(float, float, float, float);
    ~Square();
    void setCor();
    void setRCor();
    void getCor() const;
    void getLen() const;
    void getPerimeter() const override;
    void getArea() const override;
    void getCount() const;

protected:
    void Perimeter() override;
    void Area() override;
    float P;
    float S;

private:
    static int count;
    static int made;
};

int Square::count = 0;
int Square::made = 0;

void Square::getCount() const
{
    cout << "There're " << count << " squares exist." << endl;
    cout << "There're " << made << " squares made." << endl;
}

Square::~Square()
{
    count--;
    // delete this;
}

Square::Square() : Line()
{
    Perimeter();
    Area();
    count++;
    made++;
}
Square::Square(float x_p, float y_p, float x2_p, float y2_p) : Line(x_p, y_p, x2_p, y2_p)
{
    Perimeter();
    Area();
    count++;
    made++;
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
    cout << "Figure perimeter = " << P << endl;
}

void Square::getArea() const
{
    cout << "Figure area = " << S << endl;
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
    void getCount() const;

protected:
    void Len2();
    void Perimeter();
    void Area();
    float x3;
    float y3;
    float length2;

private:
    static int count;
    static int made;
};

int Rectangle::count = 0;
int Rectangle::made = 0;

void Rectangle::getCount() const
{
    cout << "There're " << count << " rectangles exist." << endl;
    cout << "There're " << made << " rectangles made." << endl;
}

Rectangle::~Rectangle()
{
    count--;
    // delete this;
}

Rectangle::Rectangle() : Square()
{
    x3 = x2 + rand() % 51 - 50;
    y3 = y2 + rand() % 51 - 50;
    Len2();
    count++;
    made++;
}

Rectangle::Rectangle(float x_p, float y_p, float x2_p, float y2_p, float x3_p, float y3_p) : Square(x_p, y_p, x2_p, y2_p)
{
    x3 = x3_p;
    y3 = y3_p;
    Len2();
    count++;
    made++;
}

void Rectangle::setCor()
{
    Square::setCor();
    cout << "Input second end coordinates: ";
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
    cout << "length2 = " << length2 << endl;
}

void Rectangle::getCor() const
{
    Square::getCor();
    cout << "second end coordinates: (" << x3 << ", " << y3 << ")" << endl;
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
public:
    Circle();
    Circle(float, float);
    ~Circle();
    void getPerimeter() const override;
    void getArea() const override;
    void getCount() const;

protected:
    void Perimeter() override;
    void Area() override;
    float P;
    float S;

private:
    float R;
    static int count;
    static int made;
};

int Circle::count = 0;
int Circle::made = 0;

void Circle::getCount() const
{
    cout << "There're " << count << " circles exist." << endl;
    cout << "There're " << made << " circles made." << endl;
}

Circle::~Circle()
{
    count--;
    // delete this;
}

Circle::Circle() : Figure()
{
    R = rand() % 51;
    Perimeter();
    Area();
    count++;
    made++;
}

Circle::Circle(float x_p, float y_p) : Figure(x_p, y_p)
{
    cout << "Input radius: ";
    cin >> R;
    cout << endl;
    Perimeter();
    Area();
    count++;
    made++;
}

void Circle::Perimeter()
{
    P = 2 * Pi * R;
}

void Circle::Area()
{
    P = Pi * pow(R, 2);
}

void Circle::getPerimeter() const
{
    cout << "Figure perimeter = " << P << endl;
}

void Circle::getArea() const
{
    cout << "Figure area = " << S << endl;
}

class Ellips : public Circle
{
public:
    Ellips();
    Ellips(float, float, float, float);
    ~Ellips();

protected:
    float a;
    float b;
    void Perimeter();
    void Area();
    void getCount() const;

private:
    static int count;
    static int made;
};

int Ellips::count = 0;
int Ellips::made = 0;

void Ellips::getCount() const
{
    cout << "There're " << count << " ellipses exist." << endl;
    cout << "There're " << made << " ellipses made." << endl;
}

Ellips::~Ellips()
{
    count--;
    // delete this;
}

Ellips::Ellips() : Circle()
{
    a = rand() % 51;
    b = rand() % 51;
    Perimeter();
    Area();
    count++;
    made++;
}

Ellips::Ellips(float x_p, float y_p, float a_p, float b_p) : Circle(x_p, y_p)
{
    a = a_p;
    b = b_p;
    Perimeter();
    Area();
    count++;
    made++;
}

void Ellips::Perimeter()
{
    P = 4 * ((Pi * a * b + pow(a - b, 2)) / (a + b));
}

void Ellips::Area()
{
    S = Pi * a * b;
}

int main()
{
    srand(time(NULL));

    Line L1, L2(10, 10, 20, 20);
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

    Square S1, S2(10, 10, 20, 20);
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

    cout << "\n"
         << endl;
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

    cout << "amout of rectangles after experiments: " << endl;
    R2.getCount();

    cout << "\n"
         << endl;

    Rectangle *r;

    cout << "amout of rectangles after a rectangle pointer was made: " << endl;
    R2.getCount();

    cout << endl;

    r = new Rectangle;
    cout << "amout of rectangles after a rectangle pointer after pointer = new Rectangle: " << endl;
    r->getCount();

    cout << endl;

    Figure **figures = new Figure *[4];

    figures[0] = new Square;
    figures[1] = new Rectangle;
    figures[2] = new Circle;
    figures[3] = new Ellips;

    cout << "amout of rectangles after massiv creation: " << endl;
    r->getCount();
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ") ";
        figures[i]->getPerimeter();
        cout << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        figures[i]->~Figure();
    }
    delete[] figures;

    cout << endl;

    cout << "amout of rectangles after massiv destruction: " << endl;
    r->getCount();
}
