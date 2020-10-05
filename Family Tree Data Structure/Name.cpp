#include "pch.h"
#include "Name.h"


namespace Iman_familytree {



	Name::Name()
	{}

	Name::Name(const char* t_name)
	{ 
		std::string name{ t_name };
		size_t numOfNames = std::count(name.begin(), name.end(), ' ');

		auto partfullname = [](std::string& l_name)->std::string {
			std::string namePart;
			size_t findspace = l_name.find_first_of(' ');
			namePart.append(l_name, 0, findspace);
			l_name.erase(0, findspace + 1);
			return namePart;
		};

		switch (numOfNames)
		{
		case 0:
			givenName = partfullname(name);
			break;
		case 1:
			givenName = partfullname(name);
			surName = partfullname(name);
			break;

		default:
			givenName = partfullname(name);
			middleName = partfullname(name);
			surName = partfullname(name);
			break;
		}
		
	}

	const std::string Name::fullNameText()
	{
		fullName.clear();
		auto appendUnto = [&](const std::string& nameToAppend){
			if (!nameToAppend.empty() && fullName.empty())
				fullName.append(nameToAppend);
			else if (!nameToAppend.empty() && !fullName.empty())
				fullName.append(" " + nameToAppend);
		};

		appendUnto(givenName);
		appendUnto(middleName);
		appendUnto(surName);

		return fullName;
	}
	
	bool Name::operator==(Name& b)
	{

		if (this->fullNameText() == b.fullNameText())
			return true;
		else
			return false;
	}
} //Iman namespace