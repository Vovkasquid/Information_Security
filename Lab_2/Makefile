TARGET=Lab_2
$(TARGET): Lab_2.o
	gcc Lab_2.o -o $(TARGET)
Lab_1.o: Lab_2.c
	gcc Lab_2.c -c

clean:
	rm -f *.o $(TARGET)
