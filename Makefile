all : bin/SFML_jeu

	#Test

test : obj/Contents.o obj/AnimatedSprite.o obj/Animation.o
	g++ -Wall -ggdb obj/Contents.o obj/AnimatedSprite.o obj/Animation.o -o bin/tests -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

obj/Contents.o : src/SFML/Contents.cpp src/SFML/Contents.h src/SFML/AnimatedSprite.h src/SFML/Animation.h
	g++ -Wall -ggdb	-c src/SFML/Contents.cpp -o obj/Contents.o

obj/AnimatedSprite.o : src/SFML/AnimatedSprite.cpp src/SFML/AnimatedSprite.h src/SFML/Animation.h
	g++ -Wall -ggdb	-c src/SFML/AnimatedSprite.cpp -o obj/AnimatedSprite.o

obj/Animation.o : src/SFML/Animation.cpp src/SFML/Animation.h
	g++ -Wall -ggdb	-c src/SFML/Animation.cpp -o obj/Animation.o

		#SFMLJeu

bin/SFML_jeu : obj/SFMLmain.o obj/SFMLJeu.o obj/Contents.o obj/SFMLMap.o obj/SFMLRoom.o obj/SFMLPersonnages.o obj/AnimatedSprite.o obj/Animation.o
	g++ -Wall -ggdb obj/SFMLmain.o obj/SFMLJeu.o obj/SFMLMap.o obj/SFMLRoom.o obj/SFMLPersonnages.o obj/Contents.o obj/AnimatedSprite.o obj/Animation.o -o bin/SFML_jeu -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

obj/SFMLmain.o : src/SFML/main.cpp src/SFML/SFMLJeu.h src/SFML/Map.h src/SFML/Room.h src/SFML/Personnages.h src/SFML/Contents.h src/SFML/AnimatedSprite.h src/SFML/Animation.h
	g++ -Wall -ggdb	-c src/SFML/main.cpp -o obj/SFMLmain.o

obj/SFMLJeu.o : src/SFML/SFMLJeu.cpp src/SFML/SFMLJeu.h src/SFML/Map.h src/SFML/Room.h src/SFML/Personnages.h src/SFML/Contents.h src/SFML/AnimatedSprite.h src/SFML/Animation.h
	g++ -Wall -ggdb	-c src/SFML/SFMLJeu.cpp -o obj/SFMLJeu.o

obj/Contents.o : src/SFML/Contents.cpp src/SFML/Contents.h src/SFML/AnimatedSprite.h src/SFML/Animation.h
	g++ -Wall -ggdb	-c src/SFML/Contents.cpp -o obj/Contents.o

obj/SFMLMap.o : src/SFML/Map.cpp src/SFML/Map.h src/SFML/Room.h src/SFML/Personnages.h
	g++ -std=c++11 -Wall -ggdb -c src/SFML/Map.cpp -o obj/SFMLMap.o

obj/SFMLPersonnages.o : src/SFML/Personnages.cpp src/SFML/Personnages.h src/SFML/AnimatedSprite.h src/SFML/Animation.h
	g++ -std=c++11 -Wall -ggdb -c src/SFML/Personnages.cpp -o obj/SFMLPersonnages.o

obj/AnimatedSprite.o : src/SFML/AnimatedSprite.cpp src/SFML/AnimatedSprite.h src/SFML/Animation.h
	g++ -Wall -ggdb	-c src/SFML/AnimatedSprite.cpp -o obj/AnimatedSprite.o

obj/Animation.o : src/SFML/Animation.cpp src/SFML/Animation.h
	g++ -Wall -ggdb	-c src/SFML/Animation.cpp -o obj/Animation.o

obj/SFMLRoom.o : src/SFML/Room.cpp src/SFML/Room.h
	g++ -Wall -ggdb -c src/SFML/Room.cpp -o obj/SFMLRoom.o


		#txtJeu

#bin/txt_regression : obj/mainRegressionP.o obj/Personnages.o
#	g++ -Wall -ggdb obj/mainRegressionP.o obj/Personnages.o -o bin/txt_regression

bin/txt_jeu : obj/txtmain.o obj/txtJeu.o obj/txtMap.o obj/txtRoom.o obj/txtPersonnages.o
	g++ -Wall -ggdb obj/txtmain.o obj/txtJeu.o obj/txtMap.o obj/txtRoom.o obj/txtPersonnages.o -o bin/txt_jeu

#bin/exec_gen_test : obj/RegressionGeneration.o obj/Room.o obj/Map.o obj/Personnages.o
#	g++ -Wall -ggdb obj/RegressionGeneration.o obj/Room.o obj/Map.o -o bin/exec_gen_test

obj/txtmain.o : src/txt/main.cpp src/txt/txtJeu.h src/txt/Map.h src/txt/Room.h src/txt/Personnages.h
	g++ -Wall -ggdb	-c src/txt/main.cpp -o obj/txtmain.o

#obj/RegressionGeneration.o : src/txt/RegressionGeneration.cpp src/txt/Map.h src/txt/Personnages.h src/txt/Room.h
#	g++ -Wall -ggdb	-c src/txt/RegressionGeneration.cpp -o obj/RegressionGeneration.o

#obj/mainRegressionP.o : src/txt/mainRegressionP.cpp src/txt/Personnages.h
#	g++ -Wall -ggdb	-c src/txt/mainRegressionP.cpp -o obj/mainRegressionP.o

obj/txtJeu.o : src/txt/txtJeu.cpp src/txt/txtJeu.h src/txt/Map.cpp src/txt/Map.h src/txt/Room.h src/txt/Personnages.h
	g++ -Wall -ggdb	-c src/txt/txtJeu.cpp -o obj/txtJeu.o

obj/txtMap.o : src/txt/Map.cpp src/txt/Map.h src/txt/Room.h src/txt/Personnages.h
	g++ -std=c++11 -Wall -ggdb -c src/txt/Map.cpp -o obj/txtMap.o

obj/txtPersonnages.o : src/txt/Personnages.cpp src/txt/Personnages.h
	g++ -std=c++11 -Wall -ggdb -c src/txt/Personnages.cpp -o obj/txtPersonnages.o

obj/txtRoom.o : src/txt/Room.cpp src/txt/Room.h
	g++ -Wall -ggdb -c src/txt/Room.cpp -o obj/txtRoom.o

clean :
		rm obj/*.o && rm bin/*
