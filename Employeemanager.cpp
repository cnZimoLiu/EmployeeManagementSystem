#include <iostream>
#include "EmployeeManager.h"
using namespace std;

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

void test1(bool act)
{
    if(act==0) return;
    EmployeeManager em;
    em.showMenu();
}

int main ()
{
    test1(0);

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
        case1://增加职工信息
            /* code */
            break;
        case 2://显示职工信息
            /* code */
            break;
        case 3://删除
            /* code */
            break;
        case 4://修改
            /* code */
            break;
        case 5://查找
            /* code */
            break;
        case 6://按照编号排序
            /* code */
            break;
        case 7://按照编号排序
            /* code */
            break;        
        default:
            system("cls");
            break;
        }
    }
    
    return 0;
}