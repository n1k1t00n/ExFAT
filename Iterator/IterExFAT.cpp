#include "IterExFAT.h"

Cluster IterExFAT::GetCurrent()
{
    Cluster* obj = new Cluster();
    exfat->ReadCluster(obj, Pos);
    return *obj;
}
