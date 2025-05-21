#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>

struct Admin
{
    char fullname[100], email[50], phoneNum[20], username[50], password[50];
};

struct FoodItem
{
    int id;
    char name[50];
    float price;
};

struct CartItem
{
    char name[50];
    int quantity;
    float price;
} cart[100];

int cartItemCount = 0;

void logo();
void adminCustomerChoice();
void AdminChoice();
void adminLogin();
void adminReg();
void adminMenu();
void showAdminItem();
void viewSpecificItem(const char *filename, const char *title);
void updateItem();
void viewUpdateItem(const char *filename, const char *title);
void viewaddMenuItem();
void addMenuItem(const char *filename, const char *title);
void viewdeleteItem();
void deleteMenuItem(const char *filename, const char *title);

void customerMenu();
void orderFood();

void runBreakfastMenuSystem();
void writeBreakfastMenuToFile(struct FoodItem menu[], int count, const char *filename);
void displayBreakfastMenuFromFile(const char *filename);

void runKhanaSetMenuSystem();
void writeKhanaSetMenuToFile(struct FoodItem menu[], int count, const char *filename);
void displayKhanaSetMenuFromFile(const char *filename);

void runDrinksMenuSystem();
void writedrinksMenuToFile(struct FoodItem menu[], int count, const char *filename);
void displaydrinksMenuFromFile(const char *filename);

void runSnacksMenuSystem();
void writeSnacksMenuToFile(struct FoodItem menu[], int count, const char *filename);
void displaySnacksMenuFromFile(const char *filename);

void runDessertsMenuSystem();
void writeDessertsMenuToFile(struct FoodItem menu[], int count, const char *filename);
void displayDessertsMenuFromFile(const char *filename);

void addToCart(const char name[], float price, int quantity);
void displayCart();
int main()
{
    logo();
    system("cls");
    adminCustomerChoice();
}

// function for the design of home page
void logo()
{
    printf("\n\n\n\n\n");
    printf("\t\t\t*****************************************************************\n");
    printf("\t\t\t*\t\t\t\t\t\t\t\t*\n");
    printf("\t\t\t*\t\tWelcome to Food Ordering System\t\t\t*\n");
    printf("\t\t\t*\t\t\t\t\t\t\t\t*\n");
    printf("\t\t\t*****************************************************************\n\n");
    printf("\t\t\t\t    *****************************************\n");
    printf("\t\t\t\t    *\t\t\t\t\t    *\n");
    printf("\t\t\t\t    *\t\t   ABC Hotel\t\t    *\n");
    printf("\t\t\t\t    *\t\t\t\t\t    *\n");
    printf("\t\t\t\t    *****************************************\n\n\n\n\n");
    printf("\t\t\t Press any key to continue...");
    getch();
}

