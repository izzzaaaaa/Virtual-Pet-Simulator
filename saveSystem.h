#pragma once
#include "petClass.h"

class SaveSystem {
public:
    static void saveGame(const Pet& pet);
    static void loadGame(Pet& pet);
};
