# rksh

**rksh** is a simple Unix shell implemented in C, inspired by the [lsh](https://github.com/brenns10/lsh) project. This project serves as an educational tool to understand the fundamentals of shell development, including system calls, command parsing and execution.

## Features

- **Command Execution**: Executes system commands with arguments.
- **Built-in Commands**: Supports `cd`, `help`, and `exit` commands.
- **Command Parsing**: Handles parsing of user input into commands and arguments. Supports quoting (double quoting) and backslash escaping.

## Getting Started

### Prerequisites

- GCC compiler
- Make utility

### Installation

1. **Clone the repository**:

   ```bash
   git clone https://github.com/RohanKaran/rksh.git
   cd rksh
   ```

2. **Build the shell**:

   ```bash
   make
   ```

3. **Run the shell**:

   ```bash
   ./build/rksh
   ```

## Usage

- **Executing Commands**: Type any valid Unix command and press Enter.
- **Help**: Type `help` to display built-in commands.
- **Exit**: Type `exit` to quit the shell.

## Acknowledgements

This project is inspired by Stephen Brennan's [Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/) tutorial and the [lsh](https://github.com/brenns10/lsh) project.

## License

This project is licensed under the [Apache License 2.0](https://github.com/RohanKaran/rksh/blob/main/LICENSE).