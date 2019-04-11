default:
	make dp
	make dnc
	make testcase
	make test

dp : dp.cpp
	g++ dp.cpp -o dp

dnc : dnc.cpp
	g++ dnc.cpp -o dnc

binary :
	make dp
	make dnc

testcase :
	bash ./gen.sh

test :
	bash ./test.sh
