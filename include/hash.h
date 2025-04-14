/****************************************************************
 * File:    hash.c
 * Author:  Group 6: CS125
 * Purpose: Definition of the hashing algorithm.
 * Date:    4/6/2025
 ***************************************************************/

#ifndef HASH_H
#define HASH_H

#include <stdint.h>
#include <string.h>

/**
 * @brief Simple implementation of the djb2 hashing algorithm.
 * @param str Target string to hash
 * @return The hash of the string provided
 * @note Explanation found here: https://theartincode.stanis.me/008-djb2/
 */
uint32_t djb2(const char *str);

#endif
