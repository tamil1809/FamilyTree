#include "FamilyDB.h"
namespace Iman_familytree {
	FamilyDB::FamilyDB():m_famEnv(u_int32_t(0)),
		                 m_famDb(&m_famEnv,u_int32_t(0))
	{
	}
	FamilyDB::~FamilyDB()
	{
		m_famDb.close(0);
		m_famEnv.close(DB_FORCESYNC);

	}
}