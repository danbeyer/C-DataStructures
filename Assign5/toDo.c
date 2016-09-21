/*
 * CS 261 Assignment 5
 * Name: Daniel Beyer
 * Date: 07/28/16
 * Implementation of a to-do list application using a heap-based priority queue.
 */
#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
*Compares a task with each task already in the heap.
*@param heap
*@param the new task to compare to the heap
*@Returns: 0 if not present, 1 if present
*/

int duplicateCheck(DynamicArray *heap, struct Task *task)
{

 int i;
 Task *tempTask;
 for(i = 0; i<dySize(heap); i++) {
    tempTask = dyGet(heap, i);
    /*Using strcmp to compare the names of 2 tasks*/
    if(strcmp(task->name, tempTask->name) == 0) {
        return 1;
    }
    else if (task->priority == tempTask->priority) {
            return 1; }
    }
    return 0;
 }



/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
 snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);

    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
	struct Task *newTask = taskNew(temp.priority, temp.name);           	if (duplicateCheck(heap, newTask) == 0)
  	if (duplicateCheck(heap, newTask) == 0){
		  dyHeapAdd(heap, newTask, taskCompare);
	}
    }

 }


/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
    while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    FILE *inputFile;
    FILE *outputFile;
    char filename[100];
    char desc[100];
    char *nullptr;
    int priority;
    Task *newTask;
    Task *firstTask;


    switch(command) {
        case 'l':  /*load list from file specified by user*/
                    printf("\nEnter file name to open: ");
                    scanf("%s", filename);

                    /*remove trailing char*/
                    while(getchar() != '\n');

                    if((inputFile = fopen(filename, "r"))==0)
                        printf("Error opening file.\n");
                    else {
                        listLoad(list, inputFile);
                        printf("The list has been loaded from the file successfully.\n");
                        fclose(inputFile);
                    }
                    break;

        case 's':  /*save list to location specified by user*/
                    if(dySize(list)>0) {
                    printf("\nEnter file name to save to: ");
                    scanf("%s", filename);
                    while(getchar() != '\n');
                    if((outputFile = fopen(filename, "w"))==0)
                        printf("Error opening file.\n");
                    else {
                        listSave(list, outputFile);
                        printf("The list has been saved into the file successfully.\n");
                        fclose(outputFile);
                    }
                    }
                    else
                        printf("You to-do list is empty! \n");
                    break;

        case 'a':  ;/*add new task to list*/
                    int k = 1;
                    while(k == 1){
                    printf("Enter the task description: ");
                    if(fgets(desc, sizeof(desc), stdin) != NULL) {
                        nullptr = strchr(desc, '\n');
                        if(nullptr) *nullptr = '\0';
                    }

                    /*input validation*/
                    do{
                        printf("Enter task priority from 0 to 999: ");
                        scanf("%d", &priority);
                    } while(!(priority >= 0 && priority<=999));
                    while(getchar() != '\n');

                    newTask = taskNew(priority, desc);
                    k = duplicateCheck(list, newTask);
                    if(k == 1) {
                        printf("Error, that task or priority is already on your list.\n");
                    }
                    }
                    dyHeapAdd(list, newTask, taskCompare);
                    printf("Task '%s' was added to your to-do list.\n", desc);
                    break;

        case 'g':  /*Gets and prints the first task*/
                    if(dySize(list)>0) {
                        firstTask = (Task*)dyHeapGetMin(list);
                        printf("Your first task is: '%s'\n", firstTask->name);
                    }
                    else {
                        printf("Your to-do list is empty!\n");
                    }
                    break;

        case 'r':  /*Removes first task*/
                    if(dySize(list)==0) {
                        printf("Your to-do list is empty!\n");
                    }
                    else {
                        firstTask = (Task*)dyHeapGetMin(list);
                        printf("You have removed '%s' from your list", firstTask->name);
                        dyHeapRemoveMin(list, taskCompare);
                    }
                    break;

        case 'p':  /*print list*/
                    if(dySize(list)==0) {
                        printf("Your to-do list is empty!\n");
                    }
                    else {
                        listPrint(list);
                    }
                    break;

        case 'e':
                    printf("Bye!");
                    break;

    }
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
    dyDelete(list);
    return 0;
}
