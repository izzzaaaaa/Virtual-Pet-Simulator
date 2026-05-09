#pragma once
#include "petClass.h"
#include <string>
using namespace std;

class GameManager {
public:
    GameManager();
    ~GameManager();
    void run();

private:
    bool handleInput();
    void update();
    void displayStats();
    void showControls();
    void createPetMenu();
    void usePetAction(char choice);
    void saveGame();
    void loadGame();

    Pet* activePet;
    bool isRunning;
    string petName;
};
