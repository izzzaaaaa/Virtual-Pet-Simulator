#pragma once
#include "petClass.h"

class Dog : public Pet {
public:
    Dog(string name);

    void makeSound() override;
    void draw() override;
    string getType() override;

    void bark();
    void fetch();

private:
    float loyalty;
};
