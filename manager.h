#pragma once
#include "worker.h"

class manager :public worker
{
private:
    /* data */
public:
    manager(int id ,string name,int depId);
    ~manager();

    string getDepartment() override;
    void showDepartment() override ;
    void showInfo() override;
};


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