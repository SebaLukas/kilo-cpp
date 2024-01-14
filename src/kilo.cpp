#include <iostream>

#include <stdlib.h>
#include <cstdint>
#include <termios.h>
#include <unistd.h>

termios original_terminos;

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_terminos);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &original_terminos);
    atexit(disableRawMode);

    termios raw = original_terminos;

    raw.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {

    enableRawMode();

    uint8_t c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
        std::cout << "Output: " << c << "\n";
    };

    return 0;
}
