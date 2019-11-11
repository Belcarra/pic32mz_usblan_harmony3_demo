
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void usage(const char * msg) {
    fprintf(stderr, "Usage: sh -c 'args'\r\n");
    fprintf(stderr, "%s\r\n", msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    char *cp;
    int i;
#if 0
    fprintf(stderr, "argc: %d\r\n", argc);
    for (i = 0; i < argc; i++) {
	fprintf(stderr, "[%d] %s\r\n", i, argv[i]);
    }
#endif

    cp = argv[2];
    if (strncmp(cp, "./", 2) == 0) cp += 2; 
    argv[2] = cp;

//    fprintf(stderr, "CALLING %s\r\n", cp);


    fprintf(stderr, "Windows fakesh exec: ");
    for (i = 2; i < argc; i++) {
	fprintf(stderr, "%s ", argv[i]);
    }
    fprintf(stderr, "\r\n");

    system(cp);
//    _execv(cp, (const char *const*)&argv[2]);
//    fprintf(stderr, "errno: %d\r\n", errno);

}

