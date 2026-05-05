*This project has been created as part of the 42 curriculum by gigarcia.*

# get_next_line

## Description
The **Get Next Line (GNL)** project is which its primary goal is to write a function that reads a file descriptor line by line, regardless of the size of the buffer used for reading. 

This project introduces a crucial concept: **Static Variables**. Since the function is called repeatedly to read subsequent lines, it must "remember" the leftover text from previous reads that didn't form a complete line. 

**Bonus Part:**
This project includes the implementation of the bonus requirements. The function is capable of managing multiple file descriptors simultaneously without losing the reading thread of any of them, all while using only **one single static variable**.

## Instructions

### Compilation
The project requires you to compile the source files alongside your main program. A macro `BUFFER_SIZE` must be defined during compilation to determine how many bytes the `read()` function will fetch at once.

To compile your code with the `get_next_line` function, use the following syntax:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.h get_next_line.c get_next_line_utils.c
````

And to compile the bonus part, we must use the following command:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_bonus.h get_next_line_utils_bonus.c
```

## Resources
### Documentation & References

- https://man7.org/linux/man-pages/man2/read.2.html
- https://man7.org/linux/man-pages/man2/open.2.html
- https://man7.org/linux/man-pages/man3/malloc.3.html
- https://en.wikipedia.org/wiki/File_descriptor
- https://en.wikipedia.org/wiki/Input/output

### Learning Materials
- 42 Intra subject and guidelines
- Various C programming resources on memory management and string handling
AI Usage

## AI Usage:

- Clarifying concepts related to file descriptors and buffering
- Reviewing and improving code structure
- Debugging edge cases and memory leaks
- Assistance in structuring this README file

*All core logic, implementation, and design decisions were developed and validated independently.*
