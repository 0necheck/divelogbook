#include <vector>
#include "DiveInfo.h"

#pragma once
class DiveLog 
{
private:
    std::vector<DiveInfo> diveLogs;

public:
    DiveLog();

    void addDiveInfo(const DiveInfo& diveInfo);
    void removeDiveInfo(int index);
    void displayDiveLogs() const;
};
