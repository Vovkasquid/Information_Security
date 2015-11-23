TARGET=Lab_1
$(TARGET): Lab_1.o
	gcc Lab_1.o -o $(TARGET)
Lab_1.o: Lab_1.c
	gcc Lab_1.c -c

clean:
	rm -f *.o $(TARGET)
