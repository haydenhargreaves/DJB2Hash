/****************************************************************
 * File:    cli_test.c
 * Author:  Group 6: CS125
 * Purpose: Implementation of the testing of the cli module.
 * Date:    4/16/2025
 ***************************************************************/

#include "cli_tests.h"

int test_flag_parsers() {
  char *args_1[5] = {"hashbat", "hello", "-v", "-o", "stdout"};
  if (!f_verbose(args_1[2]))
    return 1;
  if (f_flag(args_1[1]) || f_flag(args_1[4]))
    return 1;
  if (!f_output(args_1[3]))
    return 1;

  char *args_2[2] = {"hashbat", "-h"};
  if (!f_help(args_2[1]))
    return 1;
  if (f_flag(args_2[0]))
    return 1;

  char *args_3[5] = {"hashbat", "261238937", "-r", "-l", "words_list"};
  if (!f_rainbow(args_3[2]))
    return 1;
  if (!f_list(args_3[3]))
    return 1;
  if (f_flag(args_3[4]) || f_flag(args_3[1]))
    return 1;

  return 0;
}
