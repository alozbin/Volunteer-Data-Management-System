#ifndef VOLUNTEER_H
#define VOLUNTEER_H

// macro definitions
#define EMAIL_LEN 100
#define NAME_LEN 30

// structure to store information for volunteer
struct volunteer{
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	int grade_level;
	struct volunteer *next;
};

// function prototypes for volunteer operations
struct volunteer *add_to_list(struct volunteer *list);
void search_list(struct volunteer *list);
void print_list(struct volunteer *list);
void clear_list(struct volunteer *list);
struct volunteer *delete_from_list(struct volunteer *list);

#endif
