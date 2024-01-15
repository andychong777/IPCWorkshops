/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* positive)
{
    int number;
    do
    {
        scanf("%d", &number);
        if (number <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
       
    } while (number <= 0);

    if (positive != NULL)
    {
        *positive = number;
    }
    
    return number;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePositive)
{
    double number;
    do
    {
        scanf("%lf", &number);
        if (number <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        
    } while (number <= 0);

    if (doublePositive != NULL)
    {
        *doublePositive = number;
    }

    return number;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int sequenceNum)//maxproducts?
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n"
    , sequenceNum);
    printf("NOTE: A 'serving' is %dg\n\n", NUMBER_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum) 
{
	struct CatFoodInfo cfi = { 0 };
	
	printf("Cat Food Product #%d\n", sequenceNum + 1);
	printf("--------------------\n");
	printf("SKU           : "); // SKU
    getIntPositive(&cfi.sku);
    printf("PRICE         : $"); //PRICE
    getDoublePositive(&cfi.productPrice);
    printf("WEIGHT (LBS)  : "); //WEIGHT
    getDoublePositive(&cfi.productWeight);
    printf("CALORIES/SERV.: "); //CAL
    getIntPositive(&cfi.calPerServing);
    putchar('\n');

	// Returning the struct
	return cfi;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* productPrice,
                        const double* productWeight, const int calPerServing)
{
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *productPrice, *productWeight, calPerServing);
}
// 7. Logic entry point
void start(void) //start
{
    //declare variables
    int i;
    struct CatFoodInfo cfi[MAX_PRODUCTS] = { { 0 } };

    openingMessage(MAX_PRODUCTS); //start subprocess openingmsg

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        cfi[i] = getCatFoodInfo(i);// start subprocess userInput
    }

    displayCatFoodHeader();//start subprocess chart

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        displayCatFoodData(cfi[i].sku, &cfi[i].productPrice, &cfi[i].productWeight, cfi[i].calPerServing);
    }
}