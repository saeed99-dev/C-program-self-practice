#include <stdio.h>
#include <string.h>

char SignName[20];
char SignPassword[20];
char LogName[20];
char LogPassword[20];
char Email[50];
char Gender;
char Mobile[11];

char BusNumbers[5][10] = {"BR101", "BR202", "DL303", "UK404", "MH505"};
char Routes[5][50] = {"Patna to Delhi", "Patna to Gya", "Delhi to Patna", "Uk to Agra", "Mumbai to Pune"};
char DepartureTimes[5][10] = {"08:00 AM", "10:30 AM", "02:00 PM", "05:45 PM", "11:00 PM"};
int TotalbusSeats[5] = {50, 50, 50, 50, 50};
int AvailableSeats[5] = {50, 50, 50, 50, 50};
float Fare[5] = {700.00, 300.00, 700.00, 500.00, 600.00};

void Login();
void Logout();
void Menu();
void CheckBusDetail();
void HomePage();
void BookTicket();
void CancelTicket();
void InfoDisplay();
void ProcessPayment(int ticketsBooked, float farePerTicket);
void ProcessRefund(int ticketsCancelled, float farePerTicket);

int main()
{
    printf("\n\x1b[1;4;92m******************** BSRTC BUS RESERVATION SERVICE SYSTEM *************************\x1b[0m\n");
    HomePage();
    return 0;
}

void Menu()
{
    int choice;
    printf("\n\x1b[96m***** USER MENU *****\x1b[0m\n");
    printf("\n\x1b[93m1.\x1b[0m Book a Ticket\n\x1b[93m2.\x1b[0m Cancel Ticket\n\x1b[93m3.\x1b[0m Check Bus Detail\n\x1b[93m4.\x1b[0m Logout");

    printf("\n\x1b[32mEnter Your Choice: \x1b[0m");
    scanf("%d", &choice);

    switch (choice)
    {
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
        Logout();
        break;

    default:
        printf("\n\x1b[92mInvalid Input! Please select the Input carefully!\x1b[0m\n");
        Menu();
        break;
    }
}

