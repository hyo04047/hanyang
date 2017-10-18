main = simple_int_set_main
class = simple_int_set

all: $(main)

$(main): $(main).o $(class).o
	g++ -o $(main) $(main).o $(class).o

$(main).o: $(main).cc
	g++ -c $(main).cc

$(class).o: $(class).cc
	g++ -c $(class).cc

clean:
	rm $(main) *.o
