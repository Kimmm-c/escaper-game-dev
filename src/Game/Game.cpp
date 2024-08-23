#include <iostream>
#include "Game.h"

using namespace std;

Game::Game()
: mainMenu(new GameMenu(6, "Please choose one of the following options to proceed:\n"
                           "1. Game Guide\n"
                           "2. Start a New Game\n"
                           "3. Load Existing Game\n"
                           "4. Difficulty\n"
                           "5. Map Grid\n"
                           "6. Exit"))
//, optionMenu(new GameOptionMenu())
//, collisionSystem(new CollisionSystem())
//, renderSystem(new RenderSystem())

Game::~Game() {
    delete mainMenu;
//    delete optionMenu;
//    delete collisionSystem;
//    delete renderSystem;
};

int Game::getMainMenuSelection() {
    int menuSelection;
    cout << mainMenu->getMenuText() << endl;

    cin >> menuSelection;

    while (cin.fail() or menuSelection < 1 or menuSelection > 6) {
        cout << "Invalid input. Please enter a number from 1-6" << endl;
        cin >> menuSelection;
    }

    return menuSelection;
};

int Game::getDifficultySelection() {
    int difficulty;
    cout << "Please choose one of the following options to proceed:\n"
            "1. Ease\n"
            "2. Normal\n"
            "3. Hard" << endl;

    cin >> difficulty;

    while (cin.fail() or difficulty < 1 or difficulty > 3) {
        cout << "Invalid input. Please enter a number from 1-3" << endl;
        cin >> difficulty;
    }

    return difficulty;
}



void Game::displayGameGuide() {

};

void Game::setDifficultyLevel() {

};

void Game::config() {

};

void Game::handleInput() {

};

void Game::update() {

};

void Game::render() {

};

void Game::run() {
    // Pre-game
    int difficulty;
    int mapGrid;

    // Prompt for menu selection
    int menuSelection = getMainMenuSelection();

    while (menuSelection == 1) {
        displayGameGuide();
        menuSelection = getMainMenuSelection();
    }

    while (menuSelection == 4) {
        // prompt for difficulty selection

        // set difficulty level

        menuSelection = getMainMenuSelection();
    }

    while (menuSelection == 5) {
        // prompt for map dimension

        // set map dimension

        menuSelection = getMainMenuSelection();
    }

    switch (menuSelection) {
        case 2:
            // config game settings
            break;
        case 3:
            // get data from saved txt file

            // config game settings with the saved data

            break;

        case 6:
            return 0;
    }

    // Game loop
    // Display map
    // Prompt user input
    // Process user input (validate input, go to next step if input is valid, otherwise, re-prompt
    // Update player and enemies components
    // Render

    // Post-game
    // Display main menu
};



