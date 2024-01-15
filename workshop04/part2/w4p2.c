/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Andy Chong
Student ID#: 150558229
Email      : achong11@myseneca.ca
Section    : NAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apples, oranges, pears, tomatoes, cabbages;
    int applesCart, orangesCart, pearsCart, tomatoesCart, cabbagesCart;
    int repeatAgain;

    do{
        printf("Grocery Shopping\n");
        printf("================\n");
//Picking items

        printf("How many APPLES do you need? : ");
        scanf("%d", &apples);
        if (apples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
        }
        putchar('\n');

        printf("How many ORANGES do you need? : ");
        scanf("%d", &oranges);
        if (oranges < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
        }
        putchar('\n');

        printf("How many PEARS do you need? : ");
        scanf("%d", &pears);
        if (pears < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
        }
        putchar('\n');

        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomatoes);
        if (tomatoes < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
        }
        putchar('\n');

        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbages);
        if (cabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
        }
        putchar('\n');

//PICK PRODUCTS
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");
//apples and errors
    while (apples > 0)
    {
        printf("Pick some APPLES... how many did you pick? : ");
        scanf("%d", &applesCart);
        if (applesCart > apples)
        {
            printf("You picked too many... only %d more APPLE(S) are needed.\n",apples);
            applesCart = 0;
        }
        else if (applesCart <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
            applesCart = 0;
        }
        else if (applesCart < apples)
        {
            printf("Looks like we still need some APPLES...\n");
        }
        else 
        {
            if (apples == applesCart)
            {
                printf("Great, that's the apples done!\n\n");
            }
        }
       apples = apples - applesCart;
    }
    
//oranges and errors
    while (oranges > 0)
    {
        printf("Pick some ORANGES... how many did you pick? : ");
        scanf("%d", &orangesCart);
        if (orangesCart > oranges)
        {
            printf("You picked too many... only %d more ORANGE(S) are needed.\n",oranges);
            orangesCart = 0;
        }
        else if (orangesCart <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
            orangesCart = 0;
        }
        else if (orangesCart < oranges)
        {
            printf("Looks like we still need some ORANGES...\n");
        }
        else 
        {
            if (oranges == orangesCart)
            {
                printf("Great, that's the oranges done!\n\n");
            }
        }
       oranges = oranges - orangesCart;
    }
    
//pears and errors
    while (pears > 0)
    {
        printf("Pick some PEARS... how many did you pick? : ");
        scanf("%d", &pearsCart);
        if (pearsCart > pears)
        {
            printf("You picked too many... only %d more PEAR(S) are needed.\n",pears);
            pearsCart = 0;
        }
        else if (pearsCart <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
            pearsCart = 0;
        }
        else if (pearsCart < pears)
        {
            printf("Looks like we still need some PEARS...\n");
        }
        else 
        {
            if (pears == pearsCart)
            {
                printf("Great, that's the pears done!\n\n");
            }
        }
       pears = pears - pearsCart;
    }
    
//tomatoes and errors    
    while (tomatoes > 0)
    {
        printf("Pick some TOMATOES... how many did you pick? : ");
        scanf("%d", &tomatoesCart);
        if (tomatoesCart > tomatoes)
        {
            printf("You picked too many... only %d more TOMATO(ES) are needed.\n",tomatoes);
            tomatoesCart = 0;
        }
        else if (tomatoesCart <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
            tomatoesCart = 0;
        }
        else if (tomatoesCart < tomatoes)
        {
            printf("Looks like we still need some TOMATOES...\n");
        }
        else 
        {
            if (tomatoes == tomatoesCart)
            {
                printf("Great, that's the tomatoes done!\n\n");
            }
        }
       tomatoes = tomatoes - tomatoesCart;
    }
   
//cabbages and errors    
    while (cabbages > 0)
    {
        printf("Pick some CABBAGES... how many did you pick? : ");
        scanf("%d", &cabbagesCart);
        if (cabbagesCart > cabbages)
        {
            printf("You picked too many... only %d more CABBAGE(S) are needed.\n",cabbages);
            cabbagesCart = 0;
        }
        else if (cabbagesCart <= 0)
        {
            printf("ERROR: You must pick at least 1!\n");
            cabbagesCart = 0;
        }
        else if (cabbagesCart < cabbages)
        {
            printf("Looks like we still need some CABBAGES...\n");
        }
        else 
        {
            if (cabbages == cabbagesCart)
            {
                printf("Great, that's the cabbages done!\n\n");
            }
        }
       cabbages = cabbages - cabbagesCart;
    }  

        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &repeatAgain);
        putchar('\n');
    } while (repeatAgain);

    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}