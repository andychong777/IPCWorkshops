/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Andy Chong
Student ID#: 150558229
Email      : achong11@myseneca.ca
Section    : NAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double smallPrice, mediumPrice, largePrice;
    int numberShirts, subtotal, taxes, total;
    
//Shirt Prices
    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largePrice);

//Store price List
    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL : $%.2lf\n", smallPrice);
    printf("MEDIUM : $%.2lf\n", mediumPrice);
    printf("LARGE : $%.2lf\n\n", largePrice);

//pattys shirt size is 's'
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numberShirts);

//small price x number of shirts(Subtotal) +0.005 rounds to subtotal/ x100 is making it into cents //cuz its a double (int)makes it into an int
    subtotal = (int)(((smallPrice * numberShirts) + 0.005) * 100);
    taxes = (int)((((smallPrice * numberShirts) * TAX) + 0.005) * 100);
    total = subtotal + taxes;
//shopping cart

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", numberShirts);
    printf("Sub-total: $%8.4lf\n", (double) subtotal/100);
    printf("Taxes    : $%8.4lf\n", taxes/100.0);
    printf("Total    : $%8.4lf\n", total/100.0);

    return 0;
}