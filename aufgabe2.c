#include "aufgabe2.h"

int aufgabe2_1(int argc, char **argv) {
    if (argc < 2) {
        printf("No file path given!\n");
        return -1;
    }

    FILE* cFile = fopen(argv[1], "r");
    ERROR(argv[1]);

    int roundBrackets  = 0;
    int curlyBrackets  = 0;

    int maxRound = 0;
    int maxCurly = 0;

    int line = 0;

    char c;
    while ((c = fgetc(cFile)) != EOF) {
        //printf("%c", c);

        if (c == '\n') {
            ++line;
            continue;
        }

        if (c == '(') ++roundBrackets;
        if (c == '{') ++curlyBrackets;

        if (roundBrackets > maxRound) maxRound = roundBrackets;
        if (curlyBrackets > maxCurly) maxCurly = curlyBrackets;

        if (c == ')') --roundBrackets;
        if (c == '}') --curlyBrackets;

        //printf("%c: %d %d\n", c, roundBrackets, curlyBrackets);

        if (roundBrackets < 0) {
            printf("Unbalanced round brackets on line: %d", line);
            goto err;
        }
        if (curlyBrackets < 0) {
            printf("Unbalanced curly brackets on line: %d", line);
            goto err;
        }
    }

    fclose(cFile);
    printf("Done analyzing \"%s\"\n\n", argv[1]);

    if (roundBrackets != 0) {
        printf("Open round brackets at EOF");
        goto err;
    }
    if (curlyBrackets != 0) {
        printf("Open curly brackets at EOF");
        goto err;
    }

    printf("Line count: %d\n", line);
    printf("Deepest nesting (round): %d\n", maxRound);
    printf("Deepest nesting (curly): %d\n", maxCurly);

    return EXIT_SUCCESS;

    err:
    return EXIT_FAILURE;
}

int aufgabe2_2(int argc, char **argv) {
    FILE* adresses = fopen(DATA_PATH_PREFIX "adressen.dat", "r");
    ERROR(DATA_PATH_PREFIX "adressen.dat");

    char c;
    while ((c = getc(stdin)) != EOF) {
        switch (c) {
            case 'n':
            {
                // TODO: Suche nach dem Nachnamen und Ausgabe aller zutreffenden Einträge in
                //        der Form <vorname> <telefonnummer>\n auf der Konsole
                break;
            }
            case 'v':
            {
                // TODO: Suche nach dem Vornamen und Ausgabe aller zutreffenden Einträge in
                //        der Form <nachname> <telefonnummer>\n auf der Konsole
                break;
            }
            case 't':
            {
                // TODO: Suche nach der Telefonnummer und Ausgabe aller zutreffenden
                //        Einträge in der Form <vorname> <nachname>
                break;
            }
            case 'q':
            {
                goto done;
                break;
            }
            case 's\n':
            {
                // TODO: Es soll eine nach Nachnamen sortierte Liste der
                //        Form <vorname>\t<nachname>\t<telefonnummer>\n in <dateiname> ausgegeben werden
                break;
            }
            default: printf("%c", c);
        }
    }

    done:
    fclose(adresses);
    return EXIT_SUCCESS;
}
