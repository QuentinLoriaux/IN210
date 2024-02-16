CXX = gcc

INCS = -I.  -I"." 
OBJS = $(SRC:.c=.o)

SRC = ratp.c  main.c cmocka.o

#added
LDFLAGS = --coverage
OPTION = -Wall -fexceptions -fprofile-arcs -ftest-coverage
#pour générer le fichier de coverage puis le lire :
#gcov -b -c ratp.c
#gcovr --html-details result.html
#ouvrir result.html dans mon navigateur



all: $(OBJS)
	$(CXX) $(LDFLAGS) $(INCS) -o testAll  $(OBJS)

	
exec : all
	- ./testAll

%.o: %.c
	$(CXX) $(OPTION) -c  $< -o $@ $(INCS)
	
clean:
	rm -f $(OBJS) 
	rm -f cmocka.gc*
	rm -f ratp.gc*
	rm -f main.gc*
	rm -f ratp.cbp ratp.depend ratp.layout


mrproper: clean
	rm -f  testAll
	rm -f  result.*

doAll : mrproper exec
	gcov -b -c ratp.c
	gcovr --html-details result.html
	@echo "toto"
