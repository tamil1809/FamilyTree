// family_tree_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Person.h"



int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;
	using namespace Iman_familytree;

	std::cout << "Hello World!\n";

	Iman_familytree::Name iman;
	iman.givenName = "iman";
	iman.surName = "james";
	std::cout << iman.fullNameText() << std::endl << std::endl;
	

	auto output = [&](Person person) {
		std::cout << "given name: " << person.m_name.givenName << std::endl;
		std::cout << "middle name: " << person.m_name.middleName << std::endl;
		std::cout << "surname: " << person.m_name.surName << std::endl;
		std::cout << "fullname: " << person.m_name.fullNameText() << std::endl << endl;
	};
	
	
	Iman_familytree::Name james{ "immanuel ongweny" };
	output(Person(james));
	

	Person person("immanuel james ongweny");
	output(person);

	Person person1{"Jennifer L Zaki" };
	output(person1);




	//int findSpace = name.find_first_of(" ");
	//std::cout << findSpace;


	std::cin.get();



}

