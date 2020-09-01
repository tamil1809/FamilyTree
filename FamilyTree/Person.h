#pragma once
#include <string>;
#include "Name.h"
#include "genderTypes.h"
#include "boost/date_time/gregorian/gregorian_types.hpp"


namespace Iman_familytree {
	struct Person
	{
	public:
		using date = boost::gregorian::date;

		Person();
		Person(Name, genderTypes);

		date getDeathdate() const;   //throws std::logic_error, person must be marked deceased
		void setDeathdate(date t_deathday);  //throws std::logic_error, person must be marked deceased

	//variables
	public:
		Name m_name;
		genderTypes m_gender;
		std::string m_countryOrigin;
		boost::gregorian::date m_birthday;
		bool m_deceased;
		
	private:
		boost::gregorian::date m_deathday;

	};
}
 