void adminCustomerChoice()
{
    int choice;

    system("cls"); // Clear screen for better appearance

    printf("\n\n\t\t\t============================================");
    printf("\n\t\t\t|           WELCOME TO THE SYSTEM          |");
    printf("\n\t\t\t============================================");
    printf("\n\n\t\t\t\t    1.  Customer                           ");
    printf("\n\t\t\t\t    2.  Admin                              \n");
    printf("\n\t\t\t============================================");

    printf("\n\n\t\t\tEnter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar();


    switch (choice)
    {
    case 1:
    	system("cls");
        customerMenu();
        break;

    case 2:
    	system("cls");
        AdminChoice();
        break;

    default:
        printf("\n\t\t\t Invalid Input! Please enter 1 or 2.\n");
        printf("\n\t\t\t Press any key to try again!");
        getch();
        adminCustomerChoice();
        break;
    }
}

void AdminChoice()
{
    system("cls");
    int adminChoice;

    printf("\n\n\t\t\t==============================================");
    printf("\n\t\t\t|                ADMIN PANEL                 |");
    printf("\n\t\t\t==============================================");
    printf("\n\n\t\t\t\t    1)  Registration                        ");
    printf("\n\t\t\t\t    2)  Login                               ");
    printf("\n\n\t\t\t==============================================");

    printf("\n\n\t\t\t Enter your choice: ");
    scanf("%d", &adminChoice);
    getchar();

    switch (adminChoice)
    {
    case 1:
        system("cls");
        adminReg();
        break;

    case 2:
        system("cls");
        adminLogin();
        break;

    default:
        printf("\n\t\t\t Invalid input! Please enter 1 or 2.\n");
        printf("\n\t\t\t Press any key to try again!");
        getch();
        AdminChoice();
        break;
    }
}

// function for registration for admin
void adminReg()
{
    char ch;
    int index = 0;
    printf("\n\n\t\t\t==============================================");
    printf("\n\t\t\t|             ADMIN REGISTRATION             |");
    printf("\n\t\t\t==============================================\n\n\n");
    struct Admin admin;
    FILE *fp = fopen("admin.txt", "a");
    if (fp == NULL)
    {
        printf("Error in opening file!\n");
        return;
    }
    printf("\t\t\t\tEnter Full Name::");
    fflush(stdin);
    gets(admin.fullname);
    printf("\t\t\t\tEnter Email::");
    fflush(stdin);
    gets(admin.email);
    printf("\t\t\t\tEnter Phone Number::");
    fflush(stdin);
    gets(admin.phoneNum);
    printf("\t\t\t\tEnter Username::");
    fflush(stdin);
    gets(admin.username);
    printf("\t\t\t\tEnter Password::");
    fflush(stdin);
    while (1)
    {
        ch = getch(); // Read a character without echoing

        // Check for Enter key (ASCII 13)
        if (ch == 13)
        {
            admin.password[index] = '\0'; // Null-terminate the string
            break;
        }
        // Handle backspace
        else if (ch == 8)
        {
            if (index > 0)
            {
                index--;
                printf("\b \b"); // Erase the last asterisk
            }
        }
        else
        {
            admin.password[index++] = ch;
            printf("*"); // Show asterisk instead of actual character
        }
    }

    fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", admin.fullname, admin.email, admin.phoneNum, admin.username, admin.password);
    fclose(fp);
    printf("\n\n\t\t\t\tCreating your account.");
    for(int i=0;i<8;i++){
    	Sleep(100);
    	printf(".");
    	fflush(stdout);
	}
    printf("\n\n\t\t\t\tRegistration Successfull!");
    printf("\n\n\t\t\t\tPress any key to go to login page...");
    getch();
    system("cls");
    printf("\t\t\t\tEnter the credentials used in registration to login:\n\n");
    adminLogin();
}

// Function for login for admin
void adminLogin()
{

    struct Admin admin;
    int found = 0, index = 0;
    char ch, username[50], password[50];
    FILE *fp = fopen("admin.txt", "r");
    if (fp == NULL)
    {
        printf("Error in opening file!\n");
        return;
    }
    system("cls");
    printf("\n\n\n\t\t\t==============================================");
    printf("\n\t\t\t|               ADMIN LOGIN                  |");
    printf("\n\t\t\t==============================================\n\n\n");
    printf("\t\t\t\tEnter Username::");
    fflush(stdin);
    gets(username);
    printf("\t\t\t\tEnter Password::");
    fflush(stdin);
    while (1)
    {
        ch = getch(); // Read a character without echoing

        // Check for Enter key (ASCII 13)
        if (ch == 13)
        {
            password[index] = '\0'; // Null-terminate the string
            break;
        }
        // Handle backspace
        else if (ch == 8)
        {
            if (index > 0)
            {
                index--;
                printf("\b \b"); // Erase the last asterisk
            }
        }
        else
        {
            password[index++] = ch;
            printf("*"); // Show asterisk instead of actual character
        }
    }

    while (fscanf(fp, "%s%s", admin.username, admin.password) != EOF)
    {
        if (strcmp(admin.username, username) == 0 && strcmp(admin.password, password) == 0)
        {
            found = 1;
        }
    }
    fclose(fp);
    printf("\n\n\t\t\t\tLogging in.");
    for(int i=0;i<8;i++){
    	Sleep(100);
    	printf(".");
    	fflush(stdout);
	}
    if (found)
    {
        printf("\n\n\t\t\t\tLogin Successfull!");
        Sleep(1500);
//        printf("\n\n\t\t\t\tPress any key to continue...");
//        getch();
        system("cls");
        adminMenu();
    }
    else
    {
        printf("\n\n\t\t\t\tInvalid credentials. Try again!\n");
        printf("\n\t\t\t\tPress any key to try again!");
        getch();
        adminLogin();
    }
    system("cls");
    adminMenu();
}

void adminMenu()
{
    int choice;
    printf("\n\t\t\t================================================");
    printf("\n\t\t\t|               ADMIN CONTROL PANEL            |");
    printf("\n\t\t\t================================================");
    printf("\n\n\t\t\t\t1) View Available Items\n\t\t\t\t2) Update Item/Price\n\t\t\t\t3) Add Item\n\t\t\t\t4) Delete Item\n\t\t\t\t5) Logout\n");
    printf("\n\t\t\t\tEnter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        showAdminItem();
        break;

    case 2:
        updateItem();
        break;

    case 3:
        viewaddMenuItem();
        break;

    case 4:
        viewdeleteItem();
        break;
        
    case 5:
    	printf("\n\n\t\t\t\tLogging out .");
		for(int i=0;i<8;i++){
			Sleep(100);
			printf(".");
			fflush(stdout);
		}
		adminCustomerChoice();   

    default:
        printf("\n\t\tEnter valid Input");
        printf("\n\t Press any key to try again!");
        getch();
        adminMenu();
    }
}

void customerMenu()
{
    int choice;

    system("cls");

    printf("\n\t\t\t==============================================");
    printf("\n\t\t\t|                CUSTOMER MENU               |");
    printf("\n\t\t\t==============================================\n");
    printf("\n\t\t\t\t    1)  Order Food                          ");
    printf("\n\t\t\t\t    2)  View Cart                           ");
    printf("\n\t\t\t\t    3)  Payment                             ");
    printf("\n\t\t\t\t    4)  Exit                                 ");
    printf("\n\n\t\t\t==============================================");

    printf("\n\n\t\t\t Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        orderFood();
        break;

    case 2:
        system("cls");
        displayCart();
        break;

    case 3:
        system("cls");
        printf("\n\t Payment processing (Coming soon)...\n");
        break;

    case 4:
        system("cls");
		adminCustomerChoice();
        break;

    default:
        printf("\n\t Invalid input! Please choose between 1-4.\n");
        break;
    }
}
// function to choose  the food for customer
void orderFood()
{
    system("cls");
    int choice;
    printf("\n\n\n\t\t\t================================================");
    printf("\n\t\t\t|                  ORDER FOOD MENU             |");
    printf("\n\t\t\t================================================");
    printf("\n\n\t\t\t\t\t1) Breakfast\n\t\t\t\t\t2) Khana Set\n\t\t\t\t\t3) Fast food\n\t\t\t\t\t4) Drinks\n\t\t\t\t\t5) Desserts\n\t\t\t\t\t6) Back to Main Menu");
    printf("\n\n\t\t\t================================================\n");
    printf("\n\t\t\t\t\tEnter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        runBreakfastMenuSystem();
        break;

    case 2:
        runKhanaSetMenuSystem();
        break;

    case 3:
        runSnacksMenuSystem();
        break;

    case 4:
        runDrinksMenuSystem();
        break;

    case 5:
        runDessertsMenuSystem();
        break;

    case 6:
        customerMenu();
        break;

    default:
        printf("\n\t\tEnter valid Input");
    }
}

// function to run the breakfast menu of this system
void runBreakfastMenuSystem()
{
    struct FoodItem breakfast[100];
    int itemCount = 0;
    const char *filename = "breakfast_menu.txt";
    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        while (fscanf(file, "%d,%49[^,],%f\n", &breakfast[itemCount].id, breakfast[itemCount].name, &breakfast[itemCount].price) == 3)
        {
            itemCount++;
        }
        writeBreakfastMenuToFile(breakfast, itemCount, filename);
        displayBreakfastMenuFromFile(filename);
        fclose(file);
    }
    else
    {

        struct FoodItem breakfast[] = {
            {1, "Puri Tarkari", 100},
            {2, "Chana Boiled Egg", 110},
            {3, "Aloo Paratha", 60},
            {4, "Samosa", 30},
            {5, "Toast with Butter Jam", 100},
            {6, "Egg Benedict", 130},
            {7, "Sandwich", 90},
            {8, "Fruits/Mix Veg Soup", 140}};

        itemCount = sizeof(breakfast) / sizeof(breakfast[0]);
        // Save to file
        writeBreakfastMenuToFile(breakfast, itemCount, filename);

        // Display from file
        displayBreakfastMenuFromFile(filename);
    }
}
// function to write/save the breakfast items into file
void writeBreakfastMenuToFile(struct FoodItem menu[], int count, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error creating file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d,%s,%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }

    fclose(fp);
}

