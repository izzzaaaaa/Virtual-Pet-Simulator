#include <iostream>
using namespace std;


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

// Dog constructor
Dog::Dog(string n) : Pet(n) {
    loyalty = 90;
}

void Dog::makeSound() {
    cout << name << " says: Woof! Woof!" << endl;
}

void Dog::draw() {
    cout << "  / ^..^ \\" << endl;
    cout << " ( o    o )" << endl;
    cout << "  \\  --  / " << endl;
    cout << "  " << name << " the Dog" << endl;
}

string Dog::getType() {
    return "Dog";
}

void Dog::bark() {
    if (!alive) {
        cout << name << " is dead. Cannot bark." << endl;
        return;
    }
    cout << name << " barks loudly: WOOF WOOF!" << endl;
    energy -= 5;
    happiness += 8;
    if (happiness > 100) happiness = 100;
    if (energy < 0) energy = 0;
}

void Dog::fetch() {
    if (!alive) {
        cout << name << " is dead. Cannot fetch." << endl;
        return;
    }

    if (energy < 20) {
        cout << name << " is too tired to fetch." << endl;
        return;
    }

    cout << name << " fetched the ball!" << endl;
    energy -= 20;
    hunger += 10;
    happiness += 15;
    loyalty += 5;

    if (happiness > 100) happiness = 100;
    if (hunger > 100) hunger = 100;
    if (loyalty > 100) loyalty = 100;
}