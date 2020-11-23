#include "Component.h"
namespace ComponentSystem {
	/* Component Class */
	const std::string& const Component::GetName() const
	{
		return this->m_Name;
	}
	const int32_t& const Component::GetId() const
	{
		return this->m_Id;
	}

	/* Inherited classes */
	Button::Button(const std::string& name, int32_t id)
	{
		this->m_Name = name;
		this->m_Id = id;
	}
	void Button::Press()
	{
		this->m_State = true;
	}
	void Button::Release()
	{
		this->m_State = false;

	}

	LightLED::LightLED(const std::string& name, int32_t id)
	{
		this->m_Name = name;
		this->m_Id = id;
	}
}