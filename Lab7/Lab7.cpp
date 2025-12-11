#include <iostream>

using namespace std;

template <typename Type>
class Element
{
public:
    Element(Type p_data) : data(p_data), next(NULL) {}
    void setData(Type new_data)
    {
        data = new_data;
    }

    void setNext(Element *new_next)
    {
        next = new_next;
    }

    Type getData() const
    {
        return data;
    }

    Element *getNext() const
    {
        return next;
    }

protected:
    Type data;
    Element *next;
};

//-----------------------------------------------------------------------------------------------------------

template <typename Type>
class List
{
public:
    List() : head(NULL), tail(NULL) {}

    virtual ~List()
    {
        Element<Type> *p = head;
        while (p != NULL)
        {
            Element<Type> *nextElement = p->getNext();
            delete p;
            p = nextElement;
        }
    }

    virtual void Add(Type new_element) = 0;

    Type getSum() const
    {
        Type sum = 0;
        Element<Type> *p = head;
        while (p != NULL)
        {
            sum += p->getData();
            p = p->getNext();
        }
        return sum;
    }
    void print() const
    {
        Element<Type> *p = head;
        while (p != NULL)
        {
            cout << p->getData() << "   ";
            p = p->getNext();
        }
    }

    void setValue(Type new_value, int index)
    {
        int i = 0;
        Element<Type> *p = head;
        while (i != index)
        {
            if (p != NULL)
            {
                p = p->getNext();
                i++;
            }
            else
            {
                throw "ERROR! Element with this index is absent in the list.";
            }
        }
        p->setData(new_value);
    }

    Type getValue(int index) const
    {
        int i = 0;
        Element<Type> *p = head;
        while (i != index)
        {
            if (p != NULL)
            {
                p = p->getNext();
                i++;
            }
            else
            {
                throw "ERROR! Element with this index is absent in the list.";
            }
        }
        return p->getData();
    }

protected:
    Element<Type> *head;
    Element<Type> *tail;
};

//-----------------------------------------------------------------------------------------------------------------------------

template <typename Type>
class Stack : public List<Type>
{
public:
    void Add(Type new_element) override
    {
        Element<Type> *p = new Element<Type>(new_element);
        p->setData(new_element);
        p->setNext(this->head);
        this->head = p;
    }
};

template <typename Type>
class Queque : public List<Type>
{
public:
    void Add(Type new_element) override
    {
        Element<Type> *p = new Element<Type>(new_element);
        if (this->tail == NULL)
        {
            this->head = this->tail = p;
        }
        else
        {
            p->setData(new_element);
            this->tail->setNext(p);
            this->tail = p;
        }
        this->tail->setNext(NULL);
    }
};

//-----------------------------------------------------------------------------------------------------------------

int main()
{
    cout << "\n"
         << endl;
    Stack<int> stack;
    stack.Add(10);
    stack.Add(20);
    stack.Add(30);
    cout << "Stack: ";
    stack.print();
    cout << endl
         << "Sum: "
         << stack.getSum() << endl;
    cout << "\n"
         << endl;

    Queque<double> queque;
    queque.Add(7.4);
    queque.Add(6.3);
    queque.Add(9.8);
    queque.Add(2.28);
    queque.Add(5.5);
    cout << "Queque: ";
    queque.print();
    cout << endl
         << "Sum: "
         << queque.getSum() << endl;

    cout << "\n"
         << endl;

    cout << "Try to get value of the cell number 4 in the stack: " << endl;

    try
    {
        cout << stack.getValue(4) << endl;
    }
    catch (const char *error_message)
    {
        cout << error_message << endl;
    }

    cout << "\n"
         << endl;

    cout << "Try to get value of the cell number 4 in the queque: " << endl;
    try
    {
        cout << queque.getValue(4) << endl;
    }
    catch (const char *error_message)
    {
        cout << error_message << endl;
    }

    cout << "\n"
         << endl;

    cout << "Try to get value of the cell number 7 in the queque: " << endl;
    try
    {
        cout << queque.getValue(7) << endl;
    }
    catch (const char *error_message)
    {
        cout << error_message << endl;
    }

    cout << "\n"
         << endl;
}
