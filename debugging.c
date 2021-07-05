#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#include "textcolor.h"

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

        textcolor(10);
        printf("[Debug] Start report...\n\n"); // Report Start
        Sleep(2000);

        textcolor(15);
        printf("Start debug: boolean\n"); // Start status boolean
        Sleep(1000);

        textcolor(14);
        printf("Running Status: "); // Running
        
        textcolor(13);
        printf("%s\n", run_status ? "true" : "false");
        Sleep(2000);

        textcolor(14);
        printf("Toggle Status: "); // Toggle

        textcolor(13);
        printf("%s\n", toggle_status ? "true" : "false");
        Sleep(2000);

        textcolor(14);
        printf("Tab Status: "); // Tab

        textcolor(13);
        printf("%s\n", tab_status ? "true" : "false");
        Sleep(2000);
        
        textcolor(15);
        printf("\nEnd debug: boolean\n\n"); // End status boolean
        Sleep(1000);
        
        printf("Start debug: Counter\n"); // Start status counters
        Sleep(1000);

        textcolor(14);
        printf("Toggle Sprint Count: "); // Toggle Sprint

        textcolor(15);
        printf("%d\n", sprint_count);
        Sleep(1000);

        textcolor(14);
        printf("Enter Tab Count: "); // Tab
            
        textcolor(15);
        printf("%d\n", tab_count);
        Sleep(1000);

        printf("\nEnd debug: Counters\n"); // End status counter
        Sleep(1000);

        textcolor(12);
        printf("\n[Debug] Ending report...\n\n"); // Report End

        textcolor(14);
        printf("This counter is only using debugging purposes.");
        printf("\n");

        textcolor(15);
        system("pause");
    }
}