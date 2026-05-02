#include <iostream>
using namespace std;

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

// Dragon constructor
Dragon::Dragon(string n) : Pet(n) {
    fireLevel = 60;
}

void Dragon::makeSound() {
    cout << name << " says: ROAAARRR!" << endl;
}

void Dragon::draw() {
    cout << "  >>==>" << endl;
    cout << " ( o  o)" << endl;
    cout << "  ) /\\ ( " << endl;
    cout << "  " << name << " the Dragon" << endl;
}

string Dragon::getType() {
    return "Dragon";
}

void Dragon::breatheFire() {
    if (!alive) {
        cout << name << " is dead. Cannot breathe fire." << endl;
        return;
    }

    if (fireLevel < 20) {
        cout << name << " doesn't have enough fire!" << endl;
        return;
    }

    if (energy < 15) {
        cout << name << " is too tired to breathe fire." << endl;
        return;
    }

    cout << name << " breathes fire: FWOOOOSH!" << endl;
    fireLevel -= 20;
    energy -= 15;
    hunger += 15;
    happiness += 10;

    if (hunger > 100) hunger = 100;
    if (happiness > 100) happiness = 100;
    if (fireLevel < 0) fireLevel = 0;
}