void Signup()
{
    printf("\n\x1b[1;35m--- Sign-up ---\x1b[0m\n");

    int nameValid = 0;
    while (!nameValid)
    {
        int i;
        printf("\x1b[36mEnter Your Name: \x1b[0m");
        scanf(" %19[^\n]", SignName);

        if (strlen(SignName) < 4)
        {
            printf("\x1b[31mName length must be > 4.\x1b[0m\n");
            continue;
        }

        if (SignName[0] < 'A' || SignName[0] > 'Z')
        {
            printf("\x1b[31mName must start with capital letter.\x1b[0m\n");
            continue;
        }

        nameValid = 1;
        for (i = 0; i < strlen(SignName) - 2; i++)
        {
            if (SignName[i] == SignName[i + 1] && SignName[i] == SignName[i + 2])
            {
                printf("\x1b[31m3 Consecutive same word is not allowed.\x1b[0m\n");
                nameValid = 0;
                break;
            }
        }
        if (!nameValid)
        {
            continue;
        }

        for (i = 0; i < strlen(SignName); i++)
        {
            if (SignName[i] == ' ' || (SignName[i] >= '0' && SignName[i] <= '9'))
            {
                printf("\x1b[31mNo spaces or digits allowed in name.\x1b[0m\n");
                nameValid = 0;
                break;
            }
            if (!((SignName[i] >= 'A' && SignName[i] <= 'Z') || (SignName[i] >= 'a' && SignName[i] <= 'z')))
            {
                printf("\x1b[31mOnly letters allowed in name.\x1b[0m\n");
                nameValid = 0;
                break;
            }
        }
    }

    int mobileValid = 0;
    while (!mobileValid)
    {
        printf("\x1b[36mEnter Your Mobile Number: \x1b[0m");
        scanf("%12s", Mobile);

        if (Mobile[0] == '0')
        {
            printf("\x1b[31mMobile number must not start with '0'\x1b[0m\n");
            continue;
        }

        int i;
        mobileValid = 1;

        for (i = 0; i < strlen(Mobile); i++)
        {
            if (Mobile[i] < '0' || Mobile[i] > '9')
            {
                printf("\x1b[31mNumber must contain only digits b/w 0-9\x1b[0m\n");
                mobileValid = 0;
                break;
            }
        }
        if (strlen(Mobile) != 10)
        {
            printf("\x1b[31mMobile number must be 10 digits.\x1b[0m\n");
            mobileValid = 0;
            continue;
        }
    }

    int emailValid = 0;
    while (!emailValid)
    {
        printf("\x1b[36mEnter Your Email: \x1b[0m");
        scanf("%49s", Email);

        int atCount = 0;
        if (strlen(Email) < 10 || strlen(Email) > 50)
        {
            printf("\x1b[31mEmail length must be > 10 and < 50\x1b[0m\n");
            continue;
        }

        int i;
        emailValid = 1;
        for (i = 0; i < strlen(Email); i++)
        {
            char c = Email[i];
            if (c == '!' || c == '#' || c == '$' || c == '%' || c == '&' || c == '\'' || c == '*' || c == '+' || c == '-' || c == '/' || c == '=' || c == '?' || c == '^' || c == '_' || c == '`' || c == '{' || c == '|' || c == '}' || c == '~')
            {
                printf("\x1b[31mEmail must not contain any special character.\x1b[0m\n");
                emailValid = 0;
                break;
            }
        }

        for (i = 0; i < strlen(Email); i++)
        {
            if (Email[i] == '@')
            {
                atCount++;
            }
        }
        if (atCount != 1)
        {
            printf("\x1b[31mEmail must contain only one '@'.\x1b[0m\n");
            emailValid = 0;
            continue;
        }

        if (Email[0] == '@' || Email[strlen(Email) - 1] == '@')
        {
            printf("\x1b[31mEmail cannot start or end with '@'.\x1b[0m\n");
            continue;
        }

        for (i = 0; i < strlen(Email) - 1; i++)
        {
            if (Email[i] == '.' && Email[i + 1] == '.')
            {
                printf("\x1b[31mEmail must not contain consecutive dots.\x1b[0m\n");
                emailValid = 0;
                break;
            }
        }

        for (i = 0; i < strlen(Email) - 3; i++)
        {
            if (Email[i] == Email[i + 1] && Email[i] == Email[i + 2])
            {
                printf("\x1b[31mEmail must not contain consecutive same character.\x1b[0m\n");
                emailValid = 0;
                break;
            }
        }
    }

    int genderValid = 0;
    while (!genderValid)
    {
        printf("\x1b[36mEnter gender (M/F): \x1b[0m");
        scanf(" %c", &Gender);

        if (Gender == 'M' || Gender == 'm')
        {
            printf("Gender: Male\n");
            genderValid = 1;
        }
        else if (Gender == 'F' || Gender == 'f')
        {
            printf("Gender: Female\n");
            genderValid = 1;
        }
        else
        {
            printf("\x1b[31mInvalid! Enter M/m or F/f only.\x1b[0m\n");
        }
    }

    int passwordValid = 0;
    while (!passwordValid)
    {
        int valid = 0, i;
        printf("\x1b[36mSet Your Password: \x1b[0m");
        scanf("%19s", SignPassword);

        if (strlen(SignPassword) < 8)
        {
            printf("\x1b[31mPassword length must be at least 8.\x1b[0m\n");
            continue;
        }

        for (i = 0; i < strlen(SignPassword); i++)
        {
            if (SignPassword[i] >= '0' && SignPassword[i] <= '9')
            {
                valid = 1;
                break;
            }
        }
        if (!valid)
        {
            printf("\x1b[31mPassword must contain at least one digit.\x1b[0m\n");
            continue;
        }

        passwordValid = 1;
        for (i = 0; i < strlen(SignPassword) - 2; i++)
        {
            if (SignPassword[i] == SignPassword[i + 1] && SignPassword[i] == SignPassword[i + 2])
            {
                printf("\x1b[31m3 Consecutive same word is not allowed\x1b[0m\n");
                passwordValid = 0;
                break;
            }
        }
    }

    printf("\x1b[92mRegistered successfully!\x1b[0m\n");
}

void Logout()
{
    printf("\n\x1b[1;32m--- Thank you for visiting BSRTC Bus Service! ---\x1b[0m\n");
    printf("\x1b[34mGoodbye!\x1b[0m\n");
    return;
}

void Login()
{
    int loginValid = 0;
    while (!loginValid)
    {
        printf("\n\x1b[1;35m--- Login Page ---\x1b[0m\n");
        printf("\x1b[36mEnter Name: \x1b[0m");
        scanf(" %s", &LogName);

        printf("\x1b[36mEnter Password: \x1b[0m");
        scanf("%s", &LogPassword);

        if (strcmp(LogName, SignName) == 0 && strcmp(LogPassword, SignPassword) == 0)
        {
            printf("\n\x1b[92mLogin Successful! Welcome Saeed to BSRTC Bus Service.\x1b[0m\n"); // Make it Bright Green
            loginValid = 1;
        }
        else
        {
            printf("\n\x1b[31mLogin Failed! Please Enter your Correct Username or Password!\x1b[0m\n");
            Login();
            break;
        }
    }
}

void HomePage()
{
    int choice;
    printf("\n\x1b[1;36m=== HOME PAGE ===\x1b[0m\n");
    printf("\x1b[93m1.\x1b[0m Sign-up\n");
    printf("\x1b[93m2.\x1b[0m Log-in\n");
    printf("\x1b[93m3.\x1b[0m Exit\n");
    printf("\n\x1b[32mPlease Enter Your Choice: \x1b[0m");
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
        break;
    default:
        printf("\n\x1b[31mInvalid Input! Please select the Input carefully!\x1b[0m\n");
        HomePage();
        break;
    }
}

