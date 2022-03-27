#include<iostream>
#include<string>
#include <windows.h>//SetConsoleOutputCP�������ڿ⺯������cmd����ı����Ϊutf-8
using namespace std;

#define Max 1000
//�����ϵ�˵Ľṹ��
struct Person{
    //����
    string m_Name;
    //�Ա� 1 �� 2 Ů
    int m_Sex;
    //����
    int m_Age;
    //�绰
    string m_Phone;
    //סַ
    string m_Addr;
};

//���ͨѶ¼�Ľṹ��
struct Addressbooks{
    //ͨѶ¼�б������ϵ������
    struct Person personArray[Max];
    //ͨѶ¼�е�ǰ��¼��ϵ�˸���
    int m_Size;
};

//1.�����ϵ��
void addPerson(Addressbooks * Abs){
    //�ж�ͨѶ¼�Ƿ�������������˾Ͳ����
    if(Abs->m_Size==Max){
        cout<<"ͨѶ¼�������޷����"<<endl;
        return ;
    }else{
        //�����ϵ��
        //����
        string name;
        cout<<"������������"<<endl;
        cin>>name;
        Abs->personArray[Abs->m_Size].m_Name=name;
        //�Ա� 1 �� 2 Ů
        cout<<"�������Ա�"<<endl;
        cout<<"1 --- ��"<<endl;
        cout<<"2 --- Ů"<<endl;
        int sex = 0;
        while(true){
            cin>>sex;
            if(sex==1||sex==2){
                Abs->personArray[Abs->m_Size].m_Sex=sex;
                break;
            }else{
                cout<<"������������������:"<<endl;
            }
        }
        //����
        cout<<"���������䣺"<<endl;
        int age=0;
        cin>>age;
        Abs->personArray[Abs->m_Size].m_Age=age;
        //�绰
        cout<<"��������ϵ�绰��"<<endl;
        string phone;
        cin>>phone;
        Abs->personArray[Abs->m_Size].m_Phone=phone;
        //סַ
        cout<<"�������ͥ��ַ��"<<endl;
        string address;
        cin>>address;
        Abs->personArray[Abs->m_Size].m_Addr=address;

        //����ͨѶ¼�е�����
        Abs->m_Size++;

        cout<<"��ӳɹ���"<<endl;

        system("pause");//�밴���������
        system("cls");//��������
    }
}

//2.��ʾ��ϵ��
void showPerson(Addressbooks * Abs){
    //�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
    //�����Ϊ0����ʾ��¼����ϵ����Ϣ
    if(Abs->m_Size==0){
        cout<<"��ǰ��¼Ϊ��"<<endl;
    }else{
        for(int i=0;i<Abs->m_Size;i++){
            cout<<"������"<<Abs->personArray[i].m_Name<<"\t";
            cout<<"�Ա�"<<(Abs->personArray[i].m_Sex == 1 ? "��":"Ů")<<"\t";
            cout<<"���䣺"<<Abs->personArray[i].m_Age<<"\t";
            cout<<"�绰��"<<Abs->personArray[i].m_Phone<<"\t";
            cout<<"סַ��"<<Abs->personArray[i].m_Addr<<endl;
        }
    }
    system("pause");
    system("cls");
}

//�����ϵ���Ƿ���ڣ����ڷ�����ϵ�˵�λ�ã������ڷ���-1
int isExist(Addressbooks *Abs,string name){
    for(int i=0;i<Abs->m_Size;i++){
        //�ҵ��û����������
        if(Abs->personArray[i].m_Name == name){
            return i;
        }
    }
    return -1;//û���ҵ��û����������
}

//3.ɾ��ָ������ϵ��
void deletePerson(Addressbooks * Abs){
    cout<<"��������Ҫɾ������ϵ�ˣ�"<<endl;
    string name;
    cin>>name;
    int ret=isExist(Abs,name);
    if(ret!=-1){
        //�鵽���ˣ�������ɾ��
        for(int i=ret;i<Abs->m_Size-1;i++){
            Abs->personArray[i]=Abs->personArray[i+1];//����ǰ��
        }
        Abs->m_Size--;
        cout<<"ɾ���ɹ���"<<endl;
    }else{
        cout<<"���޴���"<<endl;
    }
    system("pause");
    system("cls");
}

