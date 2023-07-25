#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class EmployeeManager
{
private:
    /* data */
public:
    int num;
    worker** workerArray;

    EmployeeManager(/* args */);
    ~EmployeeManager();
    void showMenu();
    void exitSystem();
    void addEmp();
};
