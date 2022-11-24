#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// PROTOTYYPIT
void rivienKysynta(int rivienMaara, int taulukko[5][7]);
void lottoRiviArvonta(int oikeatNumerot[7], int oikeatLisanumerot[3]);
void voittoTarkistus(int oikea[], int lisanumerot[], int numerot[][7]);
// MAIN
int main(void){
    // AJAN NOLLAUS
    srand(time(NULL));

    // TAULUKOT
    int palautettuTaulukko[5][7];
    int oikeatNumerot[7];
    int oikeatLisanumerot[3];

    int rivienMaara = 0;
    printf("Montako riviä haluat syöttää (max 5 riviä) > ");
    scanf("%d", &rivienMaara);

    rivienKysynta(rivienMaara, palautettuTaulukko);
    lottoRiviArvonta(oikeatNumerot, oikeatLisanumerot);
    voittoTarkistus(oikeatNumerot, oikeatLisanumerot, palautettuTaulukko);
}

// Rivienkysyntä ja arpominen
void rivienKysynta(int rivienMaara, int taulukko[5][7]){

    // Tallennetaan manuaalisesti annettavat arvo taulukkoon, JOS arvo rivienmäärässä on suurempi kuin 0
    if(rivienMaara > 0){
    for(int kysynta = 0; kysynta < rivienMaara; kysynta++){
        for(int taltiointi = 0; taltiointi < 7; taltiointi++){
            printf("Anna %d rivin %d. numero > ", kysynta + 1 , taltiointi + 1);
            scanf("%d", &taulukko[kysynta][taltiointi]);
            }
        }
    } // IF END

    // Arvotaan loput rivit, mikäli rivienmäärä on pienempää kuin 5
    if(rivienMaara < 5){
        // ARVONTA
        for(int arvonta = rivienMaara; arvonta < 5; arvonta++){
            // TALLENNUSVAIHE
            for(int taltiointi = 0; taltiointi < 7; taltiointi++){
                // ARVONTA 1 - 40 välille
                int a = (rand() % 40) + 1;
                // PUSKEE ENSIMMÄISEN ARVON
                if(taltiointi == 0){
                    taulukko[arvonta][taltiointi] = a;
                } else {

                    // Tarkistus dubbeja varten
                    for(int tarkistus = taltiointi; tarkistus >= 0; tarkistus--){

                        // Tarkistaa aina kohdasta (taltiointi) alaspäin
                        if(taulukko[arvonta][tarkistus] == a){
                            a = (rand() % 40) + 1;
                            tarkistus = taltiointi;
                        }
                    }
                    taulukko[arvonta][taltiointi] = a;
                }
            }
        }
    } // IF END
    
    printf("\nLottorivit:\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++){
            printf("%3d", taulukko[i][j]);
        }
        printf("\n");
    }
}
// Lottorivin arpominen
void lottoRiviArvonta(int oikeatNumerot[7], int oikeatLisanumerot[3]){

    // Oikeat numerot
    for(int arvonta = 0; arvonta < 7; arvonta++){
        // Arvonta välille 1 - 40
        int arpa = (rand() % 40) + 1;
        if(arvonta == 0){
            oikeatNumerot[arvonta] = arpa;
        } else {
            // Tarkistus
            for(int tarkistus = arvonta; tarkistus >= 0; tarkistus--){
                if(oikeatNumerot[tarkistus] == arpa){
                    arpa = (rand() % 40) + 1;
                    tarkistus = arvonta;
                }
            }
            oikeatNumerot[arvonta] = arpa;
        }
    } // FOR END

    // Lisänumerot
    for(int arvonta = 0; arvonta < 3; arvonta++){
        // Arvonta välille 1 - 40
        int arpa = (rand() % 40) + 1;
        if(arvonta == 0){
            oikeatLisanumerot[arvonta] = arpa;
        } else {
            // Tarkistus
            for(int tarkistus = arvonta; tarkistus >= 0; tarkistus--){
                if(oikeatLisanumerot[tarkistus] == arpa){
                    arpa = (rand() % 40) + 1;
                    tarkistus = arvonta;
                }
            }
            oikeatLisanumerot[arvonta] = arpa;
        }
    } // FOR END

    // TULOSTUS
    printf("\nOikea rivi:");
    for(int i = 0; i < 7; i++){
        printf(" %d", oikeatNumerot[i]);
    }
    printf("   lisänumerot:");
    for(int i = 0; i < 3; i++){
        printf(" %d", oikeatLisanumerot[i]);
    }
    printf("\n");
}
// Voittotarkistus
void voittoTarkistus(int oikeatNumerot[], int oikeatLisanumerot[], int arvatutNumerot[][7]){
    // Tarkistetaan rivi riviltä ja etsitään oikeita numeroita
    for(int rivi = 0; rivi < 5; rivi++){
        int oikein = 0;
        int lisaOikein = 0;

        // Oikein tarkistus
        for(int tarkistus = 0; tarkistus < 7; tarkistus++){
            for(int tarkistus2 = 0; tarkistus2 < 7; tarkistus2++){
                if(arvatutNumerot[rivi][tarkistus] == oikeatNumerot[tarkistus2]){
                    oikein += 1;
                }
            }
        }

        // Lisänumerot
        for(int tarkistus = 0; tarkistus < 3; tarkistus++){
            for(int tarkistus2 = 0; tarkistus2 < 7; tarkistus2++){
                if(oikeatLisanumerot[tarkistus] == arvatutNumerot[rivi][tarkistus2]){
                    lisaOikein += 1;
                }
            }
        }


        printf("\nRivillä %d. on %d oikein ja %d lisänumeroa", rivi + 1, oikein, lisaOikein);
    }
}
