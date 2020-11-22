CC = g++
CPPFLAGS = -std=c++11 -g -Wall
OBJS = data.o tree.o appmgr.o app.o

app: $(OBJS)

app.o: data.o tree.o appmgr.o

appmgr.o: appmgr.h tree.h data.h

tree.o: tree.h data.h

data.o: data.h

clean: 
	rm *.o app
