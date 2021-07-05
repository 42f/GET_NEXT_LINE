# GET_NEXT_LINE
École 42's project in C. Read line by line from the standard input, with a few contraints. 


---

## 👩‍💻 Usage <a name = "usage"></a>

Function prototype:
- `int		get_next_line(int fd, char **line)`
with `fd` for a file descriptor to be read from and `line` a pointer to the memory location where to store the output line.

Return value are :
- `1` : A line has been read
- `0` : EOF has been reached
- `-1` : An error happened


- Calling get_next_line function in a loop will allow to read the text
available on a file descriptor one line at a time until the EOF.
- It reads from the standard input or from a file.
- libft is not allowed for this project. File `get_next_line_utils.c` contains the functions that are needed for your get_next_line to work.
- Your program compiles with the flag -D BUFFER_SIZE=xx. which will be used as the buffer size for the read calls get_next_line.

## 🏁 Getting Started <a name = "getting_started"></a>

- `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl && ./gnl`
Compiling GNL with a minimalist main with the above command will start reading from the standard input of the current terminal, each `enter` will return from the get_next_line function with the return value displayed between `[]`
To end this, `EOF` can be enter with `ctrl + D`
Alternatively, stdin can be filled using pipes: `echo hello '\n' bye | ./gnl`
