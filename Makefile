#------------------------------------------------------------------------------

SOURCE=src/relacionamento.cpp src/metodo.cpp src/classe.cpp src/gerador.cpp main.cpp
UNITTEST_SRC=src/relacionamento.cpp src/metodo.cpp src/classe.cpp src/gerador.cpp unittest/unittest.cpp
MYPROGRAM=bin/geradorcpp
UNITTEST=unittest/unittest
MYINCLUDE1=./include/
MYINCLUDE2=./unittest/

MYLIBRARIES=boost
CC=g++

#------------------------------------------------------------------------------



all: $(MYPROGRAM) $(UNITTEST)

$(UNITTEST): $(UNITTEST_SRC)

	$(CC) -I$(MYINCLUDE1) -I$(MYINCLUDE2) $(UNITTEST_SRC) -o$(UNITTEST) -std=c++98

$(MYPROGRAM): $(SOURCE)
    
	$(CC) -I$(MYINCLUDE1) $(SOURCE) -o$(MYPROGRAM) -std=c++98 #-l$(MYLIBRARIES)

clean:

	rm -f $(MYPROGRAM) $(UNITTEST);\
