#include <stdio.h>
#include <dirent.h>

int main() {
    DIR* dir = opendir("."); // Open the current directory

    if (dir == NULL) {
        printf("Error opening directory\n");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name); // Print the name of each entry in the directory
    }

    closedir(dir); // Close the directory

    return 0;
}
