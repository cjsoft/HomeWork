.PHONY : default binary testcase test clean
default:
	make dp
	make dnc
	make testcase
	make test
dp : dp.cpp
	g++ dp.cpp input.cpp -o dp

dnc : dnc.cpp
	g++ dnc.cpp input.cpp -o dnc

binary :
	make dp
	make dnc

testcase :
	bash ./gen.sh

test :
	bash ./test.sh

clean : 
	-rm dp
	-rm dnc