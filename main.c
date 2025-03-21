#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#define Sleep(x) Sleep(x * 1000)
#else
#include <unistd.h>
#define CLEAR "clear"
#define Sleep(x) sleep(x)
#endif

void AdminPass();
void UserLogin();
void AdminMenu();
void UserMenu(int userIndex);
void UserDetails();
void UserChecker();
void AddUser(int userNum);
void EditUser();
void DelUser();
void AddQuiz();
void EditQuiz();
void DeleteQuiz();
void TakeQuiz(int userIndex);
void ViewQuizQuizResults();
void ManageQuizzes();

char User[5][20] = {"USER1", "USER2", "USER3", "USER4", "USER5"};
char FullName[5][40] = {"Name One", "Name Two", "Name Three", "Name Four", "Name Five"};
int Sem[5] = {1, 1, 1, 1, 1};
char Trade[5][20] = {"SET", "SET", "SET", "SET", "SET"};
int Group[5] = {2, 2, 2, 2, 2};
char Pass[5][20] = {"12345", "12345", "12345", "12345", "12345"};

#define MAX_QUIZZES 10
#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

struct Question
{
    char question[200];
    char options[MAX_OPTIONS][50];
    int correctAnswer;
};

struct Quiz
{
    char title[50];
    struct Question questions[MAX_QUESTIONS];
    int numQuestions;
    int isActive;
};

struct Quiz quizzes[MAX_QUIZZES];
int numQuizzes = 0;

struct QuizResult
{
    char username[20];
    char quizTitle[50];
    int score;
    int totalQuestions;
};

struct QuizResult QuizResults[50];
int numQuizResults = 0;

int main()
{
    int menuChoice;

    // Initialize quizzes
    for (int i = 0; i < MAX_QUIZZES; i++)
    {
        quizzes[i].isActive = 0;
    }

    printf("\n\tWelcome To KUDO QUIZ\n\t");
    Sleep(3);
    system(CLEAR);

    while (1)
    {
        system(CLEAR);
        printf("\n\tKUDO QUIZ\n\n\t1. Admin\n\t2. User\n\t3. Exit\n\t");
        printf("\n\tEnter your choice: ");
        scanf("%d", &menuChoice);

        system(CLEAR);
        switch (menuChoice)
        {
        case 1:
            AdminPass();
            break;
        case 2:
            UserLogin();
            break;
        case 3:
            printf("\n\tBye\n\t");
            exit(0);
        default:
            printf("\n\tPlease make a correct selection.\n\t");
            Sleep(2);
            break;
        }
    }

    return 0;
}

void AdminPass()
{
    char password[20];
    int tryCount = 3;

    while (tryCount > 0)
    {
        system(CLEAR);
        printf("\n\t-----------\n\tADMIN LOGIN\n\t-----------\n");
        printf("\n\tPassword: ");
        scanf("%s", password);

        if (strcmp(password, "12345678") == 0)
        {
            system(CLEAR);
            AdminMenu();
            return;
        }
        else
        {
            tryCount--;
            if (tryCount == 0)
            {
                printf("\n\tAccess denied. Please try again later.\n\t");
                return;
            }
            printf("\n\tIncorrect password. %d attempts left.\n\t", tryCount);
            Sleep(2);
        }
    }
}

void UserDetails()
{
    int userChoice;

    while (1)
    {
        printf("\n\tREAD USER DETAILS\n\n");
        for (int i = 0; i < 5; i++)
        {
            printf("\t%d. %s\n", i + 1, User[i]);
        }
        printf("\t6. Exit\n\n\tEnter your choice: ");
        scanf("%d", &userChoice);

        if (userChoice >= 1 && userChoice <= 5)
        {
            int idx = userChoice - 1;
            printf("\n\tUsername: %s", User[idx]);
            printf("\n\tFull Name: %s", FullName[idx]);
            printf("\n\tSemester: %d", Sem[idx]);
            printf("\n\tTrade: %s", Trade[idx]);
            printf("\n\tGroup: %d", Group[idx]);
            printf("\n\tPassword: %s\n", Pass[idx]);
        }
        else if (userChoice == 6)
        {
            return;
        }
        else
        {
            printf("\n\tInvalid selection. Try again.\n\t");
            Sleep(2);
        }
    }
}