// Read and display breakfast items from file
void displayBreakfastMenuFromFile(const char *filename)
{
    int quantity, choice;
    float price;
    char orderchoice, more;
    system("cls");
    do
    {

        FILE *fp = fopen(filename, "r");
        struct FoodItem item;

        if (fp == NULL)
        {
            printf("Error reading file or file not found.\n");
            return;
        }

        printf("\n\n\n\t\t   ================================================");
        printf("\n\t\t   |                  BREAKFAST MENU              |");
        printf("\n\t\t   ================================================\n\n");
        printf("\t\t\tID\tName\t\t\tPrice\n");
        printf("\t\t\t-----------------------------------------\n");

        while (fscanf(fp, "%d,%49[^,],%f\n", &item.id, item.name, &item.price) == 3)
        {
            printf("\t\t\t%d\t%-24s %.2f\n", item.id, item.name, item.price);
        }

        fclose(fp);
        printf("\n\n\t\t\tDo you want to order?(Y/N):");
        scanf(" %c", &orderchoice);
        if (orderchoice == 'Y' || orderchoice == 'y')
        {
            printf("\n\n\t\t\tEnter the Serial Number(SN) of the item you want to order:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\t\t\tEnter the quantity of Puri Tarkari:");
                scanf("%d", &quantity);
                addToCart("Puri Tarkari", 100, quantity);
                break;

            case 2:
                printf("\t\t\tEnter the quantity of Chana Boiled Egg:");
                scanf("%d", &quantity);
                addToCart("Chana Boiled Egg", 110, quantity);
                break;

            case 3:
                printf("\t\t\tEnter the quantity of  Aloo Paratha:");
                scanf("%d", &quantity);
                addToCart("Aloo Paratha", 60, quantity);
                break;

            case 4:
                printf("\t\t\tEnter the quantity of Samosa:");
                scanf("%d", &quantity);
                addToCart("Samosa", 30, quantity);
                break;

            case 5:
                printf("\t\t\tEnter the quantity of Toast with Butter Jamveg):");
                scanf("%d", &quantity);
                addToCart("Toast with Butter Jam", 100, quantity);
                break;

            case 6:
                printf("\t\t\tEnter the quantity of Egg Benedict:");
                scanf("%d", &quantity);
                addToCart("Egg Benedict", 130, quantity);
                break;

            case 7:
                printf("\t\t\tEnter the quantity of Sandwich:");
                scanf("%d", &quantity);
                addToCart("Sandwich", 90, quantity);
                break;

            case 8:
                printf("\t\t\tEnter the quantity of Fruits/Mix Veg Soup:");
                scanf("%d", &quantity);
                addToCart("Fruits/Mix Veg Soup", 140, quantity);
                break;

            default:
                printf("\t\t\tEnter the valid Input!");
            }
        }
        else
        {
            orderFood();
        }
        printf("\n\t\t\tDo you want to order more? (Y/N): ");
        scanf(" %c", &more);
    } while (more == 'Y' || more == 'y');
    orderFood();
}

// function to run the khana set item in this system

void runKhanaSetMenuSystem()
{
    struct FoodItem khana[100];
    int itemCount = 0;
    const char *filename = "khana_set_menu.txt";
    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        while (fscanf(file, "%d,%49[^,],%f\n", &khana[itemCount].id, khana[itemCount].name, &khana[itemCount].price) == 3)
        {
            itemCount++;
        }
        writeKhanaSetMenuToFile(khana, itemCount, filename);
        displayKhanaSetMenuFromFile(filename);
        fclose(file);
    }
    else
    {

        struct FoodItem khanaSet[] = {
            {1, "Khana set(veg)", 300},
            {2, "Khana set(Chicken)", 400},
            {3, "Khana set(Mutton)", 500},
            {4, "Khana set(Fish)", 450},
            {5, "Thakali Khana set(veg)", 400},
            {6, "Thakali Khana set(Chicken)", 500},
            {7, "Thakali Khana set(Mutton)", 600},
            {8, "Thakali Khana set(Fish)", 550}};

        itemCount = sizeof(khanaSet) / sizeof(khanaSet[0]);

        writeKhanaSetMenuToFile(khanaSet, itemCount, filename);
        displayKhanaSetMenuFromFile(filename);
    }
}
// Write khana set menu to file
void writeKhanaSetMenuToFile(struct FoodItem menu[], int count, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error creating file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d,%s,%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }

    fclose(fp);
}

