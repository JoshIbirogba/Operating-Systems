COMPILER=g++
OBJS=MemSimulation.o
default: testcase
testcase: $(OBJS)
	$(COMPILER) -o test $(OBJS)

.PHONY: clean
clean:
	rm *.o
	rm file