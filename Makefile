gcc_spanish: main_spanish.cpp
	g++ -o Cubensi main_spanish.cpp

gcc_english: main_english.cpp
	g++ -o Cubensi main_english.cpp

mingw_spanish: main_spanish.cpp
	g++.exe -o Cubensi.exe main_spanish.cpp
  
mingw_english: main_english.cpp
	g++.exe -o Cubensi.exe main_english.cpp

clean:
	rm Cubensi
	rm Cubensi.exe
