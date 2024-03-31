#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

struct game_state
{
    int P1_CUR_AMT;         //Shows current amount of each player
    int P2_CUR_AMT;

    int P1_CUR_POS;         //Shows current position of each player
    int P2_CUR_POS;

    int currentPlayer;      //Another data type to know who's player turn

    int THO;
    int ECO;
    int BHO;
    int CO;                 //Shows the owner of each property
    int RRO;                //1 for player 1 and 2 for player 2
    int IO;
    int FHO;

    int THORent;
    int BHORent;
    int CORent;
    int RRORent;
    int IORent;
    int FHORent;
    
};


//Displays the lines 
void Lines()
{
    printf("\n\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
}


//Displays introduction
void Introduction()
{
    printf("%40s", "WELCOME TO BIG BRAIN PROPERTY \n");  
    printf("\n\n%38s", "Press Any Key to Continue...");
}


void displayBoard()
{
    printf("\n\n\t\t\t\tPROPERTY PROPERTY\n\n");
    printf(" ___________________________________________________________________________________\n");
    printf("|                    |                    |                    |                    |\n");
    printf("|         GO         |     TREE HOUSE     |  ELECTRIC COMPANY  |     BEACH HOUSE    |\n");

    printf("|____________________|____________________|____________________|____________________|\n");
    printf("|                    |                                         |                    |\n");

    printf("|     FARM HOUSE     |                                         |      JAIL TIME     |\n");

    printf("|____________________|_________________________________________|____________________|\n");
    printf("|                    |                    |                    |                    |\n");

    printf("|       IGLOO        |      RAIL ROAD     |   FEELING LUCKY    |       CASTLE       |\n");

    printf("|____________________|____________________|____________________|____________________|\n\n");
    printf("\n\n");
    system("pause");
}


//Displays the rules
void cRules()
{
    Lines();
    system("cls");
    printf("\n\tOBJECTIVE OF THE GAME");
    printf("\n\tBecome the wealthiest player through buying, renting and selling of property and force other player into bankruptcy.");
    printf("\n\n\tGAMEPLAY");
    printf("\n\tAt the start of the game, players do not own any property.");
    printf("\n\tAll properties on the board are owned by the Bank. All properties owned by the Bank are up for sale and are not renovated.");
    printf("\n\tThe Bank has unlimited cash. The smallest denomination in this game is 1.");
    printf("\n\tEach player has an initial cash-on-hand of 200.");
    printf("\n\tThey can use this to buy properties or pay rent during the game. Initially, both players are at Go.");
    printf("\n\nPress any key to continue to next page...");
    getch();
    printf("\n\n\tSTART");
    printf("\n\tPlayers take turn in rolling the dice to move clockwise around the board.");
    printf("\n\tThe player may land on Go, on Jail Time, on Feelin Lucky, or on a property . Based on the space where the player lands on, different actions may take place.");
    printf("\n\n\tBUYING PROPERTY");
    printf("\n\tWhen a player lands on a property that is owned by the Bank, the player can choose to buy that property from the Bank by paying the property cost.");
    printf("\n\t The player must have enough cash-on-hand to pay for the cost, otherwise he cannot buy the property.");
    printf("\n\n\tPAYING RENT");
    printf("\n\tWhen a player lands on a property that is owned by another player, he has to pay the owner rent for this property.");
    printf("\n\n\tFEELIN LUCKY");
    printf("\n\tWhen a player lands on Feelin Lucky, the player rolls the dice to determin his luck. His luck is determined by the dice value.");
    printf("\n\n\tJAIL");
    printf("\n\tPlayer lands on Jail Time. The player loses his next turn.");
    printf("\n\n\tGO");
    printf("\n\tPlayer lands on or passes by Go. The player collects 200 from the Bank.");
    printf("\n\n\tHOUSES AND HOTELS");
    printf("\n\tWhen a player lands on a property that is owned by the Bank, the player can choose to buy that property from the Bank by paying the property cost.");
    printf("\n\t The player must have enough cash-on-hand to pay for the cost, otherwise he cannot buy the property.");
    printf("\n\tWhen a player lands on a property that is owned by another player, he has to pay the owner rent for this property.");
    printf("\n\n\tBANKRUPTCY");
    printf("\n\tWhen one player goes bankrupt, the game ends and the other player is declared the winner.");        
    printf("\n\tA player is considered bankrupt when he is unable to pay rent even after selling all his properties to the bank.");                                                                                                                                                 
    printf("\n\n\tNOT ENOUGH CASH!");
    printf("\n\tWhen a player does not have enough cash-on-hand to pay for rent, he can sell his properties back to the Bank until he collects enough cash to pay for rent.");
    printf("\n\tThe player selects a property to resell back to the Bank (one property at a time). The resell value of the property is half the cost of the property.");
    printf("\n\nPress any key to continue...");
    getch();
}


//Function for Dice
int RollDice()
{
   return (rand() % 6) + 1;
}


//Function to check where players land and computes for the money.
int checkLand( struct game_state *pgs, int Money )
{
    int choice = 0;
    char RoS;

    if(pgs->currentPlayer == 1)
    {
        pgs->P1_CUR_POS += RollDice();
        
        if(pgs->P1_CUR_POS == 10)
        {
            if(pgs->currentPlayer == 1)
            {
                pgs->P1_CUR_POS = 0;
                
            }
            pgs->P1_CUR_POS = 0;
        }
        else if(pgs->P1_CUR_POS > 10)
        {
            pgs->P1_CUR_POS = pgs->P1_CUR_POS - 10;
            Money += 200;
            printf("\nYou Passed Go and collect 200$ from the bank.");
            printf("\nYour New Balance is: $%d and landed ", Money);
        }

        choice = pgs->P1_CUR_POS;
    }
    
    if(pgs->currentPlayer == 2)
    {
        pgs->P2_CUR_POS += RollDice();
        if(pgs->P2_CUR_POS == 10)
        {
            pgs->P2_CUR_POS = 0;
            
        }
        else if(pgs->P2_CUR_POS > 10)
        {
            pgs->P2_CUR_POS = pgs->P2_CUR_POS - 10;
            Money += 200;
            printf("\nYou Passed Go and collect 200$ from the bank.");
            printf("\nYour New Balance is: $%d and landed ", Money);
        }
        choice = pgs->P2_CUR_POS;
    }

    char playerchoice;
    int dice = RollDice();

    if (choice == 0)
    {
        printf(" on Go.\n\n");
        Money += 200;
        printf("You collect $200 from the Bank.");
        printf("\nYour New Balance is $%d", Money);
    }

    else if (choice == 1)
    {
        printf(" on Tree House.\n\n");
        if (pgs->THO == 0)
        {
            printf("\nWould you like to buy Tree House?");
            printf("\n\t [ y or Y ]\t[n or N]\n");
            scanf(" %c", &playerchoice);

            if (playerchoice == 'y' || playerchoice == 'Y')
            {
                pgs->THO = pgs->currentPlayer;
                Money -= 20;
                if (Money >= 1)
                {   
                    printf("Now owns by player %d\n", pgs->THO);
                    printf("\nYou succesfully bought Tree House");
                    printf("\nYour New Balance is $%d.", Money);
                }
                else
                    printf("\nYou dont have enough money!");
            } 
            else if (playerchoice == 'n' || playerchoice == 'N')
                printf("Thank You for Staying.");
        }
        else if (pgs->currentPlayer != pgs->THO && pgs->THO !=0)
        {
            printf("\n You need to pay rent to player %d!", pgs->THO);
            Money -= pgs->THORent;
            printf("\nYour New Balance is $%d.", Money);
        }
        else if (pgs->currentPlayer == pgs->THO)
        {
            printf("Would you like to renovate or sell your property?\n");
            printf("\t[r]\t\t[s]\n");
            scanf(" %c", &RoS);
            switch (RoS)
            {
            case 'r':
            case 'R':
                printf("You've succesfully renovated this property!!!\n");
                Money -= 50;
                printf("Your New Balance is $%d", Money);
                pgs->THORent = pgs->THORent*2+1;
                break;
            
            case 's':
            case 'S':
                printf("You succesfully sold this property back to the bank!!!\n");
                pgs->THO = 0;
                Money += 20;
                printf("Your New Balance is $%d", Money);
                break;
            }
        }
    }

    else if (choice == 2)
    {
        printf(" on Electric Company.\n\n");
        if (pgs->ECO == 0)
        {
            printf("\nWould you like to buy Electric Company?");
            printf("\n\t [ y or Y ]\t[n or N]\n");
            scanf(" %c", &playerchoice);

            if (playerchoice == 'y' || playerchoice == 'Y')
            {
                pgs->ECO = pgs->currentPlayer;
                Money -= 150;
                if (Money >= 1)
                {   
                    printf("Now owns by player %d\n", pgs->ECO);
                    printf("\nYou succesfully bought Electric Company\n");
                    printf("\nYour New Balance is $%d.", Money);
                }
                else
                    printf("\nYou dont have enough money!");
            } 
            else if (playerchoice == 'n' || playerchoice == 'N')
                printf("Thank You for Staying.");
        }
        else if (pgs->currentPlayer != pgs->ECO && pgs->ECO !=0)
        {
            printf("\n You need to pay rent to player %d!", pgs->ECO);
            Money -= (dice*8);
            printf("\nYour New Balance is $%d.", Money);
        }
        else if (pgs->currentPlayer == pgs->ECO)
        {
            printf("Would you like to sell your property?\n");
            printf("\t[y]\t\t[n]\n");
            scanf(" %c", &RoS);
            switch(RoS)
            {
            case 'y':
            case 'Y':
                printf("You succesfully sold this property back to the bank!!!\n");
                pgs->ECO = 0;
                Money += 150;
                printf("Your New Balance is $%d", Money);
                break;
            case 'n':
            case 'N':
            break;
            }
        }
    }

    else if (choice == 3)
    {
        printf(" on Beach House.\n\n");
        if (pgs->BHO == 0)
        {
            printf("\nWould you like to buy Beach House?");
            printf("\n\t [ y or Y ]\t[n or N]\n");
            scanf(" %c", &playerchoice);

        if (playerchoice == 'y' || playerchoice == 'Y')
        {
            pgs->BHO = pgs->currentPlayer;
            Money -= 60;
            if (Money >= 1)
                {   
                    printf("Now owns by player %d\n", pgs->BHO);
                    printf("\nYou succesfully bought Beach House");
                    printf("\nYour New Balance is $%d.", Money);
                }
            else
                printf("\nYou dont have enough money!");
        } 

        else if (playerchoice == 'n' || playerchoice == 'N')
            printf("Thank You for Staying.");
        }

        else if (pgs->currentPlayer != pgs->BHO && pgs->BHO !=0)
        {
            printf("%d", pgs->currentPlayer);
            printf("\n You need to pay rent to player %d!", pgs->BHO);
            Money -= pgs->BHORent;
            printf("\nYour New Balance is $%d.", Money);
        }
        else if (pgs->currentPlayer == pgs->BHO)
        {
            printf("Would you like to renovate or sell your property?\n");
            printf("\t[r]\t\t[s]\n");
            scanf(" %c", &RoS);
            switch (RoS)
            {
            case 'r':
            case 'R':
                printf("You've succesfully renovated this property!!!\n");
                Money -= 50;
                printf("Your New Balance is $%d", Money);
                pgs->BHORent = pgs->BHORent*2+1;
                break;
            
            case 's':
            case 'S':
                printf("You succesfully sold this property back to the bank!!!\n");
                pgs->BHO = 0;
                printf("Your New Balance is $%d", Money);
                break;
            }
        }
    }

    else if (choice == 4) 
    {
        printf(" on Jail Time.\n\n");
        printf("You lose a turn.");
    }
    
    else if (choice == 5) 
    {
        printf(" on Castle.\n\n");
        if (pgs->CO == 0)
        {
            printf("\nWould you like to buy Castle? ");
            printf("\n\t [ y or Y ]\t[n or N]\n");
            scanf(" %c", &playerchoice);

            if (playerchoice == 'y' || playerchoice == 'Y')
            {
                pgs->CO = pgs->currentPlayer;
                Money -= 100;
                if (Money >= 1)
                {   
                    printf("Now owns by player %d\n", pgs->CO);
                    printf("\nYou succesfully bought Castle");
                    printf("\nYour New Balance is $%d.", Money);
                }
                else
                    printf("\nYou dont have enough money!");
            } 

            else if (playerchoice == 'n' || playerchoice == 'N') 
                printf("Thank You for Staying.");
        }
        else if (pgs->currentPlayer != pgs->CO && pgs->CO !=0)
        {
            printf("\n You need to pay rent to player %d!", pgs->CO);
            Money -= pgs->CORent;
            printf("\nYour New Balance is $%d.", Money);
        }
        else if (pgs->currentPlayer == pgs->CO)
        {
            printf("Would you like to renovate or sell your property?\n");
            printf("\t[r]\t\t[s]\n");
            scanf(" %c", &RoS);
            switch (RoS)
            {
            case 'r':
            case 'R':
                printf("You've succesfully renovated this property!!!\n");
                Money -= 50;
                printf("Your New Balance is $%d", Money);
                pgs->CORent = pgs->CORent*2+1;
                break;
            
            case 's':
            case 'S':
                printf("You succesfully sold this property back to the bank!!!\n");
                pgs->CO = 0;
                Money += 100;
                printf("Your New Balance is $%d", Money);;
                break;
            }
        }
    }

    else if (choice == 6)
    {
        printf(" on Feeling Lucky.\n\n");
        printf("Congratulations! You will roll the dice to determine your luck.\n");
        printf("You rolled %d", dice);

        int PlusDollar = rand() % (200 - 100 + 1) + 100;
        int MinusDollar = rand() % (150 - 50 + 1) + 50;
        switch(dice)
        {
        case 1:
        if(pgs->currentPlayer == 1)
            {
                pgs->P1_CUR_POS = 4;
            }
        else if(pgs->currentPlayer == 2)
            {
                pgs->P2_CUR_POS = 4;
            }
        printf("\nYou are now in Jail.");
        break;

        case 2:
        case 3:
        case 5:
        Money += PlusDollar;
        printf("\nYou gain $%d.", PlusDollar);
        if (Money >= 1)
            printf("\nYour New Balance is $%d.", Money);
        else
            printf("\nYou dont have enough money!");
        break;

        case 4:
        case 6:
        Money -= MinusDollar;
        printf("\nYou Loss $%d.", MinusDollar);

        if (Money >= 1)
            printf("\nYour New Balance is $%d.", Money);
        else
            printf("\nYou dont have enough money!");
        break;
        }
    }
        

    else if (choice == 7)
    {
    printf(" on Rail Road.\n\n");
    if (pgs->RRO == 0)
        {
            printf("Would you like to buy Rail Road?");
            printf("\n\t [ y or Y ]\t[n or N]\n");
            scanf(" %c", &playerchoice);

            if (playerchoice == 'y' || playerchoice == 'Y')
            {
                pgs->RRO = pgs->currentPlayer;
                Money -= 100;
                if (Money >= 1)
                    {          
                        printf("Now owns by player %d\n", pgs->RRO);
                        printf("\nYou succesfully bought Rail Road");
                        printf("\nYour New Balance is $%d.", Money);
                    }
                else
                    printf("\nYou dont have enough money!");
            } 

            else if (playerchoice == 'n' || playerchoice == 'N') 
                printf("Thank You for Staying.");
        }
        else if (pgs->currentPlayer != pgs->RRO && pgs->RRO !=0)
        {
            printf("\n You need to pay rent to player %d!", pgs->RRO);
            Money -= pgs->RRORent;
            printf("\nYour New Balance is $%d.", Money);
        }
        else if (pgs->currentPlayer == pgs->RRO)
        {
            printf("Would you like to sell your property?\n");
            printf("\t[y]\t\t[n]\n");
            scanf(" %c", &RoS);
            switch(RoS)
            {
            case 'y':
            case 'Y':
                printf("You succesfully sold this property back to the bank!!!\n");
                pgs->RRO = 0;
                Money += 100;
                printf("Your New Balance is $%d", Money);
                break;
            case 'n':
            case 'N':
            break;
            }
        }
        
    }

    else if (choice == 8)
    {
    printf(" on Igloo.\n\n");
    if (pgs->IO == 0)
        {
            printf("Would you like to buy Igloo?");
            printf("\n\t [ y or Y ]\t[n or N]\n");
            scanf(" %c", &playerchoice);

            if (playerchoice == 'y' || playerchoice == 'Y')
            {
                pgs->IO = pgs->currentPlayer;
                Money -= 160;
                if (Money >= 1)
                    {   
                        printf("Now owns by player %d\n", pgs->IO);
                        printf("\nYou succesfully bought Igloo");
                        printf("\nYour New Balance is $%d.", Money);
                    }
                else
                    printf("\nYou dont have enough money!");
            } 

            else if (playerchoice == 'n' || playerchoice == 'N') 
                printf("Thank You for Staying.");
        }
    else if (pgs->currentPlayer != pgs->IO && pgs->IO !=0)
        {
            printf("\n You need to pay rent to player %d!", pgs->IO);
            Money -= pgs->IORent;
            printf("\nYour New Balance is $%d.", Money);
        }
        else if (pgs->currentPlayer == pgs->IO)
        {
            printf("Would you like to renovate or sell your property?\n");
            printf("\t[r]\t\t[s]\n");
            scanf(" %c", &RoS);
            switch (RoS)
            {
            case 'r':
            case 'R':
                printf("You've succesfully renovated this property!!!\n");
                Money -= 50;
                printf("Your New Balance is $%d", Money);
                pgs->IORent = pgs->IORent*2+1;
                break;
            
            case 's':
            case 'S':
                printf("You succesfully sold this property back to the bank!!!\n");
                pgs->IO = 0;
                Money += 160;
                printf("Your New Balance is $%d", Money);
                break;
            }
        }
    }

    else if (choice == 9)
    {
    printf(" on Farm House.\n\n");
    if (pgs->FHO == 0)
        {
            printf("Would you like to buy Farm House?");
            printf("\n\t [ y or Y ]\t[n or N]\n");
            scanf(" %c", &playerchoice);

            if (playerchoice == 'y' || playerchoice == 'Y')
            {
                pgs->FHO = pgs->currentPlayer;
                Money -= 180;
                if (Money >= 1)
                    {        
                        printf("Now owns by player %d\n", pgs->FHO);  
                        printf("\nYou succesfully bought Farm House");
                        printf("\nYour New Balance is $%d.", Money);
                    }
                else
                    printf("\nYou dont have enough money!");
            } 

        else if (playerchoice == 'n' || playerchoice == 'N')
            printf("Thank You for Staying.");
        }

    else if (pgs->currentPlayer != pgs->FHO && pgs->FHO !=0)
        {
            printf("\n You need to pay rent to player %d!", pgs->FHO);
            Money -= pgs->FHORent;
            printf("\nYour New Balance is $%d.", Money);
        }
        else if (pgs->currentPlayer == pgs->FHO)
        {
            printf("Would you like to renovate or sell your property?\n");
            printf("\t[r]\t\t[s]\n");
            scanf(" %c", &RoS);
            switch (RoS)
            {
            case 'r':
            case 'R':
                printf("You've succesfully renovated this property!!!\n");
                Money -= 50;
                printf("Your New Balance is $%d", Money);
                pgs->FHORent = pgs->FHORent*2+1;
                break;
            
            case 's':
            case 'S':
                printf("You succesfully sold this property back to the bank!!!\n");
                pgs->FHO = 0;
                Money += 180;
                printf("Your New Balance is $%d", Money);
                break;
            }
        }


    }
        
    return Money;
    
}


//Display if the user wants to play or not
int checkWin(struct game_state *pgs);
char PlayGame(char YesOrNo)
{
    struct game_state gs =
    {
        .P1_CUR_AMT = 200,
        .P2_CUR_AMT = 200,
        .P2_CUR_POS = 0,
        .P2_CUR_POS = 0,
        .currentPlayer = 1,
        .THO = 0,
        .ECO = 0,
        .BHO = 0,
        .CO = 0,
        .RRO = 0,
        .IO = 0,
        .FHO = 0,
        .THORent = 4,
        .BHORent = 12,
        .CORent = 20,
        .RRORent = 35,
        .IORent = 32,
        .FHORent = 36,
    };
    printf("\nWould you like to play? Enter Y or N: ", YesOrNo);                                          
    scanf(" %c", &YesOrNo);
    if (YesOrNo == 'Y' || YesOrNo == 'y')
    {
        Lines();
        printf("\n%40s", "Welcome To A Monopoly Game Called\n");
        printf("%30s", "Property Property\n\n");
        Lines();
        cRules();
        system ("cls");
        displayBoard();
    
    int player = 1, i;

        do
        {
            Lines();

            if(gs.currentPlayer > 2) gs.currentPlayer = 1;
            printf("It is Player %d turn.\n", gs.currentPlayer);
            printf("Press any key to roll a dice.");
            getch();
            printf("\nPlayer %d landed", gs.currentPlayer);

            if(gs.currentPlayer == 1)
            {
             gs.P1_CUR_AMT = gs.P1_CUR_AMT = checkLand( &gs, gs.P1_CUR_AMT );
            }
            else if(gs.currentPlayer == 2)
            {
              gs.P2_CUR_AMT = gs.P2_CUR_AMT = checkLand( &gs, gs.P2_CUR_AMT );
            }
            
            
            i = checkWin(&gs);
            gs.currentPlayer++;
        }
        while (i != 1 || i != 2);
    }
    else
    {
        printf("\nSee you Again!!!");
        _Exit(0);
    }
}


int checkWin(struct game_state *pgs)
{
    char RestartOrGoodbye;
    if(pgs->P1_CUR_AMT <= 0)
  {
        printf("\n\nPlayer 2 Wins!");
        printf("\n\nWould You like to restart the game? ");
        scanf(" %c", &RestartOrGoodbye);
        switch(RestartOrGoodbye)
        {
            case 'y':
            case 'Y':
            system("pause");
            return PlayGame(RestartOrGoodbye);
            break;

            case 'n':
            case 'N':
            printf("\n\nThank You For Playing!!!!");
            _Exit(0);
            return 0;
            break; 
        }

    }
    else if(pgs->P2_CUR_AMT <= 0)
    {
        printf("\n\nPlayer 1 Wins!");
        printf("\n\nWould You like to restart the game? ");
        scanf(" %c", &RestartOrGoodbye);
        switch(RestartOrGoodbye)
        {
            case 'y':
            case 'Y':
            system("pause");
            return PlayGame(RestartOrGoodbye);
            break;

            case 'n':
            case 'N':
            _Exit(0);
            return 0;
            break;
        }
    }
    
    else
    {
        return 1;
    }
}


int main()
{

    srand (time(0)); // Initialize random seed
    char choice;
    Introduction();
    getch();

    system ("cls");

    PlayGame(choice);
    getch();
    system ("cls");

    return 0;
}