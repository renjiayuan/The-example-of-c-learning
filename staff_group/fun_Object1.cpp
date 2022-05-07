#include<iostream>
using namespace std;
#include<string>

class MyAdd{
public:
    int operator()(int v1,int v2){
        return v1+v2;
    }
};
void test01(){
    MyAdd myadd;
    cout<<myadd(10,10)<<endl;
}
class MyPrint{
public:
    MyPrint(){
        this->count=0;
    }
    void operator()(string test){
        cout<<test<<endl;
        this->count++;
    }
    int count;
};
void test02(){
    MyPrint myprint;
    myprint("hello world!");
    cout<<"myPrint调用的次数为："<<myprint.count<<endl;
}
void doPrint(MyPrint &mp,string test){
    mp(test);
}
void test03(){
    MyPrint myprint;
    doPrint(myprint,"hello c++");
}
int main(){
    //test01();
    //test02();
    test03();
    system("pause");
    return 0;
}