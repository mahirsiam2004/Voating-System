#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_USERS 100
#define MAX_CANDIDATES 10
#define DATA_FILE "voting_data.txt"

typedef struct {
    char username[50];
    int password;
    int hasVoted;
} User;

typedef struct {
    char name[50];
    int votes;
} Candidate;

User users[MAX_USERS];
int userCount = 0;
Candidate candidates[MAX_CANDIDATES];
int candidateCount = 4; // Default candidates

void loadUserData();
void saveUserData();
void loadCandidateData();
void saveCandidateData();
void adminPanel();
void manageUsers();
void manageCandidates();
void resetPassword();

void addUser();
void removeUser();
void addCandidate();
void removeCandidate();

void showBanner();
void votecount();
void leadingthewholeprocess();
void declarewinner();
void giveyourvote(int userIndex);

void showBanner() {
    const char *BLUE = "\033[1;34m";
    const char *PURPLE = "\033[1;35m";
    const char *RESET = "\033[0m";

    printf("%s======================================================\n", BLUE);
    printf("=                                                    =\n");
    printf("=   %sWELCOME TO CLASS REPRESENTATIVE ELECTION SYSTEM%s  =\n", PURPLE, BLUE);
    printf("=                                                    =\n");
    printf("=            %sDeveloped by Team:%s                      %s=\n", PURPLE, RESET, BLUE);
    printf("=           Mahir, Shafayet, Abdullah, Rafi          =\n");
    printf("=                                                    =\n");
    printf("======================================================\n");
    printf("               %sC PROJECT IMPLEMENTATION%s              %s\n", PURPLE, RESET, BLUE);
    printf("======================================================\n\n\n%s", RESET);
}

