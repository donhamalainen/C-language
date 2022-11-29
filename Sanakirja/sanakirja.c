#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200
int main (void)
{
    FILE *tiedosto;
    int i = 0;  
    char kaanna[100];
    char rivi[MAX];
    char *x;
    char *sana;
    printf("Syötä sana > ");
    scanf("%s", kaanna);

    tiedosto = fopen("lunttilappu.txt", "r");
    // Tarkistaa avautuuko tekstitiedosto
    while (tiedosto == NULL){
        printf("Virhe tiedoston avaamisessa");
        exit(EXIT_FAILURE);
    }

    while(fgets(rivi, MAX, tiedosto))
    {
        x = strstr(rivi, kaanna);
        if(x != NULL)
        {
            i = 1;
            break;
        }
    }
    fclose(tiedosto);

    sana = strtok(rivi, ";");
    sana = strtok(NULL, ";");

    if(i == 1)
    {
        if(strcmp(kaanna, rivi) == 0)
        {
            printf("%s", sana);
        }
        else
            printf("%s", rivi);
    }
    if(i == 0)
    {
        printf("Sanaa %s ei loytynyt sanakirjasta", kaanna);
    }
}