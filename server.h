#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_CHALLENGES 12

typedef struct challenge{
    char * question;
    char * hint;
    char * answer;
    void (*func)(void);
} Challenge;

static Challenge all_challenges[NUMBER_OF_CHALLENGES] = {
    {   
        "¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?",  
        "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n
        En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\n
        Además tendrán que investigar otras preguntas para responder durante la defensa.\n
        El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.\n
        Además, deberán implementar otro programa para comunicarse conmigo.\n
        Deberán estar atentos a los easter eggs.\n
        Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\n'", 
        "entendido", 
        NULL
    },
    {
        "¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?",
        "The Wire S1E5 5295 888 6288", 
        "itba", 
        NULL
    },
    {   
        "¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?", 
        "https://ibb.co/tc0Hb6w", 
        "M4GFKZ289aku", 
        NULL
    },
    {   
        "¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?", 
        "EBADF... \n", 
        "fk3wfLCm3QvS", 
        challenge4
    },
    {   
        "¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?",
        "respuesta = strings:277", 
        "too_easy", 
        NULL
    },
    {   
        "Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?",
        ".data .bss .comment ? .shstrtab .symtab .strtab", 
        ".RUN_ME", 
        NULL
    },
    {   
        "¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?",
        "Filter error", 
        "K5n2UFfpFMUN", 
        challenge7
    },
    {   
        "¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?",
        "¿? \n", 
        "BUmyYq5XxXGt", 
        challenge8
    },
    {   
        "Sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?",
        "Latexme\n\n
        Si\n
        \\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\frac{u'}{u})\n
        entonces\n
        y = ", 
        "u^v", 
        NULL
    },
    {   
        "¿Cuáles son las características del protocolo SCTP?",
        "quine\n", 
        "chin_chu_lan_cha", 
        challenge10
    },
    {   
        "¿Qué es un RFC?",
        "b gdbme y encontrá el valor mágico\nENTER para reintentar.", 
        "gdb_rules", 
        challenge11
    },
    {   
        "¿Se divirtieron?",
        "Me conoces",
        "normal", 
        challenge12
    }
    
};

void run_challenge_function(Challenge challenge);

void run_all_challenges(int socket_fd);

void run_and_check_error(int error, char message[], int retval);

void challenge4(void);

void challenge7(void);

void challenge8(void);

void challenge10(void);

void challenge11(void);

void challenge12(void);
