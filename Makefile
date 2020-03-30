all :bin/executable_texte bin/exec_gen bin/exec_gen_test

bin/executable_texte : obj/mainRegressionP.o obj/Personnages.o
	g++ -Wall -ggdb obj/mainRegressionP.o obj/Personnages.o -o bin/executable_texte

bin/exec_gen : obj/Generation.o obj/Room.o obj/Map.o obj/Personnages.o
	g++ -Wall -ggdb obj/Generation.o obj/Room.o obj/Map.o -o bin/exec_gen

bin/exec_gen_test : obj/GenerationTest.o obj/Room.o obj/Map.o obj/Personnages.o
	g++ -Wall -ggdb obj/GenerationTest.o obj/Room.o obj/Map.o -o bin/exec_gen_test

obj/mainRegressionP.o : src/mainRegressionP.cpp src/Personnages.h
	g++ -Wall -ggdb	-c src/mainRegressionP.cpp -o obj/mainRegressionP.o

obj/Map.o : src/Map.cpp src/Map.h src/Personnages.h
	g++ -Wall -ggdb -c src/Map.cpp -o obj/Map.o

obj/Personnages.o : src/Personnages.cpp src/Personnages.h src/Room.h
	g++ -Wall -ggdb -c src/Personnages.cpp -o obj/Personnages.o

obj/Generation.o : src/Generation.cpp src/Room.h src/Map.h src/Personnages.h
	g++ -Wall -ggdb -c src/Generation.cpp -o obj/Generation.o

obj/GenerationTest.o : src/GenerationTest.cpp src/Room.h src/Map.h
	g++ -Wall -ggdb -c src/GenerationTest.cpp -o obj/GenerationTest.o

obj/Room.o : src/Room.cpp src/Room.h
	g++ -Wall -ggdb -c src/Room.cpp -o obj/Room.o

clean :
		rm obj/*.o && rm bin/*
