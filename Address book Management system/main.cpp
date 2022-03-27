#include<iostream>
#include<string>
#include <windows.h>//SetConsoleOutputCP函数所在库函数，让cmd程序的编码更为utf-8
using namespace std;

#define Max 1000
//设计联系人的结构体
struct Person{
    //姓名
    string m_Name;
    //性别 1 男 2 女
    int m_Sex;
    //年龄
    int m_Age;
    //电话
    string m_Phone;
    //住址
    string m_Addr;
};

//设计通讯录的结构体
struct Addressbooks{
    //通讯录中保存的联系人数组
    struct Person personArray[Max];
    //通讯录中当前记录联系人个数
    int m_Size;
};

//1.添加联系人
void addPerson(Addressbooks * Abs){
    //判断通讯录是否已满，如果满了就不添加
    if(Abs->m_Size==Max){
        cout<<"通讯录已满，无法添加"<<endl;
        return ;
    }else{
        //添加联系人
        //姓名
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        Abs->personArray[Abs->m_Size].m_Name=name;
        //性别 1 男 2 女
        cout<<"请输入性别："<<endl;
        cout<<"1 --- 男"<<endl;
        cout<<"2 --- 女"<<endl;
        int sex = 0;
        while(true){
            cin>>sex;
            if(sex==1||sex==2){
                Abs->personArray[Abs->m_Size].m_Sex=sex;
                break;
            }else{
                cout<<"输入有误，请重新输入:"<<endl;
            }
        }
        //年龄
        cout<<"请输入年龄："<<endl;
        int age=0;
        cin>>age;
        Abs->personArray[Abs->m_Size].m_Age=age;
        //电话
        cout<<"请输入联系电话："<<endl;
        string phone;
        cin>>phone;
        Abs->personArray[Abs->m_Size].m_Phone=phone;
        //住址
        cout<<"请输入家庭地址："<<endl;
        string address;
        cin>>address;
        Abs->personArray[Abs->m_Size].m_Addr=address;

        //更新通讯录中的人数
        Abs->m_Size++;

        cout<<"添加成功！"<<endl;

        system("pause");//请按任意键继续
        system("cls");//清屏操作
    }
}

//2.显示联系人
void showPerson(Addressbooks * Abs){
    //判断通讯录中人数是否为0，如果为0，提示记录为空
    //如果不为0，显示记录的联系人信息
    if(Abs->m_Size==0){
        cout<<"当前记录为空"<<endl;
    }else{
        for(int i=0;i<Abs->m_Size;i++){
            cout<<"姓名："<<Abs->personArray[i].m_Name<<"\t";
            cout<<"性别："<<(Abs->personArray[i].m_Sex == 1 ? "男":"女")<<"\t";
            cout<<"年龄："<<Abs->personArray[i].m_Age<<"\t";
            cout<<"电话："<<Abs->personArray[i].m_Phone<<"\t";
            cout<<"住址："<<Abs->personArray[i].m_Addr<<endl;
        }
    }
    system("pause");
    system("cls");
}

//检测联系人是否存在，存在返回联系人的位置，不存在返回-1
int isExist(Addressbooks *Abs,string name){
    for(int i=0;i<Abs->m_Size;i++){
        //找到用户输入的姓名
        if(Abs->personArray[i].m_Name == name){
            return i;
        }
    }
    return -1;//没有找到用户输入的姓名
}

