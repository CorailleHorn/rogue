# Rogue

#EN
Rogue is a second year Computer Science Degree project, consisting in the procedural generation of a dungeon (2D structure composed of a random number of randomly sized rooms linked by corridors) in C++ , with the addition of a gameplay start in the SFML library.

This Project was carried out by : 

Louis Celerier (Gameplay)
Manon Billet (Gameplay)
Jean (Field Generation)

Keys :
	a + Enter : Exit
	z + Enter : Top
	q + Enter : Left
	s + Enter : Bottom
	d + Enter: Right

#FR
Rogue est un projet de deuxième année de Licence informatique, consistant en la génération procédurale d'un donjon (structure 2D composée d'un nombre aléatoire de chambres de tailles aléaotoire relié par des couloirs) en C++ , avec l'ajout d'un début de gameplay dans la bibliothèque SFML.

Ce Projet a été mené a bien par : 

Louis Celerier (Gameplay)
Manon Billet (Gameplay)
Jean (Génération du terrain)

Pour lancer le programme (ubuntu) : 
- Vous devez d'abord vous assurer d'avoir installé g++ ainsi que la biliothèque SFML : 
	```bash 
	sudo apt install g++
	sudo apt-get install libsfml-dev
	```
- Ensuite vous devez créer à la racine du dossier rogue/ deux répertoires obj/ et bin/ (ce dernier contiendra ses executables) :
	```bash
	mkdir obj bin
	```
- Après vous devrez lancer la commande suivante pour générer les executables : 
	```bash
	make
	```
- Enfin vous pouvez executer le programme (mode graphique ou mode texte) :
	```bash
	./bin/SFML_jeu
  	./bin/txt_jeu
	```
	

Touches :
	a + Enter : Sortir
	z + Enter : Haut
	q + Enter : Gauche
	s + Enter : Bas
	d + Enter : Droite
