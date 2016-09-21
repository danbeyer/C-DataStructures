/*
 * CS 261 Assignment 5
 * Name: Daniel Beyer
 * Date: 07/31/16
 * Implementation of a to-do list application using a heap-based priority queue.
 */

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    Task *newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    return newTask;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return
 */
int taskCompare(void* left, void* right)
{
    Task *l = (Task*) left;
    Task *r = (Task*) right;
    int compareVal = 0;
    if(l->priority<r->priority) {
        compareVal = -1; }
        else if (l->priority > r->priority) {
            compareVal = 1;
        }
        return compareVal;
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
