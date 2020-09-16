#include "pch.h"
#include "FamilyMember.h"


namespace Iman_familytree {

	FamilyMember::FamilyMember(Person t_person) {

		if (!t_person.m_name.fullNameText().empty())
			m_person = t_person;
		else 
			throw std::invalid_argument("Please provide first and last name");
		
	}

	//initialize when name is empty or must have equivalent name to initialize all other variables
	bool FamilyMember::initializePerson(const Person& t_person)
	{
		
	
		return false;
	}



} 