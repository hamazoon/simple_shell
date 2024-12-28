# simple_shell

This repository contains a custom implementation of a simple UNIX shell. The project is developed as part of the ALX Software Engineering program to deepen the understanding of how shells work and how commands are executed in a UNIX-like operating system.

---

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [Usage](#usage)
- [Examples](#examples)
- [Compilation](#compilation)
- [Testing](#testing)
- [Author](#author)

---

## Introduction

A shell is a command-line interpreter that provides a user interface for the UNIX operating system. It processes user commands, executes them, and handles input and output redirection. This project replicates the basic functionality of a shell, demonstrating the underlying concepts of process management, system calls, and I/O streams.

---

## Features

- Displays a command prompt (`$ `).
- Executes commands with arguments (e.g., `ls -l`).
- Implements built-in commands:
  - `exit`: Exits the shell.
  - `env`: Prints the environment variables.
- Handles basic command errors gracefully.
- Supports input redirection via pipes.
- Works in both interactive and non-interactive modes.

---

## Project Structure

### Files

- **`main.c`**: Entry point of the shell. Handles the main loop and user input.
- **`shell.h`**: Header file containing function prototypes and global definitions.
- **`execute.c`**: Handles command execution and child process creation.
- **`builtins.c`**: Implements built-in commands like `env` and `exit`.
- **`utils.c`**: Helper functions for string manipulation and memory management.
- **`env.c`**: Functions to handle environment variables.
- **`man_1_simple_shell`**: Manual page for the custom shell.

---

## How It Works

1. **Initialization**  
   The shell initializes and displays a prompt (`$ `).

2. **Command Parsing**  
   User input is read and parsed into tokens using delimiters like spaces.

3. **Command Execution**  
   The shell searches for the command in the system's PATH and creates a child process to execute it.

4. **Loop**  
   The shell continues to run in a loop until the `exit` command is issued or EOF is reached in non-interactive mode.

---

## Usage

### Interactive Mode

```bash
$ ./hsh
$ ls -l
drwxr-xr-x 2 user user 4096 Jul 10 12:00 directory
$ exit

