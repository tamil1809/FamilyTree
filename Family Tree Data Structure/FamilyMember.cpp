#include "pch.h"
#include "FamilyMember.h"


namespace Iman_familytree {

	FamilyMember::FamilyMember(Person t_person) {

		if (!t_person.m_name.fullNameText().empty())
			m_person = std::make_shared<Person>(t_person);
		else 
			throw std::invalid_argument("Please provides members name");
		
	}

#ifndef NDEBUG
	const std::shared_ptr<Person>& FamilyMember::getPerson()
	{
		return m_person;
	}
#endif // DEBUG



	const std::vector<Relationship>& FamilyMember::getRelationship(rel_type t_relate) const
	{
		switch (t_relate)
		{
		case rel_type::Child:
			return m_children;
		case rel_type::Parent:
			return m_parent;
		case rel_type::Spouse:
			return m_spouse;
		default:
			return std::move(std::vector<Relationship>{});
		}
	}

	void FamilyMember::addRelationship(const rel_type t_relate, const std::shared_ptr<Person>& t_person)
	{
		if (t_person != nullptr && !t_person->m_name.fullNameText().empty()) {
			Relationship relation;
			relation.m_type = t_relate;
			relation.m_person1 = this->m_person;
			relation.m_person2 = t_person;
			switch (relation.m_type)
			{ 
			case rel_type::Child:
				if(!RelationshipExists(m_children,relation))
					m_children.push_back(relation);
				break;
			case rel_type::Parent:
				if (!RelationshipExists(m_parent, relation))
					m_parent.push_back(relation);
				break;
			case rel_type::Spouse:
				if (!RelationshipExists(m_spouse, relation))
					m_spouse.push_back(relation);
				break;
			default:
				break;
			}
		}
	}

 	void FamilyMember::deleteRelationship(const rel_type t_relate, const std::shared_ptr<Person>& t_person)
	{
		if (t_person != nullptr && !t_person->m_name.fullNameText().empty()) {
			
			Relationship relation;
			relation.m_type = t_relate;
			relation.m_person1 = this->m_person;
			relation.m_person2 = t_person;

			switch (t_relate)
			{
			case rel_type::Child:
				deleteFromList(m_children, relation);
				break;
			case rel_type::Parent:
				deleteFromList(m_parent, relation);
				break;
			case rel_type::Spouse:
				deleteFromList(m_spouse, relation);
				break;
			default:
				break;
			}
		}
	}

	bool FamilyMember::RelationshipExists(std::vector<Relationship>& relation_list, const Relationship& t_relation)
	{
		auto find= std::find(relation_list.begin(), relation_list.end(), t_relation);
		if (find != relation_list.end())
			return true;
		else
			return false;
	}

	void FamilyMember::deleteFromList(std::vector<Relationship>& relation_list, const Relationship& t_relation)
	{
		auto it = std::remove(relation_list.begin(), relation_list.end(), t_relation);
		relation_list.erase(it, relation_list.end());
	}




} 