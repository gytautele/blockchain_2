#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <limits>
#include <random>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

//reading from cmd
void read (vector<int> &newly, string input)
{
	int i=0;
	int temp; //temporary
	unsigned long long sum=0; //temp suma
	cout << "Please write your input, when You want to stop, press ENTER:" << endl;
	cin.ignore();
	int x=0;
	getline(cin, input);

		for (int i = 0; i < input.size(); i++){
			sum+=int(input[i]);
			x=input.length()*input.length()*input.length();

		}
		sum+=x*541354;
		newly.push_back(sum);

}
//-------------------------------
//reading from text file (for hashing all file)
void read1(vector<int> &newly, string input)
{
	std::ifstream in("test/konstitucija.txt");
	int temp; //temporary
	unsigned long long sum=0; //temp suma
	unsigned long long x=0;

	if (!in) {
    cout << "Unable to open text file";
    exit(1);   // call system to stop
	}

	std::cin.ignore();
	while (!in.eof()){
		getline(in, input);
		for (int i = 0; i < input.size(); i++){
			sum+=int(input[i]);
		}
		x=input.length()*input.length()*input.length();
		sum*=x;
		sum*=541354;
		sum+=x;
		newly.push_back(sum);
	}

	in.close();

}
//-------------------------------
//reading from text file (hashing all lines)
void read2(vector<int> &newly, string input, std::vector<std::string>& inputs)
{
	int temp; //temporary
	unsigned long long sum=0; //temp suma

	std::ifstream in("test/konstitucija.txt");

	if (!in) {
    cout << "Unable to open text file";
    exit(1);   // call system to stop
	}

    while (std::getline(in, input)) {
            
            for (int i = 0; i < input.size(); i++)
            {
			//cout << "input: " << int(input[i]) << endl;
			sum+=int(input[i]);
			sum+=input.length()*input.length();
			sum*=541354;
			newly.push_back(sum);

		}
		inputs.push_back(input);
		
    }
    in.close();
}
//for hashing all file
//-----------------------------------
void hash_fun(vector<int> &newly, string &hasher) {
	
	char rand[32]; //temporary array for saving 

	std::mt19937 generator;
	std::uniform_int_distribution<int> number(48, 57); //all numebers from ASCII table
    std::uniform_int_distribution<int> letter(97, 102);
    std::uniform_int_distribution<int> cletter(65, 70);

    generator.seed(newly[0]); //for stable generation
    std::uniform_int_distribution<int> r_s(2, 4); //for generation of letter, cletter or number;
    

    for (int j = 0; j < 32; j++) {
        int randd = r_s(generator); //generates random symbol
        if (randd==2)
            {
            	rand[j] = number(generator);
            }
            if (randd==3)
            {
            	rand[j] = letter(generator);
            }
            if (randd==4)
            {
            	rand[j] = cletter(generator);
            }
    }

    hasher = rand;

    for (int i=0; i<31; i++)
    {
    	cout << hasher[i];
    }
}
//for hashing every line
//-----------------------------
void hash_fun2(vector<int> &newly, std::vector<std::string>& hasherr, std::vector<std::string>& inputs)
{
	char rand[31]; //temporary array for saving

	std::mt19937 generator;
	std::uniform_int_distribution<int> number(48, 57); //all numebers from ASCII table
    std::uniform_int_distribution<int> letter(97, 102);
    std::uniform_int_distribution<int> cletter(65, 70);

    generator.seed(newly[0]); //for stable generation
    std::uniform_int_distribution<int> r_s(2, 4); //for generation of letter, cletter or number;

    std::string h; //for temporary saving

    for (int j = 0; j < inputs.size(); j++) {
        for (int i = 0; i < 31; i++) {
            int randd = r_s(generator); //generates random symbol
            if (randd==2)
            {
            	rand[i] = number(generator);
            }
            if (randd==3)
            {
            	rand[i] = letter(generator);
            }
            if (randd==4)
            {
            	rand[i] = cletter(generator);
            }
        }
    h = rand;
    hasherr.push_back(h);
    newly.clear();
    }
}
//------------------------------------
void writing_to_file (std::vector<std::string> hasherr)
{
	std::ofstream off ("hash.txt");

    for (int i=0; i<hasherr.size(); i++)
    {
    	off << hasherr.at(i) << endl;
    }

    off.close();	
}
//-----------------------------

int main(int argc, char const *argv[])
{
	vector<int> newly; //string for saving data
	string input; //temporary 
	int size=0; //amount of letters
	int a; //for choice
	bool b; //for choice
	string hasher; //for result
	std::vector<std::string> hasherr;
	std::vector<std::string> inputs;

	std::chrono::high_resolution_clock::time_point start; //laiko matavimui
	std::chrono::high_resolution_clock::time_point ending; //laiko matavimui

	cout << "If You want to read from file press 1, otherwise press 0:" << endl;
	cin >> a;

	while ((a != 1) && (a != 0) || (std::cin.fail())){
		cout << "Impossible input. Please try again:" << std::endl;
		cin.clear();
        cin.ignore(80, '\n');
        cin >> a;
    }

		if (a==0)
	{
		read(newly, input);
		hash_fun(newly, hasher);
	} 

	if (a==1) {
		cout << "If you want to hash all text file, press 1. If you want to hash every line of Your text file, press 0:" << endl;
		cin >> b;

		while ((b != 1) && (b != 0) || (std::cin.fail())){
		cout << "Impossible input. Please try again:" << std::endl;
		cin.clear();
        cin.ignore(80, '\n');
        cin >> b;
    	}
		
		if (b==1){
			read1(newly, input);
			hash_fun(newly, hasher);
		} 
		if (b==0)
		{
			start = std::chrono::high_resolution_clock::now();
			read2(newly, input, inputs);
			hash_fun2(newly, hasherr, inputs);
			ending = std::chrono::high_resolution_clock::now();
  			std::chrono::duration<float> laikas = ending - start;
    		std::cout << "Hash'inti konstitucija.txt truko: " << laikas.count() << std::endl;
    		writing_to_file(hasherr);
		} 
	}

	return 0;
}
