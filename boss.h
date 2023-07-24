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