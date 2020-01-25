# TEST

## Tools & Instructions

- gcc pipe.c -o pipe => results in an pipe.out file
- objdump -d pipe => disassemble the code


## The more you know

### exec 

> Most of the exec() functions expect a pathname as the specification of the new program to be loaded. However, execlp() and execvp() allow the program to be specified using just a filename. The filename is sought in the list of directories specified in the PATH environment variable (explained in more detail below). This is the kind of searching that the shell performs when given a command name. To indicate this difference in operation, the names of these functions contain the letter p (for PATH). The PATH variable is not used if the filename contains a slash (/), in which case it is treated as a relative or absolute pathname.

> Instead of using an array to specify the argv list for the new program, execle(), execlp(), and execl() require the programmer to specify the arguments as a list of strings within the call. The first of these arguments corresponds to argv[0] in the main function of the new program, and is thus typically the same as the filename argument or the basename component of the pathname argument. A NULL pointer must terminate the argument list, so that these calls can locate the end of the list. (This requirement is indicated by the commented (char *) NULL in the above prototypes; for a discussion of why the cast is required before the NULL, see Appendix C.) The names of these functions contain the letter l (for list) to distinguish them from those functions requiring the argument list as a NULLterminated array. The names of the functions that require the argument list as an array (execve(), execvp(), and execv()) contain the letter v (for vector).

Program Execution:
> The execve() and execle() functions allow the programmer to explicitly specify the environment for the new program using envp, a NULL-terminated array of pointers to character strings. The names of these functions end with the letter e (for environment) to indicate this fact. All of the other exec() functions use the caller’s existing environment (i.e., the contents of environ) as the environment for the new program.

> Version 2.11 of glibc added a nonstandard function, execvpe(file, argv, envp). This function is like execvp(), but instead of taking the environment for the new program from environ, the caller specifies the new environment via the envp argument (like execve() and execle()).


from p. 567 from the Linux Programming Interface :D
