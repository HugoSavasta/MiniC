# MiniC
## Compilation's Project

Ce projet consiste à créer un mini compilateur qui transforme du code en langage C en
un langage de graphes. Le compilateur effectue l'analyse lexicale, syntaxique et
sémantique du code MiniC. 

S'il est conforme aux conventions et à la syntaxe attendue,
le compilateur générera un fichier "fichier.dot" qui pourra être interprété à l'aide
de la commande "dot" pour produire une version PDF.


En cas de code mal formé, le compilateur affichera une erreur indiquant la ligne où
celle-ci se trouve. Les erreurs peuvent être de différentes natures selon leur
origine.

Pour exécuter le compilateur, vous avez deux méthodes disponibles :
Utilisation du makefile : Exécutez la commande "make" pour automatiser l'exécution.
Pour modifier le fichier à compiler, utilisez la commande suivante : make FILE=fichier
Attention : n'incluez pas l'extension ".c" dans le nom du fichier. Le makefile s'en
chargera automatiquement. De plus, le fichier doit se trouver dans le répertoire
"Tests".

## Execution
Utilisation de la commande automatique :
`make FILE="NOMDUFICHIER"`

exemple avec le fichier test break.c
`make FILE=break`

Utilisation des commandes manuelles :
- yacc -d miniC.y 
- flex ANSI-C.l 
- gcc -o compiled lex.yy.c y.tab.c -lfl 
- ./compiled < ./Tests/exempleminiC.c 
- dot -Tpdf DOT.dot -o graph.pdf

Erreurs connues :
- tableaux non prix en charge