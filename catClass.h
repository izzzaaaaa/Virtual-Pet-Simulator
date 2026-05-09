#pragma once
#include "petClass.h"

class Cat : public Pet {
public:
    Cat(string name);

    void makeSound() override;
    void draw() override;
    string getType() override;

    void purr();
    void scratch();

private:
    float playfulness;
};
