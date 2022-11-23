#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// PROTOTYYPIT
void rivienKysynta(int rivienMaara);
void lottoRiviArvonta(int taulukko[7], int lisanumerot[3]);
void voittoTarkistus(int oikea[], int lisanumerot[], int numerot[][7], int n);
// MAIN
int main(void){
    int rivienMaara = 0;

    printf("Montako riviä haluat syöttää (max 5 riviä) > ");
    scanf("%d",&rivienMaara);

    // Varmistetaan että rivejä on max vain 5
    if(rivienMaara > 5){
        do{
            printf("Max on 5 riviä, kokeile uudelleen > ");
            scanf("%d", &rivienMaara);
        } while(rivienMaara > 5 || rivienMaara < 0);
    }

    rivienKysynta(rivienMaara);
}

// RIVIENKYSYNTÄ
void rivienKysynta(int rivienMaara){
    int taulukko[rivienMaara][7];
    int oikeatnumerot[7];
    int lisanumerot[3];
    // TALLENNUS TAULUKKOON
    for(int i = 0; i < rivienMaara; i++){
        for(int j = 0; j < 7; j++){
            printf("\nAnna %d rivin %d. numero > ", i + 1, j + 1);
            scanf("%d", &taulukko[i][j]);
        }
    }

    printf("\nLottorivit:\n");
    for(int i = 0; i < rivienMaara; i++){
        for(int j = 0; j < 7; j++){
        printf("%d ", taulukko[i][j]);
        }
        printf("\n");
    }

    lottoRiviArvonta(oikeatnumerot, lisanumerot);
    voittoTarkistus(oikeatnumerot, lisanumerot, taulukko, rivienMaara);
}

// LOTTORIVI ARVONTA
void lottoRiviArvonta(int taulukko[7], int lisanumerot[3]){
    srand(time(NULL));
    for(int i = 0; i < 7; i++){
        int a = (rand() % 40) + 1;
        taulukko[i] = a;
    }
    for(int j = 0; j < 3; j++){
        int b = (rand() % 40) + 1;
        lisanumerot[j] = b;
    }
    
    printf("\nOikea rivi:");
    for(int i = 0; i < 7; i++){
        printf(" %d", taulukko[i]);
    }
    printf(" lisänumerot:");
    for(int i = 0; i < 3; i++){
        printf(" %d", lisanumerot[i]);
    }
}

void voittoTarkistus(int oikea[], int lisanumerot[], int numerot[][7], int n){
   // Oikein
    for(int i = 0; i < n; i++){
        int oikeatNumerot = 0;
        int lisanumerotOikein = 0;
        // Oikea
        for(int j = 0; j < 7; j++){
            if(oikea[i] == numerot[i][j]){
                oikeatNumerot += 1;
            }

            for(int x = 0; x < 3; x++){
                if(lisanumerot[x] == numerot[x][j]){
                    lisanumerotOikein += 1;
                }
            }
        }
        printf("\nRivillä %d. on %d oikein ja %d lisanumeroa", i + 1,oikeatNumerot, lisanumerotOikein);
        
    }
}