#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50

struct employee {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
};

void write_employee(FILE *fp, struct employee emp) {
    fseek(fp, emp.id * sizeof(struct employee), SEEK_SET);
    fwrite(&emp, sizeof(struct employee), 1, fp);
}

struct employee read_employee(FILE *fp, int id) {
    struct employee emp;
    fseek(fp, id * sizeof(struct employee), SEEK_SET);
    fread(&emp, sizeof(struct employee), 1, fp);
    return emp;
}

int main() {
    FILE *fp = fopen("employee.dat", "wb+");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    struct employee emp1 = {1, "John Smith", 35, 50000};
    struct employee emp2 = {2, "Jane Doe", 32, 55000};
    struct employee emp3 = {3, "Bob Johnson", 40, 60000};

    write_employee(fp, emp1);
    write_employee(fp, emp2);
    write_employee(fp, emp3);

    struct employee read_emp = read_employee(fp, 1);
    printf("ID: %d, Name: %s, Age: %d, Salary: %f\n", read_emp.id, read_emp.name, read_emp.age, read_emp.salary);

    fclose(fp);
    return 0;
}
