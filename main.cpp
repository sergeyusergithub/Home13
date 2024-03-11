// main.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include <random>

#include <queue> // очередь FIFO
#include <stack> // очередь FILO



int main() {
	
	std::ifstream input;

	input.open("ListHuman.txt");

	std::queue<std::string> qlist1;
	std::queue<std::string> qlist2;

	std::string str;

	
	int max_size{}; // максимальный размер строки, необходимо для выравнивания вывода
	while (std::getline(input,str)) {
		if(max_size < str.size()){
			max_size = str.size();
		}
		qlist1.push(str);
		qlist2.push(str);
	}


	// работа со случайными числами
	std::random_device rd; 
	std::mt19937 provider(rd()); 
	std::uniform_int_distribution<int> distributor(1,qlist1.size() - 1); 

	// цикл для перемешивания списка, так как количество
	// повторений цикла задается случайным числом,
	// то списки людей будут выглядеть как составленные случайным образом
	for(int i = 0; i < distributor(provider); ++i){
		str = qlist1.front();
		qlist1.pop();
		qlist1.push(str);
	}

	// проверяем результаты перемешивания двух списков,
	// перемешанный и исходный
	size_t size = qlist1.size();
	for (size_t i = 0; i < size; i++) {
		std::cout << std::setw(max_size) << std::left << qlist1.front() << "\t\t" << std::setw(max_size) << qlist2.front() << '\n';
		qlist1.pop();
		qlist2.pop();
	}
	

	return 0;
}