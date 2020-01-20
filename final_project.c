#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <strings.h>

/* Use puts() to print constant strings */
 
#define MSG_WELL "*** Hooray!"
#define MSG_WIN "*** This is incredible! You have won!"
#define MSG_OVER "*** Sorry, you have lost the game. Bye!"
#define MSG_SAVE "*** Ok, your progress has been saved. See you later!"
#define MSG_ERROR "*** Illegal move"
#define MSG_BYE "*** Sad to see you go..."
#define MSG_UNKNOWN "*** Unknown option."
#define MSG_WRONG "*** Woops... That's not correct."

struct Player {
    int level;
    char difficulty[20];
    char name[20];
    char j50[10];
    char j25[10];
    int tries;
} player;

struct File {
    char fichier[30];
} file;

struct Answers {
    char question[300];
    char answer[20];
    int right;
    char letter;
} answer;
/* print the status of the player */

void print_status()
{
    puts("********************************************");
    printf("*** Name:  %s               *\n", player.name);
    printf("*** Level:  %d                  *\n", player.level);
    printf("*** j50: %s                    *\n", player.j50);
    printf("*** j25:  %s                   *\n", player.j25);
    puts("********************************************");
}

int levels(int level_up)
{
    if (level_up == 0)
    {
        level_up = 500;
    }
    else if (level_up != 0)
    {
        level_up *= 2;
        if (level_up == 4000)
        {
            level_up = 5000;
        }
        if (level_up == 40000)
        {
            level_up = 5000;
        }
        if(level_up == 2000)
        {
            strcpy(player.difficulty, "medium");
        }
        if (level_up == 10000)
        {
            strcpy(player.difficulty, "hard");
        }
    }
    return level_up;
}
/* The game itself */

int game(int next_question)
{
    int infite = 1;
    char choice_2;
    FILE *quest_file;
    while(infite)
    {
        print_status();
        int i,z;
        int set_free = 0;
        char difficulty_check [20];
        struct Answers answer_1;
        struct Answers answer_2;
        struct Answers answer_3;
        struct Answers answer_4;
        struct Answers question;
        int game_condition = 0;
        char buff[200];
        char print_text [3500][100];
        if (next_question == 0)
        {
            quest_file = fopen(file.fichier,"r");
            for(z = 0; z < 3500;z++)
            {
                fgets(buff, 100, (FILE *) quest_file);
                strcpy(print_text[z],buff);
            }
        }
        while(set_free == 0)
        {
            strncpy(difficulty_check,print_text[6 + next_question] +11, 80);
            if (difficulty_check[0] == player.difficulty[0])
            {
                for (i = 0;i < 5 ;i++)
                {
                    if (i == 0)
                    {
                        strncpy(question.question,print_text[i + next_question] +9, 200);
                        printf("*** Question: %s", question.question);
                    }
                    if (i == 1)
                    {
                        strncpy(answer_1.answer,print_text[i + next_question] +8, 80);
                    }
                    if (i == 2)
                    {
                        strncpy(answer_2.answer,print_text[i + next_question] +8, 80);
                    }
                    if (i == 3)
                    {
                        strncpy(answer_3.answer,print_text[i + next_question] +8, 80);
                    }
                    if (i == 4)
                    {
                        strncpy(answer_4.answer,print_text[i + next_question] +8, 80);
                    }
                    set_free = 1;
                }
            }
            else if (difficulty_check[0] != player.difficulty[0])
            {
                next_question += 7;
            }
        }
        fclose(quest_file);
        int e = rand() %4;
        if (e == 0)
        {
            printf("*** A: %s", answer_1.answer);
            printf("*** B: %s", answer_2.answer);
            printf("*** C: %s", answer_3.answer);
            printf("*** D: %s", answer_4.answer);
            answer_1.letter = 'A';
            answer_2.letter = 'B';
            answer_3.letter = 'C';
            answer_4.letter = 'D';
        }
        if (e == 1)
        {
            printf("*** A: %s", answer_2.answer);
            printf("*** B: %s", answer_1.answer);
            printf("*** C: %s", answer_3.answer);
            printf("*** D: %s", answer_4.answer);
            answer_2.letter = 'A';
            answer_1.letter = 'B';
            answer_3.letter = 'C';
            answer_4.letter = 'D';
        }
        if (e == 2)
        {
            printf("*** A: %s", answer_2.answer);
            printf("*** B: %s", answer_3.answer);
            printf("*** C: %s", answer_1.answer);
            printf("*** D: %s", answer_4.answer);
            answer_2.letter = 'A';
            answer_3.letter = 'B';
            answer_1.letter = 'C';
            answer_4.letter = 'D';
        }
        if (e == 3)
        {
            printf("*** A: %s", answer_2.answer);
            printf("*** B: %s", answer_3.answer);
            printf("*** C: %s", answer_4.answer);
            printf("*** D: %s", answer_1.answer);
            answer_2.letter = 'A';
            answer_3.letter = 'B';
            answer_4.letter = 'C';
            answer_1.letter = 'D';
        }
        while (game_condition != 1)
        {
            char command_2[20];
            char option_2;

            printf(">");
            fgets(command_2, 100, stdin);
            sscanf(command_2, "%c %s", &choice_2, &option_2);

            if (choice_2 == answer_1.letter)
            {
                puts(MSG_WELL);
                next_question += 7;
                player.tries = 0;
                game_condition = 1;
                player.level = levels(player.level);
            }
            else if (choice_2 == answer_2.letter)
            {
                puts(MSG_WRONG);
                printf("*** The correct answer was %c: %s", answer_1.letter,answer_1.answer);
                player.tries++;
                next_question += 7;
                game_condition = 1;
            }
            else if (choice_2 == answer_3.letter)
            {
                puts(MSG_WRONG);
                printf("*** The correct answer was %c: %s", answer_1.letter,answer_1.answer);
                player.tries++;
                next_question += 7;
                game_condition = 1;
            }
            else if (choice_2 == answer_4.letter)
            {
                puts(MSG_WRONG);
                printf("*** The correct answer was %c: %s", answer_1.letter,answer_1.answer);
                player.tries++;
                next_question += 7;
                game_condition = 1;
            }
            else if (choice_2 == 'q')
            {
                puts(MSG_BYE);
                return 0;
            }
            else
            {
                puts(MSG_UNKNOWN);
            }
            
        }
        if (player.tries == 2)
        {
            puts(MSG_OVER);
            return 0;
        }
        else if(player.level == 1000000)
        {
            puts(MSG_WIN);
            printf("*** Congratulations %s", player.name);
            return 0;
        }
    }
    return 0;
}
 
