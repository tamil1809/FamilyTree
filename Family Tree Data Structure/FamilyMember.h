#pragma once
#include "pch.h"
#include "Person.h"
#include "Relationship.h"
#include "tree_serializations.h"

namespace Iman_familytree {

	class FamilyMember
	{
		
	public: 
		using rel_type = Relationship::RelationshipType;

		FamilyMember() :m_person{}, m_children{}, 
			m_parent{}, m_spouse{}{};
		explicit FamilyMember(Person);  //throws invalid argument Person must have name 

		//getters
		const std::shared_ptr<Person>& getPerson();
		const std::vector<Relationship>& getRelationship(rel_type) const;
		
		//operations
		void addRelationship(rel_type, const std::shared_ptr<Person>&);
		void deleteRelationship(rel_type, const std::shared_ptr<Person>&);

		//Serialize
		template<class Archive>
		inline void serialize(Archive& ar, const unsigned int file_version){
			ar & m_person & m_children & m_parent & m_spouse;
		}

	private:
		std::shared_ptr<Person> m_person;
		std::vector<Relationship> m_children{};
		std::vector<Relationship> m_parent{};
		std::vector<Relationship> m_spouse{};

	private:
		//helpers function
		bool RelationshipExists(std::vector<Relationship>& relation_list, const Relationship& t_relation);
		void deleteFromList(std::vector<Relationship>&, const Relationship&);

	};

}

