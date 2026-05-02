#include <iostream>
#include <string>
#include "petClass.cpp"
#include "dogClass.cpp"
#include "catClass.cpp"
#include "dragonClass.cpp"

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
    activePet = NULL;
    isRunning = true;
    petName = "";
    createPetMenu();
}

//destructor
GameManager::~GameManager() {
    if (activePet != NULL) {
        delete activePet;
        activePet = NULL;
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
    cout << "Status: " << (activePet->isAlive() ? "  ALIVE" : "  DEAD") << endl;
    
    if (activePet->isAlive()) {
        cout << "Hungry: " << (activePet->isHungry() ? "  YES" : "? No") << endl;
        cout << "Tired: " << (activePet->isTired() ? "  YES" : "? No") << endl;
        cout << "Sick: " << (activePet->isSick() ? "  YES" : "? No") << endl;
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
        if (cat != NULL) {
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
        if (dog != NULL) {
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
        if (dragon != NULL) {
            if (choice == 'b') {
                dragon->breatheFire();
                return;
            }
        }
    }
    cout << "Unknown command. Press H for controls." << endl;
}


//handle user input
void GameManager::handleInput() {
    char choice;
    cout << "\nEnter command: ";
    cin >> choice;
    
    choice = tolower(choice);
    
    if (!activePet) return;
    
    switch (choice) {
        case 'f':
            if (activePet->isAlive()) {
                float amount;
                cout << "How much food? (10-50): ";
                cin >> amount;
                if (amount < 10) amount = 10;
                if (amount > 50) amount = 50;
                activePet->feed(amount);
            } else {
                cout << activePet->getName() << " is dead." << endl;
            }
            break;
            
        case 'p':
            if (activePet->isAlive()) {
                activePet->play();
            } else {
                cout << activePet->getName() << " is dead." << endl;
            }
            break;
            
        case 's':
            if (activePet->isAlive()) {
                activePet->sleep();
            }
            break;
            
        case 'm':
            if (activePet->isAlive()) {
                activePet->makeSound();
            }
            break;
            
        case 'd':
            activePet->draw();
            break;
            
        case 't':
            displayStats();
            break;
            
        case 'h':
            showControls();
            break;
            
        case 'q':
            cout << "\nGoodbye! Thanks for playing!" << endl;
            isRunning = false;
            break;
            
        default:
            usePetAction(choice);
            break;
    }
}

//update game state
void GameManager::update() {
    if (activePet != NULL && activePet->isAlive()) {
        activePet->update(1.0f);
    }
}

//main game loop
void GameManager::run() {
    showControls();
    
    while (isRunning && activePet != NULL && activePet->isAlive()) {
        displayStats();
        handleInput();
        update();
    }
    
    if (activePet != NULL && !activePet->isAlive()) {
        cout << "\n " << activePet->getName() << " has died! Game Over!" << endl;
        cout << "\nRestart the program to get a new pet." << endl;
    }
}
