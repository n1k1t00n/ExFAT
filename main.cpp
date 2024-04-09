#include <iostream>
#include "FS.h"
#include "ExFAT.h"
#include "windows.h"
#include <iomanip>
#include "Iterator/IterExFAT.h"
using namespace std;

void hexdump(const BYTE* array, unsigned int length, unsigned int offset) {
    const int bytes_per_line = 16;
    for (size_t i = 0; i < length; i += bytes_per_line) {
        // Вывод адреса текущей строки
        std::cout << std::setw(8) << std::setfill('0') << std::hex << offset + i << ": ";

        // Вывод байтов в шестнадцатеричном формате
        for (int j = 0; j < bytes_per_line; ++j) {
            if (i + j < length) {
                std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(array[i + j]) << " ";
            }
            else {
                std::cout << "   "; // для неполных строк
            }
        }

        // Вывод символов ASCII
        std::cout << "  ";
        for (int j = 0; j < bytes_per_line; ++j) {
            if (i + j < length) {
                char c = array[i + j];
                std::cout << (c >= 32 && c < 127 ? c : '.');
            }
            else {
                std::cout << " "; // для неполных строк
            }
        }

        std::cout << std::endl;
    }
}

int main()
{

    ExFAT* fs = new ExFAT;
    
    //unsigned int clusterNum = 2;
    //std::cout << "Enter Cluster Number: ";
    //std::cin >> clusterNumber;
    //std::cout << std::endl;

    if (!fs->Init(L"\\\\.\\G:")) //Путь исследования
    {
        cout << "Init: " << GetLastError();
        return false;
    };

    unsigned int clusterSize = fs->ClusterSize();
    /*
    BYTE * cluster = new BYTE[clusterSize];
    if (!fs->ReadCluster(clusterNumber, cluster)) {
        cout << "ReadCluster: " << GetLastError();
        return false;
    }
    hexdump(cluster, clusterSize, clusterNumber * clusterSize);
    */
    std::cout << dec << "Cluster size: " << clusterSize << std::endl;

    Iterator<Cluster>* it = new IterExFAT(fs);

    for (it->First();!it->IsDone();it->Next()) {
        Cluster currentObject = it->GetCurrent();
        unsigned int offset = currentObject.GetNum() * clusterSize;
        hexdump(currentObject.GetContent(), clusterSize, offset);
    }
}