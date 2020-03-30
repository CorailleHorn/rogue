all : bin/txt_regression bin/txt_jeu

bin/txt_regression : obj/mainRegressionP.o obj/Personnages.o
	g++ -Wall -ggdb obj/mainRegressionP.o obj/Personnages.o -o bin/txt_regression

bin/txt_jeu : obj/main.o obj/txtJeu.o obj/Map.o obj/Room.o obj/Personnages.o
	g++ -Wall -ggdb obj/main.o obj/txtJeu.o obj/Map.o obj/Room.o obj/Personnages.o -o bin/txt_jeu

#bin/exec_gen_test : obj/RegressionGeneration.o obj/Room.o obj/Map.o obj/Personnages.o
#	g++ -Wall -ggdb obj/RegressionGeneration.o obj/Room.o obj/Map.o -o bin/exec_gen_test

obj/main.o : src/main.cpp src/txtJeu.h src/Map.h src/Room.h src/Personnages.h
	g++ -Wall -ggdb	-c src/main.cpp -o obj/main.o

obj/mainRegressionP.o : src/mainRegressionP.cpp src/Personnages.h
	g++ -Wall -ggdb	-c src/mainRegressionP.cpp -o obj/mainRegressionP.o

obj/txtJeu.o : src/txtJeu.cpp src/txtJeu.h src/Map.cpp src/Map.h src/Room.h src/Personnages.h
	g++ -Wall -ggdb	-c src/txtJeu.cpp -o obj/txtJeu.o

obj/Map.o : src/Map.cpp src/Map.h src/Room.h src/Personnages.h
	g++ -Wall -ggdb -c src/Map.cpp -o obj/Map.o

obj/Personnages.o : src/Personnages.cpp src/Personnages.h
	g++ -Wall -ggdb -c src/Personnages.cpp -o obj/Personnages.o

#obj/RegressionGeneration.o : src/GenerationTest.cpp src/Room.h src/Map.h
#	g++ -Wall -ggdb -c src/RegressionGeneration.cpp -o obj/GenerationTest.o

obj/Room.o : src/Room.cpp src/Room.h
	g++ -Wall -ggdb -c src/Room.cpp -o obj/Room.o

clean :
		rm obj/*.o && rm bin/*
