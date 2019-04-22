OBJS	= main.o geometry.o
HEADERS	= geometry.h
OUTPUT	= main.out
LINK	=
CC		= g++

.PHONY : src_only clean
$(OUTPUT) : $(OBJS) $(HEADERS) Makefile
	$(CC) $(OBJS) -o $(OUTPUT) $(LINK)

src_only clean :
	-$(RM) $(OUTPUT)
	-$(RM) $(OBJS)
run : $(OUTPUT)
	make $(OUTPUT)
	./$(OUTPUT)
