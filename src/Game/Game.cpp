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
{ }
//, optionMenu(new GameOptionMenu())
//, collisionSystem(new CollisionSystem())
//, renderSystem(new RenderSystem())

Game::~Game() {
    delete mainMenu;
//    delete optionMenu;
//    delete collisionSystem;
//    delete renderSystem;
};

int Game::getUserSelection(const GameMenu* menu) {
    int menuSelection;
    int upperBound = menu->getMenuOption();

    menu->displayMenu();

    cin >> menuSelection;

    while (cin.fail() or menuSelection < 1 or menuSelection > upperBound) {
        // Use cin.clear to reset the fail flag to original state.
        // Use cin.ignore to clear out the buffer
        // (numeric_limits<streamsize>::max(), '\n') clears all the characters in the buffer up to and including \n
        // OR the entire buffer size (streamsize).
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number from 1-6" << endl;
        cin >> menuSelection;
    }

    return menuSelection;
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

    // Prompt for main menu selection
    int mainMenuSelection = getUserSelection(mainMenu);
    cout << "selection: " << mainMenuSelection << endl;

    while (mainMenuSelection == 1) {
        displayGameGuide();
        mainMenuSelection = getMainMenuSelection();
    }

    while (mainMenuSelection == 4) {
        // prompt for difficulty selection

        // set difficulty level

        mainMenuSelection = getMainMenuSelection();
    }

    while (mainMenuSelection == 5) {
        // prompt for map dimension

        // set map dimension

        mainMenuSelection = getMainMenuSelection();
    }

    switch (mainMenuSelection) {
        case 2:
            // config game settings
            break;
        case 3:
            // get data from saved txt file

            // config game settings with the saved data

            break;

        case 6:
            return;
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