// Read and display khanaset menu from file
void displayKhanaSetMenuFromFile(const char *filename)
{
    int quantity, choice;
    float price;
    char orderchoice, more;
    system("cls");

    do
    {

        FILE *fp = fopen(filename, "r");
        struct FoodItem item;

        if (fp == NULL)
        {
            printf("Error reading file or file not found.\n");
            return;
        }

        printf("\n\n\n\t\t   ======================================================");
        printf("\n\t\t   |                   KHANA SET MENU                   |");
        printf("\n\t\t   ======================================================\n\n");
        printf("\t\t\tID\tName\t\t\t\tPrice\n");
        printf("\t\t\t-----------------------------------------------\n");

        while (fscanf(fp, "%d,%49[^,],%f\n", &item.id, item.name, &item.price) == 3)
        {
            printf("\t\t\t%d\t%-30s %.2f\n", item.id, item.name, item.price);
        }

        fclose(fp);
        printf("\n\n\t\t\tDo you want to order?(Y/N):");
        scanf(" %c", &orderchoice);
        if (orderchoice == 'Y' || orderchoice == 'y')
        {
            printf("\n\n\t\t\tEnter the Serial Number(SN) of the item you want to order:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\t\t\tEnter the quantity of Khana set(veg):");
                scanf("%d", &quantity);
                addToCart("Khana set(veg)", 300, quantity);
                break;

            case 2:
                printf("\t\t\tEnter the quantity of Khana set(Chicken):");
                scanf("%d", &quantity);
                addToCart("Khana set(Chicken)", 400, quantity);
                break;

            case 3:
                printf("\t\t\tEnter the quantity of  Khana set(Mutton):");
                scanf("%d", &quantity);
                addToCart("Khana set(Mutton)", 500, quantity);
                break;

            case 4:
                printf("\t\t\tEnter the quantity of Khana set(Fish):");
                scanf("%d", &quantity);
                addToCart("Khana set(Fish)", 450, quantity);
                break;

            case 5:
                printf("\t\t\tEnter the quantity of Thakali Khana set(veg):");
                scanf("%d", &quantity);
                addToCart("Thakali Khana set(veg)", 400, quantity);
                break;

            case 6:
                printf("\t\t\tEnter the quantity of Thakali Khana set(Chicken):");
                scanf("%d", &quantity);
                addToCart("Thakali Khana set(Chicken)", 500, quantity);
                break;

            case 7:
                printf("\t\t\tEnter the quantity of Thakali Khana set(Mutton):");
                scanf("%d", &quantity);
                addToCart("Thakali Khana set(Mutton)", 600, quantity);
                break;

            case 8:
                printf("\t\t\tEnter the quantity of Thakali Khana set(Fish):");
                scanf("%d", &quantity);
                addToCart("Thakali Khana set(Fish)", 550, quantity);
                break;

            default:
                printf("\t\t\tEnter the valid Input!");
            }
        }
        else
        {
            orderFood();
        }
        printf("\n\t\t\tDo you want to order more? (Y/N): ");
        scanf(" %c", &more);
    } while (more == 'Y' || more == 'y');
    orderFood();
}

// function to run the drinks menu in the system

void runDrinksMenuSystem()
{
    struct FoodItem drink[100];
    int itemCount = 0;
    const char *filename = "drinks_menu.txt";
    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        while (fscanf(file, "%d,%49[^,],%f\n", &drink[itemCount].id, drink[itemCount].name, &drink[itemCount].price) == 3)
        {
            itemCount++;
        }
        writedrinksMenuToFile(drink, itemCount, filename);
        displaydrinksMenuFromFile(filename);
        fclose(file);
    }
    else
    {

        struct FoodItem drinks[] = {
            {1, "Banana Lassi", 150},
            {2, "Fresh Lime Soda", 100},
            {3, "Pineapple Juice", 210},
            {4, "Apple Juice", 250},
            {5, "Lemon Tea", 50},
            {6, "Cappuccino", 180},
            {7, "CocaCola", 150},
            {8, "Sprite", 140},
            {9, "Red Bull", 200}};

        itemCount = sizeof(drinks) / sizeof(drinks[0]);

        writedrinksMenuToFile(drinks, itemCount, filename);
        displaydrinksMenuFromFile(filename);
    }
}
// Function to write drinks menu items to a file
void writedrinksMenuToFile(struct FoodItem menu[], int count, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error creating file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d,%s,%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }

    fclose(fp);
}

// Function to read and display drinks menu from file
void displaydrinksMenuFromFile(const char *filename)
{
    int quantity, choice;
    float price;
    char orderchoice, more;
    system("cls");
    do
    {

        FILE *fp = fopen(filename, "r");
        struct FoodItem item;

        if (fp == NULL)
        {
            printf("Error reading file or file not found.\n");
            return;
        }

        printf("\n\n\n\t\t   ===================================================");
        printf("\n\t\t   |                   DRINKS MENU                   |");
        printf("\n\t\t   ===================================================\n\n");
        printf("\t\t\tID\tName\t\t\tPrice\n");
        printf("\t\t\t---------------------------------------\n");

        while (fscanf(fp, "%d,%49[^,],%f\n", &item.id, item.name, &item.price) == 3)
        {
            printf("\t\t\t%d\t%-24s %.2f\n", item.id, item.name, item.price);
        }

        fclose(fp);
        printf("\n\n\t\t\tDo you want to order?(Y/N):");
        scanf(" %c", &orderchoice);
        if (orderchoice == 'Y' || orderchoice == 'y')
        {
            printf("\n\n\t\t\tEnter the Serial Number(SN) of the item you want to order:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\t\t\tEnter the quantity of Banana Lassi:");
                scanf("%d", &quantity);
                addToCart("Banana Lassi", 150, quantity);
                break;

            case 2:
                printf("\t\t\tEnter the quantity of Fresh Lime Soda:");
                scanf("%d", &quantity);
                addToCart("Fresh Lime Soda", 100, quantity);
                break;

            case 3:
                printf("\t\t\tEnter the quantity of  Apple Juice:");
                scanf("%d", &quantity);
                addToCart("Apple Juice", 210, quantity);
                break;

            case 4:
                printf("\t\t\tEnter the quantity of Apple Juice:");
                scanf("%d", &quantity);
                addToCart("Apple Juice", 250, quantity);
                break;

            case 5:
                printf("\t\t\tEnter the quantity of Lemon Tea:");
                scanf("%d", &quantity);
                addToCart("Lemon Tea", 50, quantity);
                break;

            case 6:
                printf("\t\t\tEnter the quantity of Cappuccino:");
                scanf("%d", &quantity);
                addToCart("Cappuccino", 180, quantity);
                break;

            case 7:
                printf("\t\t\tEnter the quantity of CocaCola:");
                scanf("%d", &quantity);
                addToCart("CocaCola", 150, quantity);
                break;

            case 8:
                printf("\t\t\tEnter the quantity of Sprite:");
                scanf("%d", &quantity);
                addToCart("Sprite", 140, quantity);
                break;

            case 9:
                printf("\t\t\tEnter the quantity of Red Bull:");
                scanf("%d", &quantity);
                addToCart("Red Bull", 200, quantity);
                break;

            default:
                printf("\t\t\tEnter the valid Input!");
            }
        }
        else
        {
            orderFood();
        }
        printf("\n\t\t\tDo you want to order more? (Y/N): ");
        scanf(" %c", &more);
    } while (more == 'Y' || more == 'y');
    orderFood();
}