void UserChecker()
{
    for (int i = 0; i < 5; i++)
    {
        printf(strcmp(User[i], "") == 0 ? "Empty\n" : "Not Empty\n");
        if (strcmp(User[i], "") == 0)
        {
            AddUser(i);
            return;
        }
    }

    printf("\n\tUser slots are full!\n");
    Sleep(2);
}

void AddUser(int userNum)
{

    char newUser[20], newFullName[40], newPass[20], newTrade[20];
    int newSem, newGroup;

    printf("\n\tADD NEW USER\n\n");
    printf("\tUsername: ");
    scanf("%s", newUser);
    printf("\tFull Name: ");
    scanf(" %[^\n]", newFullName);
    printf("\tPassword: ");
    scanf("%s", newPass);
    printf("\tSemester: ");
    scanf("%d", &newSem);
    printf("\tTrade: ");
    scanf("%s", newTrade);
    printf("\tGroup: ");
    scanf("%d", &newGroup);

    strcpy(User[userNum], newUser);
    strcpy(FullName[userNum], newFullName);
    strcpy(Pass[userNum], newPass);
    Sem[userNum] = newSem;
    strcpy(Trade[userNum], newTrade);
    Group[userNum] = newGroup;
    printf("\n\tUser added successfully!\n");
    Sleep(2);
    return;
}

void EditUser()
{
    int userChoice;

    printf("\n\tEDIT USER DETAILS\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\t%d. %s\n", i + 1, User[i]);
    }
    printf("\t6. Exit\n\n\tEnter your choice: ");
    scanf("%d", &userChoice);

    if (userChoice >= 1 && userChoice <= 5)
    {
        int idx = userChoice - 1;
        printf("\n\tCurrent Username: %s", User[idx]);
        printf("\n\tEnter New Full Name: ");
        scanf(" %[^\n]", FullName[idx]);
        printf("\tEnter New Password: ");
        scanf("%s", Pass[idx]);
        printf("\tEnter New Semester: ");
        scanf("%d", &Sem[idx]);
        printf("\tEnter New Trade: ");
        scanf("%s", Trade[idx]);
        printf("\tEnter New Group: ");
        scanf("%d", &Group[idx]);

        printf("\n\tUser updated successfully!\n");
        Sleep(2);
    }
    else if (userChoice == 6)
    {
        return;
    }
    else
    {
        printf("\n\tInvalid selection. Try again.\n\t");
        Sleep(2);
    }
}

void DelUser()
{
    int userChoice;

    printf("\n\tDELETE USER\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\t%d. %s\n", i + 1, User[i]);
    }
    printf("\t6. Exit\n\n\tEnter your choice: ");
    scanf("%d", &userChoice);

    if (userChoice >= 1 && userChoice <= 5)
    {
        int idx = userChoice - 1;
        strcpy(User[idx], "");
        strcpy(FullName[idx], "");
        Sem[idx] = 0;
        strcpy(Trade[idx], "");
        Group[idx] = 0;
        strcpy(Pass[idx], "");

        printf("\n\tUser deleted successfully!\n");
        Sleep(2);
    }
    else if (userChoice == 6)
    {
        return;
    }
    else
    {
        printf("\n\tInvalid selection. Try again.\n\t");
        Sleep(2);
    }
}

void AdminMenu()
{
    int menuChoice;
    while (1)
    {
        printf("\n\tADMIN MAIN MENU\n\n"
               "\t1. Read User Details\n"
               "\t2. Add User\n"
               "\t3. Edit User\n"
               "\t4. Delete User\n"
               "\t5. Manage Quizzes\n"
               "\t6. View Quiz QuizResults\n"
               "\t7. Exit\n\t");
        printf("\n\tEnter your choice: ");
        scanf("%d", &menuChoice);

        system(CLEAR);
        switch (menuChoice)
        {
        case 1:
            UserDetails();
            break;
        case 2:
            UserChecker();
            break;
        case 3:
            EditUser();
            break;
        case 4:
            DelUser();
            break;
        case 5:
            ManageQuizzes();
            break;
        case 6:
            ViewQuizQuizResults();
            break;
        case 7:
            return;
        default:
            printf("\n\tPlease make a correct selection.\n\t");
            Sleep(2);
        }
    }
}

