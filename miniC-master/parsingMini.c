#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "parsingMini.h"

int COMPTEUR = 0;

noeud* creerNoeud(char* val) {
    noeud* n = malloc(sizeof(noeud));
    n->val = val;
    n->nb_fils = 0;
    n->tableSymbole = malloc(sizeof(tableSymbole));
    n->tableSymbole->tailleTab = 0;
    n->tableSymbole->fonction = malloc(sizeof(fonction));
    n->tableSymbole->tabDim = NULL;
    n->tableSymbole->typeu = NULLTYPE;
    n->tableSymbole->name = NULL;
    return n;
}
noeud* addTypeNoeud(noeud* n, char* t) {
    if (strcmp(t, "int") == 0) {
        n->tableSymbole->typeu = INTEGER;
    } else if (strcmp(t, "void") == 0) {
        n->tableSymbole->typeu = VOIDE;
    } else if (strcmp(t, "array") == 0) {
        n->tableSymbole->typeu = INTARRAY;
    } else if (strcmp(t, "function") == 0) {
        n->tableSymbole->typeu = FUNCTION;
    }
    return n;
}

noeud* addSize(noeud* n, int size) {
    n->tableSymbole->tailleTab = size;
    return n;
}

noeud* addChild(noeud* parent, noeud* child) {
    parent->nb_fils++;
    parent->fils = realloc(parent->fils, parent->nb_fils * sizeof(noeud*));
    parent->fils[parent->nb_fils - 1] = child;
    parent->tableSymbole->tailleTab = parent->nb_fils;
    return parent;
}

noeud* appendChild1(noeud* n, noeud* child) {
    if(child==NULL){
        return n;
    }
    n->nb_fils++;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 1] = child;
    return n;
}
noeud* appendChild2(noeud* n, noeud* child1, noeud* child2) {
    if (child1==NULL){
        return appendChild1(n,child2);
    }
    if(child2==NULL)
    {
        return appendChild1(n,child1);
    }
    n->nb_fils += 2;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 2] = child1;
    n->fils[n->nb_fils - 1] = child2;
    return n;
}
noeud* appendChild3(noeud* n, noeud* child1, noeud* child2, noeud* child3) {
    if (child1==NULL){
        return appendChild2(n,child2,child3);
    }
    if(child2==NULL)
    {
        return appendChild2(n,child1,child3);
    }
    if(child3==NULL)
    {
        return appendChild2(n,child1,child2);
    }
    n->nb_fils += 3;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 3] = child1;
    n->fils[n->nb_fils - 2] = child2;
    n->fils[n->nb_fils - 1] = child3;
    return n;
}
noeud* appendChild4(noeud* n, noeud* child1, noeud* child2, noeud* child3, noeud* child4) {
    if (child1==NULL){
        return appendChild3(n,child2,child3,child4);
    }
    if(child2==NULL)
    {
        return appendChild3(n,child1,child3,child4);
    }
    if(child3==NULL)
    {
        return appendChild3(n,child1,child2,child4);
    }
    if(child4==NULL)
    {
        return appendChild3(n,child1,child2,child3);
    }
    n->nb_fils += 4;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 4] = child1;
    n->fils[n->nb_fils - 3] = child2;
    n->fils[n->nb_fils - 2] = child3;
    n->fils[n->nb_fils - 1] = child4;
    return n;
}

noeud* addAllChild(noeud* n, liste_noeud* f) {
    if (f == NULL) {
        return n;
    }
    if (n==NULL){
        return NULL;
    }
    for (int i = 0; i < f->nb_noeud; i++) {
        n = appendChild1(n, f->liste_noeud[i]);
    }
    return n;
}

void libererNoeud(noeud* n) {
    if (n == NULL) {
        return;
    }
    
    for (int i = 0; i < n->tableSymbole->tailleTab; i++) {
        libererNoeud(n->fils[i]);
    }
    
    free(n->fils);
    free(n);
}

void afficherNoeud(noeud* n) {
    if (n == NULL) {
        return;
    }
    
    printf("Valeur du noeud : %s\n", n->val);
    
    switch (n->tableSymbole->typeu) {
        case INTEGER:
            printf("Type du noeud : INTEGER\n");
            break;
        case INTARRAY:
            printf("Type du noeud : INTARRAY\n");
            break;
        case FUNCTION:
            printf("Type du noeud : FUNCTION\n");
            break;
        case VOIDE:
            printf("Type du noeud : VOID\n");
            break;
        default:
            printf("Type du noeud : Inconnu\n");
            break;
    }
    
    printf("Nombre de fils : %d\n", n->nb_fils);
    
    for (int i = 0; i < n->nb_fils; i++) {
        printf("Fils %d :\n", i);
        afficherNoeud(n->fils[i]);
    }
}

noeud* rechercherNoeud(noeud* n, char* valeur) {
    if (n == NULL) {
        return NULL;
    }
    printf("recherche dans %s\n", n->val);
    printf("nb fils : %d\n", n->nb_fils);
    printf("Recherche de %s\n", valeur);

    if (strcmp(n->tableSymbole->name, valeur) == 0) {
        printf("trouvé\n");
        return n;
    }
    printf("nb fils : %d\n", n->nb_fils);
    printf("pas trouvé\n");
    for (int i = 0; i < n->nb_fils; i++) {
        noeud* res = rechercherNoeud(n->fils[i], valeur);
        if (res != NULL) {
            return res;
        }
    }
    return NULL;
}

