#include <stdio.h>
#include <string.h>
char SignName[20];
char SignPassword[20];
char LogName[20];
char LogPassword[20];

void Signup()
{
    printf("--- Sign-up ---\n");
    printf("Enter Name: ");
    scanf(" %s", &SignName);

    printf("Enter Password: ");
    scanf("%s", &SignPassword);

    printf("Registered successfully!\n");
    return;
}

void Exit()
{
    printf("\n--- Thank you for visiting BSRTC Service! ---\n");
    printf("Goodbye!\n");
    return;
}

void Login()
{
    int choice;

    printf("--- Login Page ---\n");
    printf("Enter Name: ");
    scanf(" %s", &LogName);

    printf("Enter Password: ");
    scanf("%s", &LogPassword);

    if (strcmp(LogName, SignName) == 0 && strcmp(LogPassword, SignPassword) == 0)
    {
        printf("\nLogin Successful! Welcome to Bus Reservation System.\n"); // Make it Green
        // keep here menu function to explore more.
    }
    else
    {
        printf("\nLogin Failed! Try Again!'\n");
        Login();
    }
}

void HomePage()
{
    int choice;
    printf("\n1. Sign-up\n");
    printf("2. Log-in\n");
    printf("3. Exit\n");
    printf("Please Enter Your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        Signup();
        Login();
        break;
    case 2:
        Login();
        break;
    case 3:
        Exit();
    default:
        break;
    }
}

int main()
{
    printf("\n******************** STAR BUS RESERVATION SYSTEM *************************\n");
    HomePage();
    return 0;
}
