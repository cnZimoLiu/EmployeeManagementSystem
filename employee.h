#pragma once
#include "worker.h"

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
