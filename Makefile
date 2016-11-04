project.o: project.c
	cc -Wall -c project.c
	cc project.o -o project
