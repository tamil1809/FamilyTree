#include "pch.h"
#include "Name.h"


namespace Iman_familytree {



	std::string Name::fullNameText()
	{
		fullName.clear();
		appendUntoFullName(givenName);
		appendUntoFullName(middleName);
		appendUntoFullName(surName);

		return fullName;
	}
	
	bool Name::operator==(Name rhs)
	{

		if (givenName == rhs.givenName && middleName == rhs.middleName && surName == rhs.surName)
			return true;
		else
			return false;
	}

	void Name::appendUntoFullName(std::string append)
	{

		if (!append.empty() && fullName.empty())
			fullName.append(append);
		else if (!append.empty() && !fullName.empty())
			fullName.append(" " + append);

	}

}