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
#define F_OUTPUT_S "-o"
#define F_OUTPUT_L "--output"
#define F_LIST_S "-l"
#define F_LIST_L "--list"
#define F_RAINBOW_S "-r"
#define F_RAINBOW_L "--rainbow"

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

/**
 * @brief Is the string provided a output flag.
 * @param str Argument.
 * @return Is output flag
 */
bool f_output(char *str);

/**
 * @brief Is the string provided a list flag.
 * @param str Argument.
 * @return Is list flag
 */
bool f_list(char *str);

/**
 * @brief Is the string provided a rainbow flag.
 * @param str Argument.
 * @return Is rainbow flag
 */
bool f_rainbow(char *str);

#endif
