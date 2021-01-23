// family_tree_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Person.h"
#include "FamilyMember.h"
#include "FamilyDB.h"





//using std directives
using std::cout;
using std::endl;
using std::cin;
using std::string;
using namespace std::chrono;

//boost
using namespace boost::gregorian;

//DB
#include <db_cxx.h>

//family tree app
using namespace Iman_familytree;
typedef Relationship::RelationshipType RelationType;


//Globals
constexpr auto FAM_ENV_DIR = "C:/Users/Immanuel Ongweny/Documents/Projects/Family Tree/FamilyTree App/Family Tree Data Structure/DB Environment";
constexpr auto FAM_DB_DIR = "C:/Users/Immanuel Ongweny/Documents/Projects/Family Tree/FamilyTree App/Family Tree Data Structure/DB Environment/Tests";

void familyTreeTests();
void concurrency_tests();
void keygen_tests();
void berkleydb_tests();
void serialization();

auto output = [](Person person) {
	std::cout << "given name: " << person.m_name.givenName << std::endl;
	std::cout << "middle name: " << person.m_name.middleName << std::endl;
	std::cout << "surname: " << person.m_name.surName << std::endl;
	std::cout << "fullname: " << person.m_name.fullNameText() << std::endl;
	std::cout << "Gender: " << static_cast<int>(person.m_gender) << std::endl;
	std::cout << "Birthday: " << person.m_birthday << endl << std::endl;
};

int main(int argc, char* argv[], char* envp[])
{
	//familyTreeTests();
	//concurrency_tests();
	//keygen_tests();
	//berkleydb_tests();
	serialization();
	//cout << argv[0] << endl;



}

void familyTreeTests() {
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


	FamilyMember iman(person);
	FamilyMember jenn(*person1);
	
	auto& person2 = iman.getPerson();

	person2->m_gender = Person::gender::Male;
	person2->m_birthday = from_string("1994-9-03");


	output(*iman.getPerson());

	cout << person2.use_count() << endl;


	for (size_t i = 0; i < 6; i++)
	{
		iman.addRelationship(RelationType::Child, jenn.getPerson());
	}


	auto& imanChild = iman.getRelationship(RelationType::Child);
	//auto& jennParent = jenn.getRelationship(RelationType::Parent);

	

	int i{};
	auto printRelationships = [&]() {
		for (auto elem : imanChild) {
			elem.m_person2.lock()->m_gender = Person::gender::Female;
			elem.m_person2.lock()->m_birthday = from_string("1994-11-05");
			output(*elem.m_person2.lock());
		}
	};

	printRelationships();

	iman.deleteRelationship(RelationType::Child, jenn.getPerson());


	printRelationships();


	//for (auto elem : jennParent) {
	//	cout << elem.m_person2.lock()->m_name.fullNameText() << endl;
	//	cout << elem.m_person2.use_count() << endl;

	//}


	

	std::cin.get();

}

void concurrency_tests()
{
	FamilyMember member1(Person("immanuel Ongweny"));
	FamilyMember member2(Person("Jennifer L Zaki"));

	try
	{
		auto f = std::async(std::launch::async, &FamilyMember::addRelationship, &member1, RelationType::Spouse, member2.getPerson());
		std::this_thread::sleep_for(std::chrono::microseconds(521));

		//f.get();
		auto relation = member1.getRelationship(RelationType::Spouse);
	
		cout << relation[0].m_person2.lock()->m_name.fullNameText() << endl;

	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...) {
		cout << "WTF" << endl;
	}

	




}

void keygen_tests()
{

	auto iman_birth = day_clock::local_day() - date(1994, 9, 03);
	auto  age = iman_birth.days() / 365;
	cout << age << endl;

	string iman = "Immanuel James Ongweny";
	string imanCap = "Immananuel";
	string andrew{ "Andrew James Ongweny" };
	string jenn = "Jennifer L zaki";

	cout << "iman / age: \t" << std::hash<string>{}(iman) / age << endl;
	cout << "iman: \t\t" << std::hash<string>{}(iman) << endl;
	//cout << std::hash<string>{}(imanCap) << endl;
	//cout << std::hash<string>{}(andrew) << endl;
	cout << std::hash<string>{}(jenn) << endl;
}

