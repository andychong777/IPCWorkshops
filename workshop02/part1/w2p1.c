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
    int numberofShirts;
    int subtotal, taxes, total;

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
    printf("SMALL  : $%.2lf\n", smallPrice);
    printf("MEDIUM : $%.2lf\n", mediumPrice);
    printf("LARGE  : $%.2lf\n\n", largePrice);

//pattys shirt size is 's'
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numberofShirts);

//shopping cart
    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", numberofShirts);

    subtotal = smallPrice * numberofShirts;
    printf("Sub-total: $%.4lf\n", subtotal);
//ROUNDING AND TOTAL
    taxes = subtotal * TAX;
    taxes = (taxes + 0.005) * 100.0;
    cents = taxes;
    taxes = cents / 100.0;
    printf("Taxes    : $ %.4lf\n", taxes);


    total = subtotal + taxes;
    total = (total + 0.005) * 100.0;
    cents = total;
    total = cents / 100.0;
    printf("Total    : $%.4lf\n", total);

    return 0;
}