liste_noeud* addNoeudList(liste_noeud* a, liste_noeud* b) {
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }
    liste_noeud* res = creerListeNoeud(NULL);
    res->nb_noeud = a->nb_noeud + b->nb_noeud;
    res->liste_noeud = malloc(res->nb_noeud * sizeof(noeud*));
    for (int i = 0; i < a->nb_noeud; i++) {
        res->liste_noeud[i] = a->liste_noeud[i];
    }
    for (int i = 0; i < b->nb_noeud; i++) {
        res->liste_noeud[i + a->nb_noeud] = b->liste_noeud[i];
    }
    return res;
}

liste_noeud* rechercherNoeudListe(noeud* n,char* valeur){
    if (n == NULL) {
        return NULL;
    }
    liste_noeud* res = creerListeNoeud(NULL);
    if (strcmp(n->tableSymbole->name, valeur) == 0) {
        res = addNoeud(res, n);
    }
    for (int i = 0; i < n->nb_fils; i++) {
        liste_noeud* res2 = rechercherNoeudListe(n->fils[i], valeur);
        if (res2 != NULL) {
            res = addNoeudList(res, res2);
        }
    }
    return res;
}

void afficherArbre(noeud* n) {
    if (n == NULL) {
        return;   // Cas de base : le noeud est vide
    }

    // Affichage de la valeur du noeud
    printf("%s", n->val);

    // Parcours des fils du noeud
    if (n->nb_fils == 0) {
      return;
    }
    printf("(");
    int i;
    for (i = 0; i < n->nb_fils; i++) {
        if (n->nb_fils > 0) {
            afficherArbre(n->fils[i]);
            if (i < n->nb_fils - 1) {
                printf(",");
            }
        } else {
            return;
        }
    }
    printf(")\n");
}

liste_noeud* creerListeNoeud(noeud* n){
  liste_noeud* f = malloc(sizeof(liste_noeud));
  if (n==NULL){
    return f;
  }
  f->nb_noeud = 1;
  f->liste_noeud = malloc(sizeof(noeud*));
  f->liste_noeud[0] = n;
  return f;
}

liste_noeud* addNoeud(liste_noeud* f, noeud* n){
    if (f == NULL) {
        f=creerListeNoeud(n);
        return f;
    }
    if (n == NULL) {
        return f;
    }
  f->nb_noeud++;
  f->liste_noeud = realloc(f->liste_noeud, f->nb_noeud * sizeof(noeud*));
  f->liste_noeud[f->nb_noeud - 1] = n;
  return f;
}

char* typeToString(NoeudType typeu){
    switch (typeu) {
        case INTEGER:
        return "int";
        break;
        case INTARRAY:
        return "int[]";
        break;
        case VOIDE:
        return "void";
        break;
    default:
        return "inconnu";
        break;
    }
}

int stringToType(char* type){
    if(strcmp(type, "int")==0){
        return INTEGER;
    }
    else if(strcmp(type, "int[]")==0){
        return INTARRAY;
    }
    else if(strcmp(type, "void")==0){
        return VOIDE;
    }
    else{
        return -1;
    }
}

void nodeType(FILE* f, noeud* n, int* COMPTEUR){
  if(n->type == APPELFONCTION){
    fprintf(f, "node_%d [label=\"%s\"shape=septagon];\n", *COMPTEUR, n->val);
  }
  else if(n->type == FONCTION){
    fprintf(f, "node_%d [label=\"%s\"shape=invtrapezium color=blue];\n", *COMPTEUR, n->val);
  }
  else if(strcmp(n->val,"BREAK")==0){
    fprintf(f, "node_%d [label=\"%s\"shape=box];\n", *COMPTEUR, "BREAK");
  }
  else if(strcmp(n->val,"IF")==0){
    fprintf(f, "node_%d [label=\"%s\"shape=diamond];\n", *COMPTEUR, "IF");
  }
  else if(strcmp(n->val,"RETURN")==0){
    fprintf(f, "node_%d [label=\"%s\"shape=trapezium color=blue];\n", *COMPTEUR, "RETURN");
  }
  else if(strcmp(n->val,"EXTERN")==0){
    fprintf(f, "node_%d [label=\"%s\"shape=trapezium color=blue];\n", *COMPTEUR, "EXTERN");
  }
  else{
    fprintf(f, "node_%d [label=\"%s\"];\n", *COMPTEUR, n->val);
  }
}

void arbreToDot(noeud* n, int* COMPTEUR, FILE* fp) {
    if (n == NULL) return;

    if (strcmp(n->val, ".EMPTY.") != 0) {
        nodeType(fp, n, COMPTEUR);
        int noeud_courant = *COMPTEUR;
        (*COMPTEUR)++;

        for (int i = 0; i < n->nb_fils; i++) {
            if (n->fils[i] != NULL) {
                fprintf(fp, "node_%d -> node_%d;\n", noeud_courant, *COMPTEUR);
            }
            arbreToDot(n->fils[i], COMPTEUR, fp);
        }
    } else {
        fprintf(fp, "node_%d [label=\"%s\"];\n", *COMPTEUR, n->val);
        int noeud_courant = *COMPTEUR;
        (*COMPTEUR)++;

        for (int i = 0; i < n->nb_fils; i++) {
            if (n->fils[i] != NULL) {
                fprintf(fp, "node_%d -> node_%d;\n", noeud_courant, *COMPTEUR);
                arbreToDot(n->fils[i], COMPTEUR, fp);
            }
        }
    }
}

