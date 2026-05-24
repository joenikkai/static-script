CXX = g++

# CXXSTD = --std=c++23

BINARY = bin/static-script

SOURCES = $(shell find . -type f -name "*.cpp")

OBJECTS = $(SOURCES:%.o=cpp)

CXXFLAGS := $(CXXSTD)
LDFLAGS ?= 


.PHONY: all bin
all: $(BINARY)

$(BINARY): $(OBJECTS) | bin
	$(CXX) -o $@ -g $^ $(CXXFLAGS) $(LDFLAGS)

%.o: %.c
	$(CXX) -c -g -o $@ $< $(CXXFLAGS)


bin:
	mkdir -p $@

.PHONY: run  clean 
run: $(BINARY)
	./$<

clean:
	rm -fr $(BINARY)
	find . -name "*.o" -exec {} \;