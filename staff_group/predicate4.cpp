#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>

class MyCompare{
public:
    bool operator()(int val1,int val2){
        return val1>val2;
    }
};
//大于 greater
void test01(){
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    // sort(v.begin(),v.end(),MyCompare());
    // cout<<"-----------"<<endl;
    // for(vector<int>::iterator it=v.begin();it!=v.end();it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    sort(v.begin(),v.end(),greater<int>());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}