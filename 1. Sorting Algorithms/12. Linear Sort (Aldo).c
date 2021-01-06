#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *linearSort(char *string);

int main() {
    char string[43] = "aldo";
    for (int k = 0; string[k] != '\0'; k++) string[k] = toupper(string[k]);
    char a[3];
    linearSort(string);
    sprintf(a, "89");
    puts(a);
    int c;
    sscanf(a, "%d", &c);
    printf("%d", c);
    char ss[50][5]={"asd", "asf", "ert", "ertt"};

    return 0;
}

char *linearSort(char *string) {
    int length = strlen(string);
    // LUNGHEZZA DELLA STRINGA
    int counters[length];
    // ARRAY DI CONTATORI PER INDIVIDUARE LA "FORZA" DI OGNI SINGOLO CARATTERE
    for (int i = 0; i < length; i++) counters[i] = 0;
    // INIZIALIZZARE L'ARRAY DI INTERI A 0
    char final[length];
    // STRINGA FINALE DA RESTITUIRE ORDINATA
    int j = 0;
    // INDICE CHE RAPPRESENTA I SINGOLI ELEMENTI DI CUI CALCOLARE LA FORZA
    for (int i = j + 1; j < length - 1; ++i) {
        // VIENE ESEGUITO DA DA I = J+1 PERCHE' NON C'E' BISOGNO DI RIPETERE OGNI VOLTA I CONFRONTI DA ZERO, FINISCE AL PENULTIMO ELEMENTO PERCHE' L'ULTIMO ELEMENTO NON HA BISOGNO DI ENTRARE NEL CICLO FOR PERCHE' NON DEVE CONFRONTARSI CON NESSUNO
        string[j] > string[i] ? counters[j]++ : counters[i]++;
        // SE ARRAY[J] VIENE DOPO ALFABETICAMENTE DI ARRAY[I], INCREMENTA LA SUA POSIZIONE PER DIRE CHE DEVE ESSERE SPOSTATO DI UNO VERSO DESTRA PERCHè C'E' UN'ELEMENTO PIU' PICCOLO
        if (i == length - 1) {
            // SE IL SINGOLO CARATTERE E' STATO CONFRONTATO CON TUTTI GLI ALTRI CARATTERI ALLORA
            final[counters[j]] = string[j];
            // ASSEGNA ALL'ARRAY FINALE, ALLA POSIZIONE INDICATA DAL SUO CONTATORE, L'ELEMENTO
            i = ++j;
            // J VIENE INCREMENTATO DI 1 PER PASSARE ALL'ELEMENTO SUCCESSIVO, E AD I VIENE ASSEGNATO LO STESSO VALORE CHE ALLA FINE DI QUESTO FOR VERRA' INCREMENTATO DI 1 PER EFFETTUARE I CONFRONTI RIMANENTI DI QUELL'ELEMENTO
        }
    }
    final[counters[j]] = string[j];
    // ALL'ULTIMO ELEMENTO, CHE NON DEVE ESSERE CONFRONTATO CON NESSUNO, LO ASSEGNO NELL'ARRAY FINALE ALLA POSIZIONE INDICATA DAL SUO CONTATORE
    printf("%s", final);
    return *string;
    // RESTITUISCI UN PUNTATORE ALLA STRINGA INIZIALE
}

void sort(char *s[50], int n) {
    
}