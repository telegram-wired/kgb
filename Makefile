CC=cc -std=c99 -Wall -pedantic
SHARED=$(CC) -shared -fPIC

all:
	@mkdir -p bin
	$(CC) src/analyzer.c -o bin/kgb-analyzer
	$(SHARED) src/mem.c -o bin/kgb-mem.so
	$(CC) src/optimizer.c -o bin/kgb-optimizer
	@cp src/mem bin/kgb-mem
	@chmod +x bin/kgb-mem

clean:
	@rm -r bin
