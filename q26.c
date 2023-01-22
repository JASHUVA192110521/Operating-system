#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a new file
    FILE* fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error creating file\n");
        return 1;
    }

    // Write to the file
    fprintf(fp, "Hello, this is a text written to the file\n");

    // Close the file
    fclose(fp);

    // Open the file for reading
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading\n");
        return 1;
    }

    // Read from the file
    char buffer[100];
    fgets(buffer, sizeof(buffer), fp);
    printf("Read from file: %s\n", buffer);

    // Close the file
    fclose(fp);

    // Remove the file
    if (remove("example.txt") != 0) {
        printf("Error deleting file\n");
        return 1;
    }

    return 0;
}
