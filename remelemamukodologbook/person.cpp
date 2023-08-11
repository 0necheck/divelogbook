#include "Person.h"

Person::Person(const std::string& name, int age, double height, double weight, const std::string& certificationLevel)
    : name(name), age(age), height(height), weight(weight), certificationLevel(certificationLevel) {
}

Person::~Person() {
}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

double Person::getHeight() const {
    return height;
}

double Person::getWeight() const {
    return weight;
}

std::string Person::getCertificationLevel() const {
    return certificationLevel;
}

void Person::setName(const std::string& newName) {
    name = newName;
}

void Person::setAge(int newAge) {
    age = newAge;
}

void Person::setHeight(double newHeight) {
    height = newHeight;
}

void Person::setWeight(double newWeight) {
    weight = newWeight;
}

void Person::setCertificationLevel(const std::string& newCertificationLevel) {
    certificationLevel = newCertificationLevel;
}
