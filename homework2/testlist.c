// Name: Vilina Prenko
// Assignment number: A04
// Assignment: Dual Doubly Linked Lists 
// File name: testlist.c
// Date last modified: provided by the instructor
// Sources: provided by the instructor
//  File testlist.c

#include <stdio.h>
#include "dualdoublelist.h"

//  Interactive program useful for experimenting with the
//  dual doubly-linked list structure.

// Clear faulty keystrokes from the input stream.
static void flush_input(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        continue;
}


int main(void) {
    DualDoublyLinkedList list = ddll_make_list();
    int done = 0;
    int id;
    char command;
    char name[256];
    while (!done) {
        printf("=> ");
        scanf(" %c", &command);
        switch (command) {
           case '+':   //  Insert new person data
               scanf("%d %255s", &id, name);
               printf("Inserting ID: %d  Name: %s\n", id, name);
               if ( !ddll_insert(&list, name, id) )
                   printf("Cannot insert %s\n", name);
               break;
           case '-':   //  Remove a person by ID number
               scanf("%d", &id);
               printf("Removing %d\n", id);
               if ( !ddll_remove(&list, id) )
                   printf("Cannot remove %d\n", id);
               break;
           case 'n':  //  Print contents in name order
               printf("Printing by name\n");
               ddll_print_by_name(&list);
               break;
           case 'N':  //  Print contents in reverse name order
               printf("Printing by name reverse\n");
               ddll_print_by_name_reverse(&list);
               break;
           case 'i':  //  Print contents in ID number order 
               printf("Printing by ID number\n");
               ddll_print_by_ID(&list);
               break;
           case 'I':  //  Print contents in reverse ID number order
               printf("Printing by ID number reverse\n");
               ddll_print_by_ID_reverse(&list);
               break;
           case '?':  //  Print help message
           case '/':
               puts("+ <ID> <name>   insert new person");
               puts("- <ID>          remove existing person");
               puts("n (N)           print names forward (reverse)");
               puts("i (I)           print IDs forward (reverse)");
               puts("Q               quit");
               break;
           case 'Q':  //  Quit the program
           case 'q':
               done = 1;
               break;
           default:   //  Unknown command, flush input stream
               puts("Unknown command");
               flush_input();
        }
    }
    ddll_dispose_list(&list);
}