// function to run the snacks meny in this system

void runSnacksMenuSystem()
{
    struct FoodItem snack[100];
    int itemCount = 0;
    const char *filename = "snacks_menu.txt";
    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        while (fscanf(file, "%d,%49[^,],%f\n", &snack[itemCount].id, snack[itemCount].name, &snack[itemCount].price) == 3)
        {
            itemCount++;
        }
        writeSnacksMenuToFile(snack, itemCount, filename);
        displaySnacksMenuFromFile(filename);
        fclose(file);
    }
    else
    {

        struct FoodItem snacks[] = {
            {1, "Buff Mo:Mo", 150},
            {2, "Chicken Mo:Mo", 170},
            {3, "Veg Chowmein", 110},
            {4, "Chicken Chowmein", 150},
            {5, "Buff Chowmein", 140},
            {6, "Chicken Pizza", 400},
            {7, "Mixed Pizza", 550},
            {8, "Veg Burger", 140},
            {9, "Chicken Burger", 200},
            {10, "Chicken Drumsticks", 200},
            {11, "Buffalo Wing", 350},
            {12, "Chicken Kathi Roll", 200},
            {13, "Chicken Sausage", 50}};

        itemCount = sizeof(snacks) / sizeof(snacks[0]);
        writeSnacksMenuToFile(snacks, itemCount, filename);
        displaySnacksMenuFromFile(filename);
    }
}
// Function to write snacks menu items to a file
void writeSnacksMenuToFile(struct FoodItem menu[], int count, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error creating file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d,%s,%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }

    fclose(fp);
}

// Function to read and display snacks menu from file
void displaySnacksMenuFromFile(const char *filename)
{
    int quantity, choice;
    float price;
    char orderchoice, more;
    system("cls");
    do
    {

        FILE *fp = fopen(filename, "r");
        struct FoodItem item;

        if (fp == NULL)
        {
            printf("Error reading file or file not found.\n");
            return;
        }

        printf("\n\n\n\t\t   =======================================================");
        printf("\n\t\t   |                   FAST FOOD MENU                    |");
        printf("\n\t\t   =======================================================\n\n");
        printf("\t\t\tID\tName\t\t\t\tPrice\n");
        printf("\t\t\t----------------------------------------------\n");

        while (fscanf(fp, "%d,%49[^,],%f\n", &item.id, item.name, &item.price) == 3)
        {
            printf("\t\t\t%d\t%-30s %.2f\n", item.id, item.name, item.price);
        }

        fclose(fp);
        printf("\n\n\t\t\tDo you want to order?(Y/N):");
        scanf(" %c", &orderchoice);
        if (orderchoice == 'Y' || orderchoice == 'y')
        {
            printf("\n\n\t\t\tEnter the Serial Number(SN) of the item you want to order:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\t\t\tEnter the quantity of Buff Mo:Mo:");
                scanf("%d", &quantity);
                addToCart("Buff Mo:Mo", 150, quantity);
                break;

            case 2:
                printf("\t\t\tEnter the quantity of Chicken Mo:Mo:");
                scanf("%d", &quantity);
                addToCart("Chicken Mo:Mo", 170, quantity);
                break;

            case 3:
                printf("\t\t\tEnter the quantity of  Veg Chowmein:");
                scanf("%d", &quantity);
                addToCart("Veg Chowmein", 110, quantity);
                break;

            case 4:
                printf("\t\t\tEnter the quantity of Chicken Chowmein:");
                scanf("%d", &quantity);
                addToCart("Chicken Chowmein", 150, quantity);
                break;

            case 5:
                printf("\t\t\tEnter the quantity of Buff Chowmein:");
                scanf("%d", &quantity);
                addToCart("Buff Chowmein", 140, quantity);
                break;

            case 6:
                printf("\t\t\tEnter the quantity of Chicken Pizza:");
                scanf("%d", &quantity);
                addToCart("Chicken Pizza", 400, quantity);
                break;

            case 7:
                printf("\t\t\tEnter the quantity of Mixed Pizza:");
                scanf("%d", &quantity);
                addToCart("Mixed Pizza", 550, quantity);
                break;

            case 8:
                printf("\t\t\tEnter the quantity of Veg Burger:");
                scanf("%d", &quantity);
                addToCart("Veg Burger", 140, quantity);
                break;

            case 9:
                printf("\t\t\tEnter the quantity of Chicken Burger:");
                scanf("%d", &quantity);
                addToCart("Chicken Burger", 200, quantity);
                break;

            case 10:
                printf("\t\t\tEnter the quantity of Chicken Drumsticks:");
                scanf("%d", &quantity);
                addToCart("Chicken Drumsticks", 200, quantity);
                break;

            case 11:
                printf("\t\t\tEnter the quantity of Buffalo Wing:");
                scanf("%d", &quantity);
                addToCart("Buffalo Wing", 350, quantity);
                break;

            case 12:
                printf("\t\t\tEnter the quantity of Chicken Kathi Roll:");
                scanf("%d", &quantity);
                addToCart("Chicken Kathi Roll", 200, quantity);
                break;

            case 13:
                printf("\t\t\tEnter the quantity of Chicken Sausage:");
                scanf("%d", &quantity);
                addToCart("Chicken Sausage", 50, quantity);
                break;

            default:
                printf("\t\t\tEnter the valid Input!");
            }
        }
        else
        {
            orderFood();
        }
        printf("\n\t\t\tDo you want to order more? (Y/N): ");
        scanf(" %c", &more);
    } while (more == 'Y' || more == 'y');
    orderFood();
}

