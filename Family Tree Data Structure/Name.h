#pragma once
#include "pch.h"


namespace Iman_familytree {

	struct Name
	{
	public:
		Name();
		Name(const char*);


		const std::string fullNameText();


		bool operator==(Name rhs);


		//variables
		std::string givenName{};
		std::string middleName{};
		std::string surName{};


	private:
		std::string fullName{};
		
	};

}