#pragma once
#include "petClass.h"

class Dragon : public Pet {
public:
    Dragon(string name);

    void makeSound() override;
    void draw() override;
    string getType() override;

    void breatheFire();

private:
    float fireLevel;
};
