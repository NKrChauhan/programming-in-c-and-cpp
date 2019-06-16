#include <iostream>

using namespace std;
template <class Second,class Third>
Third smaller(Second a, Third b){
return (a<b?a:b);
}
int main()
{
    cout << "Hello world!" << endl;
    int a=23;
    float b=2.1;
    cout << smaller(a,b) <<endl;
    return 0;
}