void generateDotFile(liste_noeud* listfunc){
  FILE* f;
  f = fopen("add.dot", "a");
  fprintf(f, "digraph G {\n");
  printf("Génération du fichier dot\n");
  for (int i = 0; i < listfunc->nb_noeud; i++) {
    if(listfunc->liste_noeud[i]!= NULL && strncmp(listfunc->liste_noeud[i]->val, "EXTERN",6) != 0){
        arbreToDot(listfunc->liste_noeud[i], &COMPTEUR, f);
    }
  }
  fprintf(f, "}");}

void clearFile(){
    char* nomFichier = "add.dot";
    remove(nomFichier);
}

//check sur les variables
bool verifierTypeNoeud(noeud* n, NoeudType typeAttendu) {
    return n->tableSymbole->typeu == typeAttendu;
}

bool firstLetterIsString(noeud* n) {
    char premiereLettre = n->val[0];
    return isalpha(premiereLettre) != 0;
}

//lles sont de type entier ou tableau d’entiers à un nombre quelconque de dimensions
bool varTypeIsIntOrIntArray(noeud* n) {
    return verifierTypeNoeud(n, INTEGER) || verifierTypeNoeud(n, INTARRAY);
}

bool functionIsDeclared(noeud* n, char* nameFunction){
    noeud* res = rechercherNoeud(n, nameFunction);
    if (res == NULL) {
        printf("Erreur : la fonction '%s' n'est pas déclarée.\n", nameFunction);
        return false;
    }
    return true;
}

bool firstLetterFunctionIsString(char* nameFunction){
    char premiereLettre = nameFunction[0];
    if (!isalpha(premiereLettre)) {
        printf("Erreur de déclaration de fonction : le nom de la fonction '%s' ne commence pas par une lettre.\n", nameFunction);
        return false;
    }
    return true;
}

noeud* newFunction(noeud* n, char* nameFunction, noeud* typeFunction, liste_noeud* parametres, int line) {
    n->tableSymbole->typeu = FUNCTION;
    n->tableSymbole->name = nameFunction;
    n->tableSymbole->line = line;
    n->tableSymbole->fonction->typeRetour = stringToType(typeFunction->val);
    n->tableSymbole->fonction->nom = nameFunction;
    if (parametres == NULL || parametres->nb_noeud == 0) {
        n->tableSymbole->fonction->nbParametres = 0;
        n->tableSymbole->fonction->parametres = malloc(sizeof(Parametre*));
    }
    else{
        n->tableSymbole->fonction->nbParametres = parametres->nb_noeud;
        n->tableSymbole->fonction->parametres = malloc(sizeof(Parametre*) * parametres->nb_noeud);
        n->tableSymbole->fonction->parametres[0] = malloc(sizeof(Parametre));
        n->tableSymbole->fonction->parametres[0]->type = parametres->liste_noeud[0]->tableSymbole->typeu;
    }
    for (int i = 0; i < n->tableSymbole->fonction->nbParametres; i++) {
        n->tableSymbole->fonction->parametres[i] = malloc(sizeof(Parametre));
        n->tableSymbole->fonction->parametres[i]->type = parametres->liste_noeud[i]->tableSymbole->typeu;
        n->tableSymbole->fonction->parametres[i]->nom = parametres->liste_noeud[i]->val; 
    }
    return n;
}

noeud* newVariable(char* name, int line) {
    noeud* var = creerNoeud(name);
    var->tableSymbole->name = name;
    var->tableSymbole->typeu = INTEGER;
    var->tableSymbole->line = line;
    return var;
}


// check sur les identificateurs
bool checkIdentName(char* name){
    if (strcmp(name, "extern") == 0 || strcmp(name, "int") == 0 || strcmp(name, "void") == 0 || strcmp(name, "for") == 0 || strcmp(name, "while") == 0 || strcmp(name, "if") == 0 || strcmp(name, "then") == 0 || strcmp(name, "else") == 0 || strcmp(name, "switch") == 0 || strcmp(name, "case") == 0 || strcmp(name, "default") == 0 || strcmp(name, "break") == 0) {
        printf("Erreur : le nom '%s' est un mot clé réservé.\n", name);
        return false;
    }
    return true;
}

