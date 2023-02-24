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

sjf: sjf.c
	@gcc -o sjf.out sjf.c $(LIBS)
	@./sjf.out

producer_consumer: producer_consumer.c
	@gcc -o producer_consumer.out producer_consumer.c $(LIBS)
	@./producer_consumer.out

clean:
	@rm -f *.out
