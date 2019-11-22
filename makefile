make:
	g++ -std=c++14 sha256.cpp Transaction.cpp User.cpp MyBlock.cpp MyChain.cpp Blockchain.cpp -o test
	./test
	rm test
