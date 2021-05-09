#	254008 Makefile setup	#

FLAGS = -c -g -iquote inc -pedantic -Wall
FINAL = -pedantic -Wall

RELOC = obj/main.o obj/Kruskal.o obj/Prima.o obj/graphList.o obj/graphMatrix.o obj/utility.o

#	#	#	#	#	#	#	#

#__start__: ./output
#	clear && ./output
#	clear

./output: obj ${RELOC}
	g++ ${FINAL} -o ./output ${RELOC}
	rm -r obj
	clear

obj:
	mkdir -p obj

#	#	#	#	#	#	#	#

obj/main.o: main.cpp
	g++ ${FLAGS} -o obj/main.o main.cpp

obj/Kruskal.o: src/Kruskal.cpp inc/Kruskal.hh
	g++ ${FLAGS} -o obj/Kruskal.o src/Kruskal.cpp

obj/Prima.o: src/Prima.cpp inc/Prima.hh
	g++ ${FLAGS} -o obj/Prima.o src/Prima.cpp

obj/graphList.o: src/graphList.cpp inc/graphList.hh
	g++ ${FLAGS} -o obj/graphList.o src/graphList.cpp

obj/graphMatrix.o: src/graphMatrix.cpp inc/graphMatrix.hh
	g++ ${FLAGS} -o obj/graphMatrix.o src/graphMatrix.cpp

obj/utility.o: src/utility.cpp inc/utility.hh
	g++ ${FLAGS} -o obj/utility.o src/utility.cpp

#	#	#	#	#	#	#	#

clean:
	rm -f -r obj/*.o ./output