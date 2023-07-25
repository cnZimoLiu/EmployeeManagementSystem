#pragma once
#include <string>
using namespace std;

class worker
{
public:
    int w_id;//编号
    string w_name;//姓名
    int w_depId;//部门

    worker();
    virtual ~worker()=0;

    virtual string getDepartment()=0;
    virtual void showDepartment()=0;//显示部门
    virtual void showInfo()=0;//显示信息
};

worker::worker()
{
}

worker::~worker()
{
}

