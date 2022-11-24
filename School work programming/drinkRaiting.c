#include <stdio.h>

int main(void){
    int arvosanat[4][20];
    int keskiarvo[4];
    // JUOMIEN FOR LOOP
    for(int i = 0; i < 4; i++){
        printf("Anna juoma numero %d. pisteet\n", i + 1);
        // ARVOSANOJEN FOR LOOP
        for(int j = 0; j < 10; j++){
            printf("Anna arvosana (1-5) > ");
            scanf("%d", &arvosanat[i][j] );
            if(arvosanat[i][j]  > 5 || arvosanat[i][j] < 1){
                do{
                    printf("\nARVOSANAN TULEE OLLA VALILTA 1 - 5 !\n");
                    printf("Anna arvosana (1-5) > ");
                    scanf("%d", &arvosanat[i][j] );
                } while(arvosanat[i][j] > 5 || arvosanat[i][j] < 1);
            }
        } // ARVOSANOJEN FOR LOOP LOPPUU
        // Tallentaa yhteenlaskennan keskiarvo taulukkoon
        for(int s = 0; s < 10; s++){
            keskiarvo[i] += arvosanat[i][s];
        }
    } // JUOMIEN FOR LOOP LOPPUU
    
    // Tekee lopputulostuksen ja tarkistaa keskiarvo laskennan
    for(int i = 0; i < 5; i++){
        if((keskiarvo[i] / 10) >= 3){
            printf("Juoma numero %d on kelvollista\n", i + 1);
        } else {
            printf("Juoma numero %d on kelvotonta\n", i + 1);
        }
    }
}