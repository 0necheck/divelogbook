#include "DiveInfo.h"

DiveInfo::DiveInfo(const std::string & diveSiteName, double depth, double duration, double waterTemperature, double visibility, const std::string & notes)
    : diveSiteName(diveSiteName), depth(depth), duration(duration), waterTemperature(waterTemperature),
    visibility(visibility), notes(notes)
{}

void DiveInfo::addObservedSpecies(const std::string& species)
{
    observedSpecies.push_back(species);
}

void DiveInfo::addDiveBuddy(const Person& buddy)
{
    diveBuddies.push_back(buddy);
}

std::string DiveInfo::getDiveSiteName() const
{
    return diveSiteName;
}

double DiveInfo::getDepth() const
{
    return depth;
}

double DiveInfo::getDuration() const
{
    return duration;
}

double DiveInfo::getWaterTemperature() const
{
    return waterTemperature;
}

double DiveInfo::getVisibility() const
{
    return visibility;
}

std::string DiveInfo::getNotes() const
{
    return notes;
}

std::vector<std::string> DiveInfo::getObservedSpecies() const
{
    return observedSpecies;
}

std::vector<Person> DiveInfo::getDiveBuddies() const
{
    return diveBuddies;
}
