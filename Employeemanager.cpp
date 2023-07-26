#include <iostream>
#include "EmployeeManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <string>
using namespace std;

/**
 * ************************************************************************
 * @brief 构造函数，文件存在且有内容时读取文件到堆中
 * ************************************************************************
 */
EmployeeManager::EmployeeManager()
{
    fstream file;
    file.open(FILENAME, ios::in);
    if (!file.is_open()) // 文件不存在
    {
        cout << "file not exist" << endl;
        this->num = 0;
        this->workerArray = nullptr;
        this->fileIsEmpty = true;
        return;
    }
    if (file.peek() == EOF) // 文件为空
    {
        cout << "file empty" << endl;
        this->num = 0;
        this->workerArray = nullptr;
        this->fileIsEmpty = true;
        file.close();
        return;
    }
    // 文件存在且有内容
    this->fileIsEmpty = false;
    this->num = this->getNumFromFile();
    this->workerArray = new worker *[num]; // 开辟堆区内存要提前知道有多少个数据
    this->addWorkerFromFile();
}
/**
 * ************************************************************************
 * @brief Destroy the Employee Manager:: Employee Manager object
 * ************************************************************************
 */
EmployeeManager::~EmployeeManager()
{
    if (this->workerArray != nullptr)
    {
        delete[] workerArray;
        this->workerArray = nullptr;
    }
}
/**
 * ************************************************************************
 * @brief 显示菜单
 * ************************************************************************
 */
void EmployeeManager::showMenu()
{
    cout << "***********************************" << endl;
    cout << "*********欢迎使用职工管理系统********" << endl;
    cout << "************0.退出*****************" << endl;
    cout << "************1.增加职工信息*********" << endl;
    cout << "************2.显示职工信息*********" << endl;
    cout << "************3.删除*****************" << endl;
    cout << "************4.修改*****************" << endl;
    cout << "************5.查找*****************" << endl;
    cout << "************6.按照id排序*********" << endl;
    cout << "************7.清空所有文档*********" << endl;
    cout << "***********************************" << endl;
    cout << endl;
}
/**
 * ************************************************************************
 * @brief 退出系统
 * ************************************************************************
 */
void EmployeeManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}
/**
 * ************************************************************************
 * @brief 从终端添加worker
 * ************************************************************************
 */
void EmployeeManager::addEmp()
{
    cout << "enter the number you want to add" << endl;
    int addNum;
    cin >> addNum;
    if (addNum <= 0)
    {
        cout << "error:wrong number" << endl;
        return;
    }
    int newsize = num + addNum;
    worker **newWorkerArray = new worker *[newsize]; // worker** 第一个*说明是数组，第二个*说明在堆区
    if (workerArray != nullptr)
    {
        for (int i = 0; i < num; i++)
        {
            newWorkerArray[i] = workerArray[i];
        }
        delete[] workerArray;
    }
    for (int i = 0; i < addNum; i++)
    {
        int id;
        string name;
        int depId;
        cout << "输入第" << i + 1 << "个人的"
             << "id" << endl;
        cin >> id;
        cout << "输入第" << i + 1 << "个人的"
             << "姓名" << endl;
        cin >> name;
        cout << "输入第" << i + 1 << "个人的"
             << "部门" << endl;
        cout << "0代表员工，1代表经理，2代表老板" << endl;
        cin >> depId;
        switch (depId)
        {
        case 0:
            newWorkerArray[num + i] = new employee(id, name, depId);
            break;
        case 1:
            newWorkerArray[this->num + i] = new manager(id, name, depId);
            break;
        case 2:
            newWorkerArray[this->num + i] = new boss(id, name, depId);
            break;
        default:
            cout << "error:部门代码错误" << endl;
            break;
        }
    }
    workerArray = newWorkerArray;
    newWorkerArray = nullptr;
    num = newsize;
    cout << this->num << "个数据已保存至堆区" << endl;
    this->save();
    this->fileIsEmpty=false;
}
/**
 * ************************************************************************
 * @brief 从堆区向文件内保存数据
 * ************************************************************************
 */
void EmployeeManager::save()
{
    fstream file;
    file.open(FILENAME,ios::out);
    if (!file.is_open())
    {
        cout << "error:file not opened" << endl;
    }
    for (int i = 0; i < this->num; i++)
    {
        file << this->workerArray[i]->w_id << " "
             << this->workerArray[i]->w_name << " "
             << this->workerArray[i]->w_depId << endl;
    }
    file.close();
    cout <<"保存成功："<< this->num << " 个数据已保存至文件" << endl;
}
/**
 * ************************************************************************
 * @brief 返回行数，即worker*列元素个数，方便开辟堆区内存
 * ************************************************************************
 */
int EmployeeManager::getNumFromFile()
{
    fstream file;
    file.open(FILENAME, ios::in);
    string line;
    int lineCount = 0;
    while (getline(file, line))
    {
        lineCount++;
    }
    cout << "there are " << lineCount << " lines in file" << endl;
    file.close();
    return lineCount;
}
/**
 * ************************************************************************
 * @brief 从文件中读取内容到已开辟的堆区
 * ************************************************************************
 */
