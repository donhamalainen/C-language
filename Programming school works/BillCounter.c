#include <stdio.h>

int main(void){
    int palkka[5];
    int summa = 0;
    int viisiSataaKPL = 0, kaksiSataaKPL = 0, sataKPL = 0, viisiKymmentaKPL = 0, kaksiKymmentaKPL = 0, kymmenenKPL = 0, viisiKPL = 0, kaksiKPL = 0, yksiKPL = 0;
    int viisiSataaYHT = 0, kaksiSataaYHT = 0, sataYHT = 0, viisiKymmentaYHT = 0, kaksiKymmentaYHT = 0, kymmenenYHT = 0, viisiYHT = 0, kaksiYHT = 0, yksiYHT = 0;
    for(int i = 0; i < 5; i++){
        // printf("Anna %d. tyontekijan palkka > ", i + 1);
        scanf("%d", &palkka[i]);
    }
    printf("Palkka 500 € 	200 € 	100 € 	50 € 	20 € 	10 € 	  5 € 	  2 € 	  1 €\n");
    for(int i = 0; i < 5; i++){
        summa = palkka[i];
        // 500
        if((summa / 500) != 0){
            viisiSataaKPL = summa / 500;
            summa = summa - viisiSataaKPL * 500;
        } else {
            viisiSataaKPL = 0;
        }

        // 200
        if((summa / 200) != 0){
            kaksiSataaKPL = summa / 200;
            summa = summa - (kaksiSataaKPL * 200);
        } else {
            kaksiSataaKPL = 0;
        }
    
        // 100
        if((summa / 100) != 0){
            sataKPL = summa / 100;
            summa = summa - (sataKPL * 100);
        } else {
            sataKPL = 0;
        }
    
        // 50
        if((summa / 50) != 0){
            viisiKymmentaKPL = summa / 50;
            summa = summa - (viisiKymmentaKPL * 50);
        } else {
            viisiKymmentaKPL = 0;
        }
        
        // 20
        if((summa / 20) != 0){
            kaksiKymmentaKPL = summa / 20;
            summa = summa - (kaksiKymmentaKPL * 20);
        } else {
            kaksiKymmentaKPL = 0;
        }
       
        // 10
        if((summa / 10) != 0){
            kymmenenKPL = summa / 10;
            summa = summa - (kymmenenKPL * 10);
        } else {
            kymmenenKPL = 0;
        }
        
        // 5
        if((summa / 5) != 0){
            viisiKPL = summa / 5;
            summa = summa - (viisiKPL * 5);
        } else {
            viisiKPL = 0;
        }
    
        // 2
        if((summa / 2) != 0){
            kaksiKPL = summa / 2;
            summa = summa - (kaksiKPL * 2);
        } else {
            kaksiKPL = 0;
        }
       
        // 1
        if((summa / 1) != 0){
            yksiKPL = summa / 1;
            summa = summa - (yksiKPL * 1);
        } else {
            yksiKPL = 0;
        }
        
        printf("%6d%6d%9d%8d%7d%8d%8d%9d%8d%8d\n", palkka[i], viisiSataaKPL, kaksiSataaKPL, sataKPL, viisiKymmentaKPL, kaksiKymmentaKPL, kymmenenKPL, viisiKPL, kaksiKPL, yksiKPL);
        viisiSataaYHT += viisiSataaKPL, kaksiSataaYHT += kaksiSataaKPL, sataYHT += sataKPL, viisiKymmentaYHT += viisiKymmentaKPL, kaksiKymmentaYHT += kaksiKymmentaKPL, kymmenenYHT += kymmenenKPL, viisiYHT += viisiKPL, kaksiYHT += kaksiKPL, yksiYHT += yksiKPL;
        viisiSataaKPL = 0, kaksiSataaKPL = 0, sataKPL = 0, viisiKymmentaKPL = 0, kaksiKymmentaKPL = 0, viisiKPL = 0, kaksiKPL = 0, yksiKPL = 0;
    }
    printf("  YHT:%6d%9d%8d%7d%8d%8d%9d%8d%8d",viisiSataaYHT, kaksiSataaYHT, sataYHT, viisiKymmentaYHT, kaksiKymmentaYHT, kymmenenYHT, viisiYHT, kaksiYHT, yksiYHT);
}
