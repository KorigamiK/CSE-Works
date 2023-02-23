# Usage: make file.c
# Description: Compiles the file.c into an executable and runs it.

LIBS := -lpthread -lrt

fork: fork.c
	@gcc -o fork.out fork.c $(LIBS)
	@./fork.out

fcfs: fcfs.c
	@gcc -o fcfs.out fcfs.c $(LIBS)
	@./fcfs.out

priority: priority.c
	@gcc -o priority.out priority.c $(LIBS)
	@./priority.out

clean:
	@rm -f *.out
