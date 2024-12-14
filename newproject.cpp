#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void giveyourvote(int userIndex);
void votecount();
void leadingthewholeprocess();
void declarewinner();
void saveVoteCounts();
void loadVoteCounts();

#define PARTICIPANT1 "mahir"
#define PARTICIPANT2 "shafayet"
#define PARTICIPANT3 "rafi"
#define PARTICIPANT4 "abdullah"
#define DATA_FILE "voting_data.txt"

int votecount1 = 0, votecount2 = 0, votecount3 = 0, votecount4 = 0, unnecessaryvote = 0;
int hasVoted[30] = {0};


int main()
{
    loadVoteCounts();
    int choice;

    do
    {
        //system("cls");
        // system("COLOR 0");
    printf("======================================================\n");
    printf("=                                                    =\n");
    printf("=   WELCOME TO Class REPRESENTATIVE ELECTION SYSTEM  =\n");
    printf("=                                                    =\n");
    printf("=            Developed by Team:                      =\n");
    printf("=           Mahir, Shafayet, Abdullah, Rafi          =\n");
    printf("=                                                    =\n");
    printf("======================================================\n");
    printf("               C PROJECT IMPLEMENTATION              \n");
    printf("======================================================\n\n\n");
        printf("\n 1. Give your vote according to your preference.");
        printf("\n 2. Vote Count.");
        printf("\n 3. Show us who is the leading one.");
        printf("\n 4. Declare Winner.");
        printf("\n 0. Exit\n");
        printf("Choose an option to ensure your job: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            char d[20];
            printf("\nEnter username: ");
            scanf("%s", d);
            int password;
            printf("\nEnter your password: ");
            scanf("%d", &password);
            if ((strcmp(d, "mahir") == 0) && password == 323 && !hasVoted[0])
            {
                giveyourvote(0);
            }
            else if ((strcmp(d, "abdullah") == 0) && password == 324 && !hasVoted[1])
            {
                giveyourvote(1);
            }
            else if ((strcmp(d, "shafayet") == 0) && password == 349 && !hasVoted[2])
            {
                giveyourvote(2);
            }
            else if ((strcmp(d, "nishad") == 0) && password == 325 && !hasVoted[3])
            {
                giveyourvote(3);
            }
            else if ((strcmp(d, "minhaz") == 0) && password == 354 && !hasVoted[4])
            {
                giveyourvote(4);
            }
            else if ((strcmp(d, "arefin") == 0) && password == 347 && !hasVoted[5])
            {
                giveyourvote(5);
            }
            else if ((strcmp(d, "maliha") == 0) && password == 444 && !hasVoted[6])
            {
                giveyourvote(6);
            }
            else if ((strcmp(d, "shawon") == 0) && password == 357 && !hasVoted[7])
            {
                giveyourvote(7);
            }
            else if ((strcmp(d, "rafi") == 0) && password == 359 && !hasVoted[8])
            {
                giveyourvote(8);
            }
            else if ((strcmp(d, "theo") == 0) && password == 352 && !hasVoted[9])
            {
                giveyourvote(9);
            }
            else if ((strcmp(d, "touhid") == 0) && password == 345 && !hasVoted[10])
            {
                giveyourvote(10);
            }
            else if ((strcmp(d, "fikrat") == 0) && password == 328 && !hasVoted[11])
            {
                giveyourvote(11);
            }
            else if ((strcmp(d, "shahriar") == 0) && password == 408 && !hasVoted[12])
            {
                giveyourvote(12);
            }
            else if ((strcmp(d, "mahzilur") == 0) && password == 358 && !hasVoted[13])
            {
                giveyourvote(13);
            }
            else if ((strcmp(d, "john") == 0) && password == 331 && !hasVoted[14])
            {
                giveyourvote(14);
            }
            else if ((strcmp(d, "shaon") == 0) && password == 333 && !hasVoted[15])
            {
                giveyourvote(15);
            }
            else if ((strcmp(d, "redowan") == 0) && password == 335 && !hasVoted[16])
            {
                giveyourvote(16);
            }
            else if ((strcmp(d, "hakim") == 0) && password == 360 && !hasVoted[17])
            {
                giveyourvote(17);
            }
            else if ((strcmp(d, "rahul") == 0) && password == 340 && !hasVoted[18])
            {
                giveyourvote(18);
            }
            else if ((strcmp(d, "nur") == 0) && password == 353 && !hasVoted[19])
            {
                giveyourvote(19);
            }
            else if ((strcmp(d, "mimiya") == 0) && password == 339 && !hasVoted[20])
            {
                giveyourvote(20);
            }
            else if ((strcmp(d, "saif") == 0) && password == 361 && !hasVoted[21])
            {
                giveyourvote(21);
            }
            else if ((strcmp(d, "dristy") == 0) && password == 343 && !hasVoted[22])
            {
                giveyourvote(22);
            }
            else if ((strcmp(d, "ayesha") == 0) && password == 351 && !hasVoted[23])
            {
                giveyourvote(23);
            }
            else if ((strcmp(d, "jannatul") == 0) && password == 108 && !hasVoted[24])
            {
                giveyourvote(24);
            }
            else if ((strcmp(d, "niju") == 0) && password == 97 && !hasVoted[25])
            {
                giveyourvote(25);
            }
            else if ((strcmp(d, "Eva") == 0) && password == 330 && !hasVoted[26])
            {
                giveyourvote(26);
            }
            else if ((strcmp(d, "mariya") == 0) && password == 110 && !hasVoted[27])
            {
                giveyourvote(27);
            }
            else if ((strcmp(d, "khairul") == 0) && password == 344 && !hasVoted[28])
            {
                giveyourvote(28);
            }
            else if ((strcmp(d, "shawly") == 0) && password == 336 && !hasVoted[29])
            {
                giveyourvote(29);
            }
            else if ((strcmp(d, "nabila") == 0) && password == 334 && !hasVoted[26])
            {
                giveyourvote(30);
            }
            else if ((strcmp(d, "rizia muna") == 0) && password == 337 && !hasVoted[27])
            {
                giveyourvote(31);
            }
            else if ((strcmp(d, "sara") == 0) && password == 338 && !hasVoted[28])
            {
                giveyourvote(32);
            }
            else if ((strcmp(d, "protiva") == 0) && password == 348 && !hasVoted[29])
            {
                giveyourvote(33);
            }
            else if ((strcmp(d, "abir") == 0) && password == 360 && !hasVoted[29])
            {
                giveyourvote(34);
            }
            else
            {
              system("cls");
               printf("\033[1;31m\n \n  Sorry !!! You have pressed Wrong username or password, or you have already voted.\n \n\033[0m");



            }
            break;
        }

        case 2:
        {
            char d[20];
            printf("\nEnter ADMIN username: ");
            scanf("%s",&d);
            int password;
            printf("\nEnter ADMIN password: ");
            scanf("%d",&password);
            if((strcmp(d,"admin")==0)&&(password==123))
            {
                votecount();
            }

            else
            {
                printf("wrong username or password");
            }
        }
        break;
        case 3:
        {
            char d[20];
            printf("\nEnter ADMIN username: ");
            scanf("%s",&d);
            int password;
            printf("\nEnter ADMIN password: ");
            scanf("%d",&password);
            if((strcmp(d,"admin")==0)&&(password==123))
            {
                leadingthewholeprocess();
            }

            else
            {
                printf("wrong username or password");
            }
        }



        break;
        case 4:
            declarewinner();
            break;
        default:
            printf("Invalid choice. Please choose a valid option.\n");
        }
    }
    while (choice != 0);

    return 0;
}

