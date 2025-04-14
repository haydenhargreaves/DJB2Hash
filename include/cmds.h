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

#define HELP_MSG "This is the help menu!\nWith many lines\n"

/**
 * @brief Execute the hash command.
 * @param str String to hash.
 * @param verbose Is verbose flag.
 * @return Main program exit status code.
 */
int cmd_hash_string(char *str, bool verbose);

#endif
