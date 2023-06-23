typedef enum {
    INTEGER,
    INTARRAY,
    FUNCTION
} SymbolType;

// Structure pour la pile de déclarations
typedef struct DeclarationStack {
    Symbol* top;  // Sommet de la pile de déclarations
} DeclarationStack;

// Structure pour la pile d'utilisations
typedef struct UsageStack {
    Symbol* top;  // Sommet de la pile d'utilisations
} UsageStack;

typedef struct Symbol {
    char name[20];
    SymbolType type;
    union {
        int value;
        int* array;
        void* function;
    } data;
    int size; 
    struct Symbol* next;
} Symbol;

typedef struct SymbolStack {
    Symbol* top;
    DeclarationStack declStack;  // Pile de déclarations
    UsageStack usageStack;       // Pile d'utilisations
} SymbolStack;

// Initialiser la pile de symboles
void initSymbolStack(SymbolStack* stack) {
    stack->top = NULL;
    initDeclarationStack(&(stack->declStack));  // Initialiser la pile de déclarations
    initUsageStack(&(stack->usageStack));       // Initialiser la pile d'utilisations
}

// Empiler un symbole sur la pile de symboles et mettre à jour les piles de déclarations et d'utilisations
void pushSymbol(SymbolStack* stack, char* name, SymbolType type, int size) {
    Symbol* symbol = malloc(sizeof(Symbol));
    strncpy(symbol->name, name, 20);
    symbol->type = type;
    symbol->size = size;

    // Mettre à jour la pile de déclarations en ajoutant une case vide
    pushDeclaration(&(stack->declStack), &(stack->usageStack), NULL, UNKNOWN, 0);

    symbol->next = stack->top;
    stack->top = symbol;
}

// Ajouter une utilisation dans la pile d'utilisations et vérifier si une déclaration correspondante existe
void addUsage(SymbolStack* stack, char* name) {
    Symbol* declSymbol = popDeclaration(&(stack->declStack));
    if (declSymbol == NULL) {
        printf("Erreur : Utilisation de la variable %s non précédée d'une déclaration correspondante.\n", name);
        exit(1);
    }

    // Mettre à jour la pile d'utilisations
    pushUsage(&(stack->declStack), &(stack->usageStack), name);

    // Libérer la mémoire de la déclaration
    free(declSymbol);
}


// Initialiser la pile des déclarations
void initDeclarationStack(DeclarationStack* declStack) {
    declStack->top = NULL;
}

// Initialiser la pile des utilisations
void initUsageStack(UsageStack* usageStack) {
    usageStack->top = NULL;
}

// Empiler une déclaration sur la pile
void pushDeclaration(DeclarationStack* declStack, UsageStack* usageStack, const char* name, SymbolType type, int size) {
    Symbol* declSymbol = malloc(sizeof(Symbol));
    strncpy(declSymbol->name, name, 20);
    declSymbol->type = type;
    declSymbol->size = size;
    declSymbol->next = declStack->top;
    declStack->top = declSymbol;

    // Ajouter une case vide dans la pile des utilisations
    Symbol* usageSymbol = malloc(sizeof(Symbol));
    usageSymbol->name[0] = '\0';  // Case vide pour représenter une utilisation
    usageSymbol->type = INTEGER;  // Type par défaut (peut être modifié en fonction des besoins)
    usageSymbol->size = 0;        // Taille par défaut (0 pour les non tableaux)
    usageSymbol->next = usageStack->top;
    usageStack->top = usageSymbol;
}

// Empiler une utilisation sur la pile
void pushUsage(DeclarationStack* declStack, UsageStack* usageStack, const char* name) {
    // Ajouter une case vide dans la pile des déclarations
    Symbol* declSymbol = malloc(sizeof(Symbol));
    declSymbol->name[0] = '\0';  // Case vide pour représenter une déclaration
    declSymbol->type = INTEGER;  // Type par défaut (peut être modifié en fonction des besoins)
    declSymbol->size = 0;        // Taille par défaut (0 pour les non tableaux)
    declSymbol->next = declStack->top;
    declStack->top = declSymbol;

    // Ajouter l'utilisation dans la pile des utilisations
    Symbol* usageSymbol = malloc(sizeof(Symbol));
    strncpy(usageSymbol->name, name, 20);
    usageSymbol->type = INTEGER;  // Type par défaut (peut être modifié en fonction des besoins)
    usageSymbol->size = 0;        // Taille par défaut (0 pour les non tableaux)
    usageSymbol->next = usageStack->top;
    usageStack->top = usageSymbol;
}

// Dépiler une déclaration de la pile
Symbol* popDeclaration(DeclarationStack* declStack) {
    if (declStack->top == NULL) {
        fprintf(stderr, "La pile des déclarations est vide.\n");
        exit(1);
    }
    Symbol* declSymbol = declStack->top;
    declStack->top = declStack->top->next;
    return declSymbol;
}

// Dépiler une utilisation de la pile
Symbol* popUsage(UsageStack* usageStack) {
    if (usageStack->top == NULL) {
        fprintf(stderr, "La pile des utilisations est vide.\n");
        exit(1);
    }
    Symbol* usageSymbol = usageStack->top;
    usageStack->top = usageStack->top->next;
    return usageSymbol;
}


// Initialiser la pile de symboles
void initStack(SymbolStack* stack) { // pile symboles
    stack->top = NULL;
}

