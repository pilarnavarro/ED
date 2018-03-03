INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -I./$(INC) -c

.PHONY: all clean mrproper

#CUAL_COMPILA=1 
pilamaxVD: $(BIN)/usopila_max_VD 
#CUAL_COMPILAR=2
pilamaxcola: $(BIN)/usopila_max_cola
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de módulos ************
$(BIN)/usopila_max_cola: $(OBJ)/pila_max_cola.o $(OBJ)/usopila_max_cola.o
	$(CXX) -Wall -g -o $(BIN)/usopila_max_cola $(OBJ)/pila_max_cola.o $(OBJ)/usopila_max_cola.o

$(BIN)/usopila_max_VD: $(OBJ)/usopila_max_VD.o $(OBJ)/pila_max_VD.o
	$(CXX) -Wall -g -o $(BIN)/usopila_max_VD $(OBJ)/pila_max_VD.o $(OBJ)/usopila_max_VD.o

$(OBJ)/usopila_max_cola.o : $(SRC)/usopila_max_cola.cpp $(INC)/pila_max.h
	$(CXX) $(CPPFLAGS) $(SRC)/usopila_max_cola.cpp -o $(OBJ)/usopila_max_cola.o

$(OBJ)/usopila_max_VD.o : $(SRC)/usopila_max_VD.cpp $(INC)/pila_max.h
	$(CXX) $(CPPFLAGS) $(SRC)/usopila_max_VD.cpp -o $(OBJ)/usopila_max_VD.o

$(OBJ)/pila_max_cola.o : $(SRC)/pila_max_cola.cpp $(INC)/pila_max_cola.h $(INC)/cola.h $(INC)/cola.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/pila_max_cola.cpp -o $(OBJ)/pila_max_cola.o
	
$(OBJ)/pila_max_VD.o : $(SRC)/pila_max_VD.cpp $(INC)/pila_max_VD.h $(INC)/VDG.h $(INC)/VDG.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/pila_max_VD.cpp -o $(OBJ)/pila_max_VD.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*

tgz: 
	tgz pila_max.tgz
