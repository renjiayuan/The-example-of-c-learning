#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class Employee : public Worker{
public:
    Employee(int id,string name,int dId);
    //��ʾ������Ϣ
    virtual void showInfo();
    //��ȡ��λ����
    virtual string getDeptName();
};