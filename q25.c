#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    // Open a file
    int fd = open("example.txt", O_RDWR);
    if (fd == -1) {
        printf("Error opening file\n");
        return 1;
    }

    // Get the file status
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        printf("Error getting file status\n");
        return 1;
    }
    printf("File size: %ld bytes\n", file_stat.st_size);

    // Change the file access mode
    int flags = fcntl(fd, F_GETFL);
    flags |= O_APPEND;
    fcntl(fd, F_SETFL, flags);

    // Seek to the end of the file
    lseek(fd, 0, SEEK_END);

    // Write to the file
    char* text = "This is a new line appended to the file\n";
    write(fd, text, sizeof(text));

    // Close the file
    close(fd);

    // Open a directory
    DIR* dir = opendir(".");
    if (dir == NULL) {
        printf("Error opening directory\n");
        return 1;
    }

    // Read the directory contents
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}
