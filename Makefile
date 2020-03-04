all : bin/executable_texte

bin/executable_texte : obj/main.o obj/Personnage.o
	g++ obj/main.o obj/Personnage.o -o bin/aincrad

obj/main.o : src/main.cpp src/Personnage.h
	g++ -c src/main.cpp -o obj/main.o

obj/Personnage.o : src/Personnage.cpp src/Personnage.h
	g++ -c src/Personnage.cpp -o obj/Personnage.o

clean :
		rm obj/*.o && rm bin/*
