objs = exponentiation.o

result : $(objs)
	g++ -o result $(objs)

exponentiation.o : exponentiation.cpp
	g++ -g -c exponentiation.cpp

clean:
	-rm $(objs)
