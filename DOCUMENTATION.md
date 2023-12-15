# PROJET CPP

## Idées

**De base :**
- Simuler l’influence des JO sur Paris, transports, lieux culturels, restaurants.

**Développement :**
- Choisir certains lieux/arrondissements, déterminer l’affluence dans une liste de transports, restaurants, sites touristiques, et autres afin de prévoir l’affluence dans ces endroits.

## Bibliothèques graphiques

- **SFML :** Jeux ++ mais pas vraiment pour l’interface graphique.
- **QT :** Beaucoup plus d'interface graphique, moins pour les jeux vidéos, moins de complexité, utiliser uniquement le makefile et pas l'interface graphique +++++++.
- **GODOT :** Moteur de jeu (++ jeu vidéo unique), avantages comparés à SFML 2D-3D, pas d'informations disponibles.
- **SDL :** (C'est du C 💀).
- ... (Chercher s'il y a plus simple).

## Classes

**Transport :**
- Metro
- RER
- BUS
- TRAM (à voir)

**Lieux :**
- Private virtual affluence
- Private virtual capacité max
- Paris : Zone rouge/grise/bleue, touristique
- Lieux culturels
- Transports : Capacité atteinte
- Monument : Paramètres (nom et affluence)
- Boîte de nuit

## STEPS TO BUILD AN APP

1. Download Qt (prendre la version open source) : [Suivre ce lien](https://www.youtube.com/watch?v=H2ud-ATLIdI)
2. Configurer l’espace de développement : Qt Creator
3. New project dans Qt Creator
4. File -> New file or project : à l'intérieur, choisissez Application -> Qt Widgets Application
5. Conception de l’interface graphique : Editeur de formulaires -> Ouvrir le fichier .ui dans Qt Creator associé au projet
6. Conception : Avec l’éditeur de formulaires, ajoutez des widgets, boutons, champs de texte, etc. (Utilisez la barre latérale pour configurer les widgets)
7. Connexion de l’interface au code C++ : Dans Qt Creator, Build -> Run qmake pour générer le code C++, ouvrir le fichier .cpp associé, ajouter certains boutons
8. Compilation : Dans Qt Creator, cliquer sur le bouton de compilation ou qmake suivi de make dans le terminal
9. Exécution : Cliquer sur le bouton lecture

**Doc Qt :** [https://doc.qt.io/](https://doc.qt.io/)

**Début :**
-simuler des zones
- Afficher une petite carte et l'augmenter de plus en plus


**Ressources**
- [https://www.youtube.com/watch?v=cXojtB8vS2E](https://www.youtube.com/watch?v=cXojtB8vS2E)

- [https://www.youtube.com/watch?v=DchGfN_FudQ&list=PLVGVnMDs8tT8pTRRrdHGJyQIAf-JNGXP5&index=12](https://www.youtube.com/watch?v=DchGfN_FudQ&list=PLVGVnMDs8tT8pTRRrdHGJyQIAf-JNGXP5&index=12)




## ERROR ENCOUNTERED DURING THE INSTALLATION OF QT

- chmod: cannot access 'qt-unified-linux-x64-4.6.1-online.run': No such file or directory bash: ./qt-unified-linux-x64-4.6.1-online.run: No such file or directory lilyn@lilyn-BOHK-WAX9X:~$ vcpkg.exe search qt vcpkg.exe: command not found
**Solution**
Se mettre dans le bon dossier

**Solution :**  
- Erreur linux
```bash
chmod +x qt-unified-linux-x64-4.6.1-online.run
./qt-unified-linux-x64-4.6.1-online.run

```
- Lorsque je voulais faire marcher qt creator
```bash
sudo apt-get install libxcb-cursor0
qmake --version
```

