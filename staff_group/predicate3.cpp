#include<iostream>
using namespace std;
#include<functional>

//negate һԪ�º��� ȡ��
void test01(){
    negate<int>n;
    cout<<n(50)<<endl;
}
//plus ��Ԫ�º��� �ӷ�
void test02(){
    plus<int>p;
    cout<<p(10,20)<<endl;
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}