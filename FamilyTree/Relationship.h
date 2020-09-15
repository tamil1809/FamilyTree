#pragma once
#include "KnownRelationship.h"
#include "Person.h"
#include <memory>

namespace Iman_familytree {
	
	struct Relationship
	{
		KnownRelationships m_type{};
		std::shared_ptr<Person> m_person1{nullptr};
		std::shared_ptr<Person> m_person2{nullptr};
	};

} //Iman_familytree
