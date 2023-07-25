#include <iostream>
#include "EmployeeManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <string>
using namespace std;


EmployeeManager::EmployeeManager(/* args */)
{
    num=0;
    workerArray=nullptr;
}

EmployeeManager::~EmployeeManager()
{
    delete[] workerArray;
}

void EmployeeManager::showMenu()
{
    cout<<"***********************************"<<endl;
    cout<<"*********欢迎使用职工管理系统********"<<endl;
    cout<<"************0.退出*****************"<<endl;
    cout<<"************1.增加职工信息*********"<<endl;
    cout<<"************2.显示职工信息*********"<<endl;
    cout<<"************3.删除*****************"<<endl;
    cout<<"************4.修改*****************"<<endl;
    cout<<"************5.查找*****************"<<endl;
    cout<<"************6.按照编号排序*********"<<endl;
    cout<<"************7.清空所有文档*********"<<endl;
    cout<<"***********************************"<<endl;
    cout<<endl;
}

void EmployeeManager::exitSystem()
{
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);
}

void EmployeeManager::addEmp()
{
    cout<<"enter the number u want to add"<<endl;
    int addNum;
    cin>>addNum;
    if (addNum<=0)
    {
        cout<<"error:wrong number"<<endl;
        return;
    }
    int newsize=num+addNum;
    worker** newWorkerArray=new worker*[newsize];//worker** 第一个*说明是数组，第二个*说明在堆区
    if (workerArray!=nullptr)
    {
        for (int i = 0; i < num; i++)
        {
            newWorkerArray[i]=workerArray[i];
        }
        delete[]workerArray;
    }
    for (int i = 0; i < addNum; i++)
    {
        int id;
        string name;
        int depId;
        cout<<"输入第"<<i+1<<"个人的"<<"id"<<endl;
        cin>>id;
        cout<<"输入第"<<i+1<<"个人的"<<"姓名"<<endl;
        cin>>name;
        cout<<"输入第"<<i+1<<"个人的"<<"部门"<<endl;
        cout<<"0代表员工，1代表经理，2代表老板"<<endl;
        cin>>depId;
        switch (depId)
        {
        case 0:
            newWorkerArray[num+i]=new employee(id,name,depId );
            break;
        case 1:
            newWorkerArray[this->num+i]=new manager(id,name,depId);
            break;
        case 2:
            newWorkerArray[this->num+i]=new boss(id,name,depId);
            break;
        default:
            cout<<"error:部门代码错误"<<endl;
            break;
        }
    }
    workerArray = newWorkerArray;
    newWorkerArray=nullptr;
    num = newsize;
    
    
} 

void test1(bool act)
{
    if(act==0) return;
    EmployeeManager em;
    em.showMenu();
}

int main ()
{

    EmployeeManager em;
    int choice=0;
    while (true)
    {
        em.showMenu();
        cout<<"输入您的选择:"<<endl;
        cin>>choice;
        
        switch (choice)
        {
        case 0 ://退出
            em.exitSystem();
            break;
        case 1 ://增加职工信息
            em.addEmp();
            break;
        case 2 ://显示职工信息
            /* code */
            break;
        case 3 ://删除
            /* code */
            break;
        case 4 ://修改
            /* code */
            break;
        case 5 ://查找
            /* code */
            break;
        case 6 ://按照编号排序
            /* code */
            break;
        case 7 ://按照编号排序
            /* code */
            break;        
        default:
            system("cls");
            break;
        }
    }
    
    return 0;
}