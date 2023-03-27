all:
	g++ main.cpp Ukol1/Tree.cpp Ukol2/Polozka.cpp Ukol2/Osoba.cpp Ukol2/Faktura.cpp -o main
clean: 
	rm -rf main