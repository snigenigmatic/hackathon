#include <stdio.h>
#include <stdlib.h>

#define MAX_MENU_OPTIONS 10

void displayMenu(const char *title, const char *options[], int numOptions) {
    printf("\n=== %s ===\n", title);
    for (int i = 0; i < numOptions; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }
    printf("0. Exit\n");
}

int getUserChoice(int numOptions) {
    int choice;
    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1 || choice < 0 || choice > numOptions) {
        printf("Invalid input. Please enter a number between 0 and %d: ", numOptions);
        while (getchar() != '\n'); // clear the input buffer
    }
    return choice;
}

void handleSubmenu1Option(int choice) {
    switch (choice) {
        case 1:
            printf("Submenu 1 - Option 1 selected.\n");
            // Add your submenu 1 option 1 handling code here
            break;
        case 2:
            printf("Submenu 1 - Option 2 selected.\n");
            // Add your submenu 1 option 2 handling code here
            break;
        // Add more cases as needed for additional submenu 1 options
        default:
            printf("Returning to main menu...\n");
            break;
    }
}

void handleSubmenu2Option(int choice) {
    switch (choice) {
        case 1:
            printf("Submenu 2 - Option 1 selected.\n");
            // Add your submenu 2 option 1 handling code here
            break;
        case 2:
            printf("Submenu 2 - Option 2 selected.\n");
            // Add your submenu 2 option 2 handling code here
            break;
        // Add more cases as needed for additional submenu 2 options
        default:
            printf("Returning to main menu...\n");
            break;
    }
}

void mainMenu() {
    const char *mainMenuTitle = "Main Menu";
    const char *mainMenuOptions[] = {
        "Submenu 1",
        "Submenu 2"
    };
    int numMainMenuOptions = 2;

    int choice;
    do {
        displayMenu(mainMenuTitle, mainMenuOptions, numMainMenuOptions);
        choice = getUserChoice(numMainMenuOptions);
        switch (choice) {
            case 1:
                {
                    const char *submenu1Title = "Submenu 1";
                    const char *submenu1Options[] = {
                        "Submenu 1 - Option 1",
                        "Submenu 1 - Option 2"
                    };
                    int numSubmenu1Options = 2;

                    int submenu1Choice;
                    do {
                        displayMenu(submenu1Title, submenu1Options, numSubmenu1Options);
                        submenu1Choice = getUserChoice(numSubmenu1Options);
                        if (submenu1Choice != 0) {
                            handleSubmenu1Option(submenu1Choice);
                        }
                    } while (submenu1Choice != 0);
                }
                break;
            case 2:
                {
                    const char *submenu2Title = "Submenu 2";
                    const char *submenu2Options[] = {
                        "Submenu 2 - Option 1",
                        "Submenu 2 - Option 2"
                    };
                    int numSubmenu2Options = 2;

                    int submenu2Choice;
                    do {
                        displayMenu(submenu2Title, submenu2Options, numSubmenu2Options);
                        submenu2Choice = getUserChoice(numSubmenu2Options);
                        if (submenu2Choice != 0) {
                            handleSubmenu2Option(submenu2Choice);
                        }
                    } while (submenu2Choice != 0);
                }
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