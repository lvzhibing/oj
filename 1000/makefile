objs = a+b.o

edit : $(objs)
	g++ -o edit $(objs)

a+b.o : a+b.cpp
	g++ -c a+b.cpp

.PHONY : clean:
	-rm $(objs)
