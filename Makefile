be_togglesprint.exe: create_dir object/main.o object/sendlog.o object/textcolor.o object/debugging.o
	gcc -o be_togglesprint.exe object/main.o object/sendlog.o object/textcolor.o object/debugging.o

create_dir:
	mkdir object/

object/sendlog.o: sendlog.c
	gcc -c -o object/sendlog.o sendlog.c\

object/textcolor.o: textcolor.c
	gcc -c -o object/textcolor.o textcolor.c\

object/debugging.o: debugging.c
	gcc -c -o object/debugging.o debugging.c\

object/main.o: main.c
	gcc -c -o object/main.o main.c\

clean:
	rm -rf object/ be_togglesprint.exe\