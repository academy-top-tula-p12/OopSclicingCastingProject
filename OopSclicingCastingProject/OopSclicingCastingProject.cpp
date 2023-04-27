#include <iostream>

using namespace std;

class Base
{
protected:
    int value;
public:
    Base(int value) : value{ value } {}
    virtual string Name() const { return "Base"; }
    int Value() const { return value; }
};

class Derived : public Base
{
    string str;
public:
    Derived(int value, string str) : Base(value), str{ str } {}
    string Name() const override { return "Derived"; }
    string Str() { return str; }
};

Base* GetObject(bool flag)
{
    if (flag)
        return new Derived(100, "Hello");
    else
        return new Base(200);
}

int main()
{
    // Objects Slicing

    /*Base* base = new Derived(100);
    cout << base->Name() << " " << base->Value() << "\n";

    Derived derived(50);
    cout << derived.Name() << " " << derived.Value() << "\n";

    Base& baseRef = derived;
    cout << baseRef.Name() << " " << baseRef.Value() << "\n";

    Base baseObj = derived;
    cout << baseObj.Name() << " " << baseObj.Value() << "\n";*/



    // Dynamic Cast
    //Base* b = (Derived*)GetObject(true);
    cout << dynamic_cast<Derived*>(GetObject(true))->Str();
    
}
