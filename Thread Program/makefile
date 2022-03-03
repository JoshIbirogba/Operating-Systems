COMPILER=g++
OBJS=thread.o
default: testcase
testcase: $(OBJS)
	$(COMPILER) -o test $(OBJS)

.PHONY: clean
clean:
	rm *.o
	rm file