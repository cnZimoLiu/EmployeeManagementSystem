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