//declaration tableau
void ajouterDimensionTableau(noeud* tableau, int taille) {
    // Vérification si le nœud est de type tableau
    if (tableau->tableSymbole->typeu != INTARRAY) {
        printf("Erreur : Le nœud n'est pas un tableau.\n");
        return;
    }
    // Vérification si le tableau n'a pas encore de dimensions
    if (tableau->tableSymbole->tabDim == NULL) {
        // Allouer la structure TableauDimensions
        tableau->tableSymbole->tabDim = (TableauDimensions*) malloc(sizeof(TableauDimensions));
        // Allouer le tableau de dimensions
        tableau->tableSymbole->tabDim->dimensions = (int*) malloc(sizeof(int));
        // Initialiser le nombre de dimensions à 1
        tableau->tableSymbole->tabDim->nb_dimensions = 1;
        // Ajouter la taille de la première dimension
        tableau->tableSymbole->tabDim->dimensions[0] = taille;
    } else {
        // Récupérer le nombre de dimensions actuel
        int nbDimensionsActuel = tableau->tableSymbole->tabDim->nb_dimensions;
        // Allouer un nouveau tableau de dimensions avec une taille augmentée de 1
        int* newDimensions = (int*) malloc((nbDimensionsActuel + 1) * sizeof(int));
        // Copier les dimensions actuelles dans le nouveau tableau
        memcpy(newDimensions, tableau->tableSymbole->tabDim->dimensions, nbDimensionsActuel * sizeof(int));
        // Libérer l'ancien tableau de dimensions
        free(tableau->tableSymbole->tabDim->dimensions);
        // Affecter le nouveau tableau de dimensions au nœud
        tableau->tableSymbole->tabDim->dimensions = newDimensions;
        // Ajouter la taille de la nouvelle dimension à la fin du tableau
        tableau->tableSymbole->tabDim->dimensions[nbDimensionsActuel] = taille;
        // Augmenter le nombre de dimensions
        tableau->tableSymbole->tabDim->nb_dimensions++;
    }
}

noeud* declarerTableau(noeud* arbre, char* nomTableau, int taille, int dimensions) {
    if (arbre == NULL) {
        printf("Erreur : l'arbre est NULL.\n");
        return NULL;
    }
    if (nomTableau == NULL) {
        printf("Erreur : le nom du tableau est NULL.\n");
        return NULL;
    }
    if (taille <= 0) {
        printf("Erreur : la taille du tableau est invalide.\n");
        return NULL;
    }
    if (dimensions <= 0) {
        printf("Erreur : le nombre de dimensions du tableau est invalide.\n");
        return NULL;
    }
    if (checkIdentName(nomTableau) == false) {
        return NULL;
    }
    if (rechercherNoeud(arbre, nomTableau) != NULL) {
        printf("Erreur : le tableau '%s' est déjà déclaré.\n", nomTableau);
        return NULL;
    }

    // Création du nœud du tableau
    noeud* tableau = creerNoeud(nomTableau);
    tableau->tableSymbole->typeu = INTARRAY;
    tableau->tableSymbole->tailleTab = taille; // Assigner la taille du tableau

    // Si le tableau a plusieurs dimensions
    if (dimensions > 1) {
        // Création du tableau de dimensions
        int* dimensionsArray = malloc(dimensions * sizeof(int));
        dimensionsArray[0] = taille;

        // Création de nœuds pour chaque dimension
        for (int i = 1; i < dimensions; i++) {
            // Création du nœud de dimension
            char nomDimension[15];
            sprintf(nomDimension, "dimension%d", i + 1);
            noeud* dimension = creerNoeud(nomDimension);
            dimension->tableSymbole->typeu = INTEGER;
            dimension->val = malloc(10 * sizeof(char)); // Allocation mémoire pour la valeur
            sprintf(dimension->val, "%d", taille);

            // Ajout du nœud de dimension au tableau
            appendChild1(tableau, dimension);

            // Ajout de la taille de la dimension au tableau de dimensions
            dimensionsArray[i] = taille;
        }

        // Assigner le tableau de dimensions au tableau principal
        tableau->tableSymbole->tabDim = malloc(sizeof(TableauDimensions));
        tableau->tableSymbole->tabDim->dimensions = dimensionsArray;
        tableau->tableSymbole->tabDim->nb_dimensions = dimensions;
    } else {
        // Cas où le tableau a une seule dimension
        tableau->tableSymbole->tabDim= malloc(sizeof(TableauDimensions));
        tableau->tableSymbole->tabDim->dimensions = malloc(sizeof(int));
        tableau->tableSymbole->tabDim->dimensions[0] = taille;
        tableau->tableSymbole->tabDim->nb_dimensions = dimensions;
    }

    // Ajout du nœud du tableau à l'arbre
    appendChild1(arbre, tableau);

    return arbre;
}


liste_error* addNewError(liste_error* liste, char* message, int line) {
    error* newError = malloc(sizeof(error));
    newError->message = message;
    newError->line = line;
    if (liste==NULL){
        liste = malloc(sizeof(liste_error));
        liste->nb_error = 1;
        liste->liste_error = malloc(sizeof(error*));
        liste->liste_error[0] = newError;
        return liste;
    }
    liste->nb_error++;
    liste->liste_error = realloc(liste->liste_error, liste->nb_error * sizeof(error*));
    liste->liste_error[liste->nb_error - 1] = newError;
    return liste;
}

liste_error* addNewListError(liste_error* error1, liste_error* error2){
    if (error1 == NULL) {
        return error2;
    }
    if (error2 == NULL) {
        return error1;
    }
    liste_error* newList = malloc(sizeof(liste_error));
    newList->nb_error = error1->nb_error + error2->nb_error;
    newList->liste_error = malloc(newList->nb_error * sizeof(error*));
    for (int i = 0; i < error1->nb_error; i++) {
        newList->liste_error[i] = error1->liste_error[i];
    }
    for (int i = 0; i < error2->nb_error; i++) {
        newList->liste_error[i + error1->nb_error] = error2->liste_error[i];
    }
    return newList;
}

