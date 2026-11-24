/* Task 1: Patient register using nested structures and a structure pointer */
#include <stdio.h>
#include <string.h>

struct Date { int day, month, year; };
struct BP { int systolic, diastolic; };
struct Patient {
    char name[50];
    char phone[11];
    int age;
    struct BP bp;
    struct Date visit;
};

static struct Patient patients[100];
static int count = 0;

void addPatient(const struct Patient *p)
{
    if (count >= 100) {
        printf("Patient register is full.\n");
        return;
    }
    patients[count++] = *p;
}

void displayPatients(void)
{
    int i;
    for (i = 0; i < count; i++) {
        printf("%s, Age %d, Phone %s, BP %d/%d, Visit %02d/%02d/%04d\n",
               patients[i].name, patients[i].age, patients[i].phone,
               patients[i].bp.systolic, patients[i].bp.diastolic,
               patients[i].visit.day, patients[i].visit.month,
               patients[i].visit.year);
    }
}

int main(void)
{
    struct Patient p = {"Arun", "9876543210", 35, {120, 80}, {24, 11, 2026}};
    addPatient(&p);
    displayPatients();
    return 0;
}
