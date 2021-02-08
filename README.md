# gnl
This program reads from a file (or stdin) line by line and prints to the screen. It will return 1 when a line has been successfully read, 0 if the end of file has been reached, and -1 if there was an error.

Global variables were not allowed for this project. The only functions allowed were read, malloc, and free. Buffer size is defined during compilation and can be set to any number from 0 to INT_MAX.

Standard library functions were recoded and modified for this project.

### Installation
```bash
https://github.com/AuroraSloan/gnl.git
```

### Usage
First, run the comp2.sh file.
```bash
bash comp.sh
```

next simply use the executable gnl along with the file/s you want to read.
```bash
./gnl a.txt
```
or
```bash
./gnl a.txt b.txt
```
If more than one file is to be read, the program will automatically read only the first line from each file at a time.<br>If you would like to read a whole file at a time, open the .sh file and change ```lblmain.c``` to ```fbfmain.c```.

To change the buffer size, open the .sh file and change the number in ```BUFFER_SIZE=32``` to any number 0 to 2147483647.

If no file is specified, the program will begin to read from stdin. Type Ctrl + d to signal the end of file.
