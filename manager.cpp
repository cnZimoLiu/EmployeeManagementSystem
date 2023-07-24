#include "manager.h"
#include<iostream>
#include<string>
using namespace std;


manager::manager(int id ,string name,int depId)
{
    w_id=id;
    w_name=name;
    w_depId=depId;
}
manager::~manager()
{
}

string manager::getDepartment()
{
    return string("manager");
}

void  manager::showDepartment() 
{
   cout<<"depId:manager"<<endl;
}

void manager::showInfo()
{
    cout<<"ID:"<<w_id<<endl;
    cout<<"name:"<<w_name<<endl;
    cout<<"depId:"<<getDepartment()<<endl;
}