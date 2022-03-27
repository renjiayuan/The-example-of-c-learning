#include "workerManager.h"

WorkManager::WorkManager(){
    //1.�ļ�������
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        //cout<<"�ļ�������"<<endl;
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        this->m_FileIsEmpty= true;
        ifs.close();
        return;
    }
    //2.�ļ����ڵ�Ϊ��
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        //cout<<"�ļ�Ϊ��"<<endl;
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        this->m_FileIsEmpty= true;
        ifs.close();
        return;
    }
    //3.�ļ����ڣ����Ҽ�¼����
    int num=this->get_EmpNum();
    // cout<<"Ա������Ϊ��"<<num<<endl;
    this->m_EmpNum=num;
    this->m_EmpArray=new Worker *[this->m_EmpNum];//���ٿռ�
    this->init_Emp();
    this->m_FileIsEmpty=false;
    // for(int i=0;i<this->m_EmpNum;i++){
    //     cout<<"ְ����ţ�"<<this->m_EmpArray[i]->m_Id
    //         <<"\t������"<<this->m_EmpArray[i]->m_Name
    //         <<"\t���ű��"<<this->m_EmpArray[i]->m_DeptId<<endl;
    // }
}
//չʾ�˵�
void WorkManager::Show_Menu(){
    cout<<"***************************************"<<endl;
    cout<<"**********��ӭʹ��ְ������ϵͳ**********"<<endl;
    cout<<"**********   0.�˳��������   **********"<<endl;
    cout<<"**********   1.����ְ����Ϣ   **********"<<endl;
    cout<<"**********   2.��ʾְ����Ϣ   **********"<<endl;
    cout<<"**********   3.ɾ����ְְ��   **********"<<endl;
    cout<<"**********   4.�޸�ְ����Ϣ   **********"<<endl;
    cout<<"**********   5.����ְ����Ϣ   **********"<<endl;
    cout<<"**********   6.���ձ������   **********"<<endl;
    cout<<"**********   7.��������ĵ�   **********"<<endl;
    cout<<"***************************************"<<endl;
    cout<<endl;
}
//�˳�ϵͳ
void WorkManager::ExitSystem(){
    cout<<"��ӭ�´�ʹ��!"<<endl;
    system("pause");
    exit(0);//�˳�����
}
//���ְ��
void WorkManager::Add_Emp(){
    cout<<"���������Ա��������"<<endl;
    int addNum;
    cin>>addNum;
    if(addNum>0){
        //��������¿ռ��С���൱�����·���һЩ�ռ�
        int newSize=this->m_EmpNum+addNum;//�¿ռ�����=ԭ����¼����+��������
        //�����¿ռ�
        Worker ** newSpace=new Worker*[newSize];
        //��ԭ���ռ������ݿ������¿ռ���
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                newSpace[i]=this->m_EmpArray[i];
            }
        }
        //�������������
        for(int i=0;i<addNum;i++){
            int id;
            string name;
            int dSelect;
            cout<<"�������"<<i+1<<"����Ա����ţ�"<<endl;
            cin>>id;
            cout<<"�������"<<i+1<<"����Ա��������"<<endl;
            cin>>name;
            cout<<"�������"<<i+1<<"����Ա����λ��"<<endl;
            cout<<"1����ְͨ��"<<endl;
            cout<<"2������"<<endl;
            cout<<"3���ϰ�"<<endl;
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
            //������ְ�����浽������
            newSpace[this->m_EmpNum+i]=worker;
        }
        //�ͷ�ԭ�пռ�
        delete [] this->m_EmpArray;
        //�����¿ռ�ָ��
        this->m_EmpArray=newSpace;
        //����ְ������
        this->m_EmpNum=newSize;
        this->save();
        //��ʾ��ӳɹ�
        cout<<"�ɹ����"<<addNum<<"����ְ��"<<endl;
        this->m_FileIsEmpty=false;//���±�־��Ϊ��
    }else{
        cout<<"������������"<<endl;
    }
    system("pause");
    system("cls");
}
//�����ļ�
void WorkManager::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    //��ÿ���˵����ݶ�д�뵽�ļ���
    for(int i=0;i<this->m_EmpNum;i++){
        ofs<<this->m_EmpArray[i]->m_Id<<" "
            <<this->m_EmpArray[i]->m_Name<<" "
            <<this->m_EmpArray[i]->m_DeptId<<endl;
    }
    //�ر��ļ�
    ofs.close();
}
//ͳ���ļ��е�����
int WorkManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//��
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
//��ʼ��Ա��
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
        if(dId==1){//��ͨԱ��
            worker=new Employee(id,name,dId);
        }else if(dId==2){//����
            worker=new Manager(id,name,dId);
        }else if(dId==3){//�ϰ�
            worker = new Boss(id,name,dId);
        }
        this->m_EmpArray[index]=worker;
        index++;
    }
    ifs.close();
}
//��ʾְ��
void WorkManager::Show_Emp(){
    //�ж��ļ��Ƿ�Ϊ��
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��߼�¼Ϊ��"<<endl;
    }else{
        for(int i=0;i<m_EmpNum;i++){
            //���ö�̬���ó���ӿ�
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}
//ɾ��Ա��
void WorkManager::Del_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڣ�"<<endl;
    }else{
        cout<<"��������Ҫɾ����ְ����ţ�"<<endl;
        int id=0;
        cin>>id;
        int index=this->IsExist(id);
        if(index!=-1){
            for(int i=index;i<this->m_EmpNum-1;i++){
                this->m_EmpArray[i]=this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;
            this->save();//����ͬ�����ļ���
            cout<<"ɾ���ɹ���"<<endl;
            if(this->m_EmpNum==0){
                this->m_FileIsEmpty=true;
            }
        }else{
            cout<<"ɾ��ʧ�ܣ�δ�ҵ�Ա����"<<endl;
        }
    }
    system("pause");
    system("cls");
}
//Ա���Ƿ����,����Ա����λ��
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
//�޸�ְ��
void WorkManager::Mod_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��߼�¼Ϊ�գ�"<<endl;
    }else{
        cout<<"�������޸�ְ����ţ�"<<endl;
        int id;
        cin>>id;
        int ret=this->IsExist(id);
        if(ret!=-1){
            //�ҵ�ְ���ı��
            delete this->m_EmpArray[ret];
            int newId=0;
            string newName="";
            int newDSelect=0;
            cout<<"�鵽��"<<id<<"��Ա������������ְ���ţ�"<<endl;
            cin>>newId;
            cout<<"��������������"<<endl;
            cin>>newName;
            cout<<"������Ա���¸�λ��"<<endl;
            cout<<"1����ְͨ��"<<endl;
            cout<<"2������"<<endl;
            cout<<"3���ϰ�"<<endl;
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
            cout<<"�޸ĳɹ���";
            this->save();
        }else{
            cout<<"���޴��ˣ�"<<endl;
        }
    }
    system("pause");
    system("cls");
}
//����Ա��
void WorkManager::Find_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��߼�¼Ϊ�գ�"<<endl;
    }else{
        cout<<"��������ҵķ�ʽ��"<<endl;
        cout<<"1.��Ա����Ž��в��ң�"<<endl;
        cout<<"2.��Ա���������в��ң�"<<endl;
        int select=0;
        cin>>select;

        if(select==1){
            //����Ž��в���
            int id;
            cout<<"��������ҵ�ְ����ţ�"<<endl;
            cin>>id;
            int ret=this->IsExist(id);
            if(ret!=-1){
                cout<<"���ҳɹ�����Ա����Ϣ���£�"<<endl;
                this->m_EmpArray[ret]->showInfo();
            }else{
                cout<<"����ʧ�ܣ����޴���"<<endl;
            }
        }else if(select==2){
            //�����������в���
            string name;
            bool flag=false;//�ж��Ƿ�鵽
            cout<<"��������ҵ�����:"<<endl;
            cin>>name;
            for(int i=0;i<this->m_EmpNum;i++){
                if(this->m_EmpArray[i]->m_Name==name){
                    cout<<"���ҳɹ���ְ����Ϣ���£�"<<endl;
                    this->m_EmpArray[i]->showInfo();
                    flag=true;
                }
            } 
            if(flag==false){
                cout<<"����ʧ�ܣ�"<<endl;
            }
        }else{
            cout<<"����ѡ������"<<endl;
        }
    }
    system("pause");
    system("cls");
}
//����
void WorkManager::Sort_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��߼�¼Ϊ�գ�"<<endl;
        system("pause");
        system("cls");
    }else{
        cout<<"��ѡ������ķ�ʽ��"<<endl;
        cout<<"1.����ְ����Ž�������"<<endl;
        cout<<"2.����ְ����Ž��н���"<<endl;
        int select=0;
        cin>>select;
        for(int i=0;i<m_EmpNum;i++){
            int minOrMax=i;
            for(int j=i+1;j<this->m_EmpNum;j++){
                if(select==1){//����
                    if(this->m_EmpArray[minOrMax]->m_Id>this->m_EmpArray[j]->m_Id){
                        minOrMax=j;
                    }
                }else{//����
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
        cout<<"����ɹ���"<<endl;
        this->save();
        this->Show_Emp();
    }
}
//����ļ�
void WorkManager::Clean_File(){
    
    cout<<"�Ƿ�ȷ����գ�"<<endl;
    cout<<"1.ȷ��"<<endl;
    cout<<"2.����"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        ofstream ofs(FILENAME,ios::trunc);//ɾ���ļ������´���
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
        cout<<"��ճɹ�"<<endl;
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