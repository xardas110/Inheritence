
#include <iostream>
#include <memory>

class Base : public std::enable_shared_from_this<Base>
{
public:
    Base()
        :a(1), b(2), c(3)
    {}
    int a, b, c;
    virtual void Test()
    {
        std::cout << "hey from base" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived operator=(Base copy)
    {
        //Base::a = copy.a;
        //Base::b = copy.b;
        return *this;
    }

    /*
   std::shared_ptr<Derived> operator=(std::shared_ptr < Base > copy)
    {
        a = copy->a;
        b = copy->b;
        c = copy->c;
        return std::shared_ptr < Derived>( this);
    }
    */
    int d;
    virtual void Test()override
    {
        std::cout << "from derived hey" << std::endl;
    }
};


int main()
{
 
    std::shared_ptr<Base> b(new Base());
   // b = std::shared_ptr<Base>(new Derived());
    //std::shared_ptr<Derived> a = std::dynamic_pointer_cast<Derived>(b);
    //har bare lyst at a sin base skal bli som b, prøvd me operators, men har ikke funnet løsning
    std::shared_ptr<Derived> a = b;
    if (a)
        a->Test();
    else
    { 
        std::cout << "nullptr" << std::endl;
        return 1;
    }

    std::cout << a->a;
}

