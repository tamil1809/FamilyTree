#pragma once
#include <string>


namespace Iman_familytree {

	struct Name
	{
	public:
		std::string fullNameText();


		bool operator==(Name rhs);


		//variables
		std::string givenName{};
		std::string middleName{};
		std::string surName{};


	private:
		std::string fullName{};

		void appendUntoFullName(std::string append);
		
	};

}