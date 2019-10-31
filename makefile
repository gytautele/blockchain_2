make:
	g++ -std=c++14 classes/sha256.cpp classes/transaction.cpp classes/user.cpp classes/block.cpp classes/mychain.cpp blockchain.cpp -o prog
	./prog
	rm prog