void afficherError(error* error){
    if (error == NULL)
    {
        printf("Erreur : l'erreur est NULL.\n");
    }
    
    printf("Erreur : ligne %d -> %s\n", error->line, error->message);
}

bool afficherErrors(liste_error* liste){
    if (liste == NULL) {
        return false;
    }
    printf("Nombre d'erreur(s) : %d\n", liste->nb_error);
    for (int i = 0; i < liste->nb_error; i++) {
        afficherError(liste->liste_error[i]);
    }
    clearFile();
    return true;
}

 liste_error* checkInBlock(noeud* n, noeud* arbreGlobal, liste_error* listeError){
    if (n == NULL) {
        printf("Erreur : l'arbre est NULL.\n");
        return NULL;
    }
    if (strcmp(n->val, "BLOC") == 0) {
        if (n->type==GLOBAL){
        listeError = verifierDeclarations(n,NULL,listeError);
        }
        else{
        listeError = verifierDeclarations(n,arbreGlobal->fils[0],listeError);
        listeError = rechercherAffect(arbreGlobal,arbreGlobal->fils[0],n,n,listeError);
        }
    }
    else{   
        for (int i = 0; i < n->nb_fils; i++) {
        if (n->fils[i] != NULL) {
            listeError=checkInBlock(n->fils[i],arbreGlobal,listeError);
        }
    }
    }
    return listeError;
}

noeud* rechercherFonction(noeud* noeudCourant, const char* nomFonction) {
    if (noeudCourant == NULL) {
        return NULL;
    }
    if ((noeudCourant->type == FONCTION || noeudCourant->type == EXTERNE) && strcmp(noeudCourant->tableSymbole->name, nomFonction) == 0) {
        return noeudCourant;
    }

    for (int i = 0; i < noeudCourant->nb_fils; i++) {
        noeud* resultat = rechercherFonction(noeudCourant->fils[i], nomFonction);
        if (resultat != NULL) {
            return resultat;
        }
    }
    return NULL;
}

liste_error* verifierTypeRetourINT(noeud* n,noeud* fonction, NoeudType typeAttendu, liste_error* liste) {
    if (n == NULL) {
        return liste;
    }
    if (strcmp(n->val, "RETURN")==0) {
        if (n->nb_fils == 0) {
            char* message = malloc(100 * sizeof(char));
            if (strcmp(fonction->tableSymbole->name, "main") == 0) {
                printf("Warning : Ligne %d -> la fonction 'main' doit retourner un entier.\n", n->tableSymbole->line);
            } else {
                sprintf(message, "La fonction '%s' de type 'int' ne retourne rien.", fonction->tableSymbole->name);
                message = realloc(message, strlen(message) * sizeof(char));
                liste = addNewError(liste, message, n->tableSymbole->line);
                afficherErrors(liste);
                exit(1);
            }
        } else if (n->fils[0]->type == APPELFONCTION) {
            char* nomFonctionReturn = n->fils[0]->val;
            noeud* fonctionReturn = rechercherFonction(n, nomFonctionReturn);
            verifierTypeRetourINT(fonctionReturn, fonction, typeAttendu, liste);
        } else if (n->fils[0]->tableSymbole->typeu != typeAttendu) {
            char* message = malloc(100 * sizeof(char));
            sprintf(message, "le type de retour de la fonction '%s' est incorrect", fonction->val);
            message = realloc(message, strlen(message) * sizeof(char));
            liste = addNewError(liste, message, n->tableSymbole->line);
            afficherErrors(liste);
            exit(1);
        }
    }
    for (int i = 0; i < n->nb_fils; i++) {
        verifierTypeRetourINT(n->fils[i], fonction, typeAttendu, liste);
    }
    return liste;
}

bool ifNoReturn(noeud* n) {
    if (n == NULL) {
        return true;
    }
    if (strcmp(n->val, "RETURN") == 0) {
        return false;
    }
    for (int i = 0; i < n->nb_fils; i++) {
        if (!ifNoReturn(n->fils[i])) {
            return false;
        }
    }
    return true;
}

liste_error* verifierTypeRetourVoid(noeud* n, noeud* fonction, NoeudType typeAttendu, liste_error* liste) {
    if (n == NULL) {
        return liste;
    }
    
    if (strcmp(n->val, "RETURN")==0) {
        if (n->nb_fils == 0) {
            return liste;
        } else if (n->fils[0]->type == APPELFONCTION) {
            char* nomFonctionReturn = n->fils[0]->val;
            noeud* fonctionReturn = rechercherFonction(n, nomFonctionReturn);
            verifierTypeRetourVoid(fonctionReturn, fonction, typeAttendu, liste);
        } else if (n->fils[0]->tableSymbole->typeu != typeAttendu) {
            char* message = malloc(100 * sizeof(char));
            sprintf(message, "le type de retour de la fonction '%s' est incorrect", fonction->val);
            message = realloc(message, strlen(message) * sizeof(char));
            liste = addNewError(liste, message, n->tableSymbole->line);
            afficherErrors(liste);
            exit(1);
        }
    }
    
    for (int i = 0; i < n->nb_fils; i++) {
        verifierTypeRetourVoid(n->fils[i],fonction, typeAttendu, liste);
    }
    return liste;
}

