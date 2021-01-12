#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "sendlogs.h"
#include "debugging.h"

bool running = true;
bool return_to_main = true; // Help key handler
bool toggled = false;

bool tab_mode = false;
int tab_open_count = 0;

bool debug = false;

int count = 0;
void logo();

void get_help_button() {
    if (return_to_main) {
        send_log("Insert: On Toggle Sprint", 14, true);
        send_log("Delete: Off Toggle Sprint", 14, true);
        send_log("Pause: Exit program and debugging", 14, true);
        send_log("End: Exit program", 14, true);
    }
}

int main(int argc, char **argv) {
    system("title=BE_ToggleSprint-1.0v");
    logo();
    Sleep(500);
    
    printf("BE Toggle Sprint Program\n");
    printf("\n");
    printf("Made by Project_TL\n");
    printf("Version 1.0v\n");

    Sleep(3000);
    system("mode con cols=70 lines=30");

    while (running) { // Start Program
        get_help_button();
        return_to_main = false;

        if (GetKeyState(VK_INSERT) < 0) {
            toggled = true;
            
            send_log("[Sprint_Manager] ", 0, false);
            send_log("Toggle Sprinting... ", 10, false);
            send_log("Count: ", 14, false);
            printf("%d\n", count);

            send_log("[Attention] If you want to off toggle sprint, You'll press keyboard \"Delete\" button.", 14, true);
            send_log("[Attention] If you want to use tab(Creating Table, Furnace, etc...), You'll press keyboard \"E\" Button.", 14, true);

            while (toggled) { // Start Toggle
                keybd_event(VK_CONTROL, 0, 0, 0);
                Sleep(10);
                if (GetKeyState(0x45) < 0) {
                    tab_mode = true;
                    keybd_event(VK_CONTROL, 0, 0x0002, 0);
                    
                    send_log("[Sprint_Manager] ", 0, false);
                    send_log("Join the tab.. ", 10, false);
                    send_log("Count: ", 14, false);
                    printf("%d\n", tab_open_count);

                    while (tab_mode) { // Tab mode
                        Sleep(10);
                        if (GetKeyState(VK_ESCAPE) < 0) {
                            tab_mode = false;

                            send_log("[Sprint_Manager] ", 0, false);
                            send_log("Quit the tab.. ", 10, false);
                            send_log("Count: ", 14, false);
                            printf("%d\n", tab_open_count);
                        }
                    }

                    tab_open_count++;

                } else if (GetKeyState(VK_DELETE) < 0) {
                    keybd_event(VK_CONTROL, 0, 0x0002, 0);
                    toggled = false;
                    return_to_main = true; // Print help key message handler
                }
            }

            system("cls");
            send_log("[Sprint_Manager] ", 0, false);
            send_log("Stoped Toggle Sprint. ", 12, false);
            send_log("Count: ", 14, false);
            printf("%d\n", count);

            printf("\n");

            count++;
        } else if (GetKeyState(VK_PAUSE) < 0) {
            debug = true;
            running = false;
        } else if (GetKeyState(VK_END) < 0) {
            running = false;
        }
    }

    debugging(debug, running, toggled, tab_mode, count, tab_open_count);

    return 0;
}

void logo() {
    printf("======================================================================================\n");
    
    printf("= ");
    send_log("============     ======        ======        ======     ==            ============", 14, false);
    printf(" =\n");
    
    printf("= ");
    send_log("============    ========      ========      ========    ==            ============", 14, false);
    printf(" =\n");
    
    printf("= ");
    send_log("     ==       ==        ==  ==        ==  ==        ==  ==            ==          ", 14, false);
    printf(" =\n");

    printf("= ");
    send_log("     ==       ==        ==  ==        ==  ==        ==  ==            ==          ", 14, false);
    printf(" =\n");

    printf("= ");
    send_log("     ==       ==        ==  ==            ==            ==            ============", 14, false);
    printf(" =\n");

    printf("= ");
    send_log("     ==       ==        ==  ==     =====  ==            ==            ============", 14, false);
    printf(" =\n");

    printf("= ");
    send_log("     ==       ==        ==  ==     =====  ==     =====  ==            ==          ", 14, false);
    printf(" =\n");
    
    printf("= ");
    send_log("     ==       ==        ==  ==        ==  ==        ==  ==            ==          ", 14, false);
    printf(" =\n");
    
    printf("= ");
    send_log("     ==         ========      ========      ========    ============  ============", 14, false);
    printf(" =\n");
    
    printf("= ");
    send_log("     ==          ======        ======        ======     ============  ============", 14, false);
    printf(" =\n");
    
    printf("======================================================================================\n");
    printf("\n");
}