// Empiler un symbole sur la pile
void push(SymbolStack* stack, char* name, int value, int* array, int size, void* function, SymbolType type) {
    Symbol* symbol = malloc(sizeof(Symbol));
    strcpy(symbol->name, name);
    symbol->type = type;
    if (type == INTEGER) {
        symbol->data.value = value;
        printf("Ajout de %s de type INT avec la valeur %d\n", name, value);
    } else if (type == INTARRAY) {
        symbol->data.array = array;
        symbol->size = size; // ajout de la taille du tableau
        printf("type du tableau %s: %d\n", name, type);
        printf("Ajout de %s de type INT_ARRAY avec le tableau {", name);
        for (int i = 0; i < size; i++) { // modification de la boucle pour parcourir le tableau en utilisant la taille
            printf("%d", array[i]);
            if (i != size - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    } else if (type == FUNCTION) {
        symbol->data.function = function;
        printf("Ajout de %s de type FUNCTION\n", name);
    } else {
        printf("Type de symbole non pris en charge\n");
        printf("Ajout de %s de type %d\n", name, type);
    }
    symbol->next = stack->top;
    stack->top = symbol;
}


// Rechercher un symbole dans la pile
int* lookup(SymbolStack* stack, char* name) {
    Symbol* current = stack->top;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->type == INTEGER) {
               return &(current->data.value);
            } else if (current->type == INTARRAY) {
                return current->data.array;
            } else if (current->type == FUNCTION) {
                printf("%s : FUNCTION\n", name);
                return NULL;
            }
        }
        current = current->next;
    }
    printf("Symbole %s non defini\n", name);
    return NULL;
}

// check type of symbol
SymbolType getTypeByName(SymbolStack* stack, const char* name) {
    Symbol* current = stack->top;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->type == INTEGER) {
                return INTEGER;
            } else if (current->type == INTARRAY) {
                return INTARRAY;
            } else if (current->type == FUNCTION) {
                return FUNCTION;
            }
        }
        current = current->next;
    }
    return -1; // symbole non trouvé
}


// Dépiler un symbole de la pile
Symbol pop(SymbolStack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "La pile est vide.\n");
        exit(1);
    }
    Symbol symbol = *(stack->top);
    stack->top = stack->top->next;
    return symbol;
}

// Libérer la mémoire utilisée par la pile de symboles
void freeStack(SymbolStack* stack) {
    Symbol* current = stack->top;
    while (current != NULL) {
        Symbol* next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
}
// Exemple d'utilisation des piles de déclarations et d'utilisations
int main() {
    DeclarationStack declStack;
    UsageStack usageStack;

    // Initialisation des piles
    initDeclarationStack(&declStack);
    initUsageStack(&usageStack);

    // Ajout d'une déclaration et d'une utilisation
    pushDeclaration(&declStack, &usageStack, "x", INTEGER, 0);
    pushUsage(&declStack, &usageStack, "x");

    // Dépilage d'une déclaration et d'une utilisation
    Symbol* declSymbol = popDeclaration(&declStack);
    Symbol* usageSymbol = popUsage(&usageStack);

    // Affichage des informations de la déclaration
    printf("Déclaration : %s, Type : %d, Taille : %d\n", declSymbol->name, declSymbol->type, declSymbol->size);

    // Affichage des informations de l'utilisation
    printf("Utilisation : %s, Type : %d, Taille : %d\n", usageSymbol->name, usageSymbol->type, usageSymbol->size);

    // Libération de la mémoire
    free(declSymbol);
    free(usageSymbol);

    return 0;
}


void printStack(SymbolStack* stack) {
    printf("-----Stack-----\n");
    Symbol* current = stack->top;
    while (current != NULL) {
        printf("%s : ", current->name);
        if (current->type == INTEGER) {
            printf("%d\n", current->data.value);
        } else if (current->type == INTARRAY) {
            printf("{");
            for (int i = 0; i < current->size; i++) {
                printf("%d", current->data.array[i]);
                if (i < current->size - 1) {
                    printf(", ");
                }
            }
            printf("}\n");
        } else if (current->type == FUNCTION) {
            printf("FUNCTION\n");
        } else {
            printf("UNKNOWN TYPE\n");
        }
        current = current->next;
    }
    printf("---------------\n");
}

void test() {
    SymbolStack stack;
    initStack(&stack);

    // Ajout de symboles à la pile
    push(&stack, "x", 5, NULL, 0, NULL, INTEGER);
    push(&stack, "y", 0, (int[]){1,2,3}, 3, NULL, INTARRAY);
    /* push(&stack, "z", 0, NULL, 0, &test, FUNCTION); */

    // Affichage de la pile pour déboguer
    printf("Pile de symboles :\n");
    printStack(&stack);

    // Test de getSymbolType()
    Symbol* sym_x = lookup(&stack, "x");
    Symbol* sym_y = lookup(&stack, "y");
    /* Symbol* sym_z = lookup(&stack, "z"); */
    printf("Type de symbole x : %d\n", getTypeByName(&stack, "x")); // doit envoyer 0
	printf("Type de symbole y : %d\n", getTypeByName(&stack, "y")); // doit envoyer 1
	/* printf("Type de symbole z : %d\n", getTypeByName(&stack, "z")); */


	/* printf("y[0] de base = %d\n", lookup(&stack, "y")[0]);
	// Test de assign_array() on a soucis car il dit que cest pas un tab a mon avis
	// vu que l'enum envoie 0,1, 2 selon les types faut voir si c pas ca le soucis
	assign_array(&stack, "y", 0, 4);
	printf("y[0] après assignation = %d\n", lookup(&stack, "y")[0]); */


    // Dépilement des symboles de la pile
    Symbol symbol1 = pop(&stack);
    Symbol symbol2 = pop(&stack);
    printf("Symboles depilés : %s, %s\n", symbol1.name, symbol2.name);

    // Destruction de la pile
    freeStack(&stack);
}