// function to run the dessert menu  in this system
void runDessertsMenuSystem()
{
    struct FoodItem dessert[100];
    int itemCount = 0;
    const char *filename = "desserts_menu.txt";
    FILE *file = fopen(filename, "r");
    if (file != NULL)
    {
        while (fscanf(file, "%d,%49[^,],%f\n", &dessert[itemCount].id, dessert[itemCount].name, &dessert[itemCount].price) == 3)
        {
            itemCount++;
        }
        writeDessertsMenuToFile(dessert, itemCount, filename);
        displayDessertsMenuFromFile(filename);
        fclose(file);
    }
    else
    {
        struct FoodItem desserts[] = {
            {1, "Juju Dhau", 150},
            {2, "Ice-cream", 100},
            {3, "Sweet Boondi", 210},
            {4, "Khuwa Laddu", 250},
            {5, "Rasbari", 50},
            {6, "Peda", 180}};

        itemCount = sizeof(desserts) / sizeof(desserts[0]);

        writeDessertsMenuToFile(desserts, itemCount, filename);
        displayDessertsMenuFromFile(filename);
    }
}
// Function to write the dessert menu to file
void writeDessertsMenuToFile(struct FoodItem menu[], int count, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error creating file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d,%s,%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }

    fclose(fp);
    printf("Desserts menu saved to %s successfully.\n", filename);
}

// Function to read and display dessert menu from file
void displayDessertsMenuFromFile(const char *filename)
{
    int quantity, choice;
    float price;
    char orderchoice, more;
    system("cls");
    do
    {

        FILE *fp = fopen(filename, "r");
        struct FoodItem item;

        if (fp == NULL)
        {
            printf("Error reading file or file not found.\n");
            return;
        }

        printf("\n\n\n\t\t   ============================================");
        printf("\n\t\t   |              DESSERTS MENU               |");
        printf("\n\t\t   ============================================\n\n");
        printf("\t\t\tID\tName\t\t    Price\n");
        printf("\t\t\t-----------------------------------\n");

        while (fscanf(fp, "%d,%49[^,],%f\n", &item.id, item.name, &item.price) == 3)
        {
            printf("\t\t\t%d\t%-20s%.2f\n", item.id, item.name, item.price);
        }

        fclose(fp);
        printf("\n\n\t\t\tDo you want to order?(Y/N):");
        scanf(" %c", &orderchoice);
        if (orderchoice == 'Y' || orderchoice == 'y')
        {
            char more;
            printf("\n\n\t\t\tEnter the Serial Number(SN) of the item you want to order:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\t\t\tEnter the quantity of Juju Dhau:");
                scanf("%d", &quantity);
                addToCart("Juju Dhau", 150, quantity);
                break;

            case 2:
                printf("\t\t\tEnter the quantity of Ice-cream:");
                scanf("%d", &quantity);
                addToCart("Ice-cream", 100, quantity);
                break;

            case 3:
                printf("\t\t\tEnter the quantity of Sweet Boondi:");
                scanf("%d", &quantity);
                addToCart("Sweet Boondi", 210, quantity);
                break;

            case 4:
                printf("\t\t\tEnter the quantity of Khuwa Laddu:");
                scanf("%d", &quantity);
                addToCart("Khuwa Laddu", 210, quantity);
                break;

            case 5:
                printf("\t\t\tEnter the quantity of Rasbari:");
                scanf("%d", &quantity);
                addToCart("Rasbari", 210, quantity);
                break;

            case 6:
                printf("\t\t\tEnter the quantity of Peda:");
                scanf("%d", &quantity);
                addToCart("Peda", 210, quantity);
                break;

            default:
                printf("\t\t\tEnter the valid Input!");
            }
        }
        else
        {
            orderFood();
        }
        printf("\n\t\t\tDo you want to order more? (Y/N): ");
        scanf(" %c", &more);
    } while (more == 'Y' || more == 'y');
    orderFood();
}

void addToCart(const char name[], float price, int quantity)
{
    strcpy(cart[cartItemCount].name, name);
    cart[cartItemCount].price = price;
    cart[cartItemCount].quantity = quantity;
    cartItemCount++;
    printf("\t\t\t'%s' added to cart (%d pcs)\n", name, quantity);
}

void displayCart()
{
    float grandTotal = 0;
    float totalPrice = 0;
    printf("\n\n\n\t\t ===============================================================================");
    printf("\n\t\t |                               CART ITEMS                                    |");
    printf("\n\t\t ===============================================================================\n\n");
    if (cartItemCount == 0)
    {
        printf("\n\t\t\t\tYour Cart is empty!\n\n");
        printf("\n\t\t\t\tPress any key to return to main menu...");
        getch();
        customerMenu();
        return;
    }
    printf("\t\t\tName\t\t\tQuantity\tPrice per Unit\tTotal Price\n");
    printf("\t\t\t----------------------------------------------------------------------\n");
    for (int i = 0; i < cartItemCount; i++)
    {
        totalPrice = cart[i].price * cart[i].quantity;
        grandTotal += totalPrice;
        printf("\t\t\t%-20s\t%d\t\t%.2f\t\t%.2f\n", cart[i].name, cart[i].quantity, cart[i].price, totalPrice);
    }
    printf("\t\t\t----------------------------------------------------------------------\n");
    printf("\t\t\tGrand Total: \t\t%.2f\n\n", grandTotal);
    printf("\t\t\tPress any key to return to main menu...");
    getch();
    system("cls");
    customerMenu();
}