/* print the option menu */
 
void print_menu(void)
{
    puts("********************************************");
    puts("***            CILLIONAIRE                 *");
    puts("********************************************");
    puts("*** n <name>     - new game                *");
    puts("*** q            - quit                    *");
    puts("*** h            - show this menu          *");
    puts("*** r <filename> - resume game             *");
    puts("*** s <filename> - save progress and quit  *");
    puts("*** j 50         - play 50:50 joker        *");
    puts("*** j 25         - play 25:75 joker        *");
    puts("*** c            - show credits            *");
    puts("********************************************");
}

int main(int argc, char * argv[])
{
    
    print_menu();
    
    /*Start the programm while verifing if there's the seeds or not*/

    if(argc == 1)
    {
        srand(time(0));
    }
    if(argc >= 2)
    {
        if (strcmp(argv[1], "-s") == 0)
        {
            srand(atoi(argv[2]));
        }
        if (strcmp(argv[1], "-f") == 0)
        {
            strcpy(file.fichier,argv[2]);
        }
    }
    if(argc == 5)
    {
        if (strcmp(argv[3], "-s") == 0)
        {
            srand(atoi(argv[4]));
        }
        if (strcmp(argv[3], "-f") == 0)
        {
            strcpy(file.fichier,argv[4]);
        }
    }
    

    /*Those are the valors that we will use*/

    char command[20];
    char option[20];
    char choice;

    player.level = 0;
    player.tries = 0;
    strcpy(player.name, "Newbie");
    strcpy(player.difficulty, "easy");
    strcpy(player.j50, "YES");
    strcpy(player.j25, "YES");
    int next_question = 0;

    int check = 0;
    char text[] = ".txt";

    /*This while will cause the game to continue until you quit/lose/win*/

    while(command[0] != 'q')
    {
        printf(">");
        fgets(command, 100, stdin);
        sscanf(command, "%c %s", &choice, option);

        if (choice == 'n')
        {
            if(strlen(file.fichier) < 2)
            {
                puts("*** You can't do that");
            }
            else if (strlen(file.fichier) >= 2)
            {
                if (strlen(option) > 2)
                {
                    strcpy(player.name,option);
                    printf("*** Hi %s, let's get started!\n", player.name);
                    check = 1;
                }
                if (check == 0)
                {
                    strcpy(player.name,"Newbie");
                    printf("*** Hi %s, let's get started!\n", player.name);
                }
                game(next_question);
                break;
            }
        }
        else if (choice == 'r')
        {
            /* Do the game first */
            char file_name[20];
            strcpy(file_name ,option);
            strcat(file_name, text);
            FILE *save_file; 
            save_file = fopen(file_name,"r");
            fprintf(save_file, "%d\n" , player.level);
            char name[] = "boomer";
            printf("*** Ok %s, where were we? Oh there you go:\n", name);
            /* game(points, level, j50, j25); */
        }

        else if (choice == 's')
        {
            if (strlen(command) > 1)
            {
                /* fazer que isto pegue o nome do jogador*/
                char file_name[20];
                strcpy(file_name ,option);
                strcat(file_name, text);
                FILE *save_file; 
                save_file = fopen(file_name,"w");
                fprintf(save_file, "%d\n" , player.level);
                fprintf(save_file, "%s\n" , player.j50);
                fprintf(save_file, "%s\n" , player.j25);
                fprintf(save_file, "%s\n" , player.name);
                fclose(save_file);
                puts(MSG_SAVE);
            }
        }

        else if (choice == 'h')
        {
            print_menu();
        }

        else if (choice == 'q')
        {
            puts(MSG_BYE);
            break;
        }

        else if (choice == 'c')
        {
            puts("*** This game was made by :");
            puts("*** Vasco Duarte (21905658)");
            puts("*** Antonio Branco (21906811)");
            puts("*** Joao Gonçalves (21901696)");
        }
        
        else
        {
            puts(MSG_UNKNOWN);
        }
       
    }

    return 0;
 
}