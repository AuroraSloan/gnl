#!bin/bash/
BUFF=32

case ${1} in
    "-f")	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$BUFF get_next_line.c get_next_line_utils.c lblmain.c -o gnl 
        ;;
    *)		gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$BUFF get_next_line.c get_next_line_utils.c fbfmain.c -o gnl 
esac
