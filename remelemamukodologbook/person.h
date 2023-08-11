#include <string>

#pragma once
class Person 
{
private:
    std::string name;
    int age;
    double height;
    double weight;
    std::string certificationLevel;

public:
    Person(const std::string& name, int age, double height, double weight, const std::string& certificationLevel);

    std::string getName() const;
    int getAge() const;
    double getHeight() const;
    double getWeight() const;
    std::string getCertificationLevel() const;

    void setName(const std::string& newName);
    void setAge(int newAge);
    void setHeight(double newHeight);
    void setWeight(double newWeight);
    void setCertificationLevel(const std::string& newCertificationLevel);
};
