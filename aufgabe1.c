#include "aufgabe1.h"

int aufgabe1_5(int argc, char **argv) {
    FILE* log = fopen(DATA_PATH_PREFIX "mur2eur.dat", "r");
    ERROR(DATA_PATH_PREFIX "mur2eur.dat");

    int bufferSize = 256;
    char buffer[bufferSize];
    memset(buffer, 0, 256);
    double min = DBL_MAX, max = -DBL_MAX, mid = 0;
    int line = 0;
    while (fscanf(log, "%s", buffer) != EOF) {
        double cur = atof(buffer);
        char buf[10];
        sprintf(buf, "%d", line);
        ERROR(buf);

        if (cur < min) min = cur;
        if (cur > max) max = cur;
        mid += cur;

        ++line;
        memset(buffer, 0, 256);
    }

    if (line != 0) {
        mid /= line;
        printf("min: %f\n", min);
        printf("max: %f\n", max);
        printf("mid: %f\n", mid);
    }
    else {
        puts("mur2eur.dat is empty");
    }

    fclose(log);

    return EXIT_SUCCESS;
}

int aufgabe1_4(int argc, char **argv) {
   int bufferSize = 256;
   FILE* wechselKurse = fopen(DATA_PATH_PREFIX "wechselkurs.dat", "r");
   ERROR(DATA_PATH_PREFIX "wechselkurs.dat");
   
   char buffer[bufferSize];
   fscanf(wechselKurse, "%s", buffer);
   double rupieToEuro = atof(buffer);
   ERROR("MUR to EUR");

   memset(buffer, 0, bufferSize);

   fscanf(wechselKurse, "%s", buffer);
   double euroToRupie = atof(buffer);
   ERROR("EUR to MUR");

   fclose(wechselKurse);

   memset(buffer, 0, bufferSize);

   scanf("%s", buffer);
   double mur = atof(buffer);
   ERROR("mur value");

   FILE* log = fopen(DATA_PATH_PREFIX "mur2eur.dat", "a");
   ERROR(DATA_PATH_PREFIX "mur2eur.dat");

   memset(buffer, 0, bufferSize);
   fprintf(log, "%f\t%f\n", mur, mur * rupieToEuro);
   fclose(log);

   return EXIT_SUCCESS;
}

int aufgabe1_3(int argc, char **argv) {
    int wert;
    char *pEnd;
//    char *wertString = "123";
//    char *wertString = "123abc";
    char *wertString = "12345678901234567890";

    wert = strtol(wertString, &pEnd, 10);

    if (pEnd[0] != '\0') {
        printf("Falsche Zeichen = %s\n", pEnd); /* abc */
    }

    /* Result too large */
    ERROR("Ausgabe errno");

    printf("Zahl = %d\n", wert);
    return EXIT_SUCCESS;
}

int aufgabe1_23(int argc, char **argv) {
    int dividend = 0, divisor = 0;
    char buffer[256];

    scanf("%s", buffer);
    dividend = strtol(buffer, NULL, 10);
    ERROR("Dividend");

    memset(buffer, 0, 256);

    scanf("%s", buffer);
    divisor = strtol(buffer, NULL, 10);
    ERROR("Divisor");

    if (divisor == 0) {
       puts("Divison durch 0 ist nicht zulässig\n");
       return EXIT_FAILURE;
    }

    printf("%d geteilt durch %d ergibt %d Rest %d\n", dividend, divisor, dividend/divisor, dividend % divisor);
    return EXIT_SUCCESS;
}

int aufgabe1_1(int argc, char **argv) {
    char name[] = "Niklas Halle";
    printf("%s, 19\n", name);
    return EXIT_SUCCESS;
}
