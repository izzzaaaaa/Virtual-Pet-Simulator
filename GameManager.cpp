#include <iostream>
#include <string>
#include "petClass.cpp"

using namespace std;

//headers
class GameManager{
public:
    GameManager();
    ~GameManager();
    void run();

private:
    void handleInput();
    void update();
    void displayStats();
    void showControls();
    void createPetMenu();
    void usePetAction(char choice);

    Pet* activePet;
    bool isRunning;
    string petName;
};

//constructor
GameManager::GameManager() {
    activePet = nullptr;
    isRunning = true;
    petName = "";
    createPetMenu();
}

//destructor
GameManager::~GameManager() {
    if (activePet != nullptr) {
        delete activePet;
        activePet = nullptr;
    }
}

//menu for pet
void GameManager::createPetMenu() {
    int choice;
    string name;
    
    cout << "\n========================================" << endl;
    cout << "     VIRTUAL PET SIMULATOR" << endl;
    cout << "========================================" << endl;
    cout << "\nChoose your pet:" << endl;
    cout << "1. Cat" << endl;
    cout << "2. Dog" << endl;
    cout << "3. Dragon" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;
    
    cout << "Enter a name for your pet: ";
    cin >> name;
    petName = name;
    
    switch (choice) {
        case 1:
            activePet = new Cat(name);
            cout << "\n You chose a Cat named " << name << "!" << endl;
            break;
        case 2:
            activePet = new Dog(name);
            cout << "\n You chose a Dog named " << name << "!" << endl;
            break;
        case 3:
            activePet = new Dragon(name);
            cout << "\n You chose a Dragon named " << name << "!" << endl;
            break;
        default:
            cout << "Invalid choice. Defaulting to Cat." << endl;
            activePet = new Cat(name);
            break;
    }
    
    cout << "\nYour new pet has joined you!" << endl;
}

//stats display
void GameManager::displayStats() {
    if (!activePet) return;
    
    cout << "\n========================================" << endl;
    cout << "Pet: " << activePet->getName() << " (" << activePet->getType() << ")" << endl;
    cout << "Status: " << (activePet->isAlive() ? "?? ALIVE" : "?? DEAD") << endl;
    
    if (activePet->isAlive()) {
        cout << "Hungry: " << (activePet->isHungry() ? "?? YES" : "? No") << endl;
        cout << "Tired: " << (activePet->isTired() ? "?? YES" : "? No") << endl;
        cout << "Sick: " << (activePet->isSick() ? "?? YES" : "? No") << endl;
    }
    cout << "========================================" << endl;
}


//controls
void GameManager::showControls() {
    cout << "\n========== CONTROLS ==========" << endl;
    cout << "F - Feed your pet" << endl;
    cout << "P - Play with your pet" << endl;
    cout << "S - Put pet to sleep" << endl;
    cout << "M - Make pet sound" << endl;
    cout << "D - Draw pet" << endl;
    cout << "T - Show stats" << endl;
    cout << "H - Show controls" << endl;
    cout << "Q - Quit game" << endl;
    
    //showing pet specific controls
    if (activePet) {
        string petType = activePet->getType();
        if (petType == "Cat") {
            cout << "\n--- CAT SPECIALS ---" << endl;
            cout << "R - Purr" << endl;
            cout << "C - Scratch" << endl;
        } else if (petType == "Dog") {
            cout << "\n--- DOG SPECIALS ---" << endl;
            cout << "B - Bark" << endl;
            cout << "E - Fetch" << endl;
        } else if (petType == "Dragon") {
            cout << "\n--- DRAGON SPECIALS ---" << endl;
            cout << "B - Breathe Fire" << endl;
        }
    }
    cout << "===============================" << endl;
}

// Handle pet specific actions
void GameManager::usePetAction(char choice) {
    if (!activePet || !activePet->isAlive()) {
        if (activePet && !activePet->isAlive()) {
            cout << activePet->getName() << " is dead!" << endl;
        }
        return;
    }
    
    string petType = activePet->getType();
    
    //cat actions
    if (petType == "Cat") {
        Cat* cat = dynamic_cast<Cat*>(activePet);
        if (cat != nullptr) {
            if (choice == 'r') {
                cat->purr();
                return;
            }
            if (choice == 'c') {
                cat->scratch();
                return;
            }
        }
    }
    
    //dog actions
    if (petType == "Dog") {
        Dog* dog = dynamic_cast<Dog*>(activePet);
        if (dog != nullptr) {
            if (choice == 'b') {
                dog->bark();
                return;
            }
            if (choice == 'e') {
                dog->fetch();
                return;
            }
        }
    }
    
    //dragon actions
    if (petType == "Dragon") {
        Dragon* dragon = dynamic_cast<Dragon*>(activePet);
        if (dragon != nullptr) {
            if (choice == 'b') {
                dragon->breatheFire();
                return;
            }
        }
    }
    cout << "Unknown command. Press H for controls." << endl;
}
