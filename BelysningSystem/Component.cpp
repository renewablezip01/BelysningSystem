#include <Windows.h>
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

	void Button::Update()
	{
		/* TEMPORARY. USING KEYBOARD AS A BUTTON INSTEAD OF PHYSICAL BUTTON THIS IS ONLY FOR TESTING */
		if (GetAsyncKeyState(VK_END)) {
			m_State = true;
			return;
		}
		m_State = false;
	}

	const bool& const Button::GetState() const
	{
		return this->m_State;
	}

	LightLED::LightLED(const std::string& name, int32_t id)
	{
		this->m_Name = name;
		this->m_Id = id;
	}
	void LightLED::Logic(bool logic)
	{
		if (logic) {
			On();
		}
		else {
			Off();
		}
	}
	void LightLED::On()
	{
		this->m_State = true;
	}
	void LightLED::Off()
	{
		this->m_State = false;
	}
	const bool& const LightLED::GetBool() const
	{
		return this->m_State;
	}
}