CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc
OBJ=./obj

__start__: ${OBJ} ${OBJ}/example.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/MacierzOb.o ${OBJ}/Prostopadloscian.o ${OBJ}/Dron.o
	g++ -o example.out ${OBJ}/example.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/MacierzOb.o ${OBJ}/Prostopadloscian.o ${OBJ}/Dron.o -lpthread

${OBJ}:	
	mkdir ${OBJ}

${OBJ}/example.o: src/example.cpp inc/Dr3D_gnuplot_api.hh inc/SWektor.hh inc/Macierz.hh inc/MacierzOb.hh inc/Prostopadloscian.hh inc/Dron.hh
	g++ ${CPPFLAGS} -o ${OBJ}/example.o src/example.cpp

${OBJ}/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh


${OBJ}/MacierzOb.o:  inc/Macierz.hh inc/MacierzOb.hh src/MacierzOb.cpp
	g++ ${CPPFLAGS} -o ${OBJ}/MacierzOb.o src/MacierzOb.cpp

${OBJ}/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Prostopadloscian.o src/Prostopadloscian.cpp

inc/Prostopadloscian.hh: inc/Bryla.hh
	touch inc/Prostopadloscian.hh

${OBJ}/Dron.o: src/Dron.cpp inc/Dron.hh inc/InterfejsDrona.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dron.o src/Dron.cpp

inc/Dron.hh: inc/InterfejsDrona.hh
	touch inc/Dron.hh

clear:
	rm example.out ${OBJ}/*.o
