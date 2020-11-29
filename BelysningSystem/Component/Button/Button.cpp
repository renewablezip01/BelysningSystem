/* TODO: Remove the windows.h since we will be running on raspberry pi. */
#include <Windows.h>
#include "Button.h"

namespace ComponentSystem {
	/* Sets up button */
	Button::Button(const std::string& name, int32_t id)
	{
		this->m_Name = name;
		this->m_Id = id;
	}

	/* Used to determine if button is clicked or not. Updates the state of the bool */
	void Button::Update()
	{
		/* TEMPORARY. USING KEYBOARD AS A BUTTON INSTEAD OF PHYSICAL BUTTON THIS IS ONLY FOR TESTING */
		m_State = GetAsyncKeyState(VK_END) ? true : false;
	}

	/* Returns the current state of the bool */
	const bool& Button::GetState() const
	{
		return this->m_State;
	}

}