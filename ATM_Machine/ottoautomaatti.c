#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

// Prototyypit
void navigointi(int saldo);
void aloitusNakyma();
void lopetusNakyma();
void roskis(void);
int deposit(int tili);
int withdraw(int tili);
int saldo(int tili);
int nostoAnnetaan(int nosto);

// Main
int main(void){   
    int tili;
    int indicator = 0;
    int result;
    FILE *tiedosto;
    char accountNumber[MAX];
    char avain[MAX];
    char pinKoodi[MAX];
    int yritysta = 3;

    // Aloitus näkymä
    aloitusNakyma();

    // Kysytään käyttäjältä käyttäjätunnusta eli tässä tapauksessa tiedoston nimeä, josta data luetaan.
    do{
        printf("Syötä käyttäjätunnust > ");
        fgets(accountNumber, MAX, stdin);
        // Joudumme myös muokkaamaan fgets() takia vähän merkkijonoa, koska emme käytä kaikkea 200 tilaa.
        if(accountNumber[strlen(accountNumber) - 1] == '\n'){
            accountNumber[strlen(accountNumber) - 1] = '\0';
        } else {
            // Tyhjentää puskurin
            roskis();
        }
        // strcat yhdistää kaksisanaa keskenään
        strcat(accountNumber, ".tili");
        // Avaa tiedoston lukutilalla
        tiedosto = fopen(accountNumber, "r");

        // Tekee simuloivan tilanteen väärin syötetystä tunnuksesta, sekä tarkistuksen että onko tiedostoa olemassa.
        if(tiedosto == NULL){
            yritysta--;
            if(yritysta == 0){
                printf("Olet yrittänyt liian monesti. Lopetetaan automaatti!");
                exit(EXIT_FAILURE);
            } else {
                printf("Virhe tunnuksen avaamisessa, sinulla on vielä %d yritystä\n", yritysta);
            }
        } else {
            // Kun tiedosto on löytynyt. Järjestelmä pyytää pinkoodia, jonka se lukee käyttäjältä ja vertaa sitten tiedostossa olevaan tietoon
            do{
                printf("Syötä pinkoodi > ");
                fgets(pinKoodi, MAX, stdin);
                if(pinKoodi[strlen(pinKoodi) - 1] == '\n'){
                    pinKoodi[strlen(pinKoodi) - 1] = '\0';
                }

                /* 
                Indikaattoria jouduin käyttämään, koska tiedostossa on kaksi riviä merkkijonoja. 
                Jos käyttäjä syöttäisi väärän pinkoodin se lukisi seuraavan rivin. Tätä emme halua. 
                */
                if(indicator == 0){
                    fgets(avain, MAX, tiedosto);
                    indicator = 1;
                    if((avain[strlen(avain) - 1]) == '\n'){
                        avain[strlen(avain) - 1] = '\0';
                    }
                }

                // DEBUG: printf("%s %s", pinKoodi, avain);
                if((result = strcmp(pinKoodi, avain)) == 0){
                    fscanf(tiedosto, "%d", &tili);
                    navigointi(tili);
                    lopetusNakyma();
                } else {
                    printf("Väärä pinkoodi, ole hyvä ja yritä uudelleen.\n");
                }
            } while(1);
        } 
    } while(1);
} 


// Tyhjentää puskurin
void roskis(void){
    while (fgetc(stdin) != '\n');
}

// Aloitus näkymä funktio
void aloitusNakyma(){
    printf("\n** Tervetuloa bottimaattiin **\n");
}
// Lopetus funktio
void lopetusNakyma(){
    printf("\n** Joko olet tehny asiasi. Kiitos että käytit bottimaattia ja tervetuloa uudelleen. **");
    exit(EXIT_FAILURE);
}

