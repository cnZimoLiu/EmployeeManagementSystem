#pragma once
#include <iostream>
#include "worker.h"
#include <fstream>
#define FILENAME "emsFile.txt"
using namespace std;

class EmployeeManager
{
private:
    /* data */
public:
    int num;//容器中总人数
    worker** workerArray;//指向堆区中worker*列的指针
    bool fileIsEmpty;//文件为空

    EmployeeManager(/* args */);
    ~EmployeeManager();
    void showMenu();
    void exitSystem();
    void addEmp();
    void save();
    int getNumFromFile();
    void addWorkerFromFile();
    void showAll();
    int isExistById(int id);
    void delWorker(int id);
    void change(int id);
    void swap(int a,int b);
    void sortByID();
};

