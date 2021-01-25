#include "get_next_line.h"
#include "libc.h"

int main() {

    char *result = NULL;
    // lire entrée standard avec get_next_line
    while (get_next_line(0, &result))
    {
    printf("%s", result);
    printf("%s", "\n");
    free(result); 
    }
    // recommencer
    // a l'infini
    return 0;
}

/* 
    terminal onglet 1
    /dev/rnd > ./a.out

    terminal onglet 2
    htop
 */

/*
	terminal onglet 1
	cat /dev/random | ./a.out

	terminal onglet 2
	top -pid ...
*/
