#include <stdio.h>
#include <stdbool.h>

#include "textcolor.h"

int default_value = 15; // Text Color: White

void send_log(char *get_char, int get_color, bool get_enter) {
    if (!get_enter) {
        if (get_color == 0) {
            printf("%s", get_char);
        } else {
            textcolor(get_color);
            printf("%s", get_char);

            textcolor(default_value);
        }
    } else {
        if (get_color == 0) {
            printf("%s\n", get_char);
        } else {
            textcolor(get_color);
            printf("%s\n", get_char);

            textcolor(default_value);
        }
    }
}