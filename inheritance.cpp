#include"iostream"

class Base{
    public:
    virtual void Display() const = 0;
    virtual ~Base(){std::cout<<"Base destructor!!!";}
    //Making it an abstract class
};

class Derived1 : public Base{
    public:
    Derived1(int i): Number(i){}
    void Display() const override{
        std::cout<<"Number = "<<Number<<std::endl;
    }
    ~Derived1(){std::cout<<"Derived1";}
    private:
    int Number;
};

class Derived2: public Base{
    public:
    Derived2(std::string s): prompt(s){} 
    void Display() const override{
        std::cout<<"Prompt="<<prompt<<std::endl;
    }
    ~Derived2(){std::cout<<"Derived2";}
    private:
    const std::string prompt;
};


int main(){
    std::cout<<"Hi Sumit"<<std::endl;
    Derived1 d1(100);
    d1.Display();
    Derived2 d2("Hello There!!!");
    d2.Display();
    return 0;
}