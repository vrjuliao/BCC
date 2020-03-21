#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]){

    char *a = "\0\0\0blabla\0";
    printf("%s\nstrlen: %zd", a, strlen(a));
    return 0;
}