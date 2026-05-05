GPP = g++
LIBS=-lncurses -lsqlite3

# list all source folders
DIRS = src domain ui data

EXE := bin/lms

SRCS := $(foreach VAR,$(DIRS),$(wildcard $(VAR)/*.cpp)) # cpp files in all folders
OBJS := $(patsubst %.cpp,obj/%.o,$(SRCS))				# corresponding obj files
OBJS_NOMAIN := $(filter-out %/main.o,$(OBJS))			# dropping main from OBJS for catch2 testing
TEST_SRCS := $(wildcard test/*.cpp)						# cpp files in test
TEST_OBJS := $(patsubst %.cpp,obj/%.o,$(TEST_SRCS))		# correspnding obj files

.PHONY: all clean pre-build test sandbox

sandbox:
	$(warning  Debug: $(OBJS)) 
	$(warning  Debug: $(OBJS_NOMAIN)) 	
	$(warning  Debug: $(TEST_OBJS)) 

all: pre-build $(EXE)


pre-build:
	mkdir -p bin obj obj/test $(foreach VAR,$(DIRS),obj/$(VAR))
	
# static pattern rules, automatic vars
$(OBJS) $(TEST_OBJS): obj/%.o: %.cpp
	$(GPP) -g --std=c++17 -Wno-return-type -c $< -o $@

$(EXE): $(OBJS)
	$(GPP) -g $(OBJS) $(LIBS) -o $(EXE)

test: pre-build $(TEST_OBJS) $(OBJS_NOMAIN)
	$(GPP) $(TEST_OBJS) $(OBJS_NOMAIN) $(LIBS) -o test/test

db: pre-build
	-rm --force bin/lms.db; 
	sqlite3 bin/lms.db ".read data/initialize.sql"

clean: 
	-rm -rf bin/ obj/