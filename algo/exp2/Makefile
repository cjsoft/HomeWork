default:
	make binary
	make testcase
	make test
binary : main.cpp
	g++ main.cpp -D QSORT -o qsort.out
	g++ main.cpp -D MSORT -o msort.out
	g++ main.cpp -D ISORT -o isort.out
	g++ std.cpp -o std.out
std std.out : std.cpp
	g++ std.cpp -o std.out

testcase :
	-mkdir data
	./gen.sh

test : 
	./test.sh

clean :
	-rm runtime.txt
	-rm ./data/*
	-rm qsort.out
	-rm msort.out
	-rm isort.out
	-rm std.out
