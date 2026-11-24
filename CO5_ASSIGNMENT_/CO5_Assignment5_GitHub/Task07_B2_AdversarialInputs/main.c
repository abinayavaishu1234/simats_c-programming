#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valid_group(const char *group) {
    const char *valid[] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
    for (size_t i = 0; i < sizeof valid / sizeof valid[0]; i++)
        if (strcmp(group, valid[i]) == 0) return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    char name[32];

    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        printf("Usage: %s <donor-name> <blood-group>\n", argv[0]);
        return 0;
    }
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <donor-name> <blood-group>\n", argv[0]);
        return 1;
    }
    if (!valid_group(argv[2])) {
        fprintf(stderr, "Invalid blood group: %s\n", argv[2]);
        return 1;
    }

    /* Bounded copy ensures the name always fits and is null-terminated. */
    snprintf(name, sizeof name, "%s", argv[1]);
    printf("Accepted donor name: %s\n", name);
    printf("Accepted blood group: %s\n", argv[2]);

    FILE *fp = fopen("donors_input.txt", "a");
    if (fp == NULL) {
        perror("donors_input.txt");
        return 1;
    }
    fprintf(fp, "%s,%s\n", name, argv[2]);
    if (fclose(fp) != 0) {
        perror("fclose");
        return 1;
    }
    printf("Record saved to donors_input.txt\n");
    return 0;
}
