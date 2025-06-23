# S-havlShell (personal project)

This is a personal project to build a simple shell in C from scratch.

## Status
In development, for personal use.

## Goal

Learn how a shell works at a low level using C.  
I want to understand and practice the following concepts:

- Creating and managing processes (`fork`, `exec`)
- Reading commands from the terminal
- Handling signals (like Ctrl+C)
- Basic structure of a command-line interpreter
- Standard input/output
- Redirections (later)
- Pipes and chained command execution (later)
- How to build my own tools from scratch

## How to run it

```bash
gcc src/main.c -o mysh
./mysh