void UserLogin()
{
    char username[20], password[20];
    int tryCount = 0;

    while (tryCount < 3)
    {
        system(CLEAR);
        printf("\n\t-----\n\tLOGIN\n\t-----");
        printf("\n\n\tUsername: ");
        scanf("%s", username);
        printf("\n\tPassword: ");
        scanf("%s", password);

        for (int i = 0; i < 5; i++)
        {
            if (strcmp(username, User[i]) == 0 && strcmp(password, Pass[i]) == 0)
            {
                system(CLEAR);
                printf("\n\tWelcome to KUDO QUIZ, %s!\n\n", username);
                UserMenu(i);
                return;
            }
        }

        tryCount++;
        if (tryCount >= 3)
        {
            printf("\n\tToo many failed attempts. Please try again later.\n\t");
            return;
        }
        printf("\n\tInvalid credentials. Try again.\n\t");
        Sleep(2);
    }
}

void UserMenu(int userIndex)
{
    int choice;
    while (1)
    {
        printf("\n\tUSER MENU\n"
               "\n\t1. Take Quiz"
               "\n\t2. View My QuizResults"
               "\n\t3. Logout\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);

        system(CLEAR);
        switch (choice)
        {
        case 1:
            TakeQuiz(userIndex);
            break;
        case 2:
            printf("\n\tYOUR QUIZ QuizResultS:\n");
            for (int i = 0; i < numQuizResults; i++)
            {
                if (strcmp(QuizResults[i].username, User[userIndex]) == 0)
                {
                    printf("\n\tQuiz: %s", QuizResults[i].quizTitle);
                    printf("\n\tScore: %d/%d\n", QuizResults[i].score, QuizResults[i].totalQuestions);
                }
            }
            printf("\n\tPress Enter to continue...");
            getchar();
            getchar();
            break;
        case 3:
            return;
        default:
            printf("\n\tInvalid choice. Try again.\n");
            Sleep(2);
        }
    }
}

void ManageQuizzes()
{
    int choice;
    while (1)
    {
        printf("\n\tQUIZ MANAGEMENT\n"
               "\n\t1. Add Quiz"
               "\n\t2. Edit Quiz"
               "\n\t3. Delete Quiz"
               "\n\t4. Back to Main Menu\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);

        system(CLEAR);
        switch (choice)
        {
        case 1:
            AddQuiz();
            break;
        case 2:
            EditQuiz();
            break;
        case 3:
            DeleteQuiz();
            break;
        case 4:
            return;
        default:
            printf("\n\tInvalid choice. Try again.\n");
            Sleep(2);
        }
    }
}

void AddQuiz()
{
    if (numQuizzes >= MAX_QUIZZES)
    {
        printf("\n\tMaximum number of quizzes reached!\n");
        Sleep(2);
        return;
    }

    struct Quiz newQuiz;
    newQuiz.isActive = 1;

    printf("\n\tEnter quiz title: ");
    scanf(" %[^\n]", newQuiz.title);

    printf("\n\tEnter number of questions (max %d): ", MAX_QUESTIONS);
    scanf("%d", &newQuiz.numQuestions);

    if (newQuiz.numQuestions > MAX_QUESTIONS)
    {
        newQuiz.numQuestions = MAX_QUESTIONS;
    }

    for (int i = 0; i < newQuiz.numQuestions; i++)
    {
        printf("\n\tQuestion %d: ", i + 1);
        scanf(" %[^\n]", newQuiz.questions[i].question);

        for (int j = 0; j < MAX_OPTIONS; j++)
        {
            printf("\tOption %d: ", j + 1);
            scanf(" %[^\n]", newQuiz.questions[i].options[j]);
        }

        printf("\tCorrect answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &newQuiz.questions[i].correctAnswer);
    }

    quizzes[numQuizzes++] = newQuiz;
    printf("\n\tQuiz added successfully!\n");
    Sleep(2);
}

void EditQuiz()
{
    if (numQuizzes == 0)
    {
        printf("\n\tNo quizzes available to edit.\n");
        Sleep(2);
        return;
    }

    printf("\n\tAvailable Quizzes:\n");
    for (int i = 0; i < numQuizzes; i++)
    {
        printf("\t%d. %s\n", i + 1, quizzes[i].title);
    }

    int choice;
    printf("\n\tSelect quiz to edit (1-%d): ", numQuizzes);
    scanf("%d", &choice);

    if (choice < 1 || choice > numQuizzes)
    {
        printf("\n\tInvalid selection.\n");
        Sleep(2);
        return;
    }

    int quizIndex = choice - 1;
    struct Quiz *quiz = &quizzes[quizIndex];

    printf("\n\tEnter new quiz title (or press Enter to keep current): ");
    char newTitle[50];
    getchar();
    if (fgets(newTitle, sizeof(newTitle), stdin) && newTitle[0] != '\n')
    {
        newTitle[strcspn(newTitle, "\n")] = 0;
        strcpy(quiz->title, newTitle);
    }

    for (int i = 0; i < quiz->numQuestions; i++)
    {
        printf("\n\tEdit Question %d? (1=Yes, 0=No): ", i + 1);
        int editQuestion;
        scanf("%d", &editQuestion);

        if (editQuestion)
        {
            printf("\tNew question: ");
            scanf(" %[^\n]", quiz->questions[i].question);

            for (int j = 0; j < MAX_OPTIONS; j++)
            {
                printf("\tNew option %d: ", j + 1);
                scanf(" %[^\n]", quiz->questions[i].options[j]);
            }

            printf("\tNew correct answer (1-%d): ", MAX_OPTIONS);
            scanf("%d", &quiz->questions[i].correctAnswer);
        }
    }

    printf("\n\tQuiz updated successfully!\n");
    Sleep(2);
}

void DeleteQuiz()
{
    if (numQuizzes == 0)
    {
        printf("\n\tNo quizzes available to delete.\n");
        Sleep(2);
        return;
    }

    printf("\n\tAvailable Quizzes:\n");
    for (int i = 0; i < numQuizzes; i++)
    {
        printf("\t%d. %s\n", i + 1, quizzes[i].title);
    }

    int choice;
    printf("\n\tSelect quiz to delete (1-%d): ", numQuizzes);
    scanf("%d", &choice);

    if (choice < 1 || choice > numQuizzes)
    {
        printf("\n\tInvalid selection.\n");
        Sleep(2);
        return;
    }

    for (int i = choice - 1; i < numQuizzes - 1; i++)
    {
        quizzes[i] = quizzes[i + 1];
    }
    numQuizzes--;

    printf("\n\tQuiz deleted successfully!\n");
    Sleep(2);
}

void TakeQuiz(int userIndex)
{
    if (numQuizzes == 0)
    {
        printf("\n\tNo quizzes available.\n");
        Sleep(2);
        return;
    }

    printf("\n\tAvailable Quizzes:\n");
    for (int i = 0; i < numQuizzes; i++)
    {
        printf("\t%d. %s\n", i + 1, quizzes[i].title);
    }

    int choice;
    printf("\n\tSelect quiz to take (1-%d): ", numQuizzes);
    scanf("%d", &choice);

    if (choice < 1 || choice > numQuizzes)
    {
        printf("\n\tInvalid selection.\n");
        Sleep(2);
        return;
    }

    struct Quiz *quiz = &quizzes[choice - 1];
    int score = 0;

    for (int i = 0; i < quiz->numQuestions; i++)
    {
        system(CLEAR);
        printf("\n\tQuestion %d/%d:", i + 1, quiz->numQuestions);
        printf("\n\t%s\n", quiz->questions[i].question);

        for (int j = 0; j < MAX_OPTIONS; j++)
        {
            printf("\t%d. %s\n", j + 1, quiz->questions[i].options[j]);
        }

        int answer;
        printf("\n\tYour answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);

        if (answer == quiz->questions[i].correctAnswer)
        {
            score++;
        }
    }

    // Save QuizResult
    if (numQuizResults < 50)
    {
        strcpy(QuizResults[numQuizResults].username, User[userIndex]);
        strcpy(QuizResults[numQuizResults].quizTitle, quiz->title);
        QuizResults[numQuizResults].score = score;
        QuizResults[numQuizResults].totalQuestions = quiz->numQuestions;
        numQuizResults++;
    }

    printf("\n\tQuiz completed!\n\tYour score: %d/%d\n", score, quiz->numQuestions);
    printf("\n\tPress Enter to continue...");
    getchar();
    getchar();
}

void ViewQuizQuizResults()
{
    if (numQuizResults == 0)
    {
        printf("\n\tNo quiz QuizResults available.\n");
        Sleep(2);
        return;
    }

    printf("\n\tALL QUIZ QuizResultS:\n");
    for (int i = 0; i < numQuizResults; i++)
    {
        printf("\n\tUser: %s", QuizResults[i].username);
        printf("\n\tQuiz: %s", QuizResults[i].quizTitle);
        printf("\n\tScore: %d/%d\n", QuizResults[i].score, QuizResults[i].totalQuestions);
    }

    printf("\n\tPress Enter to continue...");
    getchar();
    getchar();
}