liste_error* verifierAppelFonction(noeud* n, noeud* racine, liste_error* liste){
    if (n == NULL) {
        return liste;
    }
    if (n->type == APPELFONCTION) {
        char* nomFonction = n->val;
        noeud* fonction = rechercherFonction(racine, nomFonction);
        if (fonction == NULL) {
            char* message = malloc(100 * sizeof(char));
            sprintf(message, "la fonction '%s' n'est pas déclarée.", nomFonction, n->tableSymbole->line);
            message = realloc(message, strlen(message) * sizeof(char));
            liste = addNewError(liste, message, n->tableSymbole->line);
            afficherErrors(liste);
            exit(1);
        }
        if (fonction->tableSymbole->fonction->nbParametres != n->tableSymbole->fonction->nbParametres) {
            char* message = malloc(100 * sizeof(char));
            sprintf(message, "la fonction '%s' n'a pas le bon nombre de paramètres.", nomFonction, n->tableSymbole->line);
            message = realloc(message, strlen(message) * sizeof(char));
            liste = addNewError(liste, message, n->tableSymbole->line);
            afficherErrors(liste);
            exit(1);
        }
    }
    for (int i = 0; i < n->nb_fils; i++) {
        verifierAppelFonction(n->fils[i], racine, liste);
    }
    return liste;
}

liste_error* verifierExpressionsArithmetiques(noeud* n, noeud* racine, noeud* bloc, liste_error* liste) {
    if (n == NULL) {
        return liste;
    }

    if (n->type == OPERATEUR) {
        for (int j=0; j<n->nb_fils; j++){
            if (n->fils[j]->type == APPELFONCTION) {
                noeud* fonction = rechercherFonction(racine->fils[1], n->fils[1]->val);
                if (fonction != NULL) {
                    NoeudType typeRetour = fonction->tableSymbole->fonction->typeRetour;
                    if (strcmp(fonction->tableSymbole->name,"main")==0){
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "la fonction '%s' ne peut pas être appelée dans une expression arithmétique.", n->fils[j]->val);
                        message = realloc(message, strlen(message) * sizeof(char));
                        liste = addNewError(liste, message, n->fils[j]->tableSymbole->line);
                        afficherErrors(liste);
                        exit(1);
                    }
                    if (typeRetour != INTEGER) {
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "la fonction '%s' ne retourne pas un type INT.", n->fils[j]->val);
                        message = realloc(message, strlen(message) * sizeof(char));
                        liste = addNewError(liste, message, n->fils[j]->tableSymbole->line);
                        afficherErrors(liste);
                        exit(1);
                    }
                } else {
                    char* message = malloc(100 * sizeof(char));
                    sprintf(message, "la fonction '%s' n'est pas déclarée.", n->fils[j]->val);
                    message = realloc(message, strlen(message) * sizeof(char));
                    liste = addNewError(liste, message, n->fils[j]->tableSymbole->line);
                    afficherErrors(liste);
                    exit(1);
                }
            } else {
                NoeudType typeValeur = n->fils[j]->tableSymbole->typeu;
                if (typeValeur != INTEGER) {
                    char* message = malloc(100 * sizeof(char));
                    sprintf(message, "la variable '%s' doit être affectée avec une valeur de type INT.", n->fils[j]->val);
                    message = realloc(message, strlen(message) * sizeof(char));
                    liste = addNewError(liste, message, n->fils[j]->tableSymbole->line);
                    afficherErrors(liste);
                    exit(1);
                }
                else if (n->fils[j]->type != CONSTANTEE && n->fils[j]->type != OPERATEUR){
                    if (rechercherVariable(bloc,n->fils[j]->val,racine->fils[0])==NULL){
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "la variable '%s' n'est pas déclarée.", n->fils[j]->val);
                        message = realloc(message, strlen(message) * sizeof(char));
                        liste = addNewError(liste, message, n->fils[j]->tableSymbole->line);
                        afficherErrors(liste);
                        exit(1);
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n->nb_fils; i++) {
        verifierExpressionsArithmetiques(n->fils[i], racine, bloc, liste);
    }

    return liste;
}

liste_error* verifierDeclarationFonction(noeud* n, liste_error* liste) {
    for (int i = 0; i < n->nb_fils; i++) {
        if (n->fils[i] == NULL) {
            continue;
        }
        noeud* fonction = n->fils[i];
        char* nomFonction = fonction->tableSymbole->name;
        // Vérifier si la fonction est unique
        for (int j = 0; j < n->nb_fils; j++) {
            if (n->fils[j] == NULL && j<n->nb_fils-1) {
                continue;
            }
            if (i == j) {
                continue;
            }
            noeud* autreFonction = n->fils[j];
            if (strcmp(nomFonction, autreFonction->tableSymbole->name) == 0) {
                char* message = malloc(100 * sizeof(char));
                sprintf(message, "la fonction '%s' est déjà déclarée.", nomFonction);
                message = realloc(message, strlen(message) * sizeof(char));
                liste = addNewError(liste, message, autreFonction->tableSymbole->line);
                n->fils[j]=NULL;
                break;
            }
        }
        NoeudType typeRetour = fonction->tableSymbole->fonction->typeRetour;
        if (typeRetour == INTEGER){
            liste=verifierTypeRetourINT(fonction,fonction, typeRetour, liste);
            if (fonction->type!=EXTERNE) {
                if (ifNoReturn(fonction)) {
                    if (strcmp(nomFonction, "main") != 0) {
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "la fonction '%s' ne retourne rien", nomFonction);
                        message = realloc(message, strlen(message) * sizeof(char));
                        liste = addNewError(liste, message, fonction->tableSymbole->line);
                    }else{
                        printf("Warning : Ligne %d : la fonction 'main' ne retourne rien.\n",fonction->tableSymbole->line);
                    }
                }
            }
        } else if (typeRetour == VOIDE){
            liste=verifierTypeRetourVoid(fonction,fonction, typeRetour, liste);
        }
    }
    verifierAppelFonction(n, n, liste);
    return liste;
}

