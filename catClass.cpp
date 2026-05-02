#include <iostream>
using namespace std;

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

//cat constructor
Cat::Cat(string n) : Pet(n) {
    playfulness = 80;
}

void Cat::makeSound() {
    cout << name << " says: Meow! Meow!" << endl;
}

// Cat draw 
void Cat::draw() {
    cout << "   /\\_/\\  " << endl;
    cout << "  ( o.o ) " << endl;
    cout << "   > ^ <  " << endl;
    cout << "  " << name << " the Cat" << endl;
}

//cat getType 
string Cat::getType() {
    return "Cat";
}

//cat specific functions
void Cat::purr() {
    if (!alive) {
        cout << name << " is dead. Cannot purr." << endl;
        return;
    }
    cout << name << " purrs: Prrrrrrr Prrrrrr..." << endl;
    happiness += 5;
    if (happiness > 100){
        happiness = 100;
    }
}

void Cat::scratch() {
    if (!alive) {
        cout << name << " is dead. Cannot scratch." << endl;
        return;
    }
    
    if (energy < 10) {
        cout << name << " is too tired to scratch." << endl;
        return;
    }
    
    cout << name << " scratches the furniture!" << endl;
    energy -= 10;
    happiness += 10;
    if (happiness > 100) {
        happiness = 100;
    }
}