void showAdminItem()
{
    system("cls");
    int choice;
    printf("\n\n\n\t\t\t   ============================================");
    printf("\n\t\t\t   |               AVAILABLE ITEMS            |");
    printf("\n\t\t\t   ============================================\n");
    printf("\n\n\t\t\t\t\t1) Breakfast\n\t\t\t\t\t2) Khana Set\n\t\t\t\t\t3) Fast food\n\t\t\t\t\t4) Drinks\n\t\t\t\t\t5) Desserts\n\t\t\t\t\t6) Back to main menu\n");
    printf("\n\t\t\t\t\tEnter the choice:");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
        viewSpecificItem("breakfast_menu.txt", "BREAKFAST MENU");
        break;
    case 2:
        viewSpecificItem("khana_set_menu.txt", "KHANA SET MENU");
        break;
    case 3:
        viewSpecificItem("snacks_menu.txt", "FAST FOOD MENU");
        break;
    case 4:
        viewSpecificItem("drinks_menu.txt", "DRINKS MENU");
        break;
    case 5:
        viewSpecificItem("desserts_menu.txt", "DESSERTS MENU");
        break;
    
	case 6:
		system("cls"); 
    	adminMenu(); 
		break; 	
	default:
    	printf("\n\t\t\t\tInvalid Input!");
		printf("\n\t\t\t\tPress any key to try again!");
		getch();
		showAdminItem();	
    }
    
    
}

void viewSpecificItem(const char *filename, const char *title)
{
    system("cls");
    int quantity, choice;
    float price;
    char orderchoice, more;
    system("cls");

    FILE *fp = fopen(filename, "r");
    struct FoodItem item;

    if (fp == NULL)
    {
        printf("Error reading file or file not found.\n");
        return;
    }

    printf("\n\n\n\t\t   =======================================================");
    printf("\n\t\t   |                     %s                  |", title);
    printf("\n\t\t   =======================================================\n\n");
    printf("\t\t\tID\tName\t\t\t\tPrice\n");
    printf("\t\t\t----------------------------------------------\n");

    while (fscanf(fp, "%d,%49[^,],%f\n", &item.id, item.name, &item.price) == 3)
    {
        printf("\t\t\t%d\t%-31s %.2f\n", item.id, item.name, item.price);
    }
    printf("\n\n\t\t\tPress any key to return back to admin menu...");
    getch();
    system("cls");
    adminMenu();
    fclose(fp);
}

void updateItem()
{
    system("cls");
    int choice;
    printf("\n\n\n\t\t\t   ============================================");
    printf("\n\t\t\t   |           AVAILABLE ITEMS TO UPDATE      |");
    printf("\n\t\t\t   ============================================\n");
    printf("\n\n\t\t\t\t\t1) Breakfast\n\t\t\t\t\t2) Khana Set\n\t\t\t\t\t3) Fast food\n\t\t\t\t\t4) Drinks\n\t\t\t\t\t5) Desserts\n\t\t\t\t\t6) Back to main menu\n");
    printf("\n\t\t\t\t\tEnter the choice:");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
        viewUpdateItem("breakfast_menu.txt", "BREAKFAST MENU");

        break;
    case 2:
        viewUpdateItem("khana_set_menu.txt", "KHANA SET MENU");
        break;
    case 3:
        viewUpdateItem("snacks_menu.txt", "FAST FOOD MENU");
        break;
    case 4:
        viewUpdateItem("drinks_menu.txt", "DRINKS MENU");
        break;
    case 5:
        viewUpdateItem("desserts_menu.txt", "DESSERTS MENU");
        break;
    case 6:
		system("cls"); 
    	adminMenu(); 
		break; 	
	default:
    	printf("\n\t\t\t\tInvalid Input!");
		printf("\n\t\t\t\tPress any key to try again!");
		getch();
		updateItem();	
    }
    
    
}

void viewUpdateItem(const char *filename, const char *title)
{
    system("cls");
    int quantity, count = 0, choice, editChoice, found = -1;
    float newPrice, price;
    char newName[50];
    system("cls");

    FILE *fp = fopen(filename, "r");
    struct FoodItem item[100];

    if (fp == NULL)
    {
        printf("Error reading file or file not found.\n");
        return;
    }

    printf("\n\n\n\t\t   =======================================================");
    printf("\n\t\t   |                     %s                  |", title);
    printf("\n\t\t   =======================================================\n\n");
    printf("\t\t\tID\tName\t\t\t\tPrice\n");
    printf("\t\t\t----------------------------------------------\n");

    while (fscanf(fp, "%d,%49[^,],%f\n", &item[count].id, item[count].name, &item[count].price) == 3)
    {
        printf("\t\t\t%d\t%-31s %.2f\n", item[count].id, item[count].name, item[count].price);
        count++;
    }
    fclose(fp);

    printf("\n\t\t\tEnter ID to edit (0 to cancel):");
    scanf("%d", &editChoice);
    if (editChoice == 0)
    {
        updateItem();
    }
    for (int i = 0; i < count && found == -1; i++)
    {
        if (item[i].id == editChoice)
        {
            found = i;
        }
    }
    if (found == -1)
    {
        printf("\n\t\t\tItem not found.\n");
        return;
    }
    printf("\n\t\t\tEditing: %s\t Rs.%f\n", item[found].name, item[found].price);
    printf("\n\t\t\tEnter the new name (Enter to keep same):");
    fflush(stdin);
    
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = 0;
    if (strlen(newName) > 0)
    {
        strcpy(item[found].name, newName);
    }

    printf("\n\t\t\tEnter new price (0 to keep the same):");
    scanf("%f", &newPrice);
    if (newPrice > 0)
    {
        item[found].price = newPrice;
    }
    fp = fopen(filename, "w");
    if (!fp)
    {
        printf("\n\t\t\tFailed to save changes.\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d,%s,%.2f\n", item[i].id, item[i].name, item[i].price);
    }
    fclose(fp);
    printf("\n\n\t\t\tUpdating Item.");
	for(int i=0;i<8;i++){
		Sleep(100);
		printf(".");
		fflush(stdout);
	}
    printf("\n\t\t\tItem updated successfully.\n");
    printf("\n\t\t\tPress any key to continue...");
    getch();
    system("cls");
    adminMenu();
}

