/*
 * CS 261 Data Structures
 * Assignment 6
 * Name: Daniel Beyer
 * Date: 08/02/16
 * Concordance implemented using a hash map that counts how many times each word occurs in a document.
 */
#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    const char* fileName = "input1.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    printf("Opening file: %s\n", fileName);

    clock_t timer = clock();

    HashMap* map = hashMapNew(10);

    // --- Concordance code begins here ---
    FILE *filep;
    filep = fopen(fileName, "r");

    /*If file not found, error */
    if(filep == NULL) {
        perror("Error");
    }

    char *word = nextWord(filep);
    while(word != NULL){
        if(hashMapContainsKey(map, word)){
            int occurrences = *(hashMapGet(map, word));
            hashMapPut(map, word, ++occurrences);
        }
        else {
            hashMapPut(map, word, 1);
        }
        free(word);
        word = nextWord(filep);
    }

    /*close file*/
    fclose(filep);

    /*print words and occurrences*/
    int i;
    for(i=0; i<map->capacity; i++) {
        HashLink *link = map->table[i];
        if(link != NULL) {
            while(link != NULL) {
                printf(" %s: %d \n", link->key, link->value);
                link = link->next;
            }
        }
    }
    // --- Concordance code ends here ---

    hashMapPrint(map);

    timer = clock() - timer;
    printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));

    hashMapDelete(map);
    return 0;
}
