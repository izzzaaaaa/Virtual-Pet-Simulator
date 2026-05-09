#include<iostream>
#include<string>
#include<fstream>
#include "petClass.cpp"
#include "dogClass.cpp"
#include "catClass.cpp"
#include "dragonClass.cpp"

using namespace std;

class SaveSystem{
    public:
    static void saveGame(const Pet& pet);
    static void loadGame(Pet& pet);
    
};
    void SaveSystem::saveGame(const Pet& pet){
        
    ofstream file("game_stats.txt");
    if(!file){
    cout<<"Could not open file for saving!" <<endl;
    return;
    }
        file << pet.getName() <<endl;
        file << pet.getHunger() <<endl;
        file << pet.getEnergy() <<endl;
        file << pet.getHappiness() <<endl;
        file << pet.getHealth() <<endl;
        file << pet.getAge() <<endl;

        file.close();
        cout<<"\nGame stats saved successfully!" <<endl<<endl;

}
    void SaveSystem::loadGame(Pet& pet){

    ifstream file("game_stats.txt");
    if(!file){
        cout<<"Could not open file for loading!" <<endl<<endl;
        return;
    }
    
    string name;
    float hunger, energy, happiness, health;
    int age;
    getline(file,name);
    file >> hunger >> energy >> happiness >> health >> age;

    pet.setName(name);
    pet.setHunger(hunger);
    pet.setEnergy(energy);
    pet.setHappiness(happiness);
    pet.setHealth(health);
    pet.setAge(age);

    file.close();
    cout<<"\nGame loaded successfully!" <<endl<<endl;
}