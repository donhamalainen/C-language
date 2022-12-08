#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>


// PROTOTYYPIT
void lueRoskat();
void generointi(int maara, char verbit[5][100], char substantiivit[5][100]);


// PÄÄOHJELMA
int main(void){
    char substantiivi[5][100];
    char verbi[5][100];
    int maara = 0;
    for(int i = 0; i < 5; i++){
        printf("Anna substantiivi (max 100 merkkia) > ");
        scanf("%s", substantiivi[i]);
        lueRoskat();
        printf("Anna verbi (max 100 merkkia > ");
        scanf("%s", verbi[i]);
        lueRoskat();
    }
    printf("\nMontako puppulausetta generoidaan > ");
    scanf("%d", &maara);

    generointi(maara, verbi, substantiivi);
}

// GENEROINTI
void generointi(int maara, char verbit[5][100], char substantiivit[5][100]){
    /*
    for(int i = 0; i < 5; i++){
        printf("%s %s\n", substantiivit[i], verbit[i]);
    }
    */
    srand(time(NULL));
    char puppulauseet[maara][100];
    char subSana[2][100]; 
    char verbiSana[2][100];
    int random_muoto;
    int verbiArvonta, substantiiviArvonta;

    printf("---Puppulauseet---\n");
    for(int i = 0; i < maara; i++){
        // Arvonta
        random_muoto = rand() % 4;
        verbiArvonta = rand() % 5;
        substantiiviArvonta = rand() % 5;
        
        if(random_muoto == 0){
            strcpy(subSana[i],substantiivit[substantiiviArvonta]);
            strcpy(verbiSana[i], verbit[verbiArvonta]);
            subSana[i][0] = toupper(subSana[i][0]);
            printf("\n%s %s.", subSana[i], verbit[i]);
            lueRoskat();
        } else if(random_muoto == 1){
            for (int x = 0; x < 2; x++){
            strcpy(subSana[x],substantiivit[substantiiviArvonta]);
            strcpy(verbiSana[x], verbit[verbiArvonta]);
            verbiArvonta = rand() % 5;
            substantiiviArvonta = rand() % 5;
            subSana[0][0] = toupper(subSana[0][0]);
            if(x == 1){
                printf("\n%s %s ja %s %s", subSana[x-1], verbiSana[x-1], subSana[x], verbiSana[x]);
            }
            }
        } else if(random_muoto == 2){
            for (int x = 0; x < 2; x++){
            strcpy(subSana[x],substantiivit[substantiiviArvonta]);
            strcpy(verbiSana[x], verbit[verbiArvonta]);
            verbiArvonta = rand() % 5;
            substantiiviArvonta = rand() % 5;
            subSana[0][0] = toupper(subSana[0][0]);
            if(x == 1){
                printf("\n%s %s tai %s %s", subSana[x-1], verbiSana[x-1], subSana[x], verbiSana[x]);
            }
            }
        } else {
            for (int x = 0; x < 2; x++){
            strcpy(subSana[x],substantiivit[substantiiviArvonta]);
            strcpy(verbiSana[x], verbit[verbiArvonta]);
            verbiArvonta = rand() % 5;
            substantiiviArvonta = rand() % 5;
            subSana[0][0] = toupper(subSana[0][0]);
            if(x == 1){
                printf("\nJos %s %s ,niin %s %s", subSana[x-1], verbiSana[x-1], subSana[x], verbiSana[x]);
            }
            }
        }
    }
}

// PUSKURIN TYHJENNYS
void lueRoskat(){
    while(fgetc(stdin) != '\n');
}



/*
Ohjelma tuottaa käyttäjän haluaman määrän innovatiivisia puppulauseita ja tulostaa ne näytölle. Lauseet muodostuvat satunnaisesti substantiivi-verbi pareista. Lauseet voivat olla neljää eri muotoa, jotka ovat yhtä todennäköisiä.

1. peruslause, esimerkkinä: Kissa lentää.
2. ja-konnektiivilla saatu yhdistetty lause, esimerkkinä: Ovi soi ja kissa nousee. 
3. tai-konnektiivilla saatu yhdistetty lause, esimerkkinä: Kello soi tai lintu soi. 
4. implikatiivinen jos --- niin lause, esimerkkinä: Jos aurinko lentää, niin kello aukeaa. 
*/