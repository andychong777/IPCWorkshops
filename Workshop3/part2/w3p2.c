/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char coffeeType1, coffeeType2, coffeeType3;
    char bestServed1, bestServed2, bestServed3;
    char coffeeStrength, cream;
    int weight1, weight2, weight3;
    int servings;
    
    //product data input
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    //coffee1
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType1);
    printf("Bag weight (g): ");
    scanf(" %d", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestServed1);   
    printf("\n");

    //coffee2
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType2);
    printf("Bag weight (g): ");
    scanf(" %d", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestServed2);
    printf("\n");

    //coffee3
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType3);
    printf("Bag weight (g): ");
    scanf(" %d", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestServed3);
    printf("\n");

    //chart
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", 
    (coffeeType1 == 'L' || coffeeType1 == 'l'), 
    (coffeeType1 == 'M' || coffeeType1 == 'm'), 
    (coffeeType1 == 'R' || coffeeType1 == 'r'),
    weight1, (weight1 / GRAMS_IN_LBS),
    (bestServed1 == 'Y' || bestServed1 == 'y'));

    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
    (coffeeType2 == 'L' || coffeeType2 == 'l'),
    (coffeeType2 == 'M' || coffeeType2 == 'm'),
    (coffeeType2 == 'R' || coffeeType2 == 'r'),
    weight2, (weight2 / GRAMS_IN_LBS),
    (bestServed2 == 'Y' || bestServed2 == 'y'));

    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n",
    (coffeeType3 == 'L' || coffeeType3 == 'l'),
    (coffeeType3 == 'M' || coffeeType3 == 'm'),
    (coffeeType3 == 'R' || coffeeType3 == 'r'),
    weight3, weight3 / GRAMS_IN_LBS,
    (bestServed3 == 'Y' || bestServed3 == 'y'));


    //how u like your coffee
    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream);
    printf("Typical number of daily servings: ");
    scanf(" %d",&servings);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    //Chart2
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", 
    ((coffeeType1 == 'L' || coffeeType1 == 'l') && (coffeeStrength == 'L' || coffeeStrength == 'l'))||
    ((coffeeType1 == 'M' || coffeeType1 == 'm') && (coffeeStrength == 'M' || coffeeStrength == 'm'))||
    ((coffeeType1 == 'R' || coffeeType1 == 'r') && (coffeeStrength == 'R' || coffeeStrength == 'r')),
    ((servings >=1 && servings <=4) && (weight1 == 250)) ||
    ((servings >4 && servings <= 9) && (weight1 ==  500)) ||
    ((servings >9) && (weight1 ==  1000)),
    ((cream == 'Y' || cream == 'y') && (bestServed1 == 'Y' || bestServed1 == 'y')) ||
    ((cream == 'N' || cream == 'n') && (bestServed1 == 'N' || bestServed1 == 'n')));
    
    printf(" 2|       %d         |      %d      |   %d   |\n",
    ((coffeeType2 == 'L' || coffeeType2 == 'l') && (coffeeStrength == 'L' || coffeeStrength == 'l'))||
    ((coffeeType2 == 'M' || coffeeType2 == 'm') && (coffeeStrength == 'M' || coffeeStrength == 'm'))||
    ((coffeeType2 == 'R' || coffeeType2 == 'r') && (coffeeStrength == 'R' || coffeeStrength == 'r')),
    ((servings >=1 && servings <=4) && (weight2 == 250)) ||
    ((servings >4 && servings <= 9) && (weight2 == 500)) ||
    ((servings >9) && (weight2 == 1000)),
    ((cream == 'Y' || cream == 'y') && (bestServed2 == 'Y' || bestServed2 == 'y')) ||
    ((cream == 'N' || cream == 'n') && (bestServed2 == 'N' || bestServed2 == 'n')));

    printf(" 3|       %d         |      %d      |   %d   |\n\n",
    ((coffeeType3 == 'L' || coffeeType3 == 'l') && (coffeeStrength == 'L' || coffeeStrength == 'l'))||
    ((coffeeType3 == 'M' || coffeeType3 == 'm') && (coffeeStrength == 'M' || coffeeStrength == 'm'))||
    ((coffeeType3 == 'R' || coffeeType3 == 'r') && (coffeeStrength == 'R' || coffeeStrength == 'r')),
    ((servings >=1 && servings <=4) && (weight3 == 250)) ||
    ((servings >4 && servings <= 9) && (weight3 == 500)) ||
    ((servings >9) && (weight3 == 1000)),
    ((cream == 'Y' || cream == 'y') && (bestServed3 == 'Y' || bestServed3 == 'y')) ||
    ((cream == 'N' || cream == 'n') && (bestServed3 == 'N' || bestServed3 == 'n')));
    //how u like
    printf("Enter how you like your coffee...\n\n");
    
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream);
    printf("Typical number of daily servings: ");
    scanf(" %d",&servings);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    //chart
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", 
    ((coffeeType1 == 'L' || coffeeType1 == 'l') && (coffeeStrength == 'L' || coffeeStrength == 'l'))||
    ((coffeeType1 == 'M' || coffeeType1 == 'm') && (coffeeStrength == 'M' || coffeeStrength == 'm'))||
    ((coffeeType1 == 'R' || coffeeType1 == 'r') && (coffeeStrength == 'R' || coffeeStrength == 'r')),
    ((servings >=1 && servings <=4) && (weight1 == 250)) ||
    ((servings >4 && servings <= 9) && (weight1 == 500)) ||
    ((servings >9) && (weight1 == 1000)),
    ((cream == 'Y' || cream == 'y') && (bestServed1 == 'Y' || bestServed1 == 'y')) ||
    ((cream == 'N' || cream == 'n') && (bestServed1 == 'N' || bestServed1 == 'n')));
    
    printf(" 2|       %d         |      %d      |   %d   |\n",
    ((coffeeType2 == 'L' || coffeeType2 == 'l') && (coffeeStrength == 'L' || coffeeStrength == 'l'))||
    ((coffeeType2 == 'M' || coffeeType2 == 'm') && (coffeeStrength == 'M' || coffeeStrength == 'm'))||
    ((coffeeType2 == 'R' || coffeeType2 == 'r') && (coffeeStrength == 'R' || coffeeStrength == 'r')),
    ((servings >=1 && servings <=4) && (weight2 == 250)) ||
    ((servings >4 && servings <= 9) && (weight2 == 500)) ||
    ((servings >9) && (weight2 == 1000)),
    ((cream == 'Y' || cream == 'y') && (bestServed2 == 'Y' || bestServed2 == 'y')) ||
    ((cream == 'N' || cream == 'n') && (bestServed2 == 'N' || bestServed2 == 'n')));

    printf(" 3|       %d         |      %d      |   %d   |\n\n",
    ((coffeeType3 == 'L' || coffeeType3 == 'l') && (coffeeStrength == 'L' || coffeeStrength == 'l'))||
    ((coffeeType3 == 'M' || coffeeType3 == 'm') && (coffeeStrength == 'M' || coffeeStrength == 'm'))||
    ((coffeeType3 == 'R' || coffeeType3 == 'r') && (coffeeStrength == 'R' || coffeeStrength == 'r')),
    ((servings >=1 && servings <=4) && (weight3 == 250)) ||
    ((servings >4 && servings <= 9) && (weight3 == 500)) ||
    ((servings >9) && (weight3 == 1000)),
    ((cream == 'Y' || cream == 'y') && (bestServed3 == 'Y' || bestServed3 == 'y')) ||
    ((cream == 'N' || cream == 'n') && (bestServed3 == 'N' || bestServed3 == 'n')));

    printf("Hope you found a product that suits your likes!\n\n");
    return 0;
}