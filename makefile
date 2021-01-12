p5: main.o Dictionary.o Cinco.o
        g++ -o p5 main.o Dictionary.o Cinco.o

main.o: main.cpp Dictionary.h Cinco.h
        g++ -c main.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
        g++ -c Dictionary.cpp

Cinco.o: Cinco.cpp Cinco.h
        g++ -c Cinco.cpp

clean:
        rm -f p5 *.o *~