void viewaddMenuItem(){
	system("cls");
    int choice;
    printf("\n\n\n\t\t\t   ============================================");
    printf("\n\t\t\t   |           AVAILABLE ITEMS TO ADD         |");
    printf("\n\t\t\t   ============================================\n");
    printf("\n\n\t\t\t\t\t1) Breakfast\n\t\t\t\t\t2) Khana Set\n\t\t\t\t\t3) Fast food\n\t\t\t\t\t4) Drinks\n\t\t\t\t\t5) Desserts\n\t\t\t\t\t6) Back to main menu\n");
    printf("\n\t\t\t\t\tEnter the choice:");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
        addMenuItem("breakfast_menu.txt", "BREAKFAST MENU");

        break;
    case 2:
        addMenuItem("khana_set_menu.txt", "KHANA SET MENU");
        break;
    case 3:
        addMenuItem("snacks_menu.txt", "FAST FOOD MENU");
        break;
    case 4:
        addMenuItem("drinks_menu.txt", "DRINKS MENU");
        break;
    case 5:
        addMenuItem("desserts_menu.txt", "DESSERTS MENU");
        break;
        
    case 6:
    	system("cls");
    	adminMenu();  
		break; 	
    
    default:
    	printf("\n\t\t\t\tInvalid Input!");
		printf("\n\t\t\t\tPress any key to try again!");
		getch();
		viewaddMenuItem();
    }
	
}

void addMenuItem(const char *filename, const char *title){
	system("cls");
	int count = 0;
	FILE *fp = fopen(filename, "r");
    struct FoodItem item[100];
    struct FoodItem newItem;

    if (fp == NULL)
    {
        printf("Error reading file or file not found.\n");
        return;
    }

    printf("\n\n\n\t\t   =======================================================");
    printf("\n\t\t   |                     %s                  |", title);
    printf("\n\t\t   =======================================================\n\n");
    printf("\t\t\tID\tName\t\t\t\tPrice\n");
    printf("\t\t\t----------------------------------------------\n");

    while (fscanf(fp, "%d,%49[^,],%f\n", &item[count].id, item[count].name, &item[count].price) == 3)
    {
        printf("\t\t\t%d\t%-31s %.2f\n", item[count].id, item[count].name, item[count].price);
        count++;
    }
    fclose(fp);
    fp = fopen(filename, "a");
	printf("\n\t\t\tEnter new item ID: ");
    scanf("%d", &newItem.id);

    printf("\t\t\tEnter new item name: ");
    getchar(); // to consume newline left by scanf
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // remove newline

    printf("\t\t\tEnter item price: ");
    scanf("%f", &newItem.price);
    
    item[count] = newItem;
    count ++;
    fprintf(fp, "%d,%s,%.2f\n", newItem.id, newItem.name, newItem.price);
    fclose(fp);
    printf("\n\n\t\t\tAdding Item.");
	for(int i=0;i<8;i++){
		Sleep(100);
		printf(".");
		fflush(stdout);
	}
    printf("\n\t\t\tNew Item Added successfully!");
    printf("\n\n\t\t\tPress any key to continue...");
    getch();
    system("cls");
    adminMenu();
}

void viewdeleteItem(){
	system("cls");
    int choice;
    printf("\n\n\n\t\t\t   ============================================");
    printf("\n\t\t\t   |           AVAILABLE ITEMS TO DELETE      |");
    printf("\n\t\t\t   ============================================\n");
    printf("\n\n\t\t\t\t\t1) Breakfast\n\t\t\t\t\t2) Khana Set\n\t\t\t\t\t3) Fast food\n\t\t\t\t\t4) Drinks\n\t\t\t\t\t5) Desserts\n\t\t\t\t\t6) Back to main menu\n");
    printf("\n\t\t\t\t\tEnter the choice:");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
        deleteMenuItem("breakfast_menu.txt", "BREAKFAST MENU");

        break;
    case 2:
        deleteMenuItem("khana_set_menu.txt", "KHANA SET MENU");
        break;
    case 3:
        deleteMenuItem("snacks_menu.txt", "FAST FOOD MENU");
        break;
    case 4:
        deleteMenuItem("drinks_menu.txt", "DRINKS MENU");
        break;
    case 5:
        deleteMenuItem("desserts_menu.txt", "DESSERTS MENU");
        break; 
    case 6:
		system("cls"); 
    	adminMenu(); 
		break; 	
    
    default:
    	printf("\n\t\t\t\tInvalid Input!");
		printf("\n\t\t\t\tPress any key to try again!");
		getch();
		viewdeleteItem();
 	}
    
}

void deleteMenuItem(const char *filename, const char *title){
	system("cls");
    struct FoodItem item[100];
	int idToDelete, count = 0, found = 0;
	FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error reading file or file not found.\n");
        return;
    }

    printf("\n\n\n\t\t   =======================================================");
    printf("\n\t\t   |                     %s                              |", title);
    printf("\n\t\t   =======================================================\n\n");
    printf("\t\t\tID\tName\t\t\t\tPrice\n");
    printf("\t\t\t----------------------------------------------\n");

    while (fscanf(fp, "%d,%49[^,],%f\n", &item[count].id, item[count].name, &item[count].price) == 3)
    {
        printf("\t\t\t%d\t%-31s %.2f\n", item[count].id, item[count].name, item[count].price);
        count++;
    }
    fclose(fp);
    printf("\n\t\t\tEnter the ID of the item to delete: ");
    scanf("%d",&idToDelete);
    fp = fopen(filename,"w");
    if(fp == NULL){
    	printf("\t\t\tError opening file for writing.\n");
    	return;
	}
	for(int i =0;i<count; i++){
		if(item[i].id != idToDelete){
			fprintf(fp,"%d,%s,%.2f\n",item[i].id,item[i].name,item[i].price);
			
		}
		else{
				found = 1;
			}
	}
	fclose(fp);
	printf("\n\n\t\t\tDeleting Item.");
	for(int i=0;i<8;i++){
		Sleep(100);
		printf(".");
		fflush(stdout);
	}
	if(found){
		printf("\n\t\t\tItem with ID %d deleted successfully.\n",idToDelete);
	}
	else{
		printf("\n\t\t\tItem with Id %d not found \n",idToDelete);
	}
	printf("Press any key to continue...");
	getch();
	adminMenu();
}













