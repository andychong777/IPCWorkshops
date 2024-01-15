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


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3
#define NUMBER_GRAMS 64
#define LBS_TO_KGS 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double productPrice;
    double productWeight;
    int calPerServing;
};

struct ReportData
{
    int sku;
    double productPrice;
    int calPerServing;
    double weightLbs;
    double weightKg;
    int weightG;
    double totalServings;
    double costPerServing;
    double costCalPerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* positive);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePositive);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int sequenceNum);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku,
                        const double* productPrice, 
                        const double* productWeight,
                        const int calPerServing);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* pounds, double* kgResult);

// 9. convert lbs: g
int convertLbsG(const double* pounds, int* gramsResult);

// 10. convert lbs: kg / g
void convertLbs(double* pounds, double* kgResult, int* gramsResult);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeG, const int totalGrams, double* numberServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalServings, double* costPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCal, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int cheapestProduct);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProductInfo);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);