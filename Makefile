exec = xlang.exe
sources = $(wildcard src/*.c)
objects = $(sources: .c = .exe)
flags = -g

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@


clean:
	-rm *.exe
	-rm src/*.exe