//3.删除指定的联系人
void deletePerson(Addressbooks * Abs){
    cout<<"输入您想要删除的联系人："<<endl;
    string name;
    cin>>name;
    int ret=isExist(Abs,name);
    if(ret!=-1){
        //查到此人，并进行删除
        for(int i=ret;i<Abs->m_Size-1;i++){
            Abs->personArray[i]=Abs->personArray[i+1];//数据前移
        }
        Abs->m_Size--;
        cout<<"删除成功！"<<endl;
    }else{
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls");
}

//4.查找指定联系人信息
void findPerson(Addressbooks * Abs){
    cout<<"请输入您要查找的联系人："<<endl;
    string name;
    cin>>name;

    int ret=isExist(Abs,name);
    if(ret!=-1){
        cout<<"姓名："<<Abs->personArray[ret].m_Name<<"\t";
        cout<<"性别："<<(Abs->personArray[ret].m_Sex == 1 ? "男":"女")<<"\t";
        cout<<"年龄："<<Abs->personArray[ret].m_Age<<"\t";
        cout<<"电话："<<Abs->personArray[ret].m_Phone<<"\t";
        cout<<"住址："<<Abs->personArray[ret].m_Addr<<endl;
    }else{
        cout<<"查无此人！"<<endl;
    }
    
    system("pause");
    system("cls");
}

//5.修改指定联系人的信息
void modifyPerson(Addressbooks * Abs){
    cout<<"请输入您要修改的联系人："<<endl;
    string name;
    cin>>name;

    int ret=isExist(Abs,name);
    if(ret!=-1){
        //姓名
        cout<<"请重新输入姓名："<<endl;
        string name;
        cin>>name;
        Abs->personArray[ret].m_Name=name;
        //性别 1 男 2 女
        cout<<"请重新输入性别："<<endl;
        cout<<"1 --- 男"<<endl;
        cout<<"2 --- 女"<<endl;
        int sex = 0;
        while(true){
            cin>>sex;
            if(sex==1||sex==2){
                Abs->personArray[ret].m_Sex=sex;
                break;
            }else{
                cout<<"输入有误，请重新输入:"<<endl;
            }
        }
        //年龄
        cout<<"请重新输入年龄："<<endl;
        int age=0;
        cin>>age;
        Abs->personArray[ret].m_Age=age;
        //电话
        cout<<"请重新输入联系电话："<<endl;
        string phone;
        cin>>phone;
        Abs->personArray[ret].m_Phone=phone;
        //住址
        cout<<"请重新输入家庭地址："<<endl;
        string address;
        cin>>address;
        Abs->personArray[ret].m_Addr=address;
        
    }else{
        cout<<"查无此人！"<<endl;
    }

    system("pause");
    system("cls");
}

//6.清空联系人
void cleanPerson(Addressbooks * Abs){
    Abs->m_Size=0;//将当前通讯录人数清零
    cout<<"通讯录已经清空！"<<endl;
    system("pause");
    system("cls");
}

//菜单界面
void showMenu(){
    cout<<"*****************************"<<endl;
    cout<<"*****   1、添加联系人   *****"<<endl;
    cout<<"*****   2、显示联系人   *****"<<endl;
    cout<<"*****   3、删除联系人   *****"<<endl;
    cout<<"*****   4、查找联系人   *****"<<endl;
    cout<<"*****   5、修改联系人   *****"<<endl;
    cout<<"*****   6、清空联系人   *****"<<endl;
    cout<<"*****   0、退出通讯录   *****"<<endl;
    cout<<"*****************************"<<endl;
}

int main(){
    //SetConsoleOutputCP(65001);
    //创建通讯录结构体变量
    struct Addressbooks Abs;
    //联系人数量初始化
    Abs.m_Size=0;
    
    int select = 0;//创建一个用户选择输入的变量

    while(true){
        //菜单调用
        showMenu();
        cout<<"请输入您需要使用的功能代号："<<endl;
        cin>>select;

        switch(select){
            case 1://1、添加联系人
                addPerson(&Abs);//利用地址传递修改实参
                break;
            case 2://2、显示联系人
                showPerson(&Abs);
                break;
            case 3://3、删除联系人
                deletePerson(&Abs);
                break;
            case 4://4、查找联系人
                findPerson(&Abs);
                break;
            case 5://5、修改联系人
                modifyPerson(&Abs);
                break;
            case 6://6、清空联系人
                cleanPerson(&Abs);
                break;
            case 0://0、退出通讯录
                cout<<"欢迎下次使用！"<<endl;
                system("pause");
                return 0;
                break;
            default:
                break;
        }
    }
    
    system("pause");
    return 0;
}