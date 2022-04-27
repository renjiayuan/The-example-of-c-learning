#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>


class Person{
public:
    Person(string name,int score){
        this->m_Name=name;
        this->m_Score=score;
    }
    string m_Name;
    int m_Score;
};
void createPerson(vector<Person>&v){
    string nameSeed="ABCDE";
    for(int i=0;i<5;i++){
        string name="player:";
        name+=nameSeed[i];
        int score=0;
        Person p(name,score);
        v.push_back(p);
    }
}
void setScore(vector<Person>&v){
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        //将评委的分数放入deque容器中
        deque<int>d;
        for(int i=0;i<10;i++){
            int score = rand()%41+60;
            d.push_back(score);
        }
        // cout<<it->m_Name<<" 打分："<<endl;
        // for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
        //     cout<<*dit<<" ";
        // }
        // cout<<endl;
        sort(d.begin(),d.end());
        d.pop_back();
        d.pop_front();
        int sum=0;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
            sum+=*dit;
        }
        int avg=sum/d.size();
        it->m_Score=avg;
    }
}
void showScore(vector<Person>&v){
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        cout<<it->m_Name<<" score:"<<it->m_Score<<endl;
    }
}
int main(){
    //随机数种子
    srand((unsigned int)time(NULL));
    //1.创建五名选手
    vector<Person>v;//存放选手容器
    createPerson(v);
    //2.给5名选手打分
    setScore(v);
    //3.显示最后得分
    showScore(v);
    system("pause");
    return 0;
}