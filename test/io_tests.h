/****************************************************************
 * File:    io_test.h
 * Author:  Group 6: CS125
 * Purpose: Definition of the testing of the io module.
 * Date:    4/16/2025
 ***************************************************************/
#ifndef IO_TESTS_H
#define IO_TESTS_H

#include "../include/io.h"
#include <stdio.h>
#include <strings.h>

/**
 * @brief Test the rainbow lookup functionality.
 * @return Status of test, 0 for pass, 1 for fail
 */
int test_find_word_by_hash();

#endif
