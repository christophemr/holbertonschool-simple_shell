# Simple Shell README

This Simple Shell implementation provides basic functionality for executing commands, including support for absolute and relative paths, as well as commands available in the system's PATH. The shell also handles tokenization of user input and supports the "exit" command for quitting the shell.

## Table of Contents

1. [Features](#features)
2. [Usage](#usage)
3. [File Descriptions](#file-descriptions)
4. [Dependencies](#dependencies)
5. [Contributing](#contributing)
6. [Authors](#Authors)
6. [License](#license)

## Features

- **Command Execution:** The shell can execute commands entered by the user.
- **Path Resolution:** Handles both absolute and relative paths for command execution.
- **PATH Lookup:** Searches the system's PATH environment variable for command execution.
- **Tokenization:** Parses user input into tokens for command execution.
- **Exit Command:** Supports the "exit" command to terminate the shell.

## Usage

1. **Compilation:**
Compiled using GCC.
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

2. **Running the Shell:**
   - Run the compiled shell executable: `./hsh`

3. **Using the Shell:**
   - The shell prompt will be displayed as "Perfect Shell."
   - Enter commands as you would in a regular shell.
   - Syntax : ```bash command {argument}```
   - Use the "exit" command  or <kbd>ctrl</kbd> + <kbd>D</kbd> to terminate the shell.

## Example
```bash
	$ ./hsh
	$ ls
	get_path.c parse_input.c run_command.c shell_header.h super_simple_shell.c user_input.c
	$
```

## File Descriptions

- **super_simple_shell.c:** Contains the main logic for the shell, including the main function.
- **shell_header.h:** Header file with function declarations and necessary includes.
- **README.md:** This file, providing information about the shell.
- **user_input.c:** Contains the function to retrieve userinput,either from terminal or script.
- **parse_input.c:** Contains the function to process and tokenize the input.
- **get_path.c:** Contains the function to get the environment PATH and search the token in it.
- **run_command.c** Contains the function that execute the program found at the path given.


## Dependencies

The shell has been implemented using standard C libraries and system calls. No external dependencies are required.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

## Authors
[Christophe "Craig" Marie-Reine](https://github.com/christophemr)
[Nicolas Taillpierre](https://github.com/TaillepierreN)

## License

This Simple Shell is licensed under the [MIT License](LICENSE). Feel free to use and modify it as needed.