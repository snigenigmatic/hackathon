#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_OPTIONS 10
#define MAX_OPTION_LENGTH 30

void displayMenu(const char *title, const char *options[], int numOptions) {
    printf("\n=== %s ===\n", title);
    for (int i = 0; i < numOptions; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }
    printf("0. Exit\n");
}

int getUserChoice(int numOptions) {
    int choice;
    char input[MAX_OPTION_LENGTH];
    do {
        printf("Enter your choice: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            return -1; // Error reading input
        }
        if (sscanf(input, "%d", &choice) != 1 || choice < 0 || choice > numOptions) {
            printf("Invalid input. Please enter a number between 0 and %d: ", numOptions);
        } else {
            break;
        }
    } while (1);
    return choice;
}

void handleSubmenuOption(int choice, const char *options[], int numOptions) {
    if (choice >= 1 && choice <= numOptions) {
        printf("%s selected.\n", options[choice - 1]);
        // Add your option handling code here
    } else {
        printf("Returning to main menu...\n");
    }
}

void mainMenu() {
    const char *mainMenuTitle = "Main Menu";
    const char *mainMenuOptions[] = {"Submenu 1", "Submenu 2"};
    int numMainMenuOptions = sizeof(mainMenuOptions) / sizeof(mainMenuOptions[0]);

    const char *submenu1Title = "Submenu 1";
    const char *submenu1Options[] = {"Submenu 1 - Option 1", "Submenu 1 - Option 2"};
    int numSubmenu1Options = sizeof(submenu1Options) / sizeof(submenu1Options[0]);

    const char *submenu2Title = "Submenu 2";
    const char *submenu2Options[] = {"Submenu 2 - Option 1", "Submenu 2 - Option 2"};
    int numSubmenu2Options = sizeof(submenu2Options) / sizeof(submenu2Options[0]);

    int choice;
    do {
        displayMenu(mainMenuTitle, mainMenuOptions, numMainMenuOptions);
        choice = getUserChoice(numMainMenuOptions);
        switch (choice) {
            case 1:
                do {
                    displayMenu(submenu1Title, submenu1Options, numSubmenu1Options);
                    choice = getUserChoice(numSubmenu1Options);
                    handleSubmenuOption(choice, submenu1Options, numSubmenu1Options);
                } while (choice != 0);
                break;
            case 2:
                do {
                    displayMenu(submenu2Title, submenu2Options, numSubmenu2Options);
                    choice = getUserChoice(numSubmenu2Options);
                    handleSubmenuOption(choice, submenu2Options, numSubmenu2Options);
                } while (choice != 0);
                break;
            default:
                printf("Exiting...\n");
                break;
        }
    } while (choice != 0);
}

int main() {
    mainMenu();
    return 0;
}


/* How to Customize the Code:
Main Menu Title and Options:

Change the mainMenuTitle variable to your desired main menu title (e.g., "Main Management Menu").
Modify the mainMenuOptions array to include your main menu options (e.g., "Supplier Menu", "Car Garage Menu").
Update the numMainMenuOptions variable to reflect the number of main menu options.
Submenu Titles and Options:

Change the submenu1Title and submenu2Title variables to your desired submenu titles.
Modify the submenu1Options and submenu2Options arrays to include your specific submenu options.
Update the numSubmenu1Options and numSubmenu2Options variables to reflect the number of options in each submenu.
Handling Submenu Options:

Update the handleSubmenu1Option and handleSubmenu2Option functions to include the logic for each submenu option. Add more case statements if you have more options.
Example Customization:
If you want to create a management system for a car garage and supplier menu:

Main Menu:

c
Copy code
const char *mainMenuTitle = "Management System";
const char *mainMenuOptions[] = {
    "Car Garage Menu",
    "Supplier Menu"
};
int numMainMenuOptions = 2;
Car Garage Submenu:

c
Copy code
const char *submenu1Title = "Car Garage Menu";
const char *submenu1Options[] = {
    "Add Car",
    "View Cars"
};
int numSubmenu1Options = 2;
Supplier Submenu:

c
Copy code
const char *submenu2Title = "Supplier Menu";
const char *submenu2Options[] = {
    "Add Supplier",
    "View Suppliers"
};
int numSubmenu2Options = 2;
Update the handling functions to include the logic for each option in the car garage and supplier submenus.

This structure allows you to easily add more submenus and options as needed. If you have any further requirements or need additional features, feel free to ask!





 */