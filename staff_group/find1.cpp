#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int>::iterator it=find(v.begin(),v.end(),5);
    if(it==v.end()){
        cout<<"don't have!";
    }
    else{
        cout<<"Yes, "<<*it<<endl;
    }
}
class Person{
public:
    Person(string name,int age){
        this->m_Name=name;
        this->m_Age=age;
    }
    string  m_Name;
    int m_Age;
};
void test02(){
    vector<Person> v;
    Person p1("a",10);
    Person p2("b",20);
    Person p3("c",30);
    Person p4("d",40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator it=find(v.begin(),v.end(),p2);
    if(it==v.end()){
        cout<<"don't have"<<endl;
    }else{
        cout<<"Yes, name is "<<it->m_Name<<", age is "<<it->m_Age<<endl;
    }
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}