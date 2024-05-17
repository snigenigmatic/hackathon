#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void displayMenu();
void createEmployee(Employee **emp, int *numEmployees, int *maxEmployees);
void displayEmployees(Employee *emp, int numEmployees);
void displayAndWriteToCSV(Employee *emp, int numEmployees, const char *dept);
void displayEmployeeRules();
void displayEmployeeFacilities();
int getValidIntInput(const char *prompt);
void getValidStringInput(char *str, int maxLength, const char *prompt);

// Menu choices enum
enum MenuChoice
{
    CREATE = 1,
    RULES,
    FACILITIES,
    DISPLAY,
    CSV,
    EXIT
};

// Employee struct
typedef struct
{
    int employeeID;
    char name[50];
    char bloodGroup[10];
    char dob[10];
    char dept[50];
    char designation[50];
} Employee;

int main()
{
    Employee *employees = NULL;
    int numEmployees = 0;
    int maxEmployees = 0;
    int choice;

    do
    {
        displayMenu();
        choice = getValidIntInput("Enter your choice: ");

        switch ((enum MenuChoice)choice)
        {
        case CREATE:
            createEmployee(&employees, &numEmployees, &maxEmployees);
            break;
        case RULES:
            displayEmployeeRules();
            break;
        case FACILITIES:
            displayEmployeeFacilities();
            break;
        case DISPLAY:
            displayEmployees(employees, numEmployees);
            break;
        case CSV:
        {
            char dept[50];
            getValidStringInput(dept, sizeof(dept), "Enter department to create CSV: ");
            displayAndWriteToCSV(employees, numEmployees, dept);
        }
        break;
        case EXIT:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while ((enum MenuChoice)choice != EXIT);

    // Free dynamically allocated memory
    for (int i = 0; i < numEmployees; i++)
    {
        free(employees[i].name);
        free(employees[i].bloodGroup);
        free(employees[i].dob);
        free(employees[i].dept);
        free(employees[i].designation);
    }
    free(employees);

    return 0;
}

// Display the menu
void displayMenu()
{
    printf("--------------MENU--------------\n");
    printf("1> Create Employee\n");
    printf("2> Employee Rules\n");
    printf("3> Employee Facilities\n");
    printf("4> Display Employees\n");
    printf("5> Make CSV\n");
    printf("6> Exit\n");
    printf("-------------------------------\n");
}

// Create a new employee
void createEmployee(Employee **emp, int *numEmployees, int *maxEmployees)
{
    // Reallocate memory if needed
    if (*numEmployees == *maxEmployees)
    {
        *maxEmployees += 10;
        *emp = realloc(*emp, *maxEmployees * sizeof(Employee));
        if (*emp == NULL)
        {
            printf("Error: Memory allocation failed.\n");
            return;
        }
    }

    Employee *newEmployee = &(*emp)[*numEmployees];

    printf("Enter Employee ID: ");
    newEmployee->employeeID = getValidIntInput("");

    getValidStringInput(newEmployee->name, sizeof(newEmployee->name), "Enter Employee Name: ");
    getValidStringInput(newEmployee->bloodGroup, sizeof(newEmployee->bloodGroup), "Enter Blood Group: ");
    getValidStringInput(newEmployee->dob, sizeof(newEmployee->dob), "Enter Date of Birth (DOB): ");
    getValidStringInput(newEmployee->dept, sizeof(newEmployee->dept), "Enter Department: ");
    getValidStringInput(newEmployee->designation, sizeof(newEmployee->designation), "Enter Designation: ");

    (*numEmployees)++;
}

// Display employees based on department
void displayEmployees(Employee *emp, int numEmployees)
{
    char dept[50];
    getValidStringInput(dept, sizeof(dept), "Enter employee department: ");

    printf("Employees in %s department:\n", dept);

    int found = 0;

    for (int i = 0; i < numEmployees; i++)
    {
        if (strcmp(emp[i].dept, dept) == 0)
        {
            found = 1;
            printf("ID: %d, Name: %s, Blood Group: %s, DOB: %s, Department: %s, Designation: %s\n",
                   emp[i].employeeID, emp[i].name, emp[i].bloodGroup, emp[i].dob, emp[i].dept, emp[i].designation);
        }
    }

    if (!found)
    {
        printf("No employees found in the %s department.\n", dept);
    }
}

// Display and write employee details to a CSV file
void displayAndWriteToCSV(Employee *emp, int numEmployees, const char *dept)
{
    int found = 0;
    FILE *file = fopen("PESU.csv", "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "Name,Employee ID,Blood Group,Date of Birth,Department,Designation\n");

    printf("\nEmployees in the %s department:\n", dept);

    for (int i = 0; i < numEmployees; i++)
    {
        if (strcmp(emp[i].dept, dept) == 0)
        {
            printf("Name: %s\n", emp[i].name);
            printf("Employee ID: %d\n", emp[i].employeeID);
            printf("Blood Group: %s\n", emp[i].bloodGroup);
            printf("Date of Birth: %s\n", emp[i].dob);
            printf("Department: %s\n", emp[i].dept);
            printf("Designation: %s\n\n", emp[i].designation);

            fprintf(file, "%s,%d,%s,%s,%s,%s\n", emp[i].name, emp[i].employeeID, emp[i].bloodGroup, emp[i].dob, emp[i].dept, emp[i].designation);

            found = 1;
        }
    }

    fclose(file);

    if (found)
    {
        printf("Employee details written to PESU.csv successfully.\n");
    }
    else
    {
        printf("No employees found in the %s department.\n", dept);
        remove("PESU.csv"); // Remove the empty CSV file
    }
}

// Display employee rules
void displayEmployeeRules()
{
    struct EmployeeRules
    {
        char leaves[50];
        char examDuty[50];
        char reportingTime[50];
        char dressCode[50];
    } rules = {"10", "30 mins prior to exam start time", "9:00 AM", "Men- Formals or Casuals, Females - Saree or Suit"};

    printf("\nEmployee Rules:\n");
    printf("Leaves: %s\n", rules.leaves);
    printf("Exam Duty: %s\n", rules.examDuty);
    printf("Reporting Time: %s\n", rules.reportingTime);
    printf("Dress Code: %s\n", rules.dressCode);
}

// Display employee facilities
void displayEmployeeFacilities()
{
    struct EmployeeFacilities
    {
        char insurance[50];
        char parkingPass[50];
        char foodPass[50];
        char gym[50];
        char library[50];
        char ticketsForConcerts[50];
        char vacations[50];
        char teamOutings[50];
    } facilities = {"INR 5 Lakh for the whole family of the Employee", "Four and Two wheeler", "INR 3000 per month", "Free Early Membership", "Unlimited Access", "One for the employee and a plus one", "One week Paid Leave", "One Per Year"};

    printf("\nEmployee Facilities:\n");
    printf("Insurance: %s\n", facilities.insurance);
    printf("Parking Pass: %s\n", facilities.parkingPass);
    printf("Food Pass: %s\n", facilities.foodPass);
    printf("Gym: %s\n", facilities.gym);
    printf("Library: %s\n", facilities.library);
    printf("Tickets for Concerts: %s\n", facilities.ticketsForConcerts);
    printf("Vacations: %s\n", facilities.vacations);
    printf("Team Outings: %s\n", facilities.teamOutings);
}

// Get a valid integer input from the user
int getValidIntInput(const char *prompt)
{
    int value;
    char buffer[100];
    char *endPtr;

    while (1)
    {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character

        value = (int)strtol(buffer, &endPtr, 10);

        if (endPtr == buffer)
        {
            printf("Invalid input. Please enter an integer.\n");
        }
        else
        {
            return value;
        }
    }
}

// Get a valid string input from the user
void getValidStringInput(char *str, int maxLength, const char *prompt)
{
    char buffer[100];

    while (1)
    {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character

        if (strlen(buffer) == 0)
        {
            printf("Input cannot be empty. Please enter a valid string.\n");
        }
        else if (strlen(buffer) >= maxLength)
        {
            printf("Input is too long. Please enter a string shorter than %d characters.\n", maxLength);
        }
        else
        {
            strncpy(str, buffer, maxLength);
            str[maxLength - 1] = '\0'; // Ensure null termination
            break;
        }
    }
}