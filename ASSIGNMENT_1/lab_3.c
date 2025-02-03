#include <stdio.h>
#include <string.h>

struct records {
    int roll;
    char name[100];
    float marks;
};

int main() {
    int n;
    char name_input[100];

    printf("Enter the number of student records you want to enter: ");
    scanf("%d", &n);
    getchar(); // Consume the newline character left by scanf

    struct records students[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the record of the student %d\n", i + 1);

        printf("Enter the name: ");
        gets(name_input);

        strcpy(students[i].name, name_input);

        printf("Enter the roll number: \n");
        scanf("%d", &students[i].roll);
        getchar(); // Consume the newline character left by scanf

        printf("Enter the marks: \n");
        scanf("%f", &students[i].marks);
        getchar(); // Consume the newline character left by scanf

        printf("\n"); // Add a newline for better readability
    }

    printf("These are the student records:\n");
    for (int i = 0; i < n; i++) {
        printf("Name of the student: %s\n", students[i].name);
        printf("Roll number of the student: %d\n", students[i].roll);
        printf("Marks of the student: %f\n\n", students[i].marks);
    }

    return 0;
}