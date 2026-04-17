#include<stdio.h>
#include<string.h>

struct Student {
    int id;
    char name[50];
    char attendance[15];
};

union Status {
    char remark[25];
    char flag;
};

int main() {
    struct Student s[50];
    union Status st;
    int count, i, option;
    char choice;

    printf("Enter number of students (max 50): ");
    scanf("%d",&count);
    getchar();

    for (i = 0; i < count; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Enter Student ID: ");
        scanf("%d",&s[i].id);
        getchar();

        printf("Enter Student Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        strcpy(s[i].attendance, "Not Marked");
    }

    do {
        printf("\n===== STUDENT ATTENDANCE MANAGEMENT =====\n");
        printf("1. Mark Attendance\n");
        printf("2. View Attendance\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&option);
        getchar();

        switch (option) {

            case 1: {
                int j = 0;
                while (j < count) {
                    char mark;
                    printf("Mark attendance for %s (P/A): ", s[j].name);
                    scanf(" %c",&mark);

                    if (mark == 'P' || mark == 'p')
                        strcpy(s[j].attendance, "Present");
                    else if (mark == 'A' || mark == 'a')
                        strcpy(s[j].attendance, "Absent");
                    else
                        strcpy(s[j].attendance, "Invalid");

                    j++;
                }
                printf("\nAttendance marked successfully!\n");
                break;
            }

            case 2:
                printf("\nID\tName\t\tAttendance\n");
                printf("-------------------------------------\n");

                for (i = 0; i < count; i++) {
                    printf("%d\t%-15s%s\n", s[i].id, s[i].name, s[i].attendance);
                }
                break;

            case 3: {
                int id, found = 0;
                printf("Enter Student ID to search: ");
                scanf("%d",&id);

                for (i = 0; i < count; i++) {
                    if (s[i].id == id) {
                        found = 1;

                        printf("\nStudent Found:\n");
                        printf("ID: %d\nName: %s\nAttendance: %s\n",
                               s[i].id, s[i].name, s[i].attendance);

                        if (strcmp(s[i].attendance, "Present") == 0)
                            strcpy(st.remark, "Good Attendance");
                        else if (strcmp(s[i].attendance, "Absent") == 0)
                            strcpy(st.remark, "Needs Improvement");
                        else
                            strcpy(st.remark, "Not Marked");

                        printf("Status Remark: %s\n", st.remark);
                        break;
                    }
                }

                if (!found)
                    printf("Student with ID %d not found!\n", id);

                break;
            }

            case 4:
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c",&choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Student Attendance Management System!\n");
    return 0;
}