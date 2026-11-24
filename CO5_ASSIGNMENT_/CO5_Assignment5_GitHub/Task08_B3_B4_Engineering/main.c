#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

typedef struct {
    int id;
    char name[24];
    char group[4];
    int age;
    int days_since_last_donation;
} Donor;

typedef struct {
    Donor *data;
    size_t size;
    size_t capacity;
} DonorList;

static int add_donor(DonorList *list, Donor d) {
    if (list->size == list->capacity) {
        size_t new_capacity = list->capacity ? list->capacity * 2 : 16;
        Donor *temp = realloc(list->data, new_capacity * sizeof *temp);
        if (temp == NULL) return 0;
        list->data = temp;
        list->capacity = new_capacity;
    }
    list->data[list->size++] = d;
    return 1;
}

static double elapsed_seconds(clock_t start, clock_t end) {
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main(int argc, char **argv) {
    long n = 1000;
    if (argc > 1) {
        char *end = NULL;
        n = strtol(argv[1], &end, 10);
        if (*argv[1] == '\0' || *end != '\0' || n < 1 || n > 1000000) {
            fprintf(stderr, "Use a record count from 1 to 1000000\n");
            return 1;
        }
    }

    FILE *text = fopen("donors_b3.txt", "w");
    FILE *binary = fopen("donors_b3.bin", "wb");
    if (!text || !binary) {
        perror("open output file");
        if (text) fclose(text);
        if (binary) fclose(binary);
        return 1;
    }

    Donor sample;
    clock_t start = clock();
    for (long i = 0; i < n; i++) {
        sample.id = 100000 + (int)i;
        snprintf(sample.name, sizeof sample.name, "Donor%ld", i);
        snprintf(sample.group, sizeof sample.group, "%s", (i % 2) ? "A+" : "O+");
        sample.age = 20 + (int)(i % 40);
        sample.days_since_last_donation = 100;
        fprintf(text, "%d,%s,%s,%d,%d\n", sample.id, sample.name,
                sample.group, sample.age, sample.days_since_last_donation);
    }
    fclose(text);
    double text_write = elapsed_seconds(start, clock());

    start = clock();
    binary = fopen("donors_b3.bin", "wb");
    if (!binary) { perror("reopen binary"); return 1; }
    for (long i = 0; i < n; i++) {
        sample.id = 100000 + (int)i;
        snprintf(sample.name, sizeof sample.name, "Donor%ld", i);
        snprintf(sample.group, sizeof sample.group, "%s", (i % 2) ? "A+" : "O+");
        sample.age = 20 + (int)(i % 40);
        sample.days_since_last_donation = 100;
        if (fwrite(&sample, sizeof sample, 1, binary) != 1) {
            perror("fwrite"); fclose(binary); return 1;
        }
    }
    fclose(binary);
    double binary_write = elapsed_seconds(start, clock());

    long text_count = 0;
    char line[160];
    start = clock();
    text = fopen("donors_b3.txt", "r");
    if (!text) { perror("open text for read"); return 1; }
    while (fgets(line, sizeof line, text)) text_count++;
    fclose(text);
    double text_read = elapsed_seconds(start, clock());

    long binary_count = 0;
    start = clock();
    binary = fopen("donors_b3.bin", "rb");
    if (!binary) { perror("open binary for read"); return 1; }
    while (fread(&sample, sizeof sample, 1, binary) == 1) binary_count++;
    fclose(binary);
    double binary_read = elapsed_seconds(start, clock());

    /* In-place binary update: record index n/2. */
    start = clock();
    binary = fopen("donors_b3.bin", "rb+");
    if (!binary) { perror("open binary for update"); return 1; }
    long index = n / 2;
    if (fseek(binary, index * (long)sizeof(Donor), SEEK_SET) != 0 ||
        fread(&sample, sizeof sample, 1, binary) != 1) {
        fprintf(stderr, "Could not read selected binary record\n");
        fclose(binary); return 1;
    }
    sample.age = 45;
    if (fseek(binary, -(long)sizeof(Donor), SEEK_CUR) != 0 ||
        fwrite(&sample, sizeof sample, 1, binary) != 1) {
        fprintf(stderr, "Could not update selected binary record\n");
        fclose(binary); return 1;
    }
    fclose(binary);
    double binary_update = elapsed_seconds(start, clock());

    /* Rewrite text file to update the selected record. */
    start = clock();
    text = fopen("donors_b3.txt", "r");
    FILE *temp = fopen("donors_temp.txt", "w");
    if (!text || !temp) {
        perror("open text update files");
        if (text) fclose(text);
        if (temp) fclose(temp);
        return 1;
    }
    long row = 0;
    while (fgets(line, sizeof line, text)) {
        if (row == index) {
            sample.id = 100000 + (int)row;
            snprintf(sample.name, sizeof sample.name, "Donor%d", (int)row);
            snprintf(sample.group, sizeof sample.group, "%s", (row % 2) ? "A+" : "O+");
            sample.age = 45;
            sample.days_since_last_donation = 100;
            fprintf(temp, "%d,%s,%s,%d,%d\n", sample.id, sample.name,
                    sample.group, sample.age, sample.days_since_last_donation);
        } else {
            fputs(line, temp);
        }
        row++;
    }
    fclose(text);
    fclose(temp);
    remove("donors_b3.txt");
    rename("donors_temp.txt", "donors_b3.txt");
    double text_update = elapsed_seconds(start, clock());

    /* Growable list report: synthetic records, freed at the end. */
    DonorList list = {NULL, 0, 0};
    size_t eligible = 0;
    for (long i = 0; i < n; i++) {
        Donor d;
        d.id = 100000 + (int)i;
        snprintf(d.name, sizeof d.name, "Donor%ld", i);
        snprintf(d.group, sizeof d.group, "%s", (i % 2) ? "A+" : "O+");
        d.age = 20 + (int)(i % 40);
        d.days_since_last_donation = 100;
        if (!add_donor(&list, d)) {
            fprintf(stderr, "Memory allocation failed\n");
            free(list.data);
            return 1;
        }
        if (d.age >= 18 && d.age <= 65 && d.days_since_last_donation >= 90)
            eligible++;
    }

    printf("Records requested: %ld\n", n);
    printf("Text records read: %ld | Binary records read: %ld\n", text_count, binary_count);
    struct stat st_text, st_binary;
    long text_bytes = (stat("donors_b3.txt", &st_text) == 0) ? (long)st_text.st_size : -1;
    long binary_bytes = (stat("donors_b3.bin", &st_binary) == 0) ? (long)st_binary.st_size : -1;
    printf("Text file size: %ld bytes | Binary file size: %ld bytes\n", text_bytes, binary_bytes);
    printf("Text write: %.6f s | Binary write: %.6f s\n", text_write, binary_write);
    printf("Text read:  %.6f s | Binary read:  %.6f s\n", text_read, binary_read);
    printf("Binary in-place update: %.6f s | Text rewrite update: %.6f s\n",
           binary_update, text_update);
    printf("Growable list: size=%zu capacity=%zu eligible=%zu\n",
           list.size, list.capacity, eligible);
    printf("Approximate donor-array memory: %zu bytes\n", list.capacity * sizeof(Donor));

    free(list.data);
    list.data = NULL;
    return 0;
}