int main() {
    loadUserData();
    loadCandidateData();

    int choice;
    do {
        showBanner();
        printf("\n 1. Admin Panel\n");
        printf(" 2. User\n");
        printf(" 0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminPanel();
                break;

            case 2: {
                char username[50];
                int password;
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%d", &password);

                int found = 0;
                for (int i = 0; i < userCount; i++) {
                    if (strcmp(users[i].username, username) == 0 && users[i].password == password) {
                        // Welcome message for the user
                        printf("\033[1;32m\nWelcome, %s! You have successfully logged in.\033[0m\n", username);

                        int userChoice;
                        do {
                            printf("\n 1. Vote\n");
                            printf(" 2. Show Winner\n");
                            printf(" 0. Back\n");
                            printf("Choose an option: ");
                            scanf("%d", &userChoice);

                            switch (userChoice) {
                                case 1:
                                    if (users[i].hasVoted) {
                                        printf("\033[1;33m\nYou have already voted. Thank you for participating!\033[0m\n");
                                    } else {
                                        giveyourvote(i);
                                    }
                                    break;
                                case 2:
                                    declarewinner();
                                    break;
                                case 0:
                                    break;
                                default:
                                    printf("\033[1;31m\nInvalid choice. Please choose a valid option.\033[0m\n");
                            }
                        } while (userChoice != 0);

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\033[1;31m\nInvalid credentials or you are not registered.\033[0m\n");
                    getch();
                }
                break;
            }

            case 0:
                printf("\033[1;35m\n===========================================================\033[0m\n");
                printf("\033[1;33m              Thank You for Using Our System!              \033[0m\n");
                printf("\033[1;36m          Powered by Passion, Dedication, and Unity        \033[0m\n");
                printf("\033[1;34m===========================================================\033[0m\n");
                printf("\033[1;32m\n          A Heartfelt Tribute to Our Development Team      \033[0m\n");
                printf("\033[1;35m-----------------------------------------------------------\033[0m\n");
                printf("\033[1;33m      Mahir Siam: Visionary Leader and Code Architect      \033[0m\n");
                printf("\033[1;36m      Shafayet: System Strategist and Debugging Wizard     \033[0m\n");
                printf("\033[1;34m      Abdullah: Creative Thinker and Functional Designer   \033[0m\n");
                printf("\033[1;32m      Rafi: Optimization Expert and Testing Guru           \033[0m\n");
                printf("\033[1;35m-----------------------------------------------------------\033[0m\n");
                printf("\033[1;36m\n         Together, We Transformed Ideas into Reality       \033[0m\n");
                printf("\033[1;33m           With Countless Hours of Hard Work and Care      \033[0m\n");
                printf("\033[1;34m===========================================================\033[0m\n");
                printf("\033[1;32m\n           Goodbye! May Success Always Be With You         \033[0m\n");
                printf("\033[1;33m               Have a Wonderful and Bright Future!         \033[0m\n");
                printf("\033[1;35m===========================================================\033[0m\n");
                break;
            default:
                printf("\033[1;31m\nInvalid choice. Please choose a valid option.\033[0m\n");
        }
    } while (choice != 0);

    saveUserData();
    saveCandidateData();
    return 0;
}

void adminPanel() {
    char adminUser[20];
    int adminPass;
    printf("\nEnter ADMIN username: ");
    scanf("%s", adminUser);
    printf("Enter ADMIN password: ");
    scanf("%d", &adminPass);

    if (strcmp(adminUser, "admin") == 0 && adminPass == 123) {
        // Fancy Welcome Message for Admin
        printf("\033[1;36m\n===========================================\033[0m\n");
        printf("\033[1;32m          Welcome, %s! Access Granted.       \033[0m\n", adminUser);
        printf("\033[1;36m===========================================\033[0m\n\n");

        int adminChoice;
        do {
            //system("cls");
            printf("\n 1. Manage Users\n");
            printf(" 2. Manage Candidates\n");
            printf(" 3. Show Vote Count\n");
            printf(" 4. Show Leading Candidate\n");
            printf(" 0. Back\n");
            printf("Choose an option: ");
            scanf("%d", &adminChoice);

            switch (adminChoice) {
                case 1:
                    manageUsers();
                    break;
                case 2:
                    manageCandidates();
                    break;
                case 3:
                    votecount();
                    break;
                case 4:
                    leadingthewholeprocess();
                    break;
                case 0:
                    break;
                default:
                    printf("\033[1;31m\nInvalid choice. Please choose a valid option.\033[0m\n");
            }
        } while (adminChoice != 0);
    } else {
        printf("\033[1;31m\nInvalid ADMIN credentials.\033[0m\n");
        getch();
    }
}


void manageUsers() {
    int choice;
    do {
        system("cls");
        printf("\n 1. Add User\n");
        printf(" 2. Remove User\n");
        printf(" 3. Reset User Password\n");
        printf(" 0. Back\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                removeUser();
                break;
            case 3:
                resetPassword();
                break;
            case 0:
                break;
            default:
                printf("\033[1;31m\nInvalid choice. Please choose a valid option.\033[0m\n");
        }
    } while (choice != 0);
}

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("\033[1;31m\nCannot add more users. Maximum limit reached.\033[0m\n");
        return;
    }

    char username[50];
    int password;
    printf("\nEnter new username: ");
    scanf("%s", username);

    // Check if the username already exists
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("\033[1;31m\nUsername already exists. Please choose a different username.\033[0m\n");
            return;
        }
    }

    printf("Enter new password: ");
    scanf("%d", &password);

    strcpy(users[userCount].username, username);
    users[userCount].password = password;
    users[userCount].hasVoted = 0;
    userCount++;

    printf("\033[1;32m\nUser added successfully.\033[0m\n");
    saveUserData();
    getch();
}


void removeUser() {
    char username[50];
    printf("\nEnter username to remove: ");
    scanf("%s", username);

    int found = 0;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("\033[1;32m\nUser removed successfully.\033[0m\n");
    } else {
        printf("\033[1;31m\nUser not found.\033[0m\n");
    }

    saveUserData();
    getch();
}

void resetPassword() {
    char username[50];
    printf("\nEnter username to reset password: ");
    scanf("%s", username);

    int found = 0;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Enter new password: ");
            scanf("%d", &users[i].password);
            found = 1;
            break;
        }
    }

    if (found) {
        printf("\033[1;32m\nPassword reset successfully.\033[0m\n");
    } else {
        printf("\033[1;31m\nUser not found.\033[0m\n");
    }

    saveUserData();
    getch();
}

