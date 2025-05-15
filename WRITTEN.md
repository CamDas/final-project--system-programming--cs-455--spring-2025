# Spring 2025 System Programming — Final Project

## Written Portion

### 1. Describe what happens to memory released by the OS with regard to virtual memory

Addresses are given to virtual memory by the OS, this process of having memory actively being used takes place in RAM. The OS will try to refer to a page in a large enough address space to hole the virtual memory. The OS and CPU will constantly update each other on where they have memory stored and what it is currently doing.

---

### 2. In a C program, why does `argv[argc]` return `NULL`?

argv is an array that holds the actual argument strings and parameters, and argc is the count of the total number of arguments, which must always be at least 1 to be executable and has to end with null. 

---

### 3. When a system call is made the CPU changes from user mode to kernel mode. Why?

To allow the program to access privileged resources and instructions that are not available in user mode, under normal circumstances a person would not just try to make CPU changes so it can be expected that somebody making changes will need this heightened clearance for additional changes.

---

### 4. Explain the relationship between the return value of a system call and the global variable `errno`

Returning 0 usually means a success, anything else is considered a failure. errno gives a certain number (that is not 0) and is used to specify what error has occurred in the program.

---

### 5. Consider the following C program. The variables and functions get allocated to which memory segments? Write your answers in comments to the right of each item

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 128

char my_string[MAX];                        //both are stored in the section of memory that stores char, but only max is declared, which means class_name must be dynamically allocated.
char class_name[] = "System Programming";   
int global_integer = 3;                     // set into memeory that only allows int.
void print_global() {
  printf("%d\n", global_integer);
}

int square(int x) {                         //x is declared but not initialized
  int result = x * x;

  return result;
}

int main (int argc, char *argv[]) {
  char *dynamic_memory;                     //pointer to location in data where it can fit additional info
  dynamic_memory = malloc(MAX);             //tries to locate MAX amounts of bytes to store the data in the char only section of memory
  free(dynamic_memory);                     //returns space back to OS
  dynamic_memory = NULL;                    //set to null, basically destroyed

  return 0;
}
```

---

### 6. Explain the difference between `malloc`, `calloc`, `realloc`

malloc allocates a specified block of memory during runtime. calloc allocates and initializes memory to zero. realloc resizes previously allocated memory instead of asking for additional memory.

---

### 7. Explain the difference between `brk` and `sbrk`. Why is `malloc` a better option of `brk`, and `sbrk`?

sbrk increments the program's data space by increment bytes and returns the previous program break, brk checks for a data segment that is a specified size and will set the last segment to a certain value. Malloc is far more flexible and is able to work if you don't know how much data you need or when you need it.

---

### 8. Explain why a shadow password file is needed

A system file in Linux that stores encrypted passwords and is accessible only to the root user is essential in case of anyone trying to access your info. If you only use a normal password file, it can be accessed by people other than the root user on the machine, and be cracked if given enough type to bypass and give the hash stored in the system to anyone.

---

### 9. What is the numeric equivalent of the `README.md` file’s permission bits below, and what is the command to give the file full access, across the board?

```sh
-rw-r--r-- 1  johnnythunders  staff  3476 May  1 11:57 README.md
```

644 file permission bits. Read is valued at 4, write is valued at 2, and execute is valued at 1. The owner can read and write, and group and other can only read. Command is chmod 777 ~/README.md, assuming the readme is on the desktop

---

### 10. What does `kill -9 1` do? Explain in detail

The initial "kill" is the command for terminating a process, the -9 is what types of processes this command will kill (in this case it is every command that can be killed). The -1 is used to identify the PID of all commands found on a system, meaning that any PID that can be killed will be killed, with no safety bounds to confirm.
