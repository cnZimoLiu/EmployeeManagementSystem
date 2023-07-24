#include "employee.h"
#include<iostream>
#include<string>
using namespace std;


employee::employee(int id ,string name,int depId)
{
    w_id=id;
    w_name=name;
    w_depId=depId;
}
employee::~employee()
{
}

string employee::getDepartment()
{
    return string("employee");
}

void  employee::showDepartment() 
{
   cout<<"depId:employee"<<endl;
}

void employee::showInfo()
{
    cout<<"ID:"<<w_id<<endl;
    cout<<"name:"<<w_name<<endl;
    cout<<"depId:"<<getDepartment()<<endl;
}