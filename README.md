# 🖥️ Minishell

Minishell is a simple UNIX shell project implemented in C as part of the 42 curriculum. It replicates the functionality of a basic shell, enabling users to execute commands, handle pipes and redirections, manage environment variables, and more.

---

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Implemented Built-in Commands](#implemented-built-in-commands)
- [Technical Details](#technical-details)
- [Known Issues](#known-issues)
- [Credits](#credits)

---

## Features

Minishell supports the following features:

- **Prompt:** A customizable prompt to accept user input.
- **Command Execution:** Supports execution of binaries in system paths.
- **Built-in Commands:** Implements basic shell built-ins like `cd`, `echo`, `pwd`, etc.
- **Pipes:** Handles multiple pipes (e.g., `ls | grep minishell | wc -l`).
- **Redirections:** Supports input (`<`), output (`>`), and append (`>>`) redirections.
- **Environment Variables:** Export, unset, and substitute environment variables.
- **Signals:** Handles signals like `Ctrl+C`, `Ctrl+D`, and `Ctrl+\` gracefully.
- **Error Handling:** Provides meaningful error messages for invalid inputs and failed commands.
- **Heredoc:** Allows input via heredoc redirection (`<<`).

---

## Installation

### Prerequisites

- A Unix-like operating system (Linux or macOS).
- GCC or Clang compiler.
- Make utility.

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/shokdot/minishell.git
   cd minishell
   ```
2. Configure the project:
   ```bash
   make config
   ```
3. Compile the project:
   ```bash
   make
   ```
4. Run Minishell:
   ```bash
   ./minishell
   ```

---

## Usage

Once the shell is running, you can type commands as you would in a standard shell. Here are some examples:

```bash
$ echo Hello, world!
Hello, world!

$ cd /path/to/directory
$ pwd
/path/to/directory

$ ls | grep minishell
$ cat file.txt > output.txt
$ cat << EOF
> This is heredoc input
> EOF
```

To exit Minishell, type `exit` or press `Ctrl+D`.

---

## Implemented Built-in Commands

- **`echo`**: Prints arguments to standard output.
- **`cd`**: Changes the current working directory.
- **`pwd`**: Prints the current working directory.
- **`export`**: Sets environment variables.
- **`unset`**: Removes environment variables.
- **`env`**: Displays all environment variables.
- **`exit`**: Exits the shell.

---

## Technical Details

- **Parser:** Tokenizes and analyzes the input to detect commands, arguments, and operators like pipes or redirections.
- **Executor:** Executes commands using `fork`, `execve`, and `wait`.
- **Signal Handling:** Custom handlers for `SIGINT`, `SIGQUIT`, and `SIGTERM`.
- **Memory Management:** Ensures proper cleanup of allocated memory to prevent leaks.
- **Environment Management:** Tracks and updates environment variables internally.

---

## Known Issues

- Does not support wildcard expansion (e.g., `*.c`).
- Limited error handling for deeply nested pipes and redirections.
- Heredoc functionality may fail with large inputs due to memory constraints.

---

## Credits

Minishell was developed by healeksa and tyavroya as part of the 42 curriculum.

Special thanks to the 42 Network and its community for guidance and support.