void giveyourvote(int userIndex)
{
    system("cls");
    if (userIndex == -1)
    {
        char d[20];
        int password;
        printf("\nEnter username: ");
        scanf("%s", d);
        printf("\nEnter your password: ");
        scanf("%d", &password);

    }

    if (userIndex >= 0 && !hasVoted[userIndex])
    {
        hasVoted[userIndex] = 1;
        printf("\n\n *Choose your preferred participant.* \n\n");
        printf("\n 1.%s\n 2.%s\n 3.%s\n 4.%s\n", PARTICIPANT1, PARTICIPANT2, PARTICIPANT3, PARTICIPANT4);
        printf("\n Input your choice (1-4): ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            votecount1++;
            break;
        case 2:
            votecount2++;
            break;
        case 3:
            votecount3++;
            break;
        case 4:
            votecount4++;
            break;
        default:
            unnecessaryvote++;
        }
        printf("\033[1;32m\n \n Your vote is successfully submitted \n \n\033[0m");

        printf("\n\n ****We do appreciate your vote.****\n\n");
        saveVoteCounts();
    }
    else
    {
        printf("Either invalid user or already voted.\n");
    }

}

void saveVoteCounts()
{
    system("cls");
    FILE *file = fopen(DATA_FILE, "w");
    if (file != NULL)
    {
        fprintf(file, "%d %d %d %d %d ", votecount1, votecount2, votecount3, votecount4, unnecessaryvote);
        for (int i = 0; i < 30; i++)
        {
            fprintf(file, "%d ", hasVoted[i]);
        }
        fclose(file);
    }
    else
    {
        printf("Unable to save data.\n");
    }

}
void votecount()
{
    system("cls");


    printf("\n\n **Voting Statistics**");
    printf("\n %s=%d",PARTICIPANT1,votecount1);
    printf("\n %s=%d",PARTICIPANT2,votecount2);
    printf("\n %s=%d",PARTICIPANT3,votecount3);
    printf("\n %s=%d",PARTICIPANT4,votecount4);
    printf("\n %s=%d","spoiled one",unnecessaryvote);
    printf("\nPress any key to continue...");
    getch();
}
void leadingthewholeprocess()
{
    system("cls");
    printf("\n\n ####PARTICIPANTS LEADING THE JOURNEY####\n\n");

    if(votecount1>votecount2 && votecount1>votecount3 && votecount1>votecount4)
    {
        printf("[%s] \n\n",PARTICIPANT1);
    }
    else if(votecount2>votecount1 && votecount2>votecount3 && votecount2>votecount4)
    {
        printf("[%s] \n\n",PARTICIPANT2);
    }
    else if(votecount3>votecount1 && votecount3>votecount2 && votecount3>votecount4)
    {
        printf("[%s] \n\n",PARTICIPANT3);
    }
    else if(votecount4>votecount1 && votecount4>votecount2 && votecount4>votecount3)
    {
        printf("[%s] \n\n",PARTICIPANT4);
    }
    else
    {
        printf("**Caution!!! No-win situation!!! Stay with us for the final result.**\n");
    }
    int total=votecount1+votecount2+votecount3+votecount4;
    float percentage=100/total;
    printf("PARTICIPANT1 %0.2f%% \n",percentage*votecount1);
    printf("PARTICIPANT2 %0.2f%% \n",percentage*votecount2);
    printf("PARTICIPANT3 %0.2f%% \n",percentage*votecount3);
    printf("PARTICIPANT4 %0.2f%% \n",percentage*votecount4);
    printf("\nPress any key to continue...");
    getch();
}

