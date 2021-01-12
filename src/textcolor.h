#include <windows.h>

/*
 - This Default Color Code -

 * Dark Black: 1
 * Dark Green: 2
 * Dark Aqua: 3
 * Dark Red: 4
 * Purple: 5
 * Dark Yellow: 6
 * Gray: 7
 * Dark Gray: 8
 * Blue: 9
 * Green: 10
 * Aqua: 11
 * Red: 12
 * Pink: 13
 * Yellow: 14
 * White: 15
 */

void textcolor(int get_color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), get_color);
}