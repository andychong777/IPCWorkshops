/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Andy Chong
Student ID#: 150229558
Email      : achong11@myseneca.ca
Section    : NAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define WISHLIST 10
#define MIN_PRIO_NUMBER 1
#define MAN_PRIO_NUMBER 3

int main(void)
{
    //min and max stored in unmodifiable variables
    const double min = 500, max = 400000, minCost = 100;
    double netIncome;
    double totalPrice;
    int wishItems;
    int i, validValue, note; //flags
    int selection, prioNumber;
    double months, years, monthsLeft, prioCost;

    double price[WISHLIST] = { 0 };
    int prio[WISHLIST] = { 0 };
    char finance[WISHLIST] = { 0 };
 
    
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");
    //ask monthly net income and errors
    do{
        validValue = 1;

        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);

        if (netIncome < min)
        {
            validValue = 0;
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        if (netIncome > max)
        {
            validValue = 0;
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
    }while (!validValue);//do while inbetween min/max

    putchar('\n');
//add flag (!validvalue)
    do{
        validValue = 1;

        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &wishItems);

        if (!(wishItems > 0 && wishItems < WISHLIST))
        {
            validValue = 0;
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
    } while (!validValue);
    putchar('\n');
//GOOD UP TO HERE^^^^
//how much, prio, financing y/n
//EACH ATTRIBUTE NEEDDS ARRAY
//array for cost, prioity (1,2,3), financial options (yes or no)
    
    for (i = 0; i <= (wishItems - 1); i++)
    {
        printf("Item-%d Details:\n", i + 1);

        do{
            validValue = 1;
            printf("   Item cost: $");
            scanf("%lf", &price[i]);

            if ((price[i] < minCost))
            {
                validValue = 0;
                printf("      ERROR: Cost must be at least $%.2lf\n", minCost);
            }
        } while (!validValue);
//GOOD UP TO HERE^^^^        
        do{
            validValue = 1;

            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &prio[i]);

            if ((prio[i] < 1 || prio[i] > 3))
            {
                validValue = 0;
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (!validValue);
//GOOD UP TO HERE^^^^        
        do{
            validValue = 1;

            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);

            if (!(finance[i] == 'y' || finance[i] == 'n'))
            {
                validValue = 0;
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (!validValue);

        putchar('\n');
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    totalPrice = 0;
    for (i = 0; i < wishItems; i++)
    {
        if (prio[i] > 0)
        {
            printf("%3d  %5d    %5c    %11.2lf\n",i + 1,prio[i],finance[i],price[i]);
            totalPrice += price[i];
        }
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n",totalPrice); 
//GOOD UP TO HERE^^^^ 
//menu 3 options
    do
    {
        validValue = 1; //set flag
        
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);
        putchar('\n');
        
        if ((selection < 0 || selection > 2))
        {
            validValue = 0;
            printf("ERROR: Invalid menu selection.\n\n");
        }
        else if ((selection == 1)) //option 1
        {
            
            printf("====================================================\n");
            printf("Filter:   All items\n"); 
            printf("Amount:   $%.2lf\n", totalPrice); 
            //calcuate months and years
            months = (totalPrice / netIncome) + 0.5;//rounding
            years = ((int)months) / 12; 
            monthsLeft = (months - (years * 12)) + 0.5; //rounding
            
            printf("Forecast: %d years, %d months\n",(int)years, (int)monthsLeft);
            note = 0;
            for (i= 0; i < wishItems; i++)
            {
                if (finance[i] == 'y')
                {
                    note += 1;
                }
            }
            if (note != 0)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
                validValue = 0;
            }
            printf("====================================================\n\n");
        }
        else if ((selection == 2))
        {
            prioCost = 0;
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &prioNumber); //1-3
            putchar('\n');

            if (prioNumber < MIN_PRIO_NUMBER || prioNumber > MAN_PRIO_NUMBER)
            {
                printf("ERROR: Value must be between 1 and 3\n");
            }
            
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", prioNumber);

            for (i = 0; i < wishItems; i++)
            {
                if (prio[i] == prioNumber)
                {
                    prioCost += price[i];
                }
            }
            months = (prioCost / netIncome) + 0.5;//rounding
            years = ((int)months) / 12; 
            monthsLeft = (months - (years * 12)) + 0.5; //rounding
            
            printf("Amount:   $%.2lf\n", prioCost);
            printf("Forecast: %d years, %d months\n",(int)years, (int)monthsLeft);

            for (i= 0; i < wishItems; i++)
            {
                if (finance[i] == 'y' && prio[i] == prioNumber)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    i = wishItems;
                }
            }
            printf("====================================================\n\n");
            validValue = 0;
        }
        else 
        {
           validValue = 1; 
        }
    } while (!validValue);

    printf("Best of luck in all your future endeavours!\n\n");
    return 0;
}