void declarewinner()
{
    system("cls");
    if(votecount1>votecount2 && votecount1>votecount3 && votecount1>votecount4)
    {
        printf("Congratulations!!!! Winner is %s with %d votes. \n",PARTICIPANT1,votecount1);
    }
    else if(votecount2>votecount1 && votecount2>votecount3 && votecount2>votecount4)
    {
        printf("Congratulations!!!! Winner is %s with %d votes. \n",PARTICIPANT2,votecount2);
    }
    else if(votecount3>votecount1 && votecount3>votecount2 && votecount3>votecount4)
    {
         printf("Congratulations!!!! Winner is %s with %d votes. \n",PARTICIPANT3,votecount3);
    }
    else if(votecount4>votecount1 && votecount4>votecount2 && votecount4>votecount3)
    {
         printf("Congratulations!!!! Winner is %s with %d votes. \n",PARTICIPANT4,votecount4);
    }

    remove("voting_data.txt");

    votecount1 = 0, votecount2 = 0, votecount3 = 0, votecount4 = 0, unnecessaryvote = 0;
    for (int i = 0; i < 30; i++)
            hasVoted[i]=0;

    printf("\nPress any key to continue...");
    getch();
    system("cls");


}


void loadVoteCounts()
{
    system("cls");
    FILE *file = fopen(DATA_FILE, "r");
    if (file != NULL)
    {
        fscanf(file, "%d %d %d %d %d", &votecount1, &votecount2, &votecount3, &votecount4, &unnecessaryvote);
        for (int i = 0; i < 30; i++)
        {
            fscanf(file, "%d", &hasVoted[i]);
        }
        fclose(file);
    }
    else
    {
        printf("No previous voting data found, starting fresh.\n");
    }

}



