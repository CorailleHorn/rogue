# Rogue

Notre projet s'appelle Rogue, mini-jeu 2D où le but est de tuer tous les ennemis grâce à notre héro dans une map de jeu.

Groupe: Les 3 Fantastiques
BILLET Manon 11805662
CELERIER Louis 11803338
SAURY Jean 11805563

Lien git: https://forge.univ-lyon1.fr/les-3-fantastiques/rogue

Organisation de notre projet:
- Les executables sont créés dans le dossier bin/ grâce au Makefile.
- Dans le fichier data se trouve toutes les ressources nécessaires à noter projet: les textures du personnages, des ennemis et de la barre de vie, la font pour l'écriture, les sons du jeu.
- Le dossier doc/ regroupe la doxygen, le cahier des charges, le diagramme de gantt, l'UML et le powerpoint de notre soutenance.
- Le dossier obj/ regroupe tous les fichiers objets générés par le Makefile.
- Les fichiers sources se trouvent tous dans le dossier src/, séparés en 2 parties, la partie SFML en graphique et la partie txt en shell.
- Il y a aussi évidemment le Makefile qui permets de générer notre jeu.

Pour lancer notre jeu, il suffit de lancer un "make" à la racine de notre projet.
Ainsi, le Makefile va générer les fichiers objets nécessaires.
Il génère la version SFML et la version TXT.
Une fois la génération de l'éxecutable faite, on l'éxécute à partir du fichier dans le dossier /bin disponible à la racine. Pour lancer la version SFML, on utilise l'executable "SFML_jeu", et pour la version TXT, on utilise l'executable "txt_jeu".

Les commandes:
- Flèche du haut pour monter
- Flèche du bas pour descendre
- Flèche de gauche pour aller à gauche
- Flèche de droite pour aller à droite

Règles du jeu:
Le but est simple, éliminer tous les ennemis de la map. Les ennemis prennent des dégâts automatiquement lorsque le héro est autour d'eux.

Lorsqu'on rentre dans une room, les ennemis sont attirés par le héro et viennent directement à lui.
Lorsque l'ennemi se trouve dans une des 8 cases autour de nous, la fonction de combat se lance et les ennemis comme le héro prennent des dégats.
La partie est finie lorsque le héro a éliminé tous les ennemis de la map sans être mort.
Le héro va ensuite monter de niveau et prendre des points d'attaques et/ou de défense et/ou des pv.

Les ressources se trouvant dans data/ n'ont pas toutes été utilisées.
