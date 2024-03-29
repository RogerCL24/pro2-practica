OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cluster.o Area_espera.o Prioridad.o Proceso.o Procesador.o
	g++ -o program.exe *.o
Cluster.o: Procesador.hh Proceso.hh
	g++ -c Cluster.cc $(OPCIONS) 
Area_espera.o: Prioridad.hh Proceso.hh Cluster.hh
	g++ -c Area_espera.cc $(OPCIONS) 
Prioridad.o: Proceso.hh Cluster.hh
	g++ -c Prioridad.cc $(OPCIONS)
Proceso.o: 
	g++ -c Proceso.cc $(OPCIONS)
Procesador.o: Proceso.hh 
	g++ -c Procesador.cc $(OPCIONS)
program.o: program.cc Procesador.hh Proceso.hh Prioridad.hh Cluster.hh Area_espera.hh
	g++ -c program.cc $(OPCIONS) 


clean:
	rm *.o
	rm *.x
	rm *.tar

practica.tar:
	tar -cvf practica.tar *.cc *.hh *.zip Makefile