#include <stdio.h>

// Funzione per stampare il messaggio di benvenuto
void stampaMessaggioBenvenuto() {
    printf("Ciao e benvenuto/a in questo Quiz Game!\n");
}

// Funzione per ottenere la scelta dell'utente (Nuova Partita o Esci)
char ottieniSceltaUtente() {
    char scelta;
    printf("Menu: Y) Nuova Partita; N) Esci (Y/N): ");
    scanf(" %c", &scelta);
    return scelta;
}

// Funzione per ottenere il nome dell'utente
void ottieniNomeUtente(char nome[]) {
    printf("Inserisci il tuo nome utente: ");
    scanf("%s", nome);
}

// Funzione per eseguire le domande del quiz e restituire il punteggio
int eseguiDomande(char domande[][100], char opzioni[][3][50], char risposteCorrette[]) {
    int punteggio = 0;

    for (int i = 0; i < 3; i++) {
        printf("\n%s\n", domande[i]);
        for (int j = 0; j < 3; j++) {
            printf("%s\n", opzioni[i][j]);
        }

        char rispostaUtente[2];  
        printf("La tua risposta (A/B/C): ");
        scanf("%s", rispostaUtente);

        // Verifica se la risposta dell'utente è valida
        if (rispostaUtente[0] == 'A' || rispostaUtente[0] == 'B' || rispostaUtente[0] == 'C') {
            // Confronta la risposta dell'utente con quella corretta
            if (rispostaUtente[0] == risposteCorrette[i]) {
                punteggio++;
            }
        } else {
            printf("Scelta non valida. Inserisci 'A', 'B' o 'C'.\n");
            i--; // Decrementa i per ripetere la stessa domanda
        }
    }

    return punteggio;
}

int main() {
    while (1) {
        stampaMessaggioBenvenuto();

        char scelta = ottieniSceltaUtente();

        if (scelta == 'Y') {
            char nomeUtente[50];
            ottieniNomeUtente(nomeUtente);

            printf("Ciao, %s! Iniziamo con le domande.\n", nomeUtente);

            char domande[3][100] = {
                "Qual è il linguaggio di programmazione più utilizzato nel web?",
                "Chi è il creatore di Microsoft?",
                "Qual è il sistema operativo open source più diffuso?"
            };

            char opzioni[3][3][50] = {
                {"A) JavaScript", "B) Python", "C) Java"},
                {"A) Steve Jobs", "B) Bill Gates", "C) Mark Zuckerberg"},
                {"A) Linux", "B) Windows", "C) MacOS"}
            };

            char risposteCorrette[3] = {'A', 'B', 'A'};

            int punteggio = eseguiDomande(domande, opzioni, risposteCorrette);

            printf("\nGrande!, %s! Il tuo punteggio è: %d\n", nomeUtente, punteggio);

        } else if (scelta == 'N') {
            printf("Alla prossima!.\n");
            break;
        } else {
            printf("Scelta non valida. Inserisci 'Y' per iniziare una nuova partita o 'N' per uscire.\n");
        }
    }

    return 0;
}
