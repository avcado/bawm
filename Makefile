CC := gcc
CFLAGS := -Iinclude/ -lX11

compile:
	@mkdir -pv bin/
	@$(CC) src/bawm.c $(CFLAGS) -o bin/bawm
	@echo Compiled!

install:
	@cp -v bin/bawm /usr/local/bin/bawm