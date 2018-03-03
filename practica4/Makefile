INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g


all: $(BIN)/prueba $(BIN)/union $(BIN)/palabraclave $(BIN)/filtradointervalo $(BIN)/estadisticaevento

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/prueba : $(SRC)/pruebacronologia.cpp $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o 
	$(CXX) -o $(BIN)/prueba $(SRC)/pruebacronologia.cpp -I$(INC) $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o

$(BIN)/union : $(SRC)/union.cpp $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o 
	$(CXX) -o $(BIN)/union $(SRC)/union.cpp -I$(INC) $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o

$(BIN)/palabraclave : $(SRC)/palabraclave.cpp $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o 
	$(CXX) -o $(BIN)/palabraclave $(SRC)/palabraclave.cpp -I$(INC) $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o

$(BIN)/filtradointervalo : $(SRC)/filtradointervalo.cpp $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o 
	$(CXX) -o $(BIN)/filtradointervalo $(SRC)/filtradointervalo.cpp -I$(INC) $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o

$(BIN)/estadisticaevento : $(SRC)/estadisticaevento.cpp $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o 
	$(CXX) -o $(BIN)/estadisticaevento $(SRC)/estadisticaevento.cpp -I$(INC) $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o


$(OBJ)/Cronologia.o : $(SRC)/Cronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp

$(OBJ)/Fecha_Historica.o : $(SRC)/Fecha_Historica.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Fecha_Historica.o $(SRC)/Fecha_Historica.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f $(BIN)/* doc/html/*