void berkleydb_tests()
{
	
	const char* envHome{ nullptr };

	DbEnv* famEnv{ nullptr };
	Db* famDb{ nullptr };

	string name{ "immanuel" };
	string birthday{ "September 3rd" };

	Dbt key(&name, sizeof(name)), data(&birthday, sizeof(birthday));
	try
	{
		FamilyDB testDb{};

		famEnv = testDb.getEnv();
		famDb = testDb.getDB();

		famEnv->add_data_dir(FAM_ENV_DIR);
		famEnv->add_data_dir(FAM_DB_DIR);
		famEnv->set_create_dir(FAM_DB_DIR);
		famEnv->open(FAM_ENV_DIR, DB_INIT_CDB | DB_INIT_MPOOL | DB_CREATE, 0);

		famDb->open(nullptr, "test.db", nullptr, DB_BTREE, DB_CREATE, 0);

		famDb->put(nullptr, &key, &data, 0);
		
		famEnv->get_home(&envHome);
		cout << famEnv->version(0, 0, 0) << endl;
		cout << envHome << endl << endl; //tree db


		famDb->get_create_dir(&envHome);
		if (envHome)
			cout << "DB DIR: " << envHome << endl << endl; //tree db
		else
			cout << "Dir Null" << endl;


	}
	catch (DbException& e)
	{
		cout << "Db exception: "<<e.what() << endl;
	}
	catch (std::exception e) {
		cout << e.what() << endl;
	}



}

void serialization()
{
	std::stringbuf boostBuf(std::ios_base::binary | std::ios_base::in | std::ios_base::out);


	try
	{
		{

			FamilyMember iman(Person("immanuel james ongweny"));
			FamilyMember daughter(Person("Caliope Ongweny"));

			iman.addRelationship(RelationType::Child, daughter.getPerson());
			auto& person2 = iman.getPerson();
			person2->m_gender = Person::gender::Male;
			person2->m_birthday = from_string("1994-9-03");


			auto& i_daughter_list = iman.getRelationship(RelationType::Child);
			cout << "Iman daughter address: " << i_daughter_list[0].m_person2.lock().get() << endl;
			cout << "Iman Person address: " << iman.getPerson().get() << endl;
			cout << "Iman Person use Count: " << iman.getPerson().use_count() << endl;

			output(*iman.getPerson());
			output(*i_daughter_list[0].m_person1.lock());
			output(*i_daughter_list[0].m_person2.lock());
			cout << endl << endl;

		
			boost::archive::binary_oarchive outarch(boostBuf);
			outarch << iman << daughter;

	

			
		}

		FamilyMember jenn{}; 
		FamilyMember daughter2{};

		{
			boost::archive::binary_iarchive inarch(boostBuf);
			inarch >> jenn >> daughter2;
		}

		{

			cout << "Jenn Person address: " << jenn.getPerson().get() << endl;
			cout << "Jenn Person use Count: " << jenn.getPerson().use_count() << endl;
			output(*jenn.getPerson());
			cout << endl;

			auto& j_daughter_list = jenn.getRelationship(RelationType::Child);

			cout << endl;

			output(*j_daughter_list[0].m_person1.lock());

			cout << endl << endl;

			cout << daughter2.getPerson().get() << endl;
			cout << "Jenn daughter address: " << j_daughter_list[0].m_person2.lock().get() << endl;
			output(*j_daughter_list[0].m_person2.lock());

			cout << "Jenn Person use Count: " << jenn.getPerson().use_count() << endl;
		}
		/*{
			std::shared_ptr<std::vector<string>> share_test = std::make_shared<std::vector<string>>();
			share_test->push_back("testing serialization of shared smart pointers");
			std::weak_ptr<std::vector<string>> weak_test{ share_test };

			cout << "Share Ptr Address: " << share_test.get() << "\n Weak Ptr Address: " << weak_test.lock().get() << endl;

			boost::archive::binary_oarchive outarch(boostBuf);
			outarch << share_test << weak_test;
		}

		{
			std::shared_ptr<std::vector<string>> share_test2{};
			std::weak_ptr<std::vector<string>> weak_test2{};
			
			boost::archive::binary_iarchive inarch(boostBuf);
			inarch >> share_test2 >> weak_test2;

			cout << "Share Ptr Address: " << share_test2.get() << "\n Weak Ptr Address: " << weak_test2.lock().get() << endl;
		}*/
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	//output(*jenn.getPerson());
}

