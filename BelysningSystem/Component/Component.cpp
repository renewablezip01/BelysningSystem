#include <Windows.h>
#include "Component.h"

namespace ComponentSystem {
	/* Gets the name of the component */
	const std::string& Component::GetName() const
	{
		return this->m_Name;
	}

	/* Gets the id of the component */
	const int32_t& Component::GetId() const
	{
		return this->m_Id;
	}
}