// Navigointi funktio
void navigointi(int tili){
    int varallisuus = tili;
    int valikko, talletettuSum = 0, nostettuSum = 0;
    do{
    printf("\n** Navigointi **\n");
    printf("\n1.Saldo       2. Talletus");
    printf("\n3.Nosto       0. Lopetus\nValitse > ");
    scanf("%d", &valikko);

        switch (valikko)
        {
    case 1:
        saldo(varallisuus);
    break;
    case 2:
        talletettuSum = deposit(varallisuus);
        varallisuus = talletettuSum;
    break;
    case 3:
        nostettuSum = withdraw(varallisuus);
        varallisuus = nostettuSum;
    break;
    
        } 
    } while (valikko != 0);
}

// Saldo funktio
int saldo(int tili){
    int valikko;
    do{
        printf("\n- Tililläsi on käytettävissä: %d€\n", tili);
        printf("\n1. Palaa takasin    0. Suljetaan automaatti\nValitse > ");
        scanf("%d", &valikko);
        if(valikko == 0){
            lopetusNakyma();
            exit(EXIT_FAILURE);
        }
    } while (valikko != 1);
    return -1;
}

// Talletus funktio
int deposit(int tili){
    int alphaCheck;
    int valikko;
    int talletus;
    do{
    printf("\nOle hyvä ja syötä talletettava summa > ");
    // Numero tarkistus
    while((alphaCheck = scanf("%d", &talletus)) != 1){
        roskis();
        printf("\nOlisi kiva jos syöttäisit numeroita. Yritä uudelleen > ");
        alphaCheck = scanf("%d", &talletus);
        if(alphaCheck == 1){
            break;
        }
    }
    if(talletus <= 0){
        do{
            printf("\nEthän sinä hyvä ihminen voi tallettaa nollaa tai negatiivistä numeroa");
            printf("\nKokeilehan uudelleen > ");
            scanf("%d", &talletus);
        } while(talletus <= 0);
    }
    tili += talletus;
    printf("Oletko lopettanut talletuksen?\n1. Kyllä    0. En\n");
    printf("Valitse > ");
    scanf("%d", &valikko);  
    if(valikko != 1 && valikko != 0){
        do{
            printf("\nAnteeksi en nyt ihan ymmärtänyt. Olitko siis lopettanut talletuksen\n");
            printf("1. Kyllä    0. En\n");
            printf("Valitse > ");
            scanf("%d", &valikko);  
        }   while(valikko != 1 && valikko != 0);
    }
    } while (valikko != 1);
    printf("\n- Saldosi on talletuksen jälkeen %d€\n", tili);
    return tili;
}

