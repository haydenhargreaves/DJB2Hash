/****************************************************************
 * File:    cmds.h
 * Author:  Group 6: CS125
 * Purpose: Definition of the command module.
 * Date:    4/13/2025
 ***************************************************************/

#ifndef CMDS_H
#define CMDS_H

#include "hash.h"
#include <stdbool.h>
#include <stdio.h>

#define HELP_MSG                                                               \
  "Usage: hashbat [OPTIONS] [INPUT]\n"                                         \
  "       hashbat <COMMAND>\n"                                                 \
  "\nArguments:\n"                                                             \
  " [INPUT]... Input string(s) to hash.\n"                                     \
  "\nOptions:\n"                                                               \
  " -v, --versbose\n"                                                          \
  "\tPrint the result of the operation to the output.\n"                       \
  " -h, --help\n"                                                              \
  "\tPrints this message.\n"                                                   \
  " -o, --output <output>\n"                                                   \
  "\tLocation to print the output, use 'stdout' for standard out\n"            \
  " -r, --rainbow\n"                                                           \
  "\tUse a words list to attempt to de-hash a hash. A list must be provided\n" \
  " -l, --list <word_list>\n"                                                  \
  "\tPath to a words list. Used when the 'rainbow' flag is provided\n"

/**
 * @brief Execute the hash command.
 * @param str String to hash.
 * @param verbose Is verbose flag.
 * @return Main program exit status code.
 */
int cmd_hash_string(char *str, bool verbose);

/**
 * @brief Execute the help command.
 * @return Main program exit status code.
 */
int cmd_help();

#endif
