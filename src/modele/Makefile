# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.
SRC = Case.cpp Position.cpp Piece.cpp PieceO.cpp Plateau.cpp config.cpp Jeu.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = jeu

# Règles principales
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean

