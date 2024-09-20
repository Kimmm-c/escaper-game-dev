#include "Utils.h"

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <iostream>

void Utils::setNonBlockingInput(bool enable) {
    /*
     * Set the terminal mode to non-blocking.
     * Non-blocking (non-canonical) allows the keyboard input to be sent
     * to the program immediately without waiting for the Enter key.
     *
     * Note: Why we have to enable BOTH non-canonical mode (of the terminal) AND non-blocking mode (of the file descriptor)?
     * Non-canonical: Characters are made available to the program without waiting for the use to press Enter.
     * Non-blocking: Allows the read() system call to return immediately with a result of -1 if no input available instead
     * of waiting (blocking) for an input.
     */
    termios ttystate;
    // tcgetattr retrieves the terminal settings for Standard input
    // from STDIN_FILENO and store it in ttystate, which represents a terminal
    tcgetattr(STDIN_FILENO, &ttystate);

    int flags = fcntl(STDIN_FILENO, F_GETFL, 0); // 0 is the dummy value because there is no argument needed to perform F_GETFL

    if (enable) {
        // c_lflag: A set of bits, where each bit represents a terminal mode.
        // We use bitwise operator to Enable/Disable a terminal mode.
        // Example: c_lflag = 1010 1010, with the bit 7 (left most) represents the Canonical mode.
        // To disable this mode, we will turn c_lflag into 0010 1010 with the bitmask 0111 1111 and the bitwise operator &.
        // And we achieve the bitmask 0111 1111 by negating ICANON
        ttystate.c_lflag &= ~ICANON;                    // Disable canonical mode to allow non-blocking
        ttystate.c_lflag &= ~ECHO;                      // Prevent the keyboard input to be logged to the console.
        tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);    // Apply the changes to STDIN immediately with TCSANOW.

        // Set input as non-blocking
        // fcntl() is used to manipulate file descriptor.
        // To set the std input to non-blocking, we first retrieves the flags from the file descriptor using the command F_GETFL.
        // Then we set the bit representing non-blocking to 1 by using the bitwise operator | in conjunction with 0_NONBLOCK.
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    } else {
        // Restore the original terminal settings
        ttystate.c_lflag |= ICANON;
        ttystate.c_lflag |= ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
        fcntl(STDIN_FILENO, F_SETFL, flags & ~O_NONBLOCK);
    }

}

void Utils::clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}