/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
void openingMessage(const int sequenceNum)
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
	struct CatFoodInfo catFoodInfo = { 0 };
	
	printf("Cat Food Product #%d\n", sequenceNum + 1);
	printf("--------------------\n");
	printf("SKU           : "); // SKU
    getIntPositive(&catFoodInfo.sku);
    printf("PRICE         : $"); //PRICE
    getDoublePositive(&catFoodInfo.productPrice);
    printf("WEIGHT (LBS)  : "); //WEIGHT
    getDoublePositive(&catFoodInfo.productWeight);
    printf("CALORIES/SERV.: "); //CAL
    getIntPositive(&catFoodInfo.calPerServing);
    putchar('\n');

	// Returning the struct
	return catFoodInfo;
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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* kgResult)
{
	double kilograms = (*pounds) / LBS_TO_KGS;
	
	if (kgResult != NULL)
	{
		*kgResult = kilograms;
	}
	return kilograms;
}
// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* gramsResult)
{
	int grams = convertLbsKg(pounds, NULL) * 1000;

	if (gramsResult != NULL)
	{
		*gramsResult = grams;
	}
	return grams;
}

// 10. convert lbs: kg and g
void convertLbs(double* pounds, double* kgResult, int* gramsResult)
{
	convertLbsKg(pounds, kgResult);
	convertLbsG(pounds, gramsResult);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeG, const int totalGrams, double* numberServings)
{
	double servings = (double)totalGrams / servingSizeG;

	if (numberServings != NULL)
	{
		*numberServings = servings;
	}
	return servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalServings,
							   double* costPerServing)
{
	double cost = *productPrice / *totalServings;

	if (costPerServing != NULL)
	{
		*costPerServing = cost;
	}

	return cost;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCal,
						   double* costPerCal)
{
	double cal = *productPrice / *totalCal;

	if (costPerCal != NULL)
	{
		*costPerCal = cal;
	}

	return cal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo)
{
	struct ReportData reportData = { 0 };

	//assign value
	reportData.sku = catFoodInfo.sku;
	reportData.productPrice = catFoodInfo.productPrice;
	reportData.weightLbs = catFoodInfo.productWeight;
	reportData.calPerServing = catFoodInfo.calPerServing;

	//calculated Values
	convertLbsKg(&reportData.weightLbs, &reportData.weightKg);
	convertLbsG(&reportData.weightLbs, &reportData.weightG);
	calculateServings(NUMBER_GRAMS, reportData.weightG, &reportData.totalServings);
	calculateCostPerServing(&reportData.productPrice, &reportData.totalServings, 
							&reportData.costPerServing);

	double calPerServing = catFoodInfo.calPerServing * reportData.totalServings;
	calculateCostPerCal(&reportData.productPrice, &calPerServing, 
						&reportData.costCalPerServing);
	
	return reportData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NUMBER_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int cheapestProduct)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", 
	reportData.sku, reportData.productPrice, reportData.weightLbs, reportData.weightKg, reportData.weightG,
	reportData.calPerServing, reportData.totalServings, reportData.costPerServing,
	reportData.costCalPerServing);
	
	
	if (cheapestProduct > 0)
	{
		printf(" ***");
	}
	
}
 
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProductInfo)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", cheapestProductInfo.sku, cheapestProductInfo.productPrice);
	putchar('\n');
	printf("Happy shopping!\n\n");
}	

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    struct CatFoodInfo catFoodInfo[MAX_PRODUCTS] = { { 0 } };
	struct ReportData reportData[MAX_PRODUCTS] = { { 0 } };
	int cheapestProduct[MAX_PRODUCTS] = { 0 };
	int i;
	int cheapProductIndex = 0;
	

    openingMessage(MAX_PRODUCTS); //start subprocess openingmsg

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        catFoodInfo[i] = getCatFoodInfo(i);// start subprocess userInput
		reportData[i] = calculateReportData(catFoodInfo[i]); //start subprocess calreport
    }

    displayCatFoodHeader();//start subprocess chart

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        displayCatFoodData(catFoodInfo[i].sku, &catFoodInfo[i].productPrice, 
						   &catFoodInfo[i].productWeight, catFoodInfo[i].calPerServing);
    }
	putchar('\n');

	displayReportHeader(); //start subprocess analysis report
	
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (reportData[i].costPerServing < reportData[cheapProductIndex].costPerServing)
		{
			cheapestProduct[i] = 1;
			cheapestProduct[cheapProductIndex] = 0;
			cheapProductIndex = i;
		}
	} 
	putchar('\n');
	
	//subprocess data
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayReportData(reportData[i], cheapestProduct[i]);
		putchar('\n');
	}
	putchar('\n');
	
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (i == cheapProductIndex)
		{
			displayFinalAnalysis(catFoodInfo[i]);
		}
	}

}