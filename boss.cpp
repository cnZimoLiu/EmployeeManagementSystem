#include "boss.h"
#include<iostream>
#include<string>
using namespace std;


boss::boss(int id ,string name,int depId)
{
    w_id=id;
    w_name=name;
    w_depId=depId;
}
boss::~boss()
{
}

string boss::getDepartment()
{
    return string("boss");
}

void  boss::showDepartment() 
{
   cout<<"depId:boss"<<endl;
}

void boss::showInfo()
{
    cout<<"ID:"<<w_id<<endl;
    cout<<"name:"<<w_name<<endl;
    cout<<"depId:"<<getDepartment()<<endl;
}