void EmployeeManager::addWorkerFromFile()
{
    fstream file;
    file.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    for (int i = 0; i < this->num; i++)
    {
        file >> id >> name >> did;
        switch (did)
        {
        case 0:
            this->workerArray[i] = new employee(id, name, did);
            break;
        case 1:
            this->workerArray[i] = new manager(id, name, did);
            break;
        case 2:
            this->workerArray[i] = new boss(id, name, did);
            break;
        default:
            cout<<"error: "<<i<<" wrong departmentID read"<<endl;
            break;
        }
    }
    file.close();
}
/**
 * ************************************************************************
 * @brief 显示所有员工信息
 * ************************************************************************
 */
void EmployeeManager::showAll()
{
    if(this->fileIsEmpty)
    {
        cout<<"no worker"<<endl;
        return;
    }
    for (int i = 0; i < this->num  ; i++)
    {
        this->workerArray[i]->showInfo();
    }
}
/**
 * ************************************************************************
 * @brief 根据id查找worker，返回该worker的索引，否则返回-1
 * @param[in] id  要查找worker的id
 * @return int 
 * ************************************************************************
 */
int
EmployeeManager::isExistById(int id)
{
    int returnValue=-1;
    for (int i = 0; i < this->num; i++)
    {
        if (this->workerArray[i]->w_id==id)
        {
            returnValue=i;
            break;
        }
        
    }
    return returnValue;
}
/**
 * ************************************************************************
 * @brief 通过id删除worker
 * @param[in] id  Comment
 * ************************************************************************
 */
void
EmployeeManager::delWorker(int id)
{
    if (this->fileIsEmpty==true)
    {
        cout<<"nothing to delete";
        return;
    }
    int index=this->isExistById(id);
    if (index==-1)
    {
        cout<<"no such id to delete";
        return;
    }
    delete this->workerArray[index];//释放内存
    for (int i = index; i < this->num-1 ; i++)
    {
        this->workerArray[i]=this->workerArray[i+1];//向前
    }
    this->workerArray[num]=nullptr;
    this->num--;
    this->save();
    cout<<"delete success"<<endl;
    

}
/**
 * ************************************************************************
 * @brief 根据ID改变员工并保存到文件中
 * @param[in] id  要改变的workerID
 * ************************************************************************
 */
void
EmployeeManager::change(int id)
{
    if (this->fileIsEmpty==true)
    {
        cout<<"nothing to change";
        return;
    }
    int index=this->isExistById(id);
    if (index==-1)
    {
        cout<<"no such id to change";
        return;
    }
    int newId;
    string newName;
    int newDid;
    cout<<"new id"<<endl;
    cin>>newId;
    cout<<"new name"<<endl;
    cin>>newName;
    cout<<"new departmentId"<<endl;
    cin>>newDid;
    switch (newDid)
    {
    case 0:
        delete this->workerArray[index];
        this->workerArray[index]=new employee(newId,newName,newDid);
        break;
    case 1:
        delete this->workerArray[index];
        this->workerArray[index]=new manager(newId,newName,newDid);
        break;
    case 2:
        delete this->workerArray[index];
        this->workerArray[index]=new boss(newId,newName,newDid);
        break;    
    default:
        cout<<"error:wrong departmentId"<<endl;
        break;
    }
    cout<<"change complete:"<<endl;
    this->workerArray[index]->showInfo();
    this->save();
}

void
EmployeeManager::swap(int a,int b)
{
    worker* temp;
    temp=this->workerArray[a];
    this->workerArray[a]=this->workerArray[b];
    this->workerArray[b]=temp;

}

void
EmployeeManager::sortByID()
{
    for (int i = 0; i < this->num-1; i++)
    {
        int minIndex=i;
        for (int j = i+1; j < this->num; j++)
        {
            if (this->workerArray[minIndex]->w_id>this->workerArray[j]->w_id)
            {
                minIndex=j;
            }
            
        }
        this->swap(i,minIndex);
        
    }
    
}
/**
 * ************************************************************************
 * @brief 
 * @return int 
 * ************************************************************************
 */
int main()
{

    EmployeeManager em;
    int choice = 0;
    while (true)
    {
        em.showMenu();
        cout << "输入您的选择:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0: // 退出
            em.exitSystem();
            break;
        case 1: // 增加职工信息
            em.addEmp();
            break;
        case 2: // 显示职工信息
            em.showAll();
            break;
        case 3: // 删除
            cout<<"enter id"<<endl;
            int id;
            cin>>id;
            em.delWorker(id);
            break;
        case 4: // 修改
            cout<<"enter id"<<endl;
            int changeid;
            cin>>changeid;
            em.change(changeid);
            break;
        case 5: // 查找
            /* code */
            break;
        case 6: // 按照编号排序
            em.sortByID();
            em.save();
            cout<<"sort success:"<<endl;
            em.showAll();
            break;
        case 7: // 清空文件
            /* code */
            break;
        default:
            system("cls");
            break;
        }
    }

    return 0;
}