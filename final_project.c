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

/* The game itself */

int game(int i)
{
    FILE *quest_file;
    char answers [4];
    int ascii = 65; 
    int number = 200;
    char buff[200];
    char print_text [5000][200];
    quest_file = fopen("questions.txt","r");
    for (; i < 5; i++)
    {
        fgets(buff, number, (FILE *)quest_file);
        strcpy(print_text[i], buff);
        if (print_text[i][0] == 'O')
        {
            strncpy(&answers[i-1],print_text[i] +8, 80);  
            printf("*** %c: %s", ascii, &answers[i-1]);
            ascii++;
        }
        else if (print_text[i][0] != 'O')
        {
            printf("*** %s", print_text[i]);
        }
    }
    fclose(quest_file);
    return i + 8;

}

/* print the status of the player */

void print_status(const int level, const char * j50, const char * j25, const char * name)
{
    puts("********************************************");
    printf("*** Name:  %s               *\n", name);
    printf("*** level:  %02d                  *\n", level);
    printf("*** j50: %s                    *\n", j50);
    printf("*** j25:  %s                   *\n", j25);
    puts("********************************************");
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
    else if(argc == 2)
    {
        srand(atoi(argv[1]));
    }
    

    /*Those are the valors that we will use*/

    char command[20];
    char choice;
    char option;
    int level = 0;
    int tries = 0;
    int check = 0;
    int i = 0;
    char text[] =".txt";
    char j50[] = "Yes";
    char j25[] = "Yes";
    char name[20] = "Newbie";

    /*This while will cause the game to continue until you quit/lose/win*/

    while(command[0] != 'q' && check != 100000 && tries != 2)
    {
        printf(">");
        fgets(command, 100, stdin);
        sscanf(command, "%c %s", &choice, &option);

        if (choice == 'n')
        {
            if (option)
            {
                char new_name[20];
                strcpy(new_name ,&option);
                printf("*** Hi %s, let's get started!\n", new_name);
                strcpy(name, new_name);
            }
            if (check == 0)
            {
                puts("*** Hi Newbie, let's get started!");
                print_status(level, j50, j25, name);
            }
            game(i);
        }
        else if (choice == 'r')
        {
            /* Do the game first */
            char file_name[20];
            strcpy(file_name ,&option);
            strcat(file_name, text);
            FILE *save_file; 
            save_file = fopen(file_name,"r");
            fprintf(save_file, "%d\n" , level);
            char name[] = "boomer";
            printf("Ok %s, where were we? Oh there you go:\n", name);
            /* game(points, level, j50, j25); */
        }

        else if (choice == 's')
        {
            if (option)
            {
                /* fazer que isto pegue o nome do jogador*/
                char file_name[20];
                strcpy(file_name ,&option);
                strcat(file_name, text);
                FILE *save_file; 
                save_file = fopen(file_name,"w");
                fprintf(save_file, "%d\n" , level);
                fprintf(save_file, "%s\n" , j50);
                fprintf(save_file, "%s\n" , j25);
                fprintf(save_file, "%s\n" , name);
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
            puts("This game was made by :");
            puts("Vasco Duarte (21905658)");
            puts("Tony (gne gne)");
            puts("Joao Magic (gagagou)");
        }
        
        else
        {
            puts(MSG_UNKNOWN);
        }
       
    }

    return 0;
 
}