# Minishell
Minishell is that involves creating a simple command-line shell program that can execute basic Unix commands. The program should support standard input/output redirection, environment variables, and signals.

## How to Use
To use the Minishell program, you need to follow these steps:

+ Download or clone the Minishell repository from GitHub.
+ Compile the program by running make in the root directory of the repository.
+ Start the program by running ./minishell.
+ The program will start, and you can type in commands to execute.
+ The program supports various built-in commands like cd, echo, export, env, pwd, and unset.
+ You can use pipes to connect multiple commands together. To use a pipe, you need to use the | symbol. For example, to pipe the output of one command to another, you can type command1 | command2.
+ The Minishell program supports multiple pipes as well. For example, to pipe the output of one command to two other commands, you can type command1 | command2 | command3.
+ You can also execute external commands by typing in the command name and its arguments. For example ls, pwd, wc.

The Minishell program uses the standard Unix system calls to execute commands and manage processes. It supports standard input/output redirection using the < and > symbols, environment variables using the $ symbol, and signals like ctrl-C and ctrl-D.

## Conclusion
The Minishell project is an excellent way to learn about command-line shell programming and process management in Unix. By implementing this program, you will gain experience with system calls, signals, and shell scripting.

<img width=700px height= 700px src="https://github.com/egulerr/Minishell/blob/master/minishell_readme_img.png"/>