// Nosto funktio
int withdraw(int tili){
    int alphaCheck;
    int valikko;
    int nostoRaja = 1000;
    int nostoPienin = 20;
    int nosto;
    int indikaattori = 0;
    // Toisto lause
    do{
    indikaattori = 0;
    // Pyytää nostettavan summan
    printf("\nOle hyvä ja syötä nostettava summa > ");

    // Numero tarkistus
    while((alphaCheck = scanf("%d", &nosto)) != 1){
        roskis();
        printf("\nOlisi kiva jos syöttäisit numeroita. Yritä uudelleen > ");
        alphaCheck = scanf("%d", &nosto);
        if(alphaCheck == 1){
            break;
        }
    }
    if(nosto <= 0){
        do{
            printf("\nVoisitko kuitenkin syöttää positiivisen summan vaikkakin rahat lähtevätkin tililtäsi :D");
            printf("\nYritä uudelleen > ");
            scanf("%d", &nosto);
        } while(nosto <= 0);
    }

    // Jos tili = 0 niin et voi luultavastikkaan nostaa enää mitään, joten palauttaa sinut takaisin Navigointiin.
    if (tili == 0){
        printf("Et voi nostaa yhtään mitään. Palataan navigointiin...\n");
        indikaattori = 1;
        break;
    // Muutoin tekee tarvittavat toimenpiteet
    } else if (tili < 20){
        printf("Tilisi saldo on pienempää kuin 20€.\nVähimmäisnosto on 20€, et täten voi nostaa mitään. Palataan navigointiin...\n");
        indikaattori = 1;
        break;
    } 

    // Tarkistaa tilin ja nostettavan määrän, jos nosto on > kuin tili niin ERROR!!!
    if(nosto > tili){
        do{
            printf("\nTilinsaldo ei riitä! tililläsi on tällähetkellä %d€\n", tili);
            if(tili == 0){
                nosto = 0;
                break;
            } else {
                printf("\nSyötä nosto uudelleen > ");
                scanf("%d", &nosto);
            }
        } while(nosto > tili);
    // Tarkistaa nostoRajan ja noston välistä eroa
    } else if(nosto > nostoRaja){
        do{
            printf("\nEt voi nostaa näin paljoa samalla kerralla. Raja on 1000€\n");
            printf("\nOle hyvä ja syötä nostettava summa uudelleen > ");
            scanf("%d", &nosto);
        } while(nosto > nostoRaja);

    // Tarkistaa noston ja pienimmän nosto mahdollisuuden eroa, sekä että nostossa ei tehdä muutakuin tasasumma nostoja.
    }
    if ((nosto < 40 && nosto != 20) || (nosto % 10) != 0){
         do{
            printf("\nPienimmät mahdolliset nostot ovat 20€ ja 40€. Pyydämme myös kymmenellä jaollisia summia eli tasasummia\n");
            printf("\nOle hyvä ja anna tasa summainen nosto uudelleen > ");
            scanf("%d", &nosto);
        } while ((nosto < 40 && nosto != 20) || (nosto % 10) != 0);
    }
    
    tili -= nosto;
    printf("Oletko lopettanut noston?\n1. Kyllä    0. En\n");
    printf("Valitse > ");
    scanf("%d", &valikko);  
    // Nosto funktion sisäinen navigointi.
    if(valikko != 1 && valikko != 0){
        do{
            printf("\nAnteeksi en nyt ihan ymmärtänyt. Olitko siis lopettanut talletuksen\n");
            printf("1. Kyllä    0. En\n");
            printf("Valitse > ");
            scanf("%d", &valikko);  
        }   while(valikko != 1 && valikko != 0);
    }
    } while (valikko != 1);
    if(indikaattori == 1){
        
    } else {
    printf("\n- Saldosi on noston jälkeen %d€\n", tili);
    // Kutsuu nostoAnnetaan funktiota joka laskee KPL määriä
    nostoAnnetaan(nosto);
    }
    return tili;
}

// KPL laskenta
int nostoAnnetaan(int nosto){

    int tarkistus = nosto;
    int tarkistuksenEtumerkki = (nosto / 100) * 2;
    int viisiKPL = 0;
    int kaksKPL = 0;
    
    if ((tarkistus % 50) == 0){
        viisiKPL = tarkistus / 50;
        printf("Sinulle annettiin: \n");
        printf("%d kpl 50€ seteleitä\n",viisiKPL);
    } else if((tarkistus % 50) % 20 == 0){
        viisiKPL = (tarkistus - (tarkistus % 50)) / 50;
        kaksKPL = (tarkistus % 50) / 20;
        printf("Sinulle annettiin: \n");
        printf("%d kpl 50€ seteleitä\n",viisiKPL);
        printf("%d kpl 20€ seteleitä\n",kaksKPL);
    } else if(((tarkistus - (tarkistuksenEtumerkki * 50)) % 20) == 0){
        viisiKPL = tarkistuksenEtumerkki;
        kaksKPL = (tarkistus - (tarkistuksenEtumerkki * 50)) / 20;
        printf("Sinulle annettiin: \n");
        printf("%d kpl 50€ seteleitä\n",viisiKPL);
        printf("%d kpl 20€ seteleitä\n",kaksKPL);
    } else {
        viisiKPL = 1;
        kaksKPL = (tarkistus - 50) / 20;
        if(kaksKPL >= 5){
            viisiKPL += ((kaksKPL - (kaksKPL % 5)) / 5) * 2;
            kaksKPL = kaksKPL % 5;
        }
        printf("Sinulle annettiin: \n");
        printf("%d kpl 50€ seteleitä\n",viisiKPL);
        printf("%d kpl 20€ seteleitä\n",kaksKPL);
    }
   
    return nosto;
}