void InfoDisplay()
{
    printf("\n\x1b[1;4;36m---- Bus Details ----\x1b[0m\n");
    printf("\x1b[34m---------------------------------------------------------------\x1b[0m\n");
    printf("\x1b[1mBus No\tRoute   \tDept Time  Avail Seats  Fare\x1b[0m\n");
    printf("\x1b[34m---------------------------------------------------------------\x1b[0m\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t%s\t%s\t%d\t%.2f\n", BusNumbers[i], Routes[i], DepartureTimes[i], AvailableSeats[i], Fare[i]);
    }
    printf("\x1b[34m---------------------------------------------------------------\x1b[0m\n");
}

void CheckBusDetail()
{
    char inputBus[10];
    int found = 0;
    printf("\x1b[36mEnter Bus Number: \x1b[0m");
    scanf("%s", inputBus);

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(inputBus, BusNumbers[i]) == 0)
        {
            printf("\n\x1b[1;32m--- Bus Details ---\x1b[0m");
            printf("\nBus No: %s\nRoute: %s\nTime: %s\nAvailable Seats: %d\nFare: %.2f\n", BusNumbers[i], Routes[i], DepartureTimes[i], AvailableSeats[i], Fare[i]);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("\x1b[31mBus not found!\x1b[0m\n");
    }
}

void BookTicket()
{
    char inputBus[10];
    int seats, found = 0;
    InfoDisplay();
    printf("\x1b[36mEnter Bus Number: \x1b[0m");
    scanf("%s", inputBus);

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(inputBus, BusNumbers[i]) == 0)
        {
            found = 1;
            printf("\x1b[36mEnter number of seats to book: \x1b[0m");
            scanf("%d", &seats);
            if (seats <= AvailableSeats[i] && seats > 0)
            {
                AvailableSeats[i] -= seats;
                printf("\x1b[92mBooking Successful! Total Fare: %.2f\n\x1b[0m", Fare[i] * seats);
                ProcessPayment(seats, Fare[i]);
            }
            else
            {
                printf("\x1b[31mNot enough seats available!\x1b[0m\n");
            }
            break;
        }
    }
    if (found == 0)
    {
        printf("\x1b[31mBus not found!\x1b[0m\n");
    }
}

void CancelTicket()
{
    char inputBus[10];
    int seats, found = 0;
    printf("\x1b[36mEnter Bus Number: \x1b[0m");
    scanf("%s", inputBus);

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(inputBus, BusNumbers[i]) == 0)
        {
            found = 1;
            printf("\x1b[36mEnter seats to cancel: \x1b[0m");
            scanf("%d", &seats);
            if (AvailableSeats[i] + seats <= TotalbusSeats[i])
            {

                AvailableSeats[i] += seats;
                printf("\x1b[93mCancellation Successful! Total Refundable Amount :%.2f\n\x1b[0m", Fare[i] * seats);
                ProcessRefund(seats, Fare[i]);
            }
            else
            {
                printf("\x1b[31mInvalid number of seats to cancel!\x1b[0m\n");
            }
            break;
        }
    }
    if (found == 0)
    {
        printf("\x1b[31mBus not found!\x1b[0m\n");
    }
}

void ProcessPayment(int ticketsBooked, float farePerTicket)
{
    int method;
    float totalAmount = ticketsBooked * farePerTicket;

    printf("\n\x1b[1;35m--- SECURE PAYMENT GATEWAY ---\x1b[0m");
    printf("\nTickets Booked : \x1b[96m%d\x1b[0m", ticketsBooked);
    printf("\nFare / Ticket  : \x1b[96m%.2f\x1b[0m", farePerTicket);
    printf("\nTotal Payable  : \x1b[92m%.2f\x1b[0m", totalAmount);

    printf("\n\n\x1b[33mSelect Payment Method:\x1b[0m");
    printf("\n\x1b[93m1.\x1b[0m UPI\n\x1b[93m2.\x1b[0m Card\n\x1b[93m3.\x1b[0m Net Banking\n\x1b[32mChoose: \x1b[0m");
    scanf("%d", &method);

    printf("\n\x1b[36mProcessing payment of \x1b[92m%.2f\x1b[36m...\x1b[0m", totalAmount);
    printf("\n\x1b[92m[Payment Received Successfully]\x1b[0m\n");
}

void ProcessRefund(int ticketsCancelled, float farePerTicket)
{
    int method;
    float totalAmount = ticketsCancelled * farePerTicket;
    printf("\n\x1b[1;35m----REFUND PROCESSING----\x1b[0m");
    printf("\nTickets Cancelled : \x1b[96m%d\x1b[0m", ticketsCancelled);
    printf("\nFare / Ticket  : \x1b[96m%.2f\x1b[0m", farePerTicket);
    printf("\nAmount Refunded: \x1b[92m%.2f\x1b[0m", totalAmount);
    printf("\n\x1b[32mRefund initiated to your original payment method...\x1b[0m");
    printf("\n\x1b[96mRefund Successfull\x1b[0m\n");
}
