#include "pch.h"
#include "Person.h"
#include <stdexcept>

namespace Iman_familytree {

	Person::Person() :
		m_gender{ genderTypes::Unkown }
	{}

	Person::Person(Name t_name, genderTypes t_gender):
		m_name{ t_name },
		m_gender{ t_gender }
	{}

	
	boost::gregorian::date Person::getDeathdate() const {
		if (m_deceased)
			return m_deathday;
		else
			throw std::logic_error("person still living");
	}
	void Person::setDeathdate(date t_deathday) {
		if (m_deceased)
			m_deathday = t_deathday;
		else
			throw std::logic_error("person still living");
	}


} //Iman_familytree