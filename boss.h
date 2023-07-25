#pragma once
#include "worker.h"

class boss :public worker
{
private:
    /* data */
public:
    boss(int id ,string name,int depId);
    ~boss();

    string getDepartment() override;
    void showDepartment() override ;
    void showInfo() override;
};

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