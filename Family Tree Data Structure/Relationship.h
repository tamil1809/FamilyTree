#pragma once
#include "KnownRelationship.h"
#include "Person.h"


namespace Iman_familytree {
	
	struct Relationship
	{
		KnownRelationships m_type{};
		std::weak_ptr<Person> m_person1{};
		std::weak_ptr<Person> m_person2{};

		bool operator==(const Relationship& b) const;
	};

} //Iman_familytree
