#include <stdio.h>
#include <string.h>

#define MAX_DONORS 10

typedef struct {
    int id;
    char name[40];
    char group[4];
    int age;
    int days_since_last_donation;
} Donor;

typedef struct {
    char group[4];
    int units;
} Stock;

int register_donor(Donor donors[], int *count, Donor donor);
int is_eligible(const Donor *donor);
int find_eligible(const Donor donors[], int count, const char *group,
                  int *eligible_count, int *youngest_id);
int update_stock(Stock stocks[], int stock_count, const char *group, int change);

int register_donor(Donor donors[], int *count, Donor donor) {
    if (*count >= MAX_DONORS) return 0;
    donors[*count] = donor;
    (*count)++;
    return 1;
}

int is_eligible(const Donor *donor) {
    return donor->age >= 18 && donor->age <= 65 &&
           donor->days_since_last_donation >= 90;
}

int find_eligible(const Donor donors[], int count, const char *group,
                  int *eligible_count, int *youngest_id) {
    int found = 0, youngest_age = 1000;
    *eligible_count = 0;
    *youngest_id = -1;

    for (int i = 0; i < count; i++) {
        if (strcmp(donors[i].group, group) == 0 && is_eligible(&donors[i])) {
            (*eligible_count)++;
            found = 1;
            if (donors[i].age < youngest_age) {
                youngest_age = donors[i].age;
                *youngest_id = donors[i].id;
            }
        }
    }
    return found;
}

int update_stock(Stock stocks[], int stock_count, const char *group, int change) {
    for (int i = 0; i < stock_count; i++) {
        if (strcmp(stocks[i].group, group) == 0) {
            if (stocks[i].units + change < 0) return 0;
            stocks[i].units += change;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    Donor donors[MAX_DONORS];
    int count = 0, eligible_count, youngest_id;
    Stock stocks[] = {{"O+", 20}, {"A+", 15}, {"B-", 8}, {"AB+", 5}};

    Donor d1 = {1001, "Arun", "O+", 24, 120};
    Donor d2 = {1002, "Kavin", "O+", 17, 150};
    Donor d3 = {1003, "Maya", "A+", 30, 100};

    register_donor(donors, &count, d1);
    register_donor(donors, &count, d2);
    register_donor(donors, &count, d3);

    find_eligible(donors, count, "O+", &eligible_count, &youngest_id);
    printf("Eligible O+ donors: %d\n", eligible_count);
    if (youngest_id != -1) printf("Youngest eligible donor ID: %d\n", youngest_id);

    if (update_stock(stocks, 4, "O+", -2))
        printf("Updated O+ stock: %d units\n", stocks[0].units);
    else
        printf("Stock update failed\n");

    return 0;
}
