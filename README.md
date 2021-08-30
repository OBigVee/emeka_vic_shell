# A simple C shell project
Write a simple UNIX command interpreter
## Description
this project is a simple UNIX command interpreter that replicates functionalities of the shell. However, the whole of this project is written in the C programming language for ALx Holberton Software Engineering School

## Synopsis:
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell
Who invented the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How does a shell work
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?

## Description:
Task 0:
Write a README
Write a man for your shell.
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format,

Task 1:
Write a beautiful code that passes the Betty checks

Task 2:
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments

Task 3:
Handle command lines with arguments

Task 4:
Simple shell 0.2 +

Handle the PATH
fork must not be called if the command doesn’t exist

Task 5:
Simple shell 0.3 +

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

Task 6:
Simple shell 0.4 +

Implement the env built-in, that prints the current environment

Task 7:
Write a blog post describing step by step what happens when you type ls -l *.c and hit Enter in a shell. Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed. You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).

Have at least one picture, at the top of the blog post
Publish your blog post on Medium or LinkedIn
Share your blog post at least on LinkedIn
Only one blog post by team
The blog post must be done and published before the first deadline (it will be part of the manual review)
Please, remember that these blogs must be written in English to further your technical ability in a variety of settings
When done, please add all urls below (blog post, LinkedIn post, etc.)
[Medium blog post](https://medium.com/@victor-ade/the-mystery-of-how-shell-commands-works-854ff7a66a99#4c16-da2e20923a4)


## Examples:

## Author:
The author of this project can be found in the AUTHORS file of this project.

## Features:
 1. can work in interactive mode
 2. can also work in non-interactive mode

## Copyright:
