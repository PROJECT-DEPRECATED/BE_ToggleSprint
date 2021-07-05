#include <stdio.h>

#include "textcolor.h"

const int default_value = 15; // Text Color: White

void logprintf(int get_color, char *get_char) {
     if (get_color == 0) {
        printf("%s", get_char);
    } else {
        textcolor(get_color);
        printf("%s", get_char);

        textcolor(default_value);
    }
}

void logprintln(int get_color, char *get_char) {
    if (get_color == 0) {
        printf("%s\n", get_char);
    } else {
        textcolor(get_color);
        printf("%s\n", get_char);

        textcolor(default_value);
    }
}