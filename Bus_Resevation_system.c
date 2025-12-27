#include <stdio.h>
#include <string.h>

char SignName[20];
char SignPassword[20];
char LogName[20];
char LogPassword[20];

// Bus & Schedule Data
char BusNumbers[5][10] = {"BR101", "BR202", "DL303", "UK404", "MH505"};
char Routes[5][50] = {"Patna to Delhi", "Patna to Gya", "Delhi to Patna", "Uk to Agra", "Mumbai to Pune"};
char DepartureTimes[5][10] = {"08:00 AM", "10:30 AM", "02:00 PM", "05:45 PM", "11:00 PM"};
int TotalbusSeats[5] = {50, 50, 50, 50, 50};
int AvailableSeats[5] = {50, 50, 50, 50, 50};
float Fare[5] = {700.00, 300.00, 700.00, 500.00, 600.00};

// Function Prototypes
void Login();                            // yes
void Logout();                           // yes
void Menu();                             // yes
void CheckBusDetail();                   // yes
void BookTicket();                       // yes
void CancelTicket();                     // yes
void displaySeats();                     // left
// void Payment(int busIndex, int seatNum); // left

void Menu()
{
    int choice;
    printf("\n*****USER MENU*****\n");
    printf("\n1. Book a Ticket\n2. Cancel Ticket\n3. Check Bus Detail\n4. Logout"); // check it with output
    printf("\nEnter Your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    { // add here to display Buses Status  and then arrange it.
    case 1:
        BookTicket();
        Menu();
        break;

    case 2:
        CancelTicket();
        Menu();
        break;

    case 3:
        CheckBusDetail();
        Menu();
        break;

    case 4:
        Logout(); // check here!
        break;

    default:
        printf("Invalid choice!\n");
        Menu();
        break;
    }
}

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

void Logout()
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
        Menu();
        break;
    case 2:
        Login();
        break;
    case 3:
        Logout();
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

void CheckBusDetail()
{
    char inputBus[10];
    int found = 0;
    printf("Enter Bus Number: ");
    scanf("%s", inputBus);

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(inputBus, BusNumbers[i]) == 0)
        {
            printf("\n--- Bus Details ---");
            printf("\nBus No: %s\nRoute: %s\nTime: %s\nAvailable Seats: %d\nFare: %.2f\n",
                   BusNumbers[i], Routes[i], DepartureTimes[i], AvailableSeats[i], Fare[i]);
            found = 1;
            break;
        }
    }
    if (found == 0)
        printf("Bus not found!\n");
}

void BookTicket()
{
    char inputBus[10];
    int seats, found = 0;
    printf("Enter Bus Number: ");
    scanf("%s", inputBus);
    // display Bus here

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(inputBus, BusNumbers[i]) == 0)
        {
            found = 1;
            printf("Enter number of seats to book: ");
            scanf("%d", &seats);
            if (seats <= AvailableSeats[i])
            {
                AvailableSeats[i] -= seats;
                printf("Booking Successful! Total Fare: %.2f\n", Fare[i] * seats);
            }
            else
            {
                printf("Not enough seats available!\n");
            }
            break;
        }
    }
    if (found == 0)
        printf("Bus not found!\n");
}

void CancelTicket()
{
    char inputBus[10];
    int seats, found = 0;
    printf("Enter Bus Number: ");
    scanf("%s", inputBus);

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(inputBus, BusNumbers[i]) == 0)
        {
            found = 1;
            printf("Enter seats to cancel: ");
            scanf("%d", &seats);
            if (AvailableSeats[i] + seats <= TotalbusSeats[i])
            {
                AvailableSeats[i] += seats;
                printf("Cancellation Successful!\n");
            }
            else
            {
                printf("Invalid number of seats to cancel!\n");
            }
            break;
        }
    }
    if (found == 0)
        printf("Bus not found!\n");
}