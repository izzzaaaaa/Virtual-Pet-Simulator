#include <iostream>
#include <string> 
#include "petClass.h"
using namespace std;


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

string Pet::getName() const {
    return name;
}
float Pet::getHunger() const{ 
    return hunger;
}
float Pet::getEnergy() const{
    return energy;
}
float Pet::getHappiness() const{
    return happiness;
}
float Pet::getHealth() const{
    return health;
}
int Pet::getAge() const{
    return age;
}
void Pet::setName(string n){
    name=n;
}
void Pet::setHunger(float h){
    hunger=h;
}
void Pet::setEnergy(float e){
    energy=e;
}
void Pet::setHappiness(float h){
    happiness=h;
}
void Pet::setHealth(float H){
    health=H;
}
void Pet::setAge(int a){
    age=a;
}

ostream& operator<<(ostream& os, const Pet& pet) { //operator overloading used here
    os << "Name: " << pet.name << endl;
    os << "Hunger: " << pet.hunger << endl;
    os << "Energy: " << pet.energy << endl;
    os << "Happiness: " << pet.happiness << endl;
    os << "Health: " << pet.health << endl;
    return os;
}