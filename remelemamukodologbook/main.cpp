#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Person.h"
#include "DiveInfo.h"
#include "DiveLog.h"

int main() {
    DiveLog diveLog;

    while (true) {
        std::string diveSiteName;
        double depth, duration;
        double waterTemperature, visibility;
        std::string notes;

        std::cout << "Enter dive information:" << std::endl;
        std::cout << "Dive Site Name: ";
        std::getline(std::cin, diveSiteName);
        try
        {
            std::cout << "Depth (m): ";
            std::cin >> depth;
            if (!std::cin)
            {
                throw std::runtime_error("Invalid input for depth. Enter a number!\n");
            } //indicate runtime errors

            std::cout << "Duration (minutes): ";
            std::cin >> duration;
            if (!std::cin) {
                throw std::runtime_error("Invalid input for duration. Enter a number!\n");
            }

            std::cout << "Water Temperature (Celsius): ";
            std::cin >> waterTemperature;
            if (!std::cin) {
                throw std::runtime_error("Invalid input for water temperature. Enter a number!\n");
            }

            std::cout << "Visibility (m): ";
            std::cin >> visibility;
            if (!std::cin) {
                throw std::runtime_error("Invalid input for visibility. Enter a number!\n");
            }
        }
        catch (const std::exception& e) 
        {
            std::cout << "Error: " << e.what() << std::endl;
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input, ensure that ignore every char up to the newline
            continue; // Restart the loop to re-enter the inputs
        }
        std::cout << "Notes: ";
        std::cin.ignore();
        std::getline(std::cin, notes);

        DiveInfo dive(diveSiteName, depth, duration, waterTemperature, visibility, notes);

        char addSpecies;
        std::cout << "Add observed species? (y/n): ";
        std::cin >> addSpecies;
        std::cin.ignore();

        if (addSpecies == 'y' || addSpecies == 'Y') 
        {
            do 
            {
                std::string species;
                std::cout << "Enter Observed Species: ";
                std::getline(std::cin, species);
                dive.addObservedSpecies(species);

                std::cout << "Add another species? (y/n): ";
                std::cin >> addSpecies;
                std::cin.ignore();
            } while (addSpecies == 'y' || addSpecies == 'Y');
        }// if the user hit enter after every species (see divelog.cpp ln.48 or around there)

        char addBuddy;
        std::cout << "Add a buddy? (y/n): ";
        std::cin >> addBuddy;
        std::cin.ignore();

        if (addBuddy == 'y' || addBuddy == 'Y') 
        {
            do 
            {
                std::cout << "Enter buddy information:" << std::endl;
                std::string buddyName;
                int buddyAge;
                double buddyHeight, buddyWeight;
                std::string buddyCertification;

                std::cout << "Name: ";
                std::getline(std::cin, buddyName);
                try
                {
                    std::cout << "Age: ";
                    std::cin >> buddyAge;
                    if (buddyAge <= 0)
                        throw std::runtime_error("Invalid input for age. Enter a number!\n");

                    std::cout << "Height: ";
                    std::cin >> buddyHeight;
                    if (buddyHeight <= 0)
                        throw std::runtime_error("Invalid input for height. Enter a number!\n");

                    std::cout << "Weight: ";
                    std::cin >> buddyWeight;
                    if (buddyWeight <= 0)
                        throw std::runtime_error("Invalid input for weight. Enter a number!\n");
                    std::cin.ignore();//newline would be after entering weight and the getline won't be happy about it (the enter is still there and would read that)

                }
                catch (const std::exception& e)
                {
                    std::cout << "Error: " << e.what() << std::endl;
                    std::cin.clear(); // Clear the error state
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input, ensure that ignore every char up to the newline
                    continue; // Restart the loop to re-enter the inputs
                }

                std::cout << "Certification Level: ";
                std::getline(std::cin, buddyCertification);

                Person buddy(buddyName, buddyAge, buddyHeight, buddyWeight, buddyCertification);
                dive.addDiveBuddy(buddy);

                std::cout << "Add another buddy? (y/n): ";
                std::cin >> addBuddy;
                std::cin.ignore(); //same reason as in ln.73. or around there
            } while (addBuddy == 'y' || addBuddy == 'Y');
        }

        diveLog.addDiveInfo(dive);

        char addAnotherDive;
        std::cout << "Add another dive? (y/n): ";
        std::cin >> addAnotherDive;

        if (addAnotherDive != 'y' && addAnotherDive != 'Y') 
            break;

        std::cin.ignore();
    }

    diveLog.displayDiveLogs();

    return 0;
}
//TODO IT WORKS SO FAR :-)
//TODO MAKE A USE OF THE PREVIOUS EQUIPMENT STUFF (INHERITANCE AND POLYMORPHISM)
