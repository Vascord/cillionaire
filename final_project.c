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

/* void game(int level, int points, char * j50, char * j25) */



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
    char text[] =".txt";
    char j50[] = "Yes";
    char j25[] = "Yes";
    char name[] = "Newbie";

    /*This while will cause the game to continue until you quit/lose/win*/

    while(command[0] != 'q' && level != 100000 && tries != 2)
    {
        printf(">");
        fgets(command, 100, stdin);
        sscanf(command, "%c %s", &choice, &option);

        if (choice == 'n')
        {
            if (option)
            {
                char name[20];
                strcpy(name ,&option);
                check = 1;

                printf("*** Hi %s, let's get started!\n", name);
                print_status(level, j50, j25,name);
                /*game(points, level, j50, j25);*/
            }

            else if (check == 0)
            {
                puts("*** Hi Newbie, let's get started!");
                print_status(level, j50, j25, name);
                /*game(points, level, j50, j25); <-- objectif number 1*/
            }


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
        
        else
        {
            puts(MSG_UNKNOWN);
        }
       
    }

    return 0;
 
}