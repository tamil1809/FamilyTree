#pragma once
#include "KnownRelationship.h"
#include "Person.h"
#include <memory>

namespace Iman_familytree {
	
	struct Relationship
	{
		KnownRelationships m_type{};
		std::unique_ptr<Person> m_person1{nullptr};
		std::unique_ptr<Person> m_person2{nullptr};
	};

} //Iman_familytree
