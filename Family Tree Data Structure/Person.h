#pragma once
#include "pch.h"
#include "Name.h"
#include "genderTypes.h"



namespace Iman_familytree {
	struct Person
	{
		Person();
		Person(Name, genderTypes = genderTypes::Unkown);

		boost::gregorian::date getDeathdate() const;   //throws std::logic_error, person must be marked deceased
		void setDeathdate(boost::gregorian::date t_deathday);  //throws std::logic_error, person must be marked deceased

	//variables
	public:
		Name m_name{};
		genderTypes m_gender{};
		std::string m_countryOrigin{};
		boost::gregorian::date m_birthday{};
		bool m_deceased{};
		
	protected:
		boost::gregorian::date m_deathday{};

	};
}
 