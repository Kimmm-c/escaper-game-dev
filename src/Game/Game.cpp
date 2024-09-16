#include <iostream>
#include "Game.h"
#include "../Enums/Enums.h"

using namespace std;
using namespace Enums;

Game::Game()
        : mainMenu(new GameMenu(6, "Please choose one of the following options to proceed:\n"
                                   "1. Game Guide\n"
                                   "2. Start a New Game\n"
                                   "3. Load Existing Game\n"
                                   "4. Difficulty\n"
                                   "5. Map Grid\n"
                                   "6. Exit")),
          difficultyMenu(new GameMenu(3, "Please choose one of the following options to proceed:\n"
                                         "1. Easy\n"
                                         "2. Normal\n"
                                         "3. Hard")),
          mapMenu(new GameMenu(3, "Please choose one of the following options to proceed:\n"
                                  "1. 5x5\n"
                                  "2. 10x10\n"
                                  "3. 15x15")),
          gameSettings(new GameSettings()) {}
//, optionMenu(new GameOptionMenu())
//, collisionSystem(new CollisionSystem())
//, renderSystem(new RenderSystem())

Game::~Game() {
    delete mainMenu;
    delete difficultyMenu;
    delete mapMenu;
    delete gameSettings;
//    delete optionMenu;
//    delete collisionSystem;
//    delete renderSystem;
};

int Game::getUserSelection(const GameMenu *menu) {
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

void Game::config() {
    // Config map grid based on game settings
    switch (gameSettings->getMapGrid()) {
        case Level::NORMAL:
            map = new Map(4, 4);
            break;
        case Level::HARD:
            map = new Map(5, 5);
            break;
        default:
            map = new Map(3, 3);
    }

    // Config difficulty level based on game settings
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

    while (mainMenuSelection == 1 or mainMenuSelection == 4 or mainMenuSelection == 5) {
        if (mainMenuSelection == 1) {
            displayGameGuide();
        } else if (mainMenuSelection == 4) {
            difficulty = getUserSelection(difficultyMenu);
            gameSettings->setDifficulty(difficulty);
        } else {
            mapGrid = getUserSelection(mapMenu);
            gameSettings->setMapGrid(mapGrid);
        }
        mainMenuSelection = getUserSelection(mainMenu);
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

    start();

    // Post-game
    // Display main menu
};

void Game::start() {
    config();
}


