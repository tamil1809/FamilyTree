// family_tree_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Person.h"
#include "FamilyMember.h"

void familyTreeTests();

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;

	familyTreeTests();
}

void familyTreeTests() {
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;
	using namespace Iman_familytree;
	using namespace boost::gregorian;


	auto output = [](Person person) {
		std::cout << "given name: " << person.m_name.givenName << std::endl;
		std::cout << "middle name: " << person.m_name.middleName << std::endl;
		std::cout << "surname: " << person.m_name.surName << std::endl;
		std::cout << "fullname: " << person.m_name.fullNameText() << endl;
		std::cout << "Gender: " << static_cast<int>(person.m_gender )<< endl;
		std::cout << "Birthday: " << person.m_birthday << endl << endl;
	};




	Person person("immanuel james ongweny");
	//output(person);
	
	Person* person1 = new Person("Jennifer L Zaki");
	//output(*person1);


	FamilyMember iman(&person);
	FamilyMember jenn(person1);
	
	auto& person2 = iman.getPerson();

	person2->m_gender = genderTypes::Male;
	person2->m_birthday = from_string("1994-9-03");


	output(*iman.getPerson());

	cout << person2.use_count() << endl;


	for (size_t i = 0; i < 6; i++)
	{
		iman.addRelationship(KnownRelationships::Child, jenn.getPerson());
	}


	auto& imanChild = iman.getRelationship(KnownRelationships::Child);
	//auto jennParent = jenn.getRelationship(KnownRelationships::Parent);

	

	int i{};
	auto printRelationships = [&]() {
		for (auto elem : imanChild) {
			elem.m_person2.lock()->m_gender = genderTypes::Female;
			elem.m_person2.lock()->m_birthday = from_string("1994-11-05");
			output(*elem.m_person2.lock());
		}
	};

	printRelationships();

	iman.deleteRelationship(KnownRelationships::Child, jenn.getPerson());


	printRelationships();


	//for (auto elem : jennParent) {
	//	cout << elem.m_person2.lock()->m_name.fullNameText() << endl;
	//	cout << elem.m_person2.use_count() << endl;

	//}


	

	std::cin.get();

}

