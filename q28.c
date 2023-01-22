#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string to search for> <file name>\n", argv[0]);
        return 1;
    }

    char* search_string = argv[1];
    char* file_name = argv[2];

    // Open the file
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[1024];
    int line_number = 1;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, search_string) != NULL) {
            printf("%d: %s", line_number, line);
        }
        line_number++;
    }

    fclose(fp);

    return 0;
}
