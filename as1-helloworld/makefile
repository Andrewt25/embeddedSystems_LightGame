CC_C = arm-linux-gnueabihf-gcc
CFLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror

all:
	$(CC_C) $(CFLAGS) hello.c game.c joystick.c led.c -o hello
	cp hello $(HOME)/cmpt433/public/myApps/
	
clean:
	rm hello
