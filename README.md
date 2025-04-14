# Hashbat: CS125 Final Spring 2025

<!--toc:start-->
- [Hashbat: CS125 Final Spring 2025](#hashbat-cs125-final-spring-2025)
  - [Description](#description)
  - [Features](#features)
  - [Usage](#usage)
    - [Arguments](#arguments)
    - [Options](#options)
    - [Commands](#commands)
  - [Examples](#examples)
  - [Exit Status](#exit-status)
  - [Installation](#installation)
  - [Hash Algorithm](#hash-algorithm)
  - [Wordlist for Rainbow Tables](#wordlist-for-rainbow-tables)
<!--toc:end-->

## Description

Hashbat is a command-line tool that calculates the hash of input strings. It also features a "rainbow table" lookup feature to attempt to reverse hashes, given a wordlist.

## Features

* **Hashing:** Calculates the hash of input strings.
* **Rainbow Table Lookup:** Attempts to find the original string from a hash using a provided wordlist.
* **Output Options:**
    * Prints the hash to standard output.
    * Option to specify an output file.
* **Verbose Output:** Prints the result of the operation to the output.
* **Help Message:** Displays usage instructions.

## Usage

```bash
hashbat [OPTIONS] [INPUT]
```

### Arguments

* `[INPUT]`...: One or more input strings to hash.

### Options

* `-v`, `--verbose`:  Print the result of the operation to the output.
    * Without this, nothing will be printed to the output.
* `-h`, `--help`:     Prints this help message.
    * Verbose flag is NOT required for the help command.
* `-o`, `--output <output>`:
    * Specifies the location to print the output.
    * Use `stdout` for standard output.
* `-r`, `--rainbow`:
    * Enables rainbow table lookup (de-hashing).
    * Requires a wordlist file provided with the `-l` option.
* `-l`, `--list <word_list>`:
    * Specifies the path to a wordlist file.
    * Required when using the `--rainbow` option.

### Commands

* `hash`:  Calculates the hash of the input string.  (This is the default behavior when no command is given.)
* `rainbow`: Performs a rainbow table lookup to find the original string from a hash.
* `help`: Displays the help message.

## Examples

1.  **Hash a string and print to standard output:**

    ```bash
    hashbat -v "hello world"
    ```

2.  **Hash a string and save the output to a file:**

    ```bash
    hashbat -v -o output.txt "hello world"
    ```

3.  **Perform a rainbow table lookup:**

    ```bash
    hashbat -v -r -l wordlist.txt "e5e9fa1ba31ecd1ae84f75caaa474f3a6639c08b"
    ```

4.  **Display the help message:**

    ```bash
    hashbat -h
    ```
    or
    ```bash
    hashbat --help
    ```

##  Exit Status

The program returns an exit status code to indicate success or failure.  (The specific codes and their meanings are not in the provided code, but it's good to document them here if you have that information.)  Common conventions are:
* 0: Success
* Non-zero: Failure

## Installation

(Provide instructions on how to compile and install your application.  Since this is C code, it likely involves using a compiler like GCC and a build system (like make).  Here's a general example; adapt it to your specific build process.)

1.  **Clone the repository:**

    ```bash
    git clone <your_repository_url>
    cd hashbat
    ```

2.  **Compile the code:**

    ```bash
    make
    ```

## Hash Algorithm

Hashbat uses the DJB2 hashing algorithm.

The DJB2 algorithm is a popular and relatively simple hashing algorithm developed by Daniel J. Bernstein. It's known for its good distribution of hash values and reasonable speed.  Here's a basic explanation of how it works:

1.  **Initialization:** A hash variable (typically a 32-bit unsigned integer) is initialized to a starting value (often 5381).

2.  **Iteration:** The algorithm iterates through each character in the input string.

3.  **Hash Calculation:** For each character, the hash value is updated using the following formula:
    `hash = hash * 33 + character`

4.  **Result:** After processing all characters, the final hash value is the result.

The multiplication by 33 and the addition of the character cause the hash value to change in a way that depends on all the characters in the string, resulting in a seemingly random distribution of output values.

## Wordlist for Rainbow Tables

For the rainbow table lookup functionality (`-r` option), you'll need a wordlist file. This file should contain a list of potential words or strings, one per line, that you expect to find when reversing hashes. The effectiveness of the rainbow table lookup depends heavily on the quality and comprehensiveness of this wordlist.
