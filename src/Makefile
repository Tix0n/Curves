CC = g++ -g
CFLAGS = -Wall -Werror -Wextra -fopenmp
LDFLAGS = -L. -lcurves

SRCDIR = curves
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: clean libcurves.so main

libcurves.so: $(OBJECTS)
	$(CC) -shared -o libcurves.so $(OBJECTS)

main: $(OBJECTS) main.cpp
	$(CC) $(CFLAGS) -o main main.cpp $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<

style:
	clang-format -i --style=Google *.cpp \
	 curves/*.h \
	 curves/*.cpp \

	clang-format -n --style=Google *.cpp \
	 curves/*.h \
	 curves/*.cpp \

valgrind: libcurves.so main
	valgrind --leak-check=full --suppressions=openmp.supp ./main

clean:
	rm -f main $(OBJECTS)
	rm -rf $(OBJDIR)
	rm -f libcurves.so