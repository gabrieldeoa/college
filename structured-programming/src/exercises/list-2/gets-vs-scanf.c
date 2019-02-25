#include <stdio.h>
#include <stdlib.h>

main () {
    char * nomeGets;
    char * nomeScanf;
    nomeGets = (char*)malloc(sizeof(char));
    nomeScanf = (char*)malloc(sizeof(char));

    printf("Digite seu nome:\n");
    scanf("%s", nomeScanf);
    gets(nomeGets);

    printf("\nSeu nome é %s... utilizando scanf", nomeScanf);
    printf("\nSeu nome é %s... utilizando gets", nomeGets);

}

