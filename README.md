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


## 🏁 Getting Started <a name = "getting_started"></a>

- `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl && ./gnl`

Compiling GNL with a minimalist main with the above command will start reading from the standard input of the current terminal, each `enter` will return from the get_next_line function with the return value displayed between `[]`
To end this, `EOF` can be enter with `ctrl + D`

Alternatively, stdin can be filled using pipes: `echo hello '\n' bye | ./gnl`

## 📌 Projet's details <a name = "details"></a>

- Calling get_next_line function in a loop will allow to read the text
available on a file descriptor one line at a time until the EOF.
- It reads from the standard input or from a file.
- libft is not allowed for this project. File `get_next_line_utils.c` contains the functions that are needed for your get_next_line to work.
- Your program compiles with the flag -D BUFFER_SIZE=xx. which will be used as the buffer size for the read calls get_next_line.

## 🍬 Bonus part <a name = "bonus"></a>

- Extra difficulty: use of a single static variable.
- Manages multipe file descriptor at the time. For example, if the file descriptors 3, 4 and 5 are accessible for reading, calling get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without
losing the reading thread on each of the descriptors.