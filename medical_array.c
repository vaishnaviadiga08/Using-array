#include <stdio.h>
#include <string.h>

#define MAX 1000

struct Manufacturer
{
    int number;
    char name[50];
};

struct Customer
{
    int number;
    char name[50];
    char phone[10];
};

struct Manufacturer man[MAX];
struct Customer c[MAX];

int mc = 0, cc = 0;

void insertManufacturer();
void insertCustomer();
void displayManufacturer();
void displayCustomer();
void deleteManufacturer();
void deleteCustomer();

int main()
{
    char username[20], password[20];
    int choice;

    printf("===== MEDICAL STORE LOGIN =====\n");
    printf("Enter username: ");
    scanf("%19s", username);

    printf("Enter password: ");
    scanf("%19s", password);

    if (strcmp(username, "admin") != 0 ||
        strcmp(password, "1234") != 0)
    {
        printf("Invalid username or password!\n");
        return 0;
    }

    printf("\nLogin successful!\n");

    for (;;)
    {
        printf("\n===== MEDICAL STORE MENU =====\n");
        printf("1. Insert Manufacturer\n");
        printf("2. Insert Customer and Generate Bill\n");
        printf("3. Display Manufacturer\n");
        printf("4. Display Customer\n");
        printf("5. Delete Manufacturer\n");
        printf("6. Delete Customer\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertManufacturer();
                break;

            case 2:
                insertCustomer();
                break;

            case 3:
                displayManufacturer();
                break;

            case 4:
                displayCustomer();
                break;

            case 5:
                deleteManufacturer();
                break;

            case 6:
                deleteCustomer();
                break;

            case 7:
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

void insertManufacturer()
{
    if (mc >= MAX)
    {
        printf("Manufacturer list is full!\n");
        return;
    }

    printf("Enter manufacturer number: ");
    scanf("%d", &man[mc].number);

    printf("Enter manufacturer name: ");
    scanf(" %49[^\n]", man[mc].name);

    mc++;

    printf("Manufacturer inserted successfully!\n");
}

void insertCustomer()
{
    int quantity;
    float price, gst, total, gstAmount, bill;
    char medicine[50];

    if (cc >= MAX)
    {
        printf("Customer list is full!\n");
        return;
    }

    printf("\nEnter customer number: ");
    scanf("%d", &c[cc].number);

    printf("Enter customer name: ");
    scanf(" %49[^\n]", c[cc].name);

    printf("Enter phone number: ");
    scanf("%19s", c[cc].phone);

    printf("\nEnter medicine name: ");
    scanf(" %49[^\n]", medicine);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price per unit: ");
    scanf("%f", &price);

    printf("Enter GST percentage: ");
    scanf("%f", &gst);

    if (quantity <= 0 || price < 0 || gst < 0)
    {
        printf("Invalid billing details!\n");
        return;
    }

    total = quantity * price;
    gstAmount = total * gst / 100;
    bill = total + gstAmount;

    printf("\n===== CUSTOMER INSERTED =====\n");
    printf("Customer Number: %d\n", c[cc].number);
    printf("Customer Name: %s\n", c[cc].name);
    printf("Phone Number: %s\n", c[cc].phone);

    cc++;

    printf("\n========== MEDICAL BILL ==========\n");
    printf("Medicine Name : %s\n", medicine);
    printf("Quantity      : %d\n", quantity);
    printf("Price         : Rs. %.2f\n", price);
    printf("Total Amount  : Rs. %.2f\n", total);
    printf("GST (%.2f%%)   : Rs. %.2f\n", gst, gstAmount);
    printf("----------------------------------\n");
    printf("Final Bill    : Rs. %.2f\n", bill);
    printf("==================================\n");
}

void displayManufacturer()
{
    int i;

    if (mc == 0)
    {
        printf("No manufacturer records found!\n");
        return;
    }

    printf("\n===== MANUFACTURER DETAILS =====\n");

    for (i = 0; i < mc; i++)
    {
        printf("\nNumber: %d\n", man[i].number);
        printf("Name: %s\n", man[i].name);
    }
}

void displayCustomer()
{
    int i;

    if (cc == 0)
    {
        printf("No customer records found!\n");
        return;
    }

    printf("\n===== CUSTOMER DETAILS =====\n");

    for (i = 0; i < cc; i++)
    {
        printf("\nNumber: %d\n", c[i].number);
        printf("Name: %s\n", c[i].name);
        printf("Phone: %s\n", c[i].phone);
    }
}

void deleteManufacturer()
{
    int number, i, j;

    printf("Enter manufacturer number to delete: ");
    scanf("%d", &number);

    for (i = 0; i < mc; i++)
    {
        if (man[i].number == number)
        {
            for (j = i; j < mc - 1; j++)
                man[j] = man[j + 1];

            mc--;
            printf("Manufacturer deleted successfully!\n");
            return;
        }
    }

    printf("Manufacturer not found!\n");
}

void deleteCustomer()
{
    int number, i, j;

    printf("Enter customer number to delete: ");
    scanf("%d", &number);

    for (i = 0; i < cc; i++)
    {
        if (c[i].number == number)
        {
            for (j = i; j < cc - 1; j++)
                c[j] = c[j + 1];

            cc--;
            printf("Customer deleted successfully!\n");
            return;
        }
    }

    printf("Customer not found!\n");
}