void manageCandidates() {
    int choice;
    do {
        system("cls");
        printf("\n 1. Add Candidate\n");
        printf(" 2. Remove Candidate\n");
        printf(" 0. Back\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                removeCandidate();
                break;
            case 0:
                break;
            default:
                printf("\033[1;31m\nInvalid choice. Please choose a valid option.\033[0m\n");
        }
    } while (choice != 0);
}

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("\033[1;31m\nCannot add more candidates. Maximum limit reached.\033[0m\n");
        return;
    }

    char name[50];
    printf("\nEnter new candidate name: ");
    scanf("%s", name);

    // Check if the candidate name already exists
    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            printf("\033[1;31m\nCandidate with this name already exists. Please choose a different name.\033[0m\n");
            return;
        }
    }

    strcpy(candidates[candidateCount].name, name);
    candidates[candidateCount].votes = 0;
    candidateCount++;

    printf("\033[1;32m\nCandidate added successfully.\033[0m\n");
    saveCandidateData();
    getch();
}


void removeCandidate() {
    char name[50];
    printf("\nEnter candidate name to remove: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            // Shift candidates after the removed one to fill the gap
            for (int j = i; j < candidateCount - 1; j++) {
                candidates[j] = candidates[j + 1];
            }
            candidateCount--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("\033[1;32m\nCandidate removed successfully.\033[0m\n");
    } else {
        printf("\033[1;31m\nCandidate not found.\033[0m\n");
    }

    saveCandidateData();
    getch();
}

void saveUserData() {
    FILE *file = fopen(DATA_FILE, "w");
    if (file == NULL) {
        printf("\033[1;31m\nError: Could not create or open the file %s.\033[0m\n", DATA_FILE);
        return;
    }
    fprintf(file, "%d\n", userCount);
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s %d %d\n", users[i].username, users[i].password, users[i].hasVoted);
    }
    fclose(file);
    printf("\033[1;32m\nUser data saved successfully to %s.\033[0m\n", DATA_FILE);
}

void saveCandidateData() {
    FILE *file = fopen("candidates_data.txt", "w");
    if (file == NULL) {
        printf("\033[1;31m\nError: Could not create or open the file candidates_data.txt.\033[0m\n");
        return;
    }
    fprintf(file, "%d\n", candidateCount);
    for (int i = 0; i < candidateCount; i++) {
        fprintf(file, "%s %d\n", candidates[i].name, candidates[i].votes);
    }
    fclose(file);
    printf("\033[1;32m\nCandidate data saved successfully to candidates_data.txt.\033[0m\n");
}

void loadUserData() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        // If the file does not exist, create default users with predefined passwords

        strcpy(users[0].username, "mahir");
        users[0].password = 323;
        users[0].hasVoted = 0;

        strcpy(users[1].username, "abdullah");
        users[1].password = 324;
        users[1].hasVoted = 0;

        strcpy(users[2].username, "shafayet");
        users[2].password = 349;
        users[2].hasVoted = 0;

        strcpy(users[3].username, "nishad");
        users[3].password = 325;
        users[3].hasVoted = 0;

        strcpy(users[4].username, "minhaz");
        users[4].password = 354;
        users[4].hasVoted = 0;

        strcpy(users[5].username, "arefin");
        users[5].password = 347;
        users[5].hasVoted = 0;

        strcpy(users[6].username, "maliha");
        users[6].password = 444;
        users[6].hasVoted = 0;

        strcpy(users[7].username, "shawon");
        users[7].password = 357;
        users[7].hasVoted = 0;

        strcpy(users[8].username, "rafi");
        users[8].password = 359;
        users[8].hasVoted = 0;

        strcpy(users[9].username, "theo");
        users[9].password = 352;
        users[9].hasVoted = 0;

        strcpy(users[10].username, "touhid");
        users[10].password = 345;
        users[10].hasVoted = 0;

        strcpy(users[11].username, "fikrat");
        users[11].password = 328;
        users[11].hasVoted = 0;

        strcpy(users[12].username, "shahriar");
        users[12].password = 408;
        users[12].hasVoted = 0;

        strcpy(users[13].username, "mahzilur");
        users[13].password = 358;
        users[13].hasVoted = 0;

        strcpy(users[14].username, "john");
        users[14].password = 331;
        users[14].hasVoted = 0;

        strcpy(users[15].username, "shaon");
        users[15].password = 333;
        users[15].hasVoted = 0;

        strcpy(users[16].username, "redowan");
        users[16].password = 335;
        users[16].hasVoted = 0;

        strcpy(users[17].username, "hakim");
        users[17].password = 360;
        users[17].hasVoted = 0;

        strcpy(users[18].username, "rahul");
        users[18].password = 340;
        users[18].hasVoted = 0;

        strcpy(users[19].username, "nur");
        users[19].password = 353;
        users[19].hasVoted = 0;

        strcpy(users[20].username, "mimiya");
        users[20].password = 339;
        users[20].hasVoted = 0;

        strcpy(users[21].username, "saif");
        users[21].password = 361;
        users[21].hasVoted = 0;

        strcpy(users[22].username, "dristy");
        users[22].password = 343;
        users[22].hasVoted = 0;

        strcpy(users[23].username, "ayesha");
        users[23].password = 351;
        users[23].hasVoted = 0;

        strcpy(users[24].username, "jannatul");
        users[24].password = 108;
        users[24].hasVoted = 0;

        strcpy(users[25].username, "niju");
        users[25].password = 97;
        users[25].hasVoted = 0;

        strcpy(users[26].username, "Eva");
        users[26].password = 330;
        users[26].hasVoted = 0;

        strcpy(users[27].username, "mariya");
        users[27].password = 110;
        users[27].hasVoted = 0;

        strcpy(users[28].username, "khairul");
        users[28].password = 123;
        users[28].hasVoted = 0;

        userCount = 29;  // Set the user count to 29
        return;  // Skip file reading if no file found
    }

    // If the file exists, load user data from the file
    fscanf(file, "%d", &userCount);
    for (int i = 0; i < userCount; i++) {
        fscanf(file, "%s %d %d", users[i].username, &users[i].password, &users[i].hasVoted);
    }
    fclose(file);
}


