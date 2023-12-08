# Makefile para compilar o projeto collision2dtest

# Compilador
CXX = g++
# Opções de compilação
CXXFLAGS = -std=c++11 -Wall

# Diretórios dos arquivos fonte, objeto e cabeçalho
SRCDIR = .
OBJDIR = obj
BINDIR = bin

# Lista de arquivos fonte
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Lista de arquivos objeto gerados
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Nome do executável
EXECUTABLE = $(BINDIR)/main

all: $(OBJDIR) $(BINDIR) $(EXECUTABLE)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lSDL2

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean


