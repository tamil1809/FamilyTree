#pragma once
#include "pch.h"
#include "Person.h"
#include "Relationship.h"

namespace Iman_familytree {
	
	class FamilyMember
	{
	public: 
		FamilyMember() = delete;
		explicit FamilyMember(Person);  //throws invalid argument Person must have name 


	private:
		Person m_person;
		std::vector<Relationship> m_children{};
		std::vector<Relationship> m_parent{};
		std::vector<Relationship> m_spouse{};

		bool initializePerson(const Person&);

	};

}

