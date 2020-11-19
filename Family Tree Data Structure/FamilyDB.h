#pragma once

//DB
#include <db_cxx.h>
namespace Iman_familytree {
	class FamilyDB
	{
	public:
		FamilyDB();

		inline DbEnv* getEnv() { return &m_famEnv; }
		inline Db* getDB(){ return &m_famDb; }
	

		virtual ~FamilyDB();
	private:
		DbEnv m_famEnv;
		Db m_famDb;
		
	};
}
