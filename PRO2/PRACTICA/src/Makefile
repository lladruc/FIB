program.exe: program.o rellotge.o tag.o event.o agenda.o comanda.o token.o
	g++ -o program.exe program.o rellotge.o tag.o event.o agenda.o comanda.o token.o

dox:
	tar -cvf dox.tar ../DOC/

jutge: dox
	tar -cvf practica.tar rellotge.cc rellotge.hh tag.cc tag.hh event.cc event.hh agenda.cc agenda.hh program.cc Makefile jp_cristian_ferrer_galan_entrada.txt jp_cristian_ferrer_galan_resum.txt jp_cristian_ferrer_galan_sortida.txt jp_marcel_olsina_in.txt jp_marcel_olsina_out.txt jp_marcel_olsina_resum.txt dox.tar RepartimentDeTasques.pdf

practica.tar:
	tar -cvf practica.tar rellotge.cc rellotge.hh tag.cc tag.hh event.cc event.hh agenda.cc agenda.hh program.cc Makefile

rellotge.o: rellotge.cc rellotge.hh
	g++ -c rellotge.cc -D_JUDGE_ -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

tag.o: tag.cc tag.hh
	g++ -c tag.cc -D_JUDGE_ -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

event.o: event.cc event.hh
	g++ -c event.cc -D_JUDGE_ -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

agenda.o: agenda.cc agenda.hh
	g++ -c agenda.cc -D_JUDGE_ -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

comanda.o: comanda.cc comanda.hh
	g++ -c comanda.cc -D_JUDGE_ -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

token.o: token.cc token.hh
	g++ -c token.cc -D_JUDGE_ -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x


program.o: program.cc
	g++ -c program.cc -D_JUDGE_ -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x


# esta ultima opcion sirve para limpiar el directorio de ficheros 
# innecesarios; se ejecuta mediante el comando "make clean"
#
clean:
	rm *.o
	rm *.exe
	rm *.tar
