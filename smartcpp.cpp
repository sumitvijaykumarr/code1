#include"iostream"
#include"string"
#include"memory"

class MyClass{
    private:
    int roll_no;
    double score;
    std::string name;
    int* ptr;
    std::unique_ptr<double> uniqptr;
    
    public:
    MyClass(int i, double d, const std::string &s):roll_no(i), score(d), name(s){
        ptr = new int(i);
        uniqptr = std::make_unique<double>(d);
    }
    //DeepCopy constructor
    MyClass(const MyClass& other): roll_no(other.roll_no), score(other.score), name(other.name){
        if(other.ptr){
            ptr = *(other.ptr);
        }
        if(other.uniqptr){
            uniqptr = std::make_unique<double>(*other.uniqptr);
        }
    }


    ~MyClass(){
        delete ptr;
    }
    void Display(){
        std::cout<<"roll_no ="<<roll_no<<std::endl;
        std::cout<<"score ="<<score<<std::endl;
        std::cout<<"Name="<<name<<std::endl;
        std::cout<<"*ptr = "<<*ptr<<std::endl;
        std::cout<<"ptr = "<<ptr<<std::endl;
        std::cout<<"*unique_ptr="<<*uniqptr<<std::endl;
        // std::cout<<"unique_ptr="<<uniqptr<<std::endl;
        //It does not work!!!!!!!!
        
        // std::cout<<roll_no = <<"i";
        // std::cout<<score = <<"d";
        // std::cout<<name = <<"s";
    }
};

int main(){
    std::cout<<"Hi";
    MyClass obj1(31, 7.71, "sumit_nimje");
    MyClass obj2=obj1;
    obj1.Display();
    std::cout<<"**********"<<std::endl;
    obj2.Display();
    return 0;
}