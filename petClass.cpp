#include <iostream>
#include <string> 
#include "dogClass.cpp"
#include "catClass.cpp"
#include "dragonClass.cpp"
using namespace std;

class Pet {
public:
    Pet(string name);
    virtual ~Pet() {};

    virtual void makeSound() = 0;
    virtual void draw() = 0;
    virtual string getType() = 0;

    virtual void feed(float amount);
    virtual void play();
    virtual void sleep();
    virtual void update(float deltaTime);

    bool isAlive();
    bool isHungry();
    bool isTired();
    bool isSick();
    string getName();

protected:
    string name;
    float hunger;
    float energy;
    float happiness;
    float health;
    int age;
    bool alive;
};

//constructor
Pet::Pet(string n) {
    name = n;
    hunger = 50;
    energy = 80;
    happiness = 70;
    health = 100;
    age = 0;
    alive = true;
}

// Feed the pet
void Pet::feed(float amount) {
    if (!alive) {
        cout << name << " is dead. Cannot feed." << endl;
        return;
    }
    
    hunger = hunger - amount;
    if (hunger < 0) {
        hunger = 0;
    }
    
    happiness = happiness + (amount * 0.3);
    if (happiness > 100) {
        happiness = 100;
    }
    
    cout << name << " ate " << amount << " food." << endl;
}

//play with the pet
void Pet::play() {
    if (!alive) {
        cout << name << " is dead. Cannot play." << endl;
        return;
    }
    
    if (energy < 20) {
        cout << name << " is too tired to play." << endl;
        return;
    }
    
    happiness = happiness + 20;
    if (happiness > 100) {
        happiness = 100;
    }
    
    energy = energy - 15;
    hunger = hunger + 10;
    if (hunger > 100) {
        hunger = 100;
    }
    
    cout << name << " played happily!" << endl;
}

void Pet::update(float deltaTime) {
     if (!alive) {
        return;
    }
    
    //increases hunger over time
    hunger += 5 * deltaTime;
    if (hunger > 100) {
        hunger = 100;
    }
    //warning
    if (isHungry() && hunger < 95) {
        cout << name << " is getting hungry!" << endl;
    }
    
    //decreases energy over time  
    energy -= 3 * deltaTime;
    if (energy < 0) {
        energy = 0;
    }
    //warning
    if (isTired() && energy > 10) {
        cout << name << " is getting tired!" << endl;
    }
    
    //decreases happiness slowly
    happiness -= 2 * deltaTime;
    if (happiness < 0){
        happiness = 0;
    }
    //warning
    if (happiness < 30 && happiness > 10) {
        cout << name << " looks a bit sad..." << endl;
    }
    
    //checks if pet dies
    if (hunger >= 100 || energy <= 0 || health <= 0) {
        alive = false;
        cout << name << " has died!" << endl;
    }
}

// Make pet sleep
void Pet::sleep() {
    if (!alive) {
        return;
    }
    
    energy = energy + 40;
    if (energy > 100) {
        energy = 100;
    }
    
    hunger = hunger + 5;
    if (hunger > 100) {
        hunger = 100;
    }
    
    cout << name << " slept well." << endl;
}

// Getter functions
bool Pet::isAlive() {
    return alive;
}

bool Pet::isHungry() {
    return hunger > 70;
}

bool Pet::isTired() {
    return energy < 30;
}

bool Pet::isSick() {
    return health < 50;
}

string Pet::getName() {
    return name;
}

int main() {
    cout << "Hello from virtual pet simulator!" << endl;
    return 0;
}