project10_volunteer: project10_volunteer.o volunteer.o read_line.o
	gcc -o project10_volunteer project10_volunteer.o volunteer.o read_line.o

project10_volunteer.o: project10_volunteer.c volunteer.h
	gcc -c project10_volunteer.c

volunteer.o: volunteer.c volunteer.h
	gcc -c volunteer.c

read_line.o: read_line.c read_line.h
	gcc -c read_line.c