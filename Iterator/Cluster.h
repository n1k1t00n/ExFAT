#pragma once
#include <iostream>
#include "windows.h"
using namespace std;

class Cluster
{
private:
    unsigned int clusterNum=0;
    BYTE* content=NULL;
public:
    void SetClusterNum(unsigned int num) { clusterNum = num; }
    void SetContent(BYTE* obj) { content = obj; }
    BYTE* GetContent() { return content; };
    unsigned int GetNum() const { return clusterNum; };
    Cluster(BYTE* data, unsigned int num, unsigned int ClusterSize);
    Cluster() {};
    ~Cluster();
};