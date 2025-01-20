#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


void generatePassword(int length, char *password)

{

char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()[]{}|\\:;,.<>?~`";
int charactersSize = strlen(characters);

srand(time(0));


for (int i = 0; i < length; i++)
    {
        password[i] = characters[rand() % charactersSize];
    }

        password[length] = '\0';

}


const char *evaluatePasswordStrength(const char *password)

 {

int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;

for (int i = 0; i < strlen(password); i++)
{
    if ( islower(password[i]) )
     hasLower = 1;

    else if ( isupper(password[i]) )
     hasUpper = 1;

    else if ( isdigit(password[i]) )
    hasDigit = 1;

    else
    hasSpecial = 1;

}

if (hasLower == 1 && hasUpper == 1 && hasDigit == 1 && hasSpecial == 1
    && strlen(password) >= 8)

 {
    return "Strong";
 }
    return "Weak";

 }


int main()

 {

    int length;
    char password[65];

    printf("Enter a number to get that length of password of range(8-64): ");
    scanf("%d", &length);


    if (length < 8 || length > 64)

    {
        printf("\nInvalid length! Please enter a value between 8 and 64.\n");
        return 1;
    }

   generatePassword(length, password);

   printf("\nGenerated Password: %s\n", password);

   evaluatePasswordStrength(password);

   printf("\nPassword Strength: %s\n", evaluatePasswordStrength(password));

return 0;

 }


