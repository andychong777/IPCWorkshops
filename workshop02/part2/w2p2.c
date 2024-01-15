/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    double smallPrice, mediumPrice, largePrice;
    int patShirts, salShirts, tomShirts;
    int patSubtotal, patTaxes, patTotal;
    int salSubtotal, salTaxes, salTotal;
    int tomSubtotal, tomTaxes, tomTotal;
    int grandSubtotal, grandTax, grandTotal;
    
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
    scanf("%d", &patShirts);
    printf("\n");

//Tommy's shirt size is 'L'
    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tomShirts);
    printf("\n");

//Sally shirt size is 'M'
    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &salShirts);
    printf("\n");

//calculate sales for patty
    patSubtotal = (int)(((smallPrice * patShirts) + 0.005) * 100);
    patTaxes = (int)((((smallPrice * patShirts) * TAX) + 0.005) * 100);
    patTotal = patSubtotal + patTaxes;

//calculate sales for Tommy
    tomSubtotal = (int)(((largePrice * tomShirts) + 0.005) * 100);
    tomTaxes = (int)((((largePrice * tomShirts) * TAX) + 0.005) * 100);
    tomTotal = tomSubtotal + tomTaxes; 

//calculate sales for Sally
    salSubtotal = (int)(((mediumPrice * salShirts) + 0.005) * 100);
    salTaxes = (int)((((mediumPrice * salShirts) * TAX) + 0.005) * 100);
    salTotal = salSubtotal + salTaxes;

//total for all 3 combined
    grandSubtotal = (patSubtotal + salSubtotal + tomSubtotal);
    grandTax = (patTaxes + tomTaxes + salTaxes);
    grandTotal = (patTotal + salTotal + tomTotal);

    
//Sales data in a tabular format
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallPrice, patShirts, patSubtotal/100.0, patTaxes/100.0, patTotal/100.0); 
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mediumPrice, salShirts, salSubtotal/100.0, salTaxes/100.0, salTotal/100.0);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largePrice, tomShirts, tomSubtotal/100.0, tomTaxes/100.0, tomTotal/100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", grandSubtotal/100.0, grandTax/100.0, grandTotal/100.0);

//sales represented by coins
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (double)grandSubtotal / 100); 

//toonies
    int Toonies, Loonies, Quaters, Dimes, Nickels, Pennies;
    float toonieRemainder, loonieRemainder, quarterRemainder, dimeRemainder, nickelRemainder, penniesRemainder;
    float subAverage, grandAverage;

    Toonies = (double)(patSubtotal + salSubtotal + tomSubtotal) / 200;
    toonieRemainder = (patSubtotal + salSubtotal + tomSubtotal) % 200;
    printf("Toonies  %3d %9.4lf\n", Toonies, toonieRemainder / 100);

    Loonies = toonieRemainder /100;
    loonieRemainder = (int)toonieRemainder % 100;
    printf("Loonies  %3d %9.4lf\n", Loonies, loonieRemainder / 100);

    Quaters = loonieRemainder / 25;
    quarterRemainder = (int)loonieRemainder % 25;
    printf("Quarters %3d %9.4lf\n", Quaters, quarterRemainder / 100);

    Dimes = quarterRemainder / 10;
    dimeRemainder = (int)quarterRemainder % 10;
    printf("Dimes    %3d %9.4lf\n", Dimes, dimeRemainder / 100);

    Nickels = dimeRemainder / 5;
    nickelRemainder = (int)dimeRemainder % 5;
    printf("Nickels  %3d %9.4lf\n", Nickels, nickelRemainder / 100);

    Pennies = nickelRemainder /1;
    penniesRemainder = (int)nickelRemainder % 1;
    printf("Pennies  %3d %9.4lf\n\n", Pennies, penniesRemainder / 100);

    subAverage = (patSubtotal + salSubtotal + tomSubtotal) / (float)(patShirts + salShirts + tomShirts) / 100;
    printf("Average cost/shirt: $%0.4lf\n\n",subAverage);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (double)grandTotal / 100);
    
    Toonies = (double)(patTotal + salTotal + tomTotal) / 200;
    toonieRemainder = (patTotal + salTotal + tomTotal) % 200;
    printf("Toonies  %3d %9.4lf\n", Toonies, toonieRemainder/ 100);

    Loonies = toonieRemainder / 100;
    loonieRemainder = (int)toonieRemainder % 100;
    printf("Loonies  %3d %9.4lf\n", Loonies, loonieRemainder / 100);

    Quaters = loonieRemainder / 25;
    quarterRemainder = (int)loonieRemainder % 25;
    printf("Quarters %3d %9.4lf\n", Quaters, quarterRemainder / 100);

    Dimes = quarterRemainder / 10;
    dimeRemainder = (int)quarterRemainder % 10;
    printf("Dimes    %3d %9.4lf\n", Dimes, dimeRemainder / 100);

    Nickels = dimeRemainder / 5;
    nickelRemainder = (int)dimeRemainder % 5;
    printf("Nickels  %3d %9.4lf\n", Nickels, nickelRemainder / 100);

    Pennies = nickelRemainder /1;
    penniesRemainder = (int)nickelRemainder % 1;
    printf("Pennies  %3d %9.4lf\n\n", Pennies, penniesRemainder / 100);

    grandAverage = (patTotal + salTotal + tomTotal) / (float)(patShirts + salShirts + tomShirts) / 100;
    printf("Average cost/shirt: $%0.4lf\n\n",grandAverage);

    return 0;
}