#include <iostream>

using namespace std;

class Abc{
public:
Abc(){
cout<<"hi  i am abc constructor\n"<<endl;
}
};

class Efg{
public:
Efg(){
cout<<"hi  i am Efg constructor\n"<<endl;
}
};

class Hij:public Efg,public Abc{
public:
Hij(){
cout<<"hi  i am Hij constructor\n"<<endl;
}
};

int main()
{
    Hij object;
    return 0;
}
