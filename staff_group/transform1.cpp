#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Transform{
public:
    int operator()(int v){
        return v;
    }
};
class MyPrint{
public:
    void operator()(int v){
        cout<<v<<" ";
    }
};
void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int>vTarget;
    vTarget.resize(v.size());
    transform(v.begin(),v.end(),vTarget.begin(),Transform());
    for_each(vTarget.begin(),vTarget.end(),MyPrint());
    cout<<endl;

}
int main(){
    test01();
    system("pause");
    return 0;
}