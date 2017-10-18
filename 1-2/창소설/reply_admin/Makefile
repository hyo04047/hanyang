main = reply_admin_main
class = reply_admin

all : $(main)

$(main): $(main).o $(class).o
		g++ -o $(main) $(main).o $(class).o

$(main).o: $(main).cc
		g++ -c $(main).cc

$(class).o: $(class).cc
		g++ -c $(class).cc

clean:
		rm $(main) *.o