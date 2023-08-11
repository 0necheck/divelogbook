#include "DiveLog.h"
#include <iostream>
#include <fstream>

DiveLog::DiveLog() {
} //the cunstructor is empty because it doesn't require any specific initialization logic

void DiveLog::addDiveInfo(const DiveInfo& diveInfo) {
    diveLogs.push_back(diveInfo);
    //gets a DiveInfo as a parameter and adds it to the divelog vector
    //with the push_back it pushes to the end of the vector
}

void DiveLog::removeDiveInfo(int index) {
    if (index >= 0 && index < diveLogs.size()) {
        diveLogs.erase(diveLogs.begin() + index);
    }
    //removes the DiveInfo from the divelogs vector
    //if it's in a valid interval it erases it
}

void DiveLog::displayDiveLogs() const { //displaying the divelogs

    std::cout << std::endl; //to separate the first dive's results with the input

    for (size_t i = 0; i < diveLogs.size(); ++i)
    {
        std::cout << "Dive #" << (i + 1) << std::endl;
        std::cout << "Dive Site: " << diveLogs[i].getDiveSiteName() << std::endl;
        std::cout << "Depth: " << diveLogs[i].getDepth() << "m" << std::endl;
        std::cout << "Duration: " << diveLogs[i].getDuration() << " minutes" << std::endl;
        std::cout << "Water Temperature: " << diveLogs[i].getWaterTemperature() << " Celsius" << std::endl;
        std::cout << "Visibility: " << diveLogs[i].getVisibility() << "m" << std::endl;
        std::cout << "Notes: " << diveLogs[i].getNotes() << std::endl << "\n";

        std::vector<Person> buddies = diveLogs[i].getDiveBuddies();

        if (!buddies.empty())
        {
            std::cout << "Dive Buddies: " << std::endl;
            for (size_t j = 0; j < buddies.size(); ++j)
            {
                std::cout << "Name:" << buddies[j].getName() << std::endl;
                std::cout << "Age:" << buddies[j].getAge() << std::endl;
                std::cout << "Height:" << buddies[j].getHeight() << std::endl;
                std::cout << "Weight:" << buddies[j].getWeight() << std::endl;
                std::cout << "Certification Level:" << buddies[j].getCertificationLevel() << std::endl;

                if (j != buddies.size() - 1)
                    std::cout << std::endl; //separate each buddy's info

            }
            std::cout << std::endl;
        }

        std::vector<std::string> species = diveLogs[i].getObservedSpecies();
        if (!species.empty()) {
            std::cout << "Observed Species: ";
            for (size_t j = 0; j < species.size(); ++j) {
                std::cout << species[j];
                if (j != species.size() - 1) {
                    std::cout << "; ";
                }
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }
}
//the displayDiveLogs iterates over the DiveInfo object in the divelogs vector with a loop
//for each dive log entry it prints out the data
//separates with a semicolon in the divebuddies and observered species 
// after each finished dive log it prints a blank line to separate the dive logs