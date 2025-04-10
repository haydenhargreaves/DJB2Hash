/****************************************************************
 * File:    hash.c
 * Author:  Group 6: CS125
 * Purpose: Definition of the file IO module
 * Date:    4/9/2025
 ***************************************************************/
#ifndef IO_H
#define IO_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

#define WORD_SIZE 128

/**
 * @brief Search the words list for a word with a given hash
 * @param f The words list file
 * @param hash Target word hash
 * @return The word located with the matching hash, or NULL if not found
 */
char *find_word_by_hash(FILE *f, uint32_t hash);

#endif
