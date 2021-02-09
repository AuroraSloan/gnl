# gnl
This program reads from a file (or stdin) line by line and prints to the screen. <br>It will return 1 when a line has been successfully read, 0 if the end of file has been reached, and -1 if there was an error.

Global variables were not allowed for the get_next_line function portion of this project.<br>The only functions allowed were read, malloc, and free.

Buffer size is defined during compilation and can be set to any number from 1 to INT_MAX.

Standard library functions were recoded and modified for this project.

----
### Installation
```bash
https://github.com/AuroraSloan/gnl.git
```

### Usage
First, run the comp.sh file.
```bash
bash comp.sh
```
The program will automatically read the whole file before moving to the next file.<br>If you want to read one line at a time from each file, run the comp.sh file with -ll.
```bash
bash comp.sh -ll
```
next simply use the executable gnl along with the file/s you want to read.
```bash
./gnl a.txt
```
or
```bash
./gnl a.txt b.txt
```
If no file is specified, the program will begin to read from stdin. Type Ctrl + d to signal the end of file.

To change the buffer size, open the .sh file and change the number in ```BUFF=32``` to any number 1 to 2147483647.

#### Coming soon...
Ability to choose which line will be read from a file.
