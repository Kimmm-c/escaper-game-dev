# Escaper

**Escaper** is a C++ text-based adventure game where the player must navigate a grid-based map, using arrow keys to move from the top-left corner to the bottom-right corner while avoiding walls. The difficulty level and map size can be customized to provide a unique challenge each time you play.

## Features
- **Customizable difficulty levels**: Choose from Easy, Normal, or Hard, which determines how long the map will remain visible before disappearing (10, 7, and 5 seconds, respectively).
- **Map grid customization**: Adjust the size of the map grid before starting the game.
- **Default gameplay mode**: Start a new game immediately with default settings (Easy difficulty and a 3x3 map grid).
- **Mid-game menu**: Pause the game to start a new game, exit, or resume the current game.

## How to Set Up the Game
When starting the game, players can choose one of two setup options:
1. **Customize the game**:
    - **Difficulty Level**:
        - Easy: The map is displayed for 10 seconds.
        - Normal: The map is displayed for 7 seconds.
        - Hard: The map is displayed for 5 seconds.
    - **Map Grid**: Set the size of the grid (e.g., 3x3, 4x4, etc.).
2. **Start a New Game Immediately**: The game will start with default settings:
    - Difficulty Level: Easy
    - Map Grid: 3x3

## How to Play
- You start at the **top-left corner** of the map.
- The objective is to reach the **bottom-right corner** without hitting any walls.
- Move your character using the following keys:
    - **Up**: ↑
    - **Down**: ↓
    - **Left**: ←
    - **Right**: →
- If you hit a wall, you lose the game.
- After the map is displayed for the designated countdown time, the map will disappear, so you'll need to remember the layout!

### Mid-Game Menu
During gameplay, you can access the mid-game menu by pressing the designated key. In the menu, you can:
- **Start a New Game**: Restart the game with the current settings or new settings.
- **Exit the Game**: Quit the game entirely.
- **Resume Game**: Continue the current game where you left off.


## Compatibility
This game is compatible with **MacOS** only.


## How to Compile and Run
1. Clone the repository:
    ```bash
    git clone https://github.com/Kimmm-c/escaper-game-dev.git
    ```
2.  Navigate to the project directory:
    ```bash
    cd escaper-game-dev
    ```
3. Compile the game:
    ```bash
    g++ -std=c++17 main.cpp -o escaper
    ```
4. Run the game:
    ```bash
    ./escaper
    ```