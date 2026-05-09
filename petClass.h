#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pet {
public:
    Pet(string name);
    virtual ~Pet() {};

    // pure virtual - subclasses must implement these
    virtual void makeSound() = 0;
    virtual void draw() = 0;
    virtual string getType() = 0;

    // virtual with defaults
    virtual void feed(float amount);
    virtual void play();
    virtual void sleep();
    virtual void update(float deltaTime);

    // status checks
    bool isAlive();
    bool isHungry();
    bool isTired();
    bool isSick();

    // getters
    string getName() const;
    float getHunger() const;
    float getEnergy() const;
    float getHappiness() const;
    float getHealth() const;
    int getAge() const;

    // setters
    void setName(string n);
    void setHunger(float h);
    void setEnergy(float e);
    void setHappiness(float h);
    void setHealth(float H);
    void setAge(int a);

protected:
    string name;
    float hunger;
    float energy;
    float happiness;
    float health;
    int age;
    bool alive;
};
