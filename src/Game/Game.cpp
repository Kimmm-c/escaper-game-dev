#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <unistd.h>
#include <fstream>

#include "Game.h"
#include "../Utils/Utils.h"

using namespace std;
using namespace Enums;

Game::Game()
        : mainMenu(new GameMenu(5, "Please choose one of the following options to proceed:\n"
                                   "1. Game Guide\n"
                                   "2. Start Game\n"
                                   "3. Difficulty\n"
                                   "4. Map Grid\n"
                                   "5. Exit")),
          difficultyMenu(new GameMenu(3, "Please choose one of the following options to proceed:\n"
                                         "1. Easy\n"
                                         "2. Normal\n"
                                         "3. Hard")),
          mapMenu(new GameMenu(3, "Please choose one of the following options to proceed:\n"
                                  "1. 3x3\n"
                                  "2. 4x4\n"
                                  "3. 5x5")),
          midGameMenu(new GameMenu(3, "Please choose one of the following options to proceed:\n"
                                  "1. Exit\n"
                                  "2. Start a New Game\n"
                                  "3. Resume")),
          gameSettings(new GameSettings()),
          physicEngine(new PhysicEngine()),
          player(new Player(0, 0)),
          countdownClock(5) {}

Game::~Game() {
    delete mainMenu;
    delete difficultyMenu;
    delete mapMenu;
    delete gameSettings;
    delete midGameMenu;
    delete physicEngine;
    delete map;
    delete player;
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
        cout << "Invalid input. Please enter a number from 1 to " << menu->getMenuOption() << endl;
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
    switch (gameSettings->getDifficulty()) {
        case Level::NORMAL:
            setCountdownClock(7);
            break;
        case Level::HARD:
            setCountdownClock(5);
            break;
        default:
            setCountdownClock(10);
    }
};

void Game::gameInit() {
    int difficulty;
    int mapGrid;

    // Prompt for main menu selection
    int mainMenuSelection = getUserSelection(mainMenu);
    cout << "selection: " << mainMenuSelection << endl;

    while (mainMenuSelection == 1 or mainMenuSelection == 3 or mainMenuSelection == 4) {
        if (mainMenuSelection == 1) {
            displayGameGuide();
        } else if (mainMenuSelection == 3) {
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
            config();
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid input." << endl;
    }
}

void Game::run() {
    gameInit();

    bool isRunning = true;

    while (isRunning) {
        start();

        if (gameState == GameState::RESTART) {
            gameInit();
        } else {
            isRunning = false;
        }
    }

    switch (gameState) {
        case GameState::WIN:
            cout << "YOU WIN!!!" << endl;
            break;
        case GameState::LOSE:
            cout << "YOU LOSE..." << endl;
            break;
        case GameState::EXIT:
            cout << "Exiting game..." << endl;
            break;
    }
};

void Game::start() {
    pair<uint8_t, uint8_t> dest = getDestination();
    bool isRunning = true;
    bool isCollided;
    int direction;

    // Display map for the countdown amount of time
    map->draw();
    cout << "Map will disappear after " << static_cast<int>(countdownClock) << " seconds..." << endl;
    this_thread::sleep_for(chrono::seconds(5));

    // Clear map from the terminal
    // Consider another version for Windows
    setenv("TERM", "xterm-256color", 1);
    system("clear");

    // Accepting non-blocking keyboard input
    // Consider another version for Windows
    Utils::setNonBlockingInput(true);
    cout << "Please enter your moves consecutively: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char move;

    // If user enter a move
    // Validate the move
    // Display the move as arrow on the console
    // Use physic engine to detect collision using current position and next visited position
    while (isRunning) {
        move = getchar();       // Get input without blocking
        if (move != EOF) {
            /*
             * Arrow input is represented by an escape character '\033' followed by a sequence of characters,
             * which is usually '[A', where 'A' is the actual arrow key code.
             * Up:      '\033[A'
             * Down:    '\033[B'
             * Right:   '\033[C'
             * Left:    '\033[D'
             */
            if (move == '\033') {
                getchar();          // Skip the '[' character
                move = getchar();   // Get the actual arrow key code

                switch (move) {
                    case 'A':
                        cout << "up" << endl;
                        direction = Direction::UP;
                        break;
                    case 'B':
                        cout << "down" << endl;
                        direction = Direction::DOWN;
                        break;
                    case 'C':
                        cout << "right" << endl;
                        direction = Direction::RIGHT;
                        break;
                    case 'D':
                        cout << "left" << endl;
                        direction = Direction::LEFT;
                        break;
                    default:
                        cout << "Invalid input." << endl;
                }

                isCollided = physicEngine->detectCollision(player->getPosition(), direction, map);

                // If there is collision, set game state to Lose. Else, update the player's position.
                if (isCollided) {
                    gameState = GameState::LOSE;
                    isRunning = false;
                } else {
                    player->setPosition(map->getNextPosition(player->getPosition(), direction));
                    // If, after updating the position, player arrives at the destination, set game state to Win.
                    if (player->getPosition() == dest) {
                        gameState = GameState::WIN;
                        isRunning = false;
                    }
                }
            } else if (move == 'q') {
                Utils::setNonBlockingInput(false);

                int selection = getUserSelection(midGameMenu);

                if (selection == 3) {
                    cout << "Please continue with the moves..." << endl;
                    Utils::setNonBlockingInput(true);
                } else {
                    switch (selection) {
                        case 1:
                            gameState = GameState::EXIT;
                            break;
                        case 2:
                            gameState = GameState::RESTART;
                            break;
                        default:
                            cout << "Something is wrong..." << endl;
                    }
                    isRunning = false;
                }
            } else {
                cout << "Invalid input." << endl;
            }
        }
        usleep(10000); // Sleep to prevent CPU overuse
    }

    Utils::setNonBlockingInput(false);
}

uint8_t Game::getCountdownClock() const {
    return countdownClock;
}

void Game::setCountdownClock(uint8_t sec) {
    countdownClock = sec;
}

pair<uint8_t, uint8_t> Game::getDestination() const {
    return make_pair(map->getWidth() - 1, map->getHeight() -1);
}

