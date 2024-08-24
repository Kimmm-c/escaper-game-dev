#include "./GameMenu.h"
#include <iostream>

GameMenu::GameMenu(int option, string text)
        : menuOption(option), text(text) {}

int GameMenu::getMenuOption() const {
    return menuOption;
}

string GameMenu::getMenuText() const {
    return text;
}

void GameMenu::displayMenu() const {
    cout << getMenuText() <<endl;
}

