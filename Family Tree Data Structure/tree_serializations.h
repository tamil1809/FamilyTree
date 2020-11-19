#pragma once
#include "pch.h"
#include "Person.h"
#include "Relationship.h"


namespace Iman_familytree {

	template<class Archive>
	inline void serialize(Archive& ar, Person& person, const unsigned int file_version) {
		ar& person.m_name.givenName& person.m_name.surName& person.m_name.middleName;
		ar& person.m_countryOrigin;
	}

	template<class Archive>
	inline void serialize(Archive& ar, Relationship& relate, const unsigned int file_version) {
		ar & relate.m_person1 & relate.m_person2;
	}
}
