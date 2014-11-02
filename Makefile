Game_Of_Life: main.o nextStepComputation.o plane.o hash.o
	gcc -lssl main.o nextStepComputation.o plane.o hash.o -o Game_of_Life

main.o: main.c plane.h nextStepComputation.h hash.h
	gcc -g -Wall -c main.c

nextStepComputation.o: nextStepComputation.c plane.h nextStepComputation.h
	gcc -g -Wall -c nextStepComputation.c

plane.o: plane.c plane.h nextStepComputation.h hash.h
	gcc -g -Wall -c plane.c

hash.o: hash.c  plane.h nextStepComputation.h hash.h
	gcc -g -Wall -c hash.c

clean:
	rm -fv *~ *.o Game_of_Life

rebuild: clean Game_Of_Life
	

archive: clean
	tar cvzf ../Game_of_Life.tar.gz ../Jeu\ de\ la\ vie