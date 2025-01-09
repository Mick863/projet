# Compiler et options
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Fichiers sources et objets
SRC = Case.cpp Position.cpp Piece.cpp PieceO.cpp Plateau.cpp config.cpp Jeu.cpp
OBJ = $(SRC:.cpp=.o)

# Nom de l'exécutable
TARGET = jeu

# Règle par défaut : compilation de l'exécutable
default: $(TARGET)

# Compilation de l'exécutable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./jeu
	

# Compilation des fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers intermédiaires
clean:
	rm -f $(OBJ) $(TARGET)

# Nettoyage complet (y compris les sauvegardes)
distclean: clean
	rm -f *~

# Phonies pour éviter les conflits avec des fichiers portant le même nom
.PHONY: default clean distclean
