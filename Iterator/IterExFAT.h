#pragma once
#include "Iterator.h"
#include "../ExFAT.h"
class IterExFAT :
    public Iterator<Cluster>
{
private:
    ExFAT* exfat;
    unsigned int Count;
    unsigned int Pos;
public:
    IterExFAT(ExFAT* fsItem) : Iterator(fsItem->ClusterCount()) {
        exfat = fsItem;
        Count = exfat->ClusterCount();
        Pos = 0;
    }
    void First() { Pos = 0; }
    void Next() { Pos++; }
    bool IsDone() const { return (Pos >= Count); }
    Cluster GetCurrent();
};
