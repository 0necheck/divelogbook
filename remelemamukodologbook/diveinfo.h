#include <string>
#include <vector>
#include "Person.h"

#pragma once
class DiveInfo 
{
private:
    std::string diveSiteName;
    std::vector<std::string> observedSpecies;
    double depth;
    double duration;
    double waterTemperature;
    double visibility;
    std::string notes;
    std::vector<Person> diveBuddies;

public:
    DiveInfo(const std::string& diveSiteName, double depth, double duration, double waterTemperature, double visibility, const std::string& notes);

    void addObservedSpecies(const std::string& species);
    void addDiveBuddy(const Person& buddy);

    std::string getDiveSiteName() const;
    double getDepth() const;
    double getDuration() const;
    double getWaterTemperature() const;
    double getVisibility() const;
    std::string getNotes() const;
    std::vector<std::string> getObservedSpecies() const;
    std::vector<Person> getDiveBuddies() const;
};
