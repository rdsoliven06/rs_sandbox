#Created by Riad Soliven

#target: dependencies
#CXX: g++/gnu compiler, $?: cpp files, $@:executable filename (output)
output: main.cpp message.cpp message.h
	$(CXX) $(CFLAGS) $? -o $@

#$<: the cpp files
.cpp.o:
	$(CXX) $(CFLAGS) -c $<
clean:
	rm output

