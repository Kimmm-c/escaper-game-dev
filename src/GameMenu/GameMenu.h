#include <string>
using namespace std;

class GameMenu {
    int menuOption;
    string text;

public:
    GameMenu(int option, string text);
    void displayMenu();

private:
    int getMenuOption() const;
    string getMenuText();
};