
CC = wla-superfx
CCC = wla-65816
CFLAGS = -o
LD = wlalink
LDFLAGS = -v -S

SFILES = main.s snes.s
IFILES = defines.i
OFILES = main.o

all: $(OFILES) makefile
	$(LD) $(LDFLAGS) linkfile result.rom

main.o: main.s defines.i
	$(CC) $(CFLAGS) main.o main.s

#snes.o: snes.s defines.i
#	$(CCC) $(CFLAGS) snes.o snes.s

$(OFILES): $(HFILES)


clean:
	rm -f $(OFILES) core *~ result.rom result.sym
