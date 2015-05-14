program.exe: program.o rellotge.o tag.o event.o agenda.o comanda.o token.o
	g++ -o program.exe program.o rellotge.o tag.o event.o agenda.o comanda.o token.o

practica.tar:
	tar -cvf practica.tar rellotge.cc rellotge.hh tag.cc tag.hh event.cc event.hh agenda.cc agenda.hh program.cc

rellotge.o: Rellotge.cc Rellotge.hh
	g++ -c Rellotge.cc -D_GLIBCXX_DEBUG

tag.o: Tag.cc Tag.hh
	g++ -c Tag.cc -D_GLIBCXX_DEBUG

event.o: Event.cc Event.hh
	g++ -c Event.cc -D_GLIBCXX_DEBUG

agenda.o: Agenda.cc Agenda.hh
	g++ -c Agenda.cc -D_GLIBCXX_DEBUG

comanda.o: comanda.cc comanda.hh
	g++ -c comanda.cc -D_GLIBCXX_DEBUG

token.o: token.cc token.hh
	g++ -c token.cc -D_GLIBCXX_DEBUG


program.o: program.cc
	g++ -c program.cc -D_GLIBCXX_DEBUG


#empaquetar: Agenda.cc Agenda.hh Event.cc Event.hh Tag.cc tags.hh Rellotge.cc Rellotge.hh
#	zip ENTREGA_NOMES_AQUEST.zip Agenda.cc Agenda.hh Event.cc Event.hh Tag.cc Tag.hh Rellotge.cc Rellotge.hh


# Esta ultima opcion sirve para limpiar el directorio de ficheros 
# innecesarios; se ejecuta mediante el comando "make clean"
#
clean:
	rm *.o
	rm *.exe
