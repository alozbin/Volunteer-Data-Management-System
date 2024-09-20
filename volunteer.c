#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "volunteer.h"
#include "read_line.h"

// function deletes volunteer from list
struct volunteer *delete_from_list(struct volunteer *list){
    if(list == NULL){
        printf("List is empty.\n");
        return NULL;
    }

    char first[NAME_LEN+1];
    char last[NAME_LEN+1];
    char email[EMAIL_LEN+1];
    int grade_level;

    printf("Enter last name: ");
    read_line(last, NAME_LEN);

    printf("Enter first name: ");
    read_line(first, NAME_LEN);

    printf("Enter email address: ");
    read_line(email, EMAIL_LEN);

    printf("Enter grade level: ");
    scanf("%d", &grade_level);

    // deletes first node if it contains volunteer
    if(strcmp(list->last, last) == 0 && strcmp(list->first, first) == 0 && strcmp(list->email, email) == 0 && list->grade_level == grade_level){
        struct volunteer *temp = list;
        list = list->next;
        free(temp);
        return list;
    }

    // loop stops if it finds matching volunteer
    struct volunteer *curr = list;
    while(curr->next != NULL && (strcmp(curr->next->last, last) != 0 || strcmp(curr->next->first, first) != 0 || strcmp(curr->next->email, email) != 0 || curr->next->grade_level != grade_level)){
        curr = curr->next;
    }

    // prints if loop reaches end of list without finding volunteer
    if(curr->next == NULL){
        printf("volunteer does not exist\n");
        return list;
    }

    // space freed from deleted volunteer
    struct volunteer *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    return list;
}

// function adds new volunteer to end of list
struct volunteer *add_to_list(struct volunteer *list){
    // space allocated and checked for new volunteer information
    struct volunteer *new_volunteer = malloc(sizeof(struct volunteer));

    if(new_volunteer == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }

    printf("Enter last name: ");
    read_line(new_volunteer->last, NAME_LEN);

    printf("Enter first name: ");
    read_line(new_volunteer->first, NAME_LEN);

    printf("Enter email address: ");
    read_line(new_volunteer->email, EMAIL_LEN);

    printf("Enter grade level: ");
    scanf("%d", &new_volunteer->grade_level);

    // new volunteer not added to list if last name and email already exist
    struct volunteer *curr = list;
    while(curr != NULL){
        if(strcmp(new_volunteer->email, curr->email) == 0 && strcmp(new_volunteer->last, curr->last) == 0){
            printf("volunteer already exists.\n");
            free(new_volunteer);
            return list;
        }
        curr = curr->next;
    }

    new_volunteer->next = NULL;

    // returns pointer to new volunteer if list is empty
    if(list == NULL){
        return new_volunteer;
    }
    // otherwise added to end of list
    else{
        curr = list;
        while(curr->next != NULL){
            curr = curr->next;
        }
    }
    curr->next = new_volunteer;

    return list;
}

// function prints volunteer information for matching grade level
void search_list(struct volunteer *list){
    int grade, flag = 0;

    printf("Enter grade level: ");
    scanf("%d", &grade);

    struct volunteer *curr = list;

    // loops through list to find volunteer with grade matching search
    while(curr != NULL){
        if(grade == curr->grade_level){
            flag = 1;
            printf("%-12s%-12s%-30s\n", curr->last, curr->first, curr->email);
        }
        curr = curr->next;
    }

    if(flag == 0){
        printf("not found\n");
    }
}

// function prints ordered list of all volunteers
void print_list(struct volunteer *list){
    struct volunteer *curr = list;

    while(curr != NULL){
        printf("%-12s%-12s%-30s%5d\n", curr->last, curr->first, curr->email, curr->grade_level);
        curr = curr->next;
    }
}

// function deallocates space for all volunteers
void clear_list(struct volunteer *list){
    struct volunteer *temp;

    while(list != NULL){
        temp = list;
        list = list->next;
        free(temp);
    }
}
