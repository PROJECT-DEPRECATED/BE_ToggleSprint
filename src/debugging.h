#include <stdio.h>
#include <windows.h>

void color(int get_color);

void debugging(
    bool debug_status,
    bool run_status,
    bool toggle_status,
    bool tab_status,
    int sprint_count,
    int tab_count
) {
    if (debug_status) { // Debug code
        system("cls");

        color(10);
        printf("[Debug] Start report...\n\n"); // Report Start
        Sleep(2000);

        color(15);
        printf("Start debug: boolean\n"); // Start status boolean
        Sleep(1000);

        color(14);
        printf("Running Status: "); // Running
        
        color(13);
        printf("%s\n", run_status ? "true" : "false");
        Sleep(2000);

        color(14);
        printf("Toggle Status: "); // Toggle

        color(13);
        printf("%s\n", toggle_status ? "true" : "false");
        Sleep(2000);

        color(14);
        printf("Tab Status: "); // Tab

        color(13);
        printf("%s\n", tab_status ? "true" : "false");
        Sleep(2000);
        
        color(15);
        printf("\nEnd debug: boolean\n\n"); // End status boolean
        Sleep(1000);
        
        printf("Start debug: Counter\n"); // Start status counters
        Sleep(1000);

        color(14);
        printf("Toggle Sprint Count: "); // Toggle Sprint

        color(15);
        printf("%d\n", sprint_count);
        Sleep(1000);

        color(14);
        printf("Enter Tab Count: "); // Tab
            
        color(15);
        printf("%d\n", tab_count);
        Sleep(1000);

        printf("\nEnd debug: Counters\n"); // End status counter
        Sleep(1000);

        color(12);
        printf("\n[Debug] Ending report...\n\n"); // Report End

        color(14);
        printf("This counter is only using debugging purposes.");
        printf("\n");

        color(15);
        system("pause");
    }
}

// Imported by textcolor.h
void color(int get_color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), get_color);
}