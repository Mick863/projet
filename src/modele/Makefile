# Définition du compilateur et des options
CPP = g++ --std=c++17 -Wall

# Fichiers sources spécifiques
SRCS = main.cpp Case.cpp CaseGagnante.cpp CaseJeu.cpp CasePaysage.cpp Jeu.cpp Piece.cpp PieceI.cpp PieceL.cpp PieceO.cpp PieceT.cpp PieceZ.cpp Plateau.cpp Position.cpp config.cpp

# Fichiers objets générés à partir des fichiers sources
OBJECTS = $(SRCS:.cpp=.o)

# Nom de l'exécutable
EXEC = run

# Règle par défaut : créer l'exécutable
all: $(EXEC)

# Règle pour créer l'exécutable
$(EXEC): $(OBJECTS)
	$(CPP) -o $@ $(OBJECTS)
	valgrind ./run


# Règle pour générer les fichiers objets à partir des fichiers sources
%.o: %.cpp
	$(CPP) -c $< -o $@

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJECTS) $(EXEC)

# Règle pour forcer une recompilation complète
rebuild: clean all

# Règle pour afficher les fichiers objets générés
list_objs:
	@echo "Fichiers objets générés :"
	@echo $(OBJECTS)


