/*
PESU Employee Management System
PART - A
1. Create an employee
-Name
-EmpID
-B_Group
-DOB
-Department Designation

2. Employee Rules - set of rules for each employee - set no input needed
- Leaves
- Exam Duty
- Reporting Time
- Dress Code

3. Employee Facilities - set of facilities for each employee - set no input needed
- Insurance
- Parking Pass
- Food Pass
- Gym
- Library
- Tickets for Concerts
- Vacations
- Team Outings

4. Display Employee Details
Keep any one department and display all the employees in that department
4a)HOD
4b)Dean of department
4c)Associate Professor
4d)Assistant Professor
4e)Lab Instructor
4f)Attender

PART - B

Print the 4th part that is employee details in the following format and print it in a csv called PESU.csv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Structure to store employee details
typedef struct
{
    char name[50];
    int empID;
    char bGroup[10];
    char dob[11];
    char department[50];
    char designation[50];
} Employee;

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

// Array to store employee details
Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

// Function prototypes
void createEmployee();
void displayEmployeeRules();
void displayEmployeeFacilities();
void displayAndWriteToCSV(char *department);
void disp_emp(Employee *x, int count);

int main()
{
    int choice;
    char department[50];

    do
    {
        printf("\nPESU Employee Management System\n");
        printf("1. Create an employee\n");
        printf("2. Display employees by department and write to CSV\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createEmployee();
            break;
        case 2:
            displayEmployeeRules();
        case 3:
            displayEmployeeFacilities();
        case 4:
            disp_emp(employees, numEmployees);
            break;
        case 5:
            printf("Enter the department: ");
            scanf("%s", department);
            displayAndWriteToCSV(department);
            disp_emp(employees, numEmployees);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to create a new employee
void createEmployee()
{
    if (numEmployees >= MAX_EMPLOYEES)
    {
        printf("Maximum number of employees reached.\n");
        return;
    }

    Employee *emp = &employees[numEmployees];

    printf("Enter employee name: ");
    scanf("%s", emp->name);
    printf("Enter employee ID: ");
    scanf("%d", &emp->empID);
    printf("Enter employee blood group: ");
    scanf("%s", emp->bGroup);
    printf("Enter employee date of birth (DD/MM/YYYY): ");
    scanf("%s", emp->dob);
    printf("Enter employee department: ");
    scanf("%s", emp->department);
    printf("Enter employee designation: ");
    scanf("%s", emp->designation);

    numEmployees++;
    printf("Employee added successfully.\n");
}

// Function to display employee rules
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
    struct EmployeeFacilities facilities = {"INR 5 Lakh for the whole family of the Employee", "Four and Two wheeler", "INR 3000 per month", "Free Yearly Membership", "Unlimited Access", "One for the employee and a plus onme", "One week Paid Leave", "One Per Year"};

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

// Function to display employees by department and write to CSV
void displayAndWriteToCSV(char *department)
{
    int found = 0;
    int count;
    printf("Enter the number of employees: ");
    scanf("%d", &count);
    FILE *file = fopen("PESU.csv", "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "Name,Employee ID,Blood Group,Date of Birth,Department,Designation\n");

    printf("\nEmployees in the %s department:\n", department);

    for (int i = 0; i < numEmployees; i++)
    {
        if (strcmp(employees[i].department, department) == 0)
        {
            printf("Name: %s\n", employees[i].name);
            printf("Employee ID: %d\n", employees[i].empID);
            printf("Blood Group: %s\n", employees[i].bGroup);
            printf("Date of Birth: %s\n", employees[i].dob);
            printf("Department: %s\n", employees[i].department);
            printf("Designation: %s\n\n", employees[i].designation);

            fprintf(file, "%s,%d,%s,%s,%s,%s\n", employees[i].name, employees[i].empID, employees[i].bGroup, employees[i].dob, employees[i].department, employees[i].designation);

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
        printf("No employees found in the %s department.\n", department);
        remove("PESU.csv"); // Remove the empty CSV file
    }
}

void disp_emp(Employee *x, int count)
{
    printf("Enter employee department(ECE/CS/BT/PHY/CHEM): ");
    char dept[4];
    scanf("%s", dept);

    printf("Employees display: \n");
    for (int j = 0; j < count; j++)
    {
        if (x->department == dept)
        {
            for (int i = 0; i < count; i++)
            {
                if ((x + i)->designation == "HOD")
                {
                    printf("HOD: %s\n", (x + i)->designation);
                }

                else if ((x + i)->designation == "DEAN")
                {
                    printf("DEAN: %s\n", (x + i)->designation);
                }
            }
            for (int i = 0; i < count; i++)
            {
                printf("Associate Professors: \n");
                if ((x + i)->designation == "Associate Professor")
                {
                    printf("%s\n", (x + i)->designation);
                }
            }
            for (int i = 0; i < count; i++)
            {
                printf("Associate Professors: \n");
                if ((x + i)->designation == "Associate Professor")
                {
                    printf("%s", (x + i)->designation);
                }
            }
            for (int i = 0; i < count; i++)
            {
                printf("Assisstant Professors: \n");
                if ((x + i)->designation == "Assisstant Professor")
                {
                    printf("%s", (x + i)->designation);
                }
            }
            for (int i = 0; i < count; i++)
            {
                printf("Lab instructor: \n");
                if ((x + i)->designation == "Lab instructor")
                {
                    printf("%s", (x + i)->designation);
                }
            }
            for (int i = 0; i < count; i++)
            {
                printf("Attendor: \n");
                if ((x + i)->designation == "Attendor")
                {
                    printf("%s", (x + i)->designation);
                }
            }
        }
    }
}