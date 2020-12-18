#include "LED.h"
namespace ComponentSystem {
	/* Sets up the LED */
	LED::LED(const std::string& name, int32_t id)
	{
		this->m_Name = name;
		this->m_Id = id;
	}
	/* Pass through the wanted LED logic to determine if LED should be on or off. */
	void LED::Logic(bool logic)
	{
		if (logic)
			On();
		else
			Off();
	}
	/* Turns on the LED */
	void LED::On()
	{
		this->m_State = true;
	}

	/* Turns off the LED */
	void LED::Off()
	{
		this->m_State = false;
	}
	/* Returns the current state of the LED */
	const bool& LED::GetBool() const
	{
		return this->m_State;
	}

	//BlinkingLED::BlinkingLED(const std::string& name, int32_t id)
	//{
	//	this->m_Name = name;
	//	this->m_Id = id;
	//}

}