void loadCandidateData() {
    FILE *file = fopen("candidates_data.txt", "r");
    if (file == NULL) {
        // Default candidates when data file does not exist
        strcpy(candidates[0].name, "Mahir");
        candidates[0].votes = 0;

        strcpy(candidates[1].name, "Shafayet");
        candidates[1].votes = 0;

        strcpy(candidates[2].name, "Abdullah");
        candidates[2].votes = 0;

        strcpy(candidates[3].name, "Rafi");
        candidates[3].votes = 0;

        candidateCount = 4;  // Set the number of default candidates
        return;  // Skip file reading if no file found
    }

    fscanf(file, "%d", &candidateCount);
    for (int i = 0; i < candidateCount; i++) {
        fscanf(file, "%s %d", candidates[i].name, &candidates[i].votes);
    }
    fclose(file);
}

void declarewinner() {
    int maxVotes = 0;
    char winner[50];
    int tie = 0; // Variable to detect a tie

    strcpy(winner, "No winner yet");

    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
            tie = 0; // Reset tie if a new leader emerges
        } else if (candidates[i].votes == maxVotes && maxVotes > 0) {
            tie = 1; // Set tie flag if votes are equal
        }
    }

    if (tie) {
        printf("\033[1;33m\nIt's a tie! No clear winner.\033[0m\n");
    } else if (maxVotes > 0) {
        printf("\033[1;32m\nThe winner is: %s with %d votes!\033[0m\n", winner, maxVotes);
    } else {
        printf("\033[1;31m\nNo votes have been cast yet.\033[0m\n");
    }

    getch();
}

void votecount() {
    printf("\nVote Counts:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    getch();
}
void giveyourvote(int userIndex) {
    printf("\nCandidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int choice;
    printf("\nChoose a candidate (1-%d): ", candidateCount);
    scanf("%d", &choice);

    if (choice > 0 && choice <= candidateCount) {
        candidates[choice - 1].votes++;
        users[userIndex].hasVoted = 1;

    saveUserData();
    saveCandidateData();
        printf("\033[1;32m\nThank you for voting!\033[0m\n");

    } else {
        printf("\033[1;31m\nInvalid choice.\033[0m\n");
    }
    getch();
}
void leadingthewholeprocess() {
    int maxVotes = 0;
    char leader[50];
    strcpy(leader, "No leader yet");

    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(leader, candidates[i].name);
        }
    }

    printf("\nLeading Candidate: %s with %d votes\n", leader, maxVotes);
    getch();
}

