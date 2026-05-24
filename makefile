
include ./make.conf

VM ?=
VM_DIR = 
ifeq ($(VM),register_vm)
  VM = vm/register_vm.o \
    vm/register_vm/fetch.o \
    vm/register_vm/decode.o \
    vm/register_vm/execute.o \
    vm/register_vm/run.o 

  VM_DIR = vm/register_vm
else
  VM = vm/stack_vm.o \
    vm/stack_vm/fetch.o \
    vm/stack_vm/decode.o \
    vm/stack_vm/execute.o \
    vm/stack_vm/run.o 

  VM_DIR = vm/stack_vm
endif

OBJECTS = \
  main.o \
  asm/asm.o \
  vm/vm.o \
  vm/get_data.o \
  vm/get_type.o \
  $(VM)

OBJECT_DIRS = $(sort $(dir $(OBJECTS)))

SOURCES = 
.PHONY: all bin
all: $(BINARY)

$(BINARY): $(OBJECTS) | bin
	$(CXX) -o $@ -g $^ $(CXXFLAGS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c -g -o $@ $< $(CXXFLAGS)


bin:
	@mkdir -p $@

.PHONY: run  clean 
run: $(BINARY)
	./$<

clean:
	rm -fr $(BINARY)
	find . -name "*.o" -exec rm -fr {} \;

$(OBJECTS):

# $(OBJECT_DIRS):
# 	@for d in $@; do \
# 	    echo $$d  here; \
# 	done


