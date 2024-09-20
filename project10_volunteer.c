// Anthony Lozbin
// This program allows the user to add, delete, search, print, and clear a list of volunteers.

#include <stdio.h>
#include <stdlib.h>
#include "volunteer.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct volunteer *volunteer_list = NULL;
  printf("Operation Code: a for adding to the list, s for searching"
	  ", d for deleting from the list, p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'd': volunteer_list = delete_from_list(volunteer_list);
                break;
      case 'a': volunteer_list = add_to_list(volunteer_list);
                break;
      case 's': search_list(volunteer_list);
                break;
      case 'p': print_list(volunteer_list);
                break;
      case 'q': clear_list(volunteer_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
