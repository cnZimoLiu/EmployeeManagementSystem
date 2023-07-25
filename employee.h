//#pragma once
#include "worker.h"
#include <string.h>
using namespace std ;

class employee :public worker
{
private:
    /* data */
public:
    employee(int id ,string name,int depId);
    ~employee();

    string getDepartment() override;
    void showDepartment() override ;
    void showInfo() override;
};


employee::employee(int id ,string name,int depId)
{
    this->w_id=id;
    this->w_name=name;
    this->w_depId=depId;
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