//4.����ָ����ϵ����Ϣ
void findPerson(Addressbooks * Abs){
    cout<<"��������Ҫ���ҵ���ϵ�ˣ�"<<endl;
    string name;
    cin>>name;

    int ret=isExist(Abs,name);
    if(ret!=-1){
        cout<<"������"<<Abs->personArray[ret].m_Name<<"\t";
        cout<<"�Ա�"<<(Abs->personArray[ret].m_Sex == 1 ? "��":"Ů")<<"\t";
        cout<<"���䣺"<<Abs->personArray[ret].m_Age<<"\t";
        cout<<"�绰��"<<Abs->personArray[ret].m_Phone<<"\t";
        cout<<"סַ��"<<Abs->personArray[ret].m_Addr<<endl;
    }else{
        cout<<"���޴��ˣ�"<<endl;
    }
    
    system("pause");
    system("cls");
}

//5.�޸�ָ����ϵ�˵���Ϣ
void modifyPerson(Addressbooks * Abs){
    cout<<"��������Ҫ�޸ĵ���ϵ�ˣ�"<<endl;
    string name;
    cin>>name;

    int ret=isExist(Abs,name);
    if(ret!=-1){
        //����
        cout<<"����������������"<<endl;
        string name;
        cin>>name;
        Abs->personArray[ret].m_Name=name;
        //�Ա� 1 �� 2 Ů
        cout<<"�����������Ա�"<<endl;
        cout<<"1 --- ��"<<endl;
        cout<<"2 --- Ů"<<endl;
        int sex = 0;
        while(true){
            cin>>sex;
            if(sex==1||sex==2){
                Abs->personArray[ret].m_Sex=sex;
                break;
            }else{
                cout<<"������������������:"<<endl;
            }
        }
        //����
        cout<<"�������������䣺"<<endl;
        int age=0;
        cin>>age;
        Abs->personArray[ret].m_Age=age;
        //�绰
        cout<<"������������ϵ�绰��"<<endl;
        string phone;
        cin>>phone;
        Abs->personArray[ret].m_Phone=phone;
        //סַ
        cout<<"�����������ͥ��ַ��"<<endl;
        string address;
        cin>>address;
        Abs->personArray[ret].m_Addr=address;
        
    }else{
        cout<<"���޴��ˣ�"<<endl;
    }

    system("pause");
    system("cls");
}

//6.�����ϵ��
void cleanPerson(Addressbooks * Abs){
    Abs->m_Size=0;//����ǰͨѶ¼��������
    cout<<"ͨѶ¼�Ѿ���գ�"<<endl;
    system("pause");
    system("cls");
}

//�˵�����
void showMenu(){
    cout<<"*****************************"<<endl;
    cout<<"*****   1�������ϵ��   *****"<<endl;
    cout<<"*****   2����ʾ��ϵ��   *****"<<endl;
    cout<<"*****   3��ɾ����ϵ��   *****"<<endl;
    cout<<"*****   4��������ϵ��   *****"<<endl;
    cout<<"*****   5���޸���ϵ��   *****"<<endl;
    cout<<"*****   6�������ϵ��   *****"<<endl;
    cout<<"*****   0���˳�ͨѶ¼   *****"<<endl;
    cout<<"*****************************"<<endl;
}

int main(){
    //SetConsoleOutputCP(65001);
    //����ͨѶ¼�ṹ�����
    struct Addressbooks Abs;
    //��ϵ��������ʼ��
    Abs.m_Size=0;
    
    int select = 0;//����һ���û�ѡ������ı���

    while(true){
        //�˵�����
        showMenu();
        cout<<"����������Ҫʹ�õĹ��ܴ��ţ�"<<endl;
        cin>>select;

        switch(select){
            case 1://1�������ϵ��
                addPerson(&Abs);//���õ�ַ�����޸�ʵ��
                break;
            case 2://2����ʾ��ϵ��
                showPerson(&Abs);
                break;
            case 3://3��ɾ����ϵ��
                deletePerson(&Abs);
                break;
            case 4://4��������ϵ��
                findPerson(&Abs);
                break;
            case 5://5���޸���ϵ��
                modifyPerson(&Abs);
                break;
            case 6://6�������ϵ��
                cleanPerson(&Abs);
                break;
            case 0://0���˳�ͨѶ¼
                cout<<"��ӭ�´�ʹ�ã�"<<endl;
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