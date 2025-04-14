/****************************************************************
 * File:    cli.h
 * Author:  Group 6: CS125
 * Purpose: Definition of the command line interface.
 * Date:    4/13/2025
 ***************************************************************/

#ifndef CLI_H
#define CLI_H

#include "cmds.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define F_VERBOSE_S "-v"
#define F_VERBOSE_L "--verbose"
#define F_HELP_S "-h"
#define F_HELP_L "--help"

/**
 * @brief Parse the command line arguments.
 * @param args Arguments passed to program.
 * @param len Number of argumentsk
 * @return Return code for the program.
 * @note This function will handle the main loop and calling of
 * other functions.
 */
int parse_arguments(char **args, int len);

/**
 * @brief Is the string provided a verbose flag.
 * @param str Argument.
 * @return Is verbose flag
 */
bool f_verbose(char *str);

/**
 * @brief Is the string provided a help flag.
 * @param str Argument.
 * @return Is help flag
 */
bool f_help(char *str);

#endif
