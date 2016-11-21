objs = a+b.o

result : $(objs)
	g++ -o result $(objs)

a+b.o : a+b.cpp
	g++ -c a+b.cpp

clean:
	-rm $(objs) result.exe
