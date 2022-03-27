#include "workerManager.h"

WorkManager::WorkManager(){
    //1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        //cout<<"文件不存在"<<endl;
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        this->m_FileIsEmpty= true;
        ifs.close();
        return;
    }
    //2.文件存在但为空
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        //cout<<"文件为空"<<endl;
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        this->m_FileIsEmpty= true;
        ifs.close();
        return;
    }
    //3.文件存在，并且记录数据
    int num=this->get_EmpNum();
    // cout<<"员工人数为："<<num<<endl;
    this->m_EmpNum=num;
    this->m_EmpArray=new Worker *[this->m_EmpNum];//开辟空间
    this->init_Emp();
    this->m_FileIsEmpty=false;
    // for(int i=0;i<this->m_EmpNum;i++){
    //     cout<<"职工编号："<<this->m_EmpArray[i]->m_Id
    //         <<"\t姓名："<<this->m_EmpArray[i]->m_Name
    //         <<"\t部门编号"<<this->m_EmpArray[i]->m_DeptId<<endl;
    // }
}
//展示菜单
void WorkManager::Show_Menu(){
    cout<<"***************************************"<<endl;
    cout<<"**********欢迎使用职工管理系统**********"<<endl;
    cout<<"**********   0.退出管理程序   **********"<<endl;
    cout<<"**********   1.增加职工信息   **********"<<endl;
    cout<<"**********   2.显示职工信息   **********"<<endl;
    cout<<"**********   3.删除离职职工   **********"<<endl;
    cout<<"**********   4.修改职工信息   **********"<<endl;
    cout<<"**********   5.查找职工信息   **********"<<endl;
    cout<<"**********   6.按照编号排序   **********"<<endl;
    cout<<"**********   7.清空所有文档   **********"<<endl;
    cout<<"***************************************"<<endl;
    cout<<endl;
}
//退出系统
void WorkManager::ExitSystem(){
    cout<<"欢迎下次使用!"<<endl;
    system("pause");
    exit(0);//退出程序
}
//添加职工
void WorkManager::Add_Emp(){
    cout<<"请输入添加员工数量："<<endl;
    int addNum;
    cin>>addNum;
    if(addNum>0){
        //计算添加新空间大小，相当于重新分配一些空间
        int newSize=this->m_EmpNum+addNum;//新空间人数=原来记录人数+新增人数
        //开辟新空间
        Worker ** newSpace=new Worker*[newSize];
        //将原来空间下数据拷贝到新空间下
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                newSpace[i]=this->m_EmpArray[i];
            }
        }
        //批量添加新数据
        for(int i=0;i<addNum;i++){
            int id;
            string name;
            int dSelect;
            cout<<"请输入第"<<i+1<<"个新员工编号："<<endl;
            cin>>id;
            cout<<"请输入第"<<i+1<<"个新员工姓名："<<endl;
            cin>>name;
            cout<<"请输入第"<<i+1<<"个新员工岗位："<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、老板"<<endl;
            cin>>dSelect;
            
            Worker * worker = NULL;
            switch(dSelect){
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker = new Manager(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
                    break;
                default:
                    break;
            }
            //将创建职工保存到数组中
            newSpace[this->m_EmpNum+i]=worker;
        }
        //释放原有空间
        delete [] this->m_EmpArray;
        //更改新空间指向
        this->m_EmpArray=newSpace;
        //更新职工人数
        this->m_EmpNum=newSize;
        this->save();
        //提示添加成功
        cout<<"成功添加"<<addNum<<"名新职工"<<endl;
        this->m_FileIsEmpty=false;//更新标志不为空
    }else{
        cout<<"输入数据有误！"<<endl;
    }
    system("pause");
    system("cls");
}
//保存文件
void WorkManager::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    //将每个人的数据都写入到文件中
    for(int i=0;i<this->m_EmpNum;i++){
        ofs<<this->m_EmpArray[i]->m_Id<<" "
            <<this->m_EmpArray[i]->m_Name<<" "
            <<this->m_EmpArray[i]->m_DeptId<<endl;
    }
    //关闭文件
    ofs.close();
}
//统计文件中的人数
int WorkManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//读
    int id;
    string name;
    int dId;
    int num=0;
    while(ifs>>id&&ifs>>name&&ifs>>dId){
        num++;
    }
    ifs.close();
    return num;
}
//初始化员工
void WorkManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;

    int index=0;
    while (ifs>>id&&ifs>>name&&ifs>>dId)
    {
        Worker * worker = NULL;
        if(dId==1){//普通员工
            worker=new Employee(id,name,dId);
        }else if(dId==2){//经理
            worker=new Manager(id,name,dId);
        }else if(dId==3){//老板
            worker = new Boss(id,name,dId);
        }
        this->m_EmpArray[index]=worker;
        index++;
    }
    ifs.close();
}
//显示职工
void WorkManager::Show_Emp(){
    //判断文件是否为空
    if(this->m_FileIsEmpty){
        cout<<"文件不存在或者记录为空"<<endl;
    }else{
        for(int i=0;i<m_EmpNum;i++){
            //利用多态调用程序接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}
//删除员工
void WorkManager::Del_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"文件不存在！"<<endl;
    }else{
        cout<<"请输入需要删除的职工编号："<<endl;
        int id=0;
        cin>>id;
        int index=this->IsExist(id);
        if(index!=-1){
            for(int i=index;i<this->m_EmpNum-1;i++){
                this->m_EmpArray[i]=this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;
            this->save();//数据同步到文件中
            cout<<"删除成功！"<<endl;
            if(this->m_EmpNum==0){
                this->m_FileIsEmpty=true;
            }
        }else{
            cout<<"删除失败，未找到员工！"<<endl;
        }
    }
    system("pause");
    system("cls");
}
//员工是否存在,返回员工的位置
int WorkManager::IsExist(int id){
    int index=-1;
    for(int i=0;i<this->m_EmpNum;i++){
        if(id==this->m_EmpArray[i]->m_Id){
            index=i;
            break;
        }
    }
    return index;
}
//修改职工
void WorkManager::Mod_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"文件不存在或者记录为空！"<<endl;
    }else{
        cout<<"请输入修改职工编号："<<endl;
        int id;
        cin>>id;
        int ret=this->IsExist(id);
        if(ret!=-1){
            //找到职工的编号
            delete this->m_EmpArray[ret];
            int newId=0;
            string newName="";
            int newDSelect=0;
            cout<<"查到："<<id<<"号员工，请输入新职工号："<<endl;
            cin>>newId;
            cout<<"请输入新姓名："<<endl;
            cin>>newName;
            cout<<"请输入员工新岗位："<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、老板"<<endl;
            cin>>newDSelect;
            
            Worker * worker = NULL;
            switch(newDSelect){
                case 1:
                    worker = new Employee(newId,newName,1);
                    break;
                case 2:
                    worker = new Manager(newId,newName,2);
                    break;
                case 3:
                    worker = new Boss(newId,newName,3);
                    break;
                default:
                    break;
            }
            this->m_EmpArray[ret]=worker;
            cout<<"修改成功！";
            this->save();
        }else{
            cout<<"查无此人！"<<endl;
        }
    }
    system("pause");
    system("cls");
}
//查找员工
void WorkManager::Find_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"文件不存在或者记录为空！"<<endl;
    }else{
        cout<<"请输入查找的方式："<<endl;
        cout<<"1.按员工编号进行查找："<<endl;
        cout<<"2.按员工姓名进行查找："<<endl;
        int select=0;
        cin>>select;

        if(select==1){
            //按编号进行查找
            int id;
            cout<<"请输入查找的职工编号："<<endl;
            cin>>id;
            int ret=this->IsExist(id);
            if(ret!=-1){
                cout<<"查找成功！该员工信息如下："<<endl;
                this->m_EmpArray[ret]->showInfo();
            }else{
                cout<<"查找失败！查无此人"<<endl;
            }
        }else if(select==2){
            //按照姓名进行查找
            string name;
            bool flag=false;//判断是否查到
            cout<<"请输入查找的姓名:"<<endl;
            cin>>name;
            for(int i=0;i<this->m_EmpNum;i++){
                if(this->m_EmpArray[i]->m_Name==name){
                    cout<<"查找成功！职工信息如下："<<endl;
                    this->m_EmpArray[i]->showInfo();
                    flag=true;
                }
            } 
            if(flag==false){
                cout<<"查找失败！"<<endl;
            }
        }else{
            cout<<"输入选项有误！"<<endl;
        }
    }
    system("pause");
    system("cls");
}
//排序
void WorkManager::Sort_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"文件不存在或者记录为空！"<<endl;
        system("pause");
        system("cls");
    }else{
        cout<<"请选择排序的方式！"<<endl;
        cout<<"1.按照职工编号进行升序："<<endl;
        cout<<"2.按照职工编号进行降序："<<endl;
        int select=0;
        cin>>select;
        for(int i=0;i<m_EmpNum;i++){
            int minOrMax=i;
            for(int j=i+1;j<this->m_EmpNum;j++){
                if(select==1){//升序
                    if(this->m_EmpArray[minOrMax]->m_Id>this->m_EmpArray[j]->m_Id){
                        minOrMax=j;
                    }
                }else{//降序
                    if(this->m_EmpArray[minOrMax]->m_Id<this->m_EmpArray[j]->m_Id){
                        minOrMax=j;
                    }
                }
            }
            if(i!=minOrMax){
                Worker * temp=this->m_EmpArray[i];
                this->m_EmpArray[i]=this->m_EmpArray[minOrMax];
                this->m_EmpArray[minOrMax]=temp;
            }
        }
        cout<<"排序成功！"<<endl;
        this->save();
        this->Show_Emp();
    }
}
//清空文件
void WorkManager::Clean_File(){
    
    cout<<"是否确认清空？"<<endl;
    cout<<"1.确认"<<endl;
    cout<<"2.返回"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        ofstream ofs(FILENAME,ios::trunc);//删除文件后重新创建
        ofs.close();
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                if(this->m_EmpArray[i]!=NULL){
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i]=NULL;
                }
            }
            delete [] this->m_EmpArray;
            this->m_EmpArray=NULL;
            this->m_EmpNum=0;
            this->m_FileIsEmpty=true;
        }
        cout<<"清空成功"<<endl;
    }
    system("pause");
    system("cls");
}
WorkManager::~WorkManager(){
    if(this->m_EmpArray!=NULL){
        for(int i=0;i<this->m_EmpNum;i++){
            if(this->m_EmpArray[i]!=NULL){
                delete this->m_EmpArray[i];
                this->m_EmpArray[i]=NULL;
            }
        }
        delete [] this->m_EmpArray;
        this->m_EmpArray=NULL;
    }
}