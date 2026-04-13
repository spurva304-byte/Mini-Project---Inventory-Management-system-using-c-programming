#include <stdio.h>
#include <string.h>

struct Item {
    int id;
    int quantity;
    int threshold;
    float price;
};

void dashboard() {
    int quantity[20]  = {40,35,25,20,50,18,12,60,45,22,15,30,18,55,28,26,20,14,65,80};
    int threshold[20] = {15,15,10,8,20,10,10,25,20,10,8,15,10,25,10,10,10,8,30,40};

    int totalItems = 20;
    int totalStock = 0;
    int lowStockItems = 0;

    for(int i = 0; i < totalItems; i++) {
        totalStock += quantity[i];
        if(quantity[i] <= threshold[i]) {
            lowStockItems++;
        }
    }

    printf("\n--- MINI DASHBOARD ---\n");
    printf("Total Items     : %d\n", totalItems);
    printf("Total Stock     : %d\n", totalStock);
    printf("Low Stock Alerts: %d\n", lowStockItems);
}

void tracking() {
    int id[5] = {101,102,103,104,105};
    int quantity[5] = {40,35,25,20,50};
    float price[5] = {420,260,180,95,45};

    int search, i;
    printf("\n--- TRACKING SYSTEM ---\n");
    printf("Enter Item ID: ");
    scanf("%d", &search);

    for(i = 0; i < 5; i++) {
        if(search == id[i]) {
            printf("Item Found\n");
            printf("Quantity: %d\n", quantity[i]);
            printf("Price: %.2f\n", price[i]);
            return;
        }
    }
    printf("Item not found\n");
}

void lowStock() {
    struct Item items[5] = {
        {101,40,15,420},
        {102,35,15,260},
        {103,8,10,180},
        {104,5,8,95},
        {105,50,20,45}
    };

    printf("\n--- LOW STOCK ALERT ---\n");
    for(int i = 0; i < 5; i++) {
        if(items[i].quantity <= items[i].threshold) {
            printf("Item ID %d is LOW in stock (Qty: %d)\n",
                   items[i].id, items[i].quantity);
        }
    }
}

void instructions() {
    printf("\n--- HOW TO USE INVENTORY SYSTEM ---\n");
    printf("1. Login using username and password\n");
    printf("2. View Mini Dashboard\n");
    printf("3. Use Tracking System to search items\n");
    printf("4. Check Low Stock Alerts\n");
    printf("5. Exit when done\n");
}

int login() {
    char u[20], p[20];

    printf("---- LOGIN SYSTEM ----\n");
    printf("Username: ");
    scanf("%s", u);

    printf("Password: ");
    scanf("%s", p);

    if(strcmp(u,"admin")==0 && strcmp(p,"1234")==0) {
        printf("Login Successful\n");
        return 1;
    } else {
        printf("Invalid Login\n");
        return 0;
    }
}

int main() {
    int choice;

    if(!login()) return 0;

    do {
        printf("\n===== INVENTORY MENU =====\n");
        printf("1. Mini Dashboard\n");
        printf("2. Tracking System\n");
        printf("3. Low Stock Alert\n");
        printf("4. Instructions\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: dashboard(); break;
            case 2: tracking(); break;
            case 3: lowStock(); break;
            case 4: instructions(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}