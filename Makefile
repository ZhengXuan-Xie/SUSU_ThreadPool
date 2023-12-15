BUILD=g++ -std=c++11 -pipe -O2 -Wall -g
CC=g++ -std=c++11 -pipe -O2 -c -Wall -g
LD = -pthread
TARGET = -o example

Thread_Object=Thread_Object.cpp Thread_Object
Thread_Controler=Thread_Controler.cpp Thread_Controler
Main=main.cpp

files=main.o Thread_Controler.o Thread_Object.o

example:main.o Thread_Object.o Thread_Controler.o
	$(BUILD) $(TARGET) $(LD) $(files)

Thread_Object.o:Thread_Object.cpp Thread_Object
	$(CC) $(Thread_Object) $(LD) -o Thread_Object.o

Thread_Controler.o:Thread_Controler.cpp Thread_Controler
	$(CC) $(Thread_Controler) $(LD) -o Thread_Controler.o

main.o:main.cpp
	$(CC) $(Main) $(LD) -o main.o

.PHONY:clean
clean:
	rm *.o example