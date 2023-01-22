#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME_LENGTH 20
#define MAX_DIRS 10

struct file {
    char name[MAX_NAME_LENGTH];
    int size;
};

struct directory {
    struct file files[MAX_FILES];
    int file_count;
    char name[MAX_NAME_LENGTH];
};

struct second_level_directory {
    struct directory dirs[MAX_DIRS];
    int dir_count;
    char name[MAX_NAME_LENGTH];
};

void init_directory(struct second_level_directory *dir) {
    dir->dir_count = 0;
}

void add_directory(struct second_level_directory *dir, char *name) {
    strcpy(dir->dirs[dir->dir_count].name, name);
    dir->dirs[dir->dir_count].file_count = 0;
    dir->dir_count++;
}

void add_file(struct second_level_directory *dir, char *dir_name, char *file_name, int size) {
    int i;
    for (i = 0; i < dir->dir_count; i++) {
        if (strcmp(dir->dirs[i].name, dir_name) == 0) {
            strcpy(dir->dirs[i].files[dir->dirs[i].file_count].name, file_name);
            dir->dirs[i].files[dir->dirs[i].file_count].size = size;
            dir->dirs[i].file_count++;
            break;
        }
    }
}

void delete_file(struct second_level_directory *dir, char *dir_name, char *file_name) {
    int i, j;
    for (i = 0; i < dir->dir_count; i++) {
        if (strcmp(dir->dirs[i].name, dir_name) == 0) {
            for (j = 0; j < dir->dirs[i].file_count; j++) {
                if (strcmp(dir->dirs[i].files[j].name, file_name) == 0) {
                    int k;
                    for (k = j; k < dir->dirs[i].file_count - 1; k++) {
                        dir->dirs[i].files[k] = dir->dirs[i].files[k + 1];
                    }
                    dir->dirs[i].file_count--;
                    break;
                }
            }
            break;
        }
