## Régler les erreurs d'include
Pour les problèmes d'include avec Qt:
Créer un dossier .vscode dans le root du projet
Dans le dossier creer un fichier c_cpp_properties.json et remplir dans ce style (change path)
```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/home/zclem/Qt/6.6.1/gcc_64/include",
                "/home/zclem/Qt/6.6.1/gcc_64/include/QtWidgets",
                "/home/zclem/Qt/6.6.1/gcc_64/include/QtCore",
                "/home/zclem/Documents/School/Language_Objet/Project_final/build-Test-Desktop_Qt_6_6_1_GCC_64bit-Debug",
                "/home/zclem/Qt/6.6.1/gcc_64/include/QtGui"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64",
            "browse": {
                "path": [
                    "${workspaceFolder}/**",
                    "/home/zclem/Qt/6.6.1/gcc_64/include",
                    "/home/zclem/Documents/School/Language_Objet/Project_final/build-Test-Desktop_Qt_6_6_1_GCC_64bit-Debug"
                ],
                "limitSymbolsToIncludedHeaders": true
            }
        }
    ],
    "version": 4
}
```
-Si c'est des librairie de Qt fait juste ajout rapide au IncludePath
-Si c'est ui_mainwindow.h qui n'est pas trouvé faire pareil que pour le includePath mais avec le path de build-Test-Desktop_Qt_6_6_1_GCC_64bit-Debug

Pour avoir le build: Try building from Qt Creator the program. Le build va être générer automatiquement.
```
To get path
Navigate to the folder
pwd
```

## Compilation du projet

Si erreur avec qmake:
qmake: could not find a Qt installation of ''
```
export PATH=/home/zclem/Qt/6.6.1/gcc_64/bin:$PATH
qmake --version
```

Utilisation de qmake pour générer le Makefile (Attention des modifs sont peu être à faire dans le .pro)
```
qmake -nomduProjet.pro
```

Compilation du projet avec le Makefile nouvellement généré
```
make
```

## Lancement du projet
```
./nomduProjet
```
Quand on fait un changement sur vscode pas beaucoup d'impact car on peut maintenant tout faire sur VSCode théoriquement. Par contre il faut faire un make a chaque fois qu'on veut mettre a jour sur le build.
Sur QtCreator il va falloir la mettre à jour en allant directement sur l'application et en faisant un build. (tout en bas à gauche toolbox)

## Ajout d'élements

### Ajout de classes (header et cpp)
Aller sur QtCreator et faire créer un nouveau fichier.
Sélectionner C++ Class et mettre le nom de la classe.
--> Ajout direct sur le fichier .pro (qui permet de créer le Makefile et donc de compiler le projet)
Ca ou sinon dans le .pro ajouter la ligne suivante manuellement:
```
SOURCES += nomdufichier.cpp
How do i add so that it takes every cpp file in the folder?

HEADERS += nomdufichier.h
```

### Ajout d'élements graphiques
Aller sur QtCreator et aller sur mainwindow.ui ou sur Design.
Ajouter les éléments graphiques souhaités.
ajout sur le mainwindow.ui directement que ce soit Qt ou VSCode





