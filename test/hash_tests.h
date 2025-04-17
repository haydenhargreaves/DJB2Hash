/****************************************************************
 * File:    hash_test.h
 * Author:  Group 6: CS125
 * Purpose: Definition of the testing of the hash module.
 * Date:    4/16/2025
 ***************************************************************/

#ifndef HASH_TESTS_H
#define HASH_TESTS_H

#include "../include/hash.h"
#include <stdint.h>

/**
 * @brief Test the djb2 hashing function.
 * @returns Status code, 0 for pass, 1 for fail
 */
int test_djb2();

#endif
