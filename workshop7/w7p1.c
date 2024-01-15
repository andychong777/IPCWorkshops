/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Andy Chong
Student ID#: 150558229
Email      : achong11@myseneca.ca
Section    : NAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

//MACRO
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_PATH 70
#define MIN_PATH 10
#define MULTIPLE 5

struct PlayerInfo
{
    int numberLives;
    char playerSymbol;
    int numberTreasure;
    int history[MAX_PATH];
};

struct GameInfo
{
    int maxMoves;
    int pathLength;
    int bombs[MAX_PATH];
    int treasure[MAX_PATH];
};

int main(void)
{
    struct PlayerInfo PlayerInfo = { 0 };
    struct GameInfo GameInfo = { 0 };

    int i, validValue;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

//player config
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &PlayerInfo.playerSymbol);

    do {
        validValue = 1;

        printf("Set the number of lives: ");
        scanf("%d",&PlayerInfo.numberLives);
        //lives must be between 1-10
        if ((PlayerInfo.numberLives < MIN_LIVES || PlayerInfo.numberLives > MAX_LIVES))
        {
            validValue = 0;
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);//dont hard code
        }
    } while (!validValue);
    
    printf("Player configuration set-up is complete\n\n");

    //game config
    printf("GAME Configuration\n");
    printf("------------------\n");

    //path length
    do {
        validValue = 1;
        printf("Set the path length (a multiple of %d between %d-%d): ",
        MULTIPLE, MIN_PATH, MAX_PATH);
        scanf("%d", &GameInfo.pathLength);

        //must be a multiple of 5
        if ((GameInfo.pathLength % MULTIPLE !=0) || GameInfo.pathLength < MIN_PATH 
        || GameInfo.pathLength > MAX_PATH)
        {
            validValue = 0;
            printf("     Must be a multiple of %d and between %d-%d!!!\n",MULTIPLE, MIN_PATH, MAX_PATH);
        }
    } while (!validValue);

    //limit for number of moves
    do {
        validValue = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &GameInfo.maxMoves);

        if (GameInfo.maxMoves < PlayerInfo.numberLives || GameInfo.maxMoves > 
        (int)(GameInfo.pathLength * 0.75))
        {
            validValue = 0;
            printf("    Value must be between %d and %d\n", PlayerInfo.numberLives, 
            (int)(GameInfo.pathLength * 0.75));
        }
    } while (!validValue);
    putchar('\n');

    //Bomb Placement
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", GameInfo.pathLength);

    for (i = 0; i < GameInfo.pathLength; i+=5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &GameInfo.bombs[i], &GameInfo.bombs[i + 1],
        &GameInfo.bombs[i + 2], &GameInfo.bombs[i + 3], &GameInfo.bombs[i + 4]);
    }
    
    printf("BOMB placement set\n");
    printf("\n");

    //treasure same as bomb
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", GameInfo.pathLength);

    for (i = 0; i < GameInfo.pathLength; i+=5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &GameInfo.treasure[i], &GameInfo.treasure[i + 1],
        &GameInfo.treasure[i + 2], &GameInfo.treasure[i + 3], &GameInfo.treasure[i + 4]);
    }
    
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    
    //summary
    printf("Player:\n");
    printf("   Symbol     : %c\n", PlayerInfo.playerSymbol);
    printf("   Lives      : %d\n", PlayerInfo.numberLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", GameInfo.pathLength);
    printf("   Bombs      : "); //printout input in 1 line.
    for (i = 0; i < GameInfo.pathLength; i++)
    {
        printf("%d", GameInfo.bombs[i]);
    }
    putchar('\n');

    printf("   Treasure   : ");
    for (i = 0; i < GameInfo.pathLength; i++)
    {
        printf("%d", GameInfo.treasure[i]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    return 0;
}