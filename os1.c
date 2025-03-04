#include <stdio.h>
#include <string.h>

// Define the structure for process information
struct process
{
    int process_id;
    char arrival_time[5];
    char departure_time[5];
};

// Function to input process information
void input_process_info(struct process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter process_id for process %d: ", i + 1);
        scanf("%d", &p[i].process_id);
        printf("Enter arrival_time in 24-hour format for process %d: ", i + 1);
        scanf("%s", p[i].arrival_time);
        printf("Enter departure_time in 24-hour format for process %d: ", i + 1);
        scanf("%s", p[i].departure_time);
    }
}

// Function to output process information
void output_process_info(struct process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nProcess Information for Process %d:\n", i + 1);
        printf("Process ID: %d\n", p[i].process_id);
        printf("Arrival Time: %s\n", p[i].arrival_time);
        printf("Departure Time: %s\n", p[i].departure_time);
    }
}

// Function to search process by ID
void search_process_by_id(struct process p[], int n, int search_id)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].process_id == search_id)
        {
            printf("\nProcess found!\n");
            printf("Process ID: %d\n", p[i].process_id);
            printf("Arrival Time: %s\n", p[i].arrival_time);
            printf("Departure Time: %s\n", p[i].departure_time);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nProcess with ID %d not found!\n", search_id);
    }
}

int main()
{
    int n, search_id;
    int choice;

    // Initial menu prompt
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n]; // Array to hold processes

    do
    {
        // Menu display
        printf("\nMenu:\n");
        printf("1. Input Process Information\n");
        printf("2. Output All Process Information\n");
        printf("3. Search Process by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Input process information
            input_process_info(p, n);
            break;

        case 2:
            // Output all processes information
            output_process_info(p, n);
            break;

        case 3:
            // Search process by ID
            printf("\nEnter the process ID to search: ");
            scanf("%d", &search_id);
            search_process_by_id(p, n, search_id);
            break;

        case 4:
            // Exit program
            printf("\nExiting program.\n");
            break;

        default:
            // Invalid option
            printf("\nInvalid choice! Please enter a valid option.\n");
            break;
        }
    } while (choice != 4); // Repeat until the user chooses to exit

    return 0;
}
