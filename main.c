#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "sendlog.h"
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
        logprintln(14, "Insert: On Toggle Sprint");
        logprintln(14, "Delete: Off Toggle Sprint");
        logprintln(14, "Pause: Exit program and debugging");
        logprintln(14, "End: Exit program");
    }
}

void boot_program() {
    system("title=BE_ToggleSprint-1.0v");
    logo();
    Sleep(500);
    
    printf("BE Toggle Sprint Program\n");
    printf("\n");
    printf("Made by Project_TL\n");
    printf("Version 1.0v\n");

    Sleep(3000);
    system("mode con cols=70 lines=30");
}

int main(int argc, char **argv) {
    boot_program();

    while (running) { // Start Program
        get_help_button();
        return_to_main = false;

        if (GetKeyState(VK_INSERT) < 0) {
            toggled = true;
            
            logprintf(0, "[Sprint_Manager] ");
            logprintf(10, "Toggle Sprinting... ");
            logprintf(14, "Count: ");
            printf("%d\n", count);

            logprintln(14, "[Attention] If you want to off toggle sprint, You'll press keyboard \"Delete\" button.");
            logprintln(14, "[Attention] If you want to use tab(Creating Table, Furnace, etc...), You'll press keyboard \"E\" Button.");

            while (toggled) { // Start Toggle
                keybd_event(VK_CONTROL, 0, 0, 0);
                Sleep(10);
                if (GetKeyState(0x45) < 0) {
                    tab_mode = true;
                    keybd_event(VK_CONTROL, 0, 0x0002, 0);
                    
                    logprintf(0, "[Sprint_Manager] ");
                    logprintf(10, "Join the tab.. ");
                    logprintf(14, "Count: ");
                    printf("%d\n", tab_open_count);

                    while (tab_mode) { // Tab mode
                        Sleep(10);
                        if (GetKeyState(VK_ESCAPE) < 0) {
                            tab_mode = false;

                            logprintf(0, "[Sprint_Manager] ");
                            logprintf(10, "Quit the tab.. ");
                            logprintf(14, "Count: ");
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
            logprintf(0, "[Sprint_Manager] ");
            logprintf(12, "Stoped Toggle Sprint. ");
            logprintf(14, "Count: ");
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
    logprintf(14, "============     ======        ======        ======     ==            ============");
    printf(" =\n");
    
    printf("= ");
    logprintf(14, "============    ========      ========      ========    ==            ============");
    printf(" =\n");
    
    printf("= ");
    logprintf(14, "     ==       ==        ==  ==        ==  ==        ==  ==            ==          ");
    printf(" =\n");

    printf("= ");
    logprintf(14, "     ==       ==        ==  ==        ==  ==        ==  ==            ==          ");
    printf(" =\n");

    printf("= ");
    logprintf(14, "     ==       ==        ==  ==            ==            ==            ============");
    printf(" =\n");

    printf("= ");
    logprintf(14, "     ==       ==        ==  ==     =====  ==            ==            ============");
    printf(" =\n");

    printf("= ");
    logprintf(14, "     ==       ==        ==  ==     =====  ==     =====  ==            ==          ");
    printf(" =\n");
    
    printf("= ");
    logprintf(14, "     ==       ==        ==  ==        ==  ==        ==  ==            ==          ");
    printf(" =\n");
    
    printf("= ");
    logprintf(14, "     ==         ========      ========      ========    ============  ============");
    printf(" =\n");
    
    printf("= ");
    logprintf(14, "     ==          ======        ======        ======     ============  ============");
    printf(" =\n");
    
    printf("======================================================================================\n");
    printf("\n");
}