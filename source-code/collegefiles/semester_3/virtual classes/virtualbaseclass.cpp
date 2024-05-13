#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class base
{
public:
    virtual void show()
    {
        cout << "Accessed via base class" << endl;
    }
};

class drv1 : public virtual base
{
public:
    virtual void show()
    {
        cout << "Accessed via derrived class 1" << endl;
    }
};

class drv2 : public virtual base
{
public:
    virtual void show()
    {
        cout << "Accessed via derrived class 2" << endl;
    }
};

class drv3 : public drv1, public drv2
{
public:
    virtual void show() override
    {
        cout << "Accessed via derrived class 3" << endl;
    }
};

int main()
{
    base base_obj;
    drv1 derrived1;
    drv2 derrived2;
    drv3 derrived3;

    base_obj.show();

    derrived1.show();
    derrived2.show();
    derrived3.show();
}