noeud* rechercherVariable(noeud* prog,char* varName, noeud* arbreGlobal) {
    noeud* arbreDeclaration = creerNoeud("arbreDeclaration");
    liste_noeud* liste;
    if (arbreGlobal == NULL) {
        liste = prog->tableSymbole->fonction->declaration;
    }
    else{
        liste = addNoeudList(arbreGlobal->tableSymbole->fonction->declaration,prog->tableSymbole->fonction->declaration);
    }
    arbreDeclaration=addAllChild(arbreDeclaration, liste);

    for (int i = 0; i < arbreDeclaration->nb_fils; i++) {
        for (int k = 0; k < arbreDeclaration->fils[i]->nb_fils; k++) {
            noeud* declaration = arbreDeclaration->fils[i]->fils[k];
            char* nomVariable = declaration->tableSymbole->name;
            if (strcmp(nomVariable, varName) == 0) {
                return declaration;
            }
        }
    }
    return NULL;
}

liste_error* rechercherAffect(noeud* prog, noeud* arbreGlobal, noeud* n, noeud* bloc, liste_error* listeError){
    if (n == NULL) {
        return listeError;
    }
    if(strcmp(n->val,"RETURN")==0){
        if (n->nb_fils==1) {
            if(n->fils[0]->type==OPERATEUR){
                verifierExpressionsArithmetiques(n, prog, bloc, listeError);
            }
            else if(n->fils[0]->tableSymbole->typeu==INTEGER && n->fils[0]->type!=CONSTANTEE){
                if(rechercherVariable(prog,n->fils[0]->val,arbreGlobal)==NULL){
                    char* message = malloc(100 * sizeof(char));
                    sprintf(message, "la variable '%s' n'est pas déclarée.", n->fils[0]->val);
                    message = realloc(message, strlen(message) * sizeof(char));
                    listeError = addNewError(listeError, message, n->tableSymbole->line);
                    afficherErrors(listeError);
                    exit(1);
                }
            }
        }
    }
    if(n->type == OPERATEUR){
        verifierExpressionsArithmetiques(n, prog, bloc, listeError);
    }
    if(n->type == SWITCHE){
        if (rechercherVariable(bloc,n->fils[0]->val,arbreGlobal)==NULL){
            char* message = malloc(100 * sizeof(char));
            sprintf(message, "la variable '%s' n'est pas déclarée.", n->fils[0]->val);
            message = realloc(message, strlen(message) * sizeof(char));
            listeError = addNewError(listeError, message, n->tableSymbole->line);
            afficherErrors(listeError);
            exit(1);
        }
    }
    if(n->type == AFFECTATION && strcmp(n->val,"TAB")!=0){
        if ((n->fils[0]->tableSymbole->typeu == INTEGER) && (strcmp(n->fils[0]->val,"TAB")!=0)) {
            if (rechercherVariable(bloc,n->fils[0]->val,arbreGlobal) == NULL) {
                char* message = malloc(100 * sizeof(char));
                sprintf(message, "la variable '%s' n'est pas déclarée.", n->fils[0]->val);
                message = realloc(message, strlen(message) * sizeof(char));
                listeError = addNewError(listeError, message, n->fils[0]->tableSymbole->line);
                afficherErrors(listeError);
                exit(1);
            }
            if (n->fils[1]->type == OPERATEUR) {
                verifierExpressionsArithmetiques(n, prog, bloc, listeError);        
            }       

            if (n->fils[1]->type == FONCTION && n->fils[1]->tableSymbole->fonction->typeRetour != INTEGER) {
                char* message = malloc(100 * sizeof(char));
                sprintf(message, "L'affectation ne peut pas se faire avec la fonction '%s' de type void.", n->fils[0]->val);
                message = realloc(message, strlen(message) * sizeof(char));
                listeError = addNewError(listeError, message, n->fils[0]->tableSymbole->line);
                afficherErrors(listeError);
            }
            if ((n->fils[1]->tableSymbole->typeu == INTEGER) && (n->fils[1]->type != CONSTANTEE) && (n->fils[1]->type != OPERATEUR)) {
                if (rechercherVariable(bloc,n->fils[1]->val,arbreGlobal) == NULL) {
                char* message = malloc(100 * sizeof(char));
                sprintf(message, "la variable '%s' n'est pas déclarée.", n->fils[1]->val);
                message = realloc(message, strlen(message) * sizeof(char));
                listeError = addNewError(listeError, message, n->fils[0]->tableSymbole->line);
                afficherErrors(listeError);
                exit(1);
            }
            }
            else {
                return listeError;
            }
        }
        else if (n->fils[0]->tableSymbole->typeu == INTEGER){
            return listeError;
        }
        else{
            char* message = malloc(100 * sizeof(char));
            sprintf(message, "L'affectation '%s' ne peut être que sur des variables.", n->fils[0]->tableSymbole->name);
            message = realloc(message, strlen(message) * sizeof(char));
            listeError = addNewError(listeError, message, n->fils[0]->tableSymbole->line);
            afficherErrors(listeError);
            exit(1);
        }
    }
    for (int i=0;i<n->nb_fils;i++){
        rechercherAffect(prog,arbreGlobal,n->fils[i],bloc,listeError);
    }
    
    return listeError;
}

