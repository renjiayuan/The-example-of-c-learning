#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
using namespace std;

#define FILENAME "empFile.txt"
class WorkManager{
public:

    WorkManager();

    //չʾ�˵�
    void Show_Menu();

    //�˳�ϵͳ
    void ExitSystem();

    //��¼Ա������
    int m_EmpNum;

    //ְ������ָ��
    Worker ** m_EmpArray;

    //���ְ��
    void Add_Emp();

    //�����ļ�
    void save();

    //�ж��ļ��Ƿ�Ϊ��
    bool m_FileIsEmpty;
    
    //ͳ���ļ�������
    int get_EmpNum();

    //��ʼ��Ա��
    void init_Emp();

    //��ʾְ��
    void Show_Emp();

    //ɾ��Ա��
    void Del_Emp();
    //Ա���Ƿ����,����Ա����λ��
    int IsExist(int id);

    //�޸�ְ��
    void Mod_Emp();

    //����Ա��
    void Find_Emp();

    //����
    void Sort_Emp();

    //����ļ�
    void Clean_File();
    ~WorkManager();
};