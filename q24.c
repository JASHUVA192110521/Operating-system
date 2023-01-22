#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Create a new file
    int fd = creat("example.txt", 0644);
    if (fd == -1) {
        printf("Error creating file\n");
        return 1;
    }

    // Write to the file
    char* text = "Hello, this is a text written to the file\n";
    write(fd, text, sizeof(text));

    // Close the file
    close(fd);

    // Open the file for reading
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file for reading\n");
        return 1;
    }

    // Read from the file
    char buffer[100];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        printf("Error reading from file\n");
        return 1;
    }
    printf("Read from file: %s\n", buffer);

    // Close the file
    close(fd);

    // Remove the file
    if (remove("example.txt") != 0) {
        printf("Error deleting file\n");
        return 1;
    }

    return 0;
}
