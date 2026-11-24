/* Task 6: Canteen inventory using nested structures and a tagged union */
#include <stdio.h>
#include <string.h>

typedef struct { int day, month, year; } Date;
typedef struct { int hour, minute; } Time;
typedef enum { PACKAGED, COOKED, COMBO } ItemType;

typedef struct { Date expiry; } PackInfo;
typedef struct { Time prepared; } CookInfo;
typedef struct { int component[3], qty[3], count; } ComboInfo;

typedef struct {
    int id;
    char name[40];
    float price;
    int stock;
    ItemType type;
    union {
        PackInfo pack;
        CookInfo cook;
        ComboInfo combo;
    } detail;
} Item;

typedef struct { char item_name[40]; int quantity; float revenue; } Sale;

int sell(Item *items, int n, int id, int qty, Sale *sales, int *sale_count)
{
    int i;
    for (i = 0; i < n; i++) {
        if (items[i].id == id) {
            if (qty <= 0 || qty > items[i].stock) {
                printf("Sale rejected for %s: insufficient stock.\n", items[i].name);
                return 0;
            }
            items[i].stock -= qty;
            strcpy(sales[*sale_count].item_name, items[i].name);
            sales[*sale_count].quantity = qty;
            sales[*sale_count].revenue = qty * items[i].price;
            (*sale_count)++;
            printf("Sale successful: %s x%d, stock=%d\n",
                   items[i].name, qty, items[i].stock);
            return 1;
        }
    }
    printf("Item ID not found.\n");
    return 0;
}

int date_value(Date d)
{
    return d.year * 10000 + d.month * 100 + d.day;
}

void warn_expiry(const Item *items, int n, Date today)
{
    int i;
    int today_value = date_value(today);
    for (i = 0; i < n; i++) {
        if (items[i].type == PACKAGED) {
            int expiry = date_value(items[i].detail.pack.expiry);
            if (expiry >= today_value && expiry <= today_value + 2)
                printf("Expiry warning: %s expires on %02d/%02d/%04d\n",
                       items[i].name, items[i].detail.pack.expiry.day,
                       items[i].detail.pack.expiry.month,
                       items[i].detail.pack.expiry.year);
        }
    }
}

void sort_revenue(Sale *s, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].revenue < s[j + 1].revenue) {
                Sale temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    Item items[3] = {
        {1, "Milk Packet", 30.0f, 5, PACKAGED, {.pack = {{26, 11, 2026}}}},
        {2, "Veg Sandwich", 45.0f, 5, COOKED, {.cook = {{8, 30}}}},
        {3, "Combo Meal", 80.0f, 4, COMBO, {.combo = {{1, 2, 0}, {1, 1, 0}, 2}}}
    };
    Sale sales[10];
    int sale_count = 0;

    sell(items, 3, 1, 2, sales, &sale_count);
    sell(items, 3, 2, 6, sales, &sale_count);
    sell(items, 3, 3, 1, sales, &sale_count);

    warn_expiry(items, 3, (Date){24, 11, 2026});
    sort_revenue(sales, sale_count);

    printf("Revenue summary (high to low):\n");
    for (int i = 0; i < sale_count; i++)
        printf("%s x%d : Rs %.2f\n",
               sales[i].item_name, sales[i].quantity, sales[i].revenue);
    return 0;
}
