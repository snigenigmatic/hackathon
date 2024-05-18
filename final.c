#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int Employee_ID;
    char name_Employee[50];
    char Blood_Group[10];
    char DOB[10];
    char dept[50];
    char desig[50];  
} Employee;

void displayMenu();
void createEmployee(Employee emp[], int *count);
void disp_emp(Employee emp[], int count);
void displayAndWriteToCSV(Employee emp[], int count, const char *dept);
void displayEmployeeRules();
void displayEmployeeFacilities();

enum MenuChoice 
{
    CREATE = 1,
    RULES,
    FACILITIES,
    DISPLAY,
    CSV,
    EXIT
};

#define MAX_EMPLOYEES 100

Employee emp[MAX_EMPLOYEES];

int main() {
    int choice;
    int numP = 0;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch ((enum MenuChoice)choice) {
            case CREATE:
                createEmployee(emp, &numP);
                break;
            case RULES:
                displayEmployeeRules();
                break;
            case FACILITIES:
                displayEmployeeFacilities();
                break;
            case DISPLAY:
                disp_emp(emp, numP);
                break;
            case CSV:
                {
                    char dept[50];
                    printf("Enter department to create CSV: ");
                    scanf("%49s", dept);
                    displayAndWriteToCSV(emp, numP, dept);
                }
                break;
            case EXIT:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while ((enum MenuChoice)choice != EXIT);

    return 0;
}

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

void createEmployee(Employee emp[], int *count) 
{
    if (*count >= MAX_EMPLOYEES) 
    {
        printf("Employee database full. Cannot add more employees.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &emp[*count].Employee_ID);
    printf("Enter Employee Name: ");
    scanf("%49s", emp[*count].name_Employee);
    printf("Enter Blood Group: ");
    scanf("%9s", emp[*count].Blood_Group);
    printf("Enter Date of Birth (DOB): ");
    scanf("%9s", emp[*count].DOB);
    printf("Enter Department: ");
    scanf("%49s", emp[*count].dept);
    printf("Enter Designation: ");
    scanf("%49s", emp[*count].desig);

    (*count)++;
}

void disp_emp(Employee emp[], int count)
{
    printf("Enter employee department (ECE/CS/BT/PHY/CHEM): ");
    char dept[50];
    scanf("%49s", dept);

    printf("Employees in %s department: \n", dept);

    int found = 0;

    for (int j = 0; j < count; j++)
    {
        if (strcmp(emp[j].dept, dept) == 0)
        {
            found = 1;
            printf("ID: %d, Name: %s, Blood Group: %s, DOB: %s, Department: %s, Designation: %s\n",
                emp[j].Employee_ID, emp[j].name_Employee, emp[j].Blood_Group, emp[j].DOB, emp[j].dept, emp[j].desig);
        }
    }

    if (!found)
    {
        printf("No employees found in the %s department.\n", dept);
    }
}

void displayAndWriteToCSV(Employee emp[], int count, const char *dept)
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

    for (int i = 0; i < count; i++)
    {
        if (strcmp(emp[i].dept, dept) == 0)
        {
            printf("Name: %s\n", emp[i].name_Employee);
            printf("Employee ID: %d\n", emp[i].Employee_ID);
            printf("Blood Group: %s\n", emp[i].Blood_Group);
            printf("Date of Birth: %s\n", emp[i].DOB);
            printf("Department: %s\n", emp[i].dept);
            printf("Designation: %s\n\n", emp[i].desig);

            fprintf(file, "%s,%d,%s,%s,%s,%s\n", emp[i].name_Employee, emp[i].Employee_ID, emp[i].Blood_Group, emp[i].DOB, emp[i].dept, emp[i].desig);

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

struct EmployeeRules
{
    char leaves[50];
    char examDuty[50];
    char reportingTime[50];
    char dressCode[50];
};

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
};

void displayEmployeeRules()
{
    struct EmployeeRules rules = {"10", "30 mins prior to exam start time", "9:00 AM", "Men- Formals or Casuals, Females - Saree or Suit"};

    printf("\nEmployee Rules:\n");
    printf("Leaves: %s\n", rules.leaves);
    printf("Exam Duty: %s\n", rules.examDuty);
    printf("Reporting Time: %s\n", rules.reportingTime);
    printf("Dress Code: %s\n", rules.dressCode);
}

void displayEmployeeFacilities()
{
    struct EmployeeFacilities facilities = {"INR 5 Lakh for the whole family of the Employee", "Four and Two wheeler", "INR 3000 per month", "Free Early Membership", "Unlimited Access", "One for the employee and a plus onme", "One week Paid Leave", "One Per Year"};
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