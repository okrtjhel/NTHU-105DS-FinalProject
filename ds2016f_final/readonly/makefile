CC = g++ -std=c++11 -w

SRCS = ../*.cpp
RO_SRCS = ./*.cpp

main: RO SRC
	$(CC) -o $@ *.o

SRC: $(SRCS)
	$(CC) -c $(SRCS)

RO: $(RO_SRCS)
	$(CC) -c $(RO_SRCS)

.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	del main.exe *.o
else
	rm -f main *.o
endif
