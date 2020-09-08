#pragma once
#include "Person.h"
#include <vector>
#include "Relationship.h"

namespace Iman_familytree {
	
	class FamilyMember : public Person
	{
	public:
		FamilyMember() = delete;
		explicit FamilyMember(Person);

	private:
		std::vector<Relationship> m_children;
		std::vector<Relationship> m_parent;
		std::vector<Relationship> m_spouse;

	};

}

