# Makefile asetukset
CXX = g++                      # Käytettävä kääntäjä
CXXFLAGS = -std=c++20 -Wall    # C++20 ja varoitukset päälle
TARGET = ./main                  # Luotavan ohjelman nimi
SRC = ./main.cpp                 # Käännettävä lähdekooditiedosto

# Oletustavoite
all: $(TARGET)

# Kääntäminen
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: 
	${TARGET}
# Siivous (poistaa käännetyt tiedostot)
clean:
	rm -f $(TARGET)
