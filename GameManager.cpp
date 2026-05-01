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