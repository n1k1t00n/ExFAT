#pragma once
#include "FS.h"
#include "Iterator/Iterator.h"
class ExFAT :
	public FS
{
private:
#pragma pack(push, 1)
    typedef struct {
        char jumpInstruction[72];
        uint64_t countSectors;
    } BootRecord;
#pragma pack(pop)
protected:
	bool ReadClusterSize();
};
