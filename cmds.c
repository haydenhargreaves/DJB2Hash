/****************************************************************
 * File:    cmds.c
 * Author:  Group 6: CS125
 * Purpose: Implementation of the command module.
 * Date:    4/13/2025
 ***************************************************************/

#include "include/cmds.h"
#include "include/cli.h"
#include "include/io.h"
#include <stdio.h>

int cmd_hash_string(char *str, char *output, bool verbose) {
  /* Generate the hash */
  uint32_t hash = djb2(str);

  /* Get the output location */
  FILE *f_out = get_output_file(output);

  /* If verbose, print it, otherwise, nothing */
  if ((f_out == stdout || f_out == stderr)) {
    if (verbose)
      fprintf(f_out, "%d\n", hash);
  } else {
    /* If its a file, print always */
    fprintf(f_out, "%d\n", hash);
  }

  fclose(f_out);

  return 0;
}

int cmd_rainbow_lookup(char *str, char *list, char *output, bool versbose) {
  errno = 0;

  /* Convert the hash to a valid hash */
  char *p_end;
  unsigned long temp_hash_ul = strtoul(str, &p_end, 10);

  /* Check for errors */
  if ((p_end == str || *p_end != '\0') ||
      (errno == ERANGE || temp_hash_ul > UINT32_MAX) || (strlen(str) > 10)) {
    fprintf(stderr, "Invalid usage. Please provide a valid hash.\n%s",
            HELP_MSG);
    return 1;
  }

  /*
   * The code above is pretty silly, but it seems to be the easiest way to
   * ensure the hash provided is within the valid bounds of an unsigned int
   * (which is the size of the numeric hashes).
   */
  uint32_t hash = (uint32_t)temp_hash_ul;

  /* Open the words list file */
  FILE *f_list = fopen(list, "r");
  if (f_list == NULL) {
    fprintf(stderr, "Invalid usage. Please provide a valid file path.\n%s",
            HELP_MSG);
    return 1;
  }

  /* If everything went well, search for the word in the list */
  char *match = find_word_by_hash(f_list, hash);
  fclose(f_list);

  /* Get the output location */
  FILE *f_out = get_output_file(output);

  /* If verbose, print it, otherwise, nothing */
  if ((f_out == stdout || f_out == stderr)) {
    if (versbose) {
      if (match == NULL) {
        fprintf(f_out, "No match found.\n");
        fclose(f_out);
        return 1;
      }
      fprintf(f_out, "%s\n", match);
    }
  } else {
    if (match == NULL) {
      fprintf(f_out, "No match found.\n");
      fclose(f_out);
      return 1;
    }
    fprintf(f_out, "%s\n", match);
  }

  fclose(f_out);

  if (match == NULL)
    return 1;
  return 0;
}

int cmd_help() {
  fprintf(stdout, "%s", HELP_MSG);
  return 0;
}
