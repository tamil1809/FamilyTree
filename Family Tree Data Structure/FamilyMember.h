#pragma once
#include "pch.h"
#include "Person.h"
#include "Relationship.h"

namespace Iman_familytree {
	
	class FamilyMember
	{
	public: 
		FamilyMember() = delete;
		explicit FamilyMember(Person*);  //throws invalid argument Person must have name 

		//getters
		const std::shared_ptr<Person>& getPerson();
		const std::vector<Relationship>& getRelationship(KnownRelationships) const;
		
		//operations
		void addRelationship(const KnownRelationships, const std::shared_ptr<Person>&);
		void deleteRelationship(const KnownRelationships, const std::shared_ptr<Person>&);


	private:
		std::shared_ptr<Person> m_person;
		std::vector<Relationship> m_children{};
		std::vector<Relationship> m_parent{};
		std::vector<Relationship> m_spouse{};

		//private functions
		bool RelationshipExists(std::vector<Relationship>& relation_list, const Relationship& t_relation);
		void deleteFromList(std::vector<Relationship>&, const Relationship&);

	};

}