liste_error* verifierDeclarations(noeud* prog, noeud* arbreGlobal, liste_error* listeError) {
    noeud* arbreDeclaration = creerNoeud("arbreDeclaration");
    liste_noeud* liste;
    if (arbreGlobal == NULL) {
        liste = prog->tableSymbole->fonction->declaration;
    }
    else{
        liste = addNoeudList(arbreGlobal->tableSymbole->fonction->declaration,prog->tableSymbole->fonction->declaration);
    }
    arbreDeclaration=addAllChild(arbreDeclaration, liste);
    for (int i = 0; i < arbreDeclaration->nb_fils; i++) {
        for (int k = 0; k < arbreDeclaration->fils[i]->nb_fils; k++) {
            if (arbreDeclaration->fils[i]->fils[k]==NULL){
                continue;
            }
            noeud* declaration = arbreDeclaration->fils[i]->fils[k];
            // Vérifier si la déclaration est unique
            char* nomVariable = declaration->tableSymbole->name;
            for (int j = 0; j < arbreDeclaration->nb_fils; j++) {
                for (int l=0;l<arbreDeclaration->fils[j]->nb_fils;l++){
                    if (i==j && k==l){
                        continue;
                    }
                    if (arbreDeclaration->fils[j]->fils[l]==NULL){
                        continue;
                    }
                    if (strcmp(nomVariable, arbreDeclaration->fils[j]->fils[l]->tableSymbole->name) == 0) {
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "la variable '%s' est déjà déclarée.", nomVariable);
                        message = realloc(message, strlen(message) * sizeof(char));
                        listeError = addNewError(listeError, message, arbreDeclaration->fils[j]->fils[l]->tableSymbole->line);
                        arbreDeclaration->fils[j]->fils[l]=NULL;
                        break;
                    }
                }
            }
        // Vérifier le type de la variable
        NoeudType typeVariable = declaration->tableSymbole->typeu;
        if (typeVariable != INTEGER && typeVariable != INTARRAY) {
            char* message = malloc(100 * sizeof(char));
            sprintf(message, "le type de la variable '%s' est incorrect", nomVariable);
            message = realloc(message, strlen(message) * sizeof(char));
            listeError = addNewError(listeError, message, declaration->tableSymbole->line);
        }
        }
    }
    return listeError;
}

noeud* makeSwitchPretty(noeud* n){
    int indice=-1;
    int compteur=0;
    liste_error* listeError = NULL;
    for (int i = 0; i<n->nb_fils;i++){
        if (strcmp("DEFAULT",n->fils[i]->val)==0){
            compteur++;
        }
    }
    if (compteur!=1){
        char* message = malloc(100 * sizeof(char));
        sprintf(message, "Il doit y avoir un seul DEFAULT dans un switch.");
        message = realloc(message, strlen(message) * sizeof(char));
        listeError = addNewError(listeError, message, n->tableSymbole->line);
        afficherErrors(listeError);
        exit(1);
    }
        for (int i = 0; i<n->nb_fils;i++){
        if (strcmp("CASE",n->fils[i]->val)==0 || strcmp("DEFAULT",n->fils[i]->val)==0){
            indice = i;
        }
        else{
            if (indice!=-1){
                n->fils[indice]->nb_fils++;
                n->fils[indice]=realloc(n->fils[indice],sizeof(noeud)*n->fils[indice]->nb_fils);
                n->fils[indice]->fils[n->fils[indice]->nb_fils-1]=n->fils[i];
                n->fils[i]=NULL;
            }
        }
    }

    for (int i=0;i<n->nb_fils;i++){
        if (n->fils[i]!=NULL && strcmp("CASE",n->fils[i]->val)==0){
            for (int j=0;j<n->nb_fils;j++){
                if (i==j){
                    continue;
                }
                if (n->fils[j]!=NULL && strcmp("CASE",n->fils[j]->val)==0){
                    if(strcmp(n->fils[i]->fils[0]->val,n->fils[j]->fils[0]->val)==0){
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "Il ne peut pas y avoir deux CASE avec la même valeur.");
                        message = realloc(message, strlen(message) * sizeof(char));
                        listeError = addNewError(listeError, message, n->tableSymbole->line);
                        afficherErrors(listeError);
                        exit(1);
                    }
                }
            }
        }
    }
    return n;
}