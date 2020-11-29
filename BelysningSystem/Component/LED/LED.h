/// <summary>
/// An LED light child of component
/// </summary>

#pragma once
#include "../Component.h"
namespace ComponentSystem {

	class LED : virtual public Component {
	public:
		LED(const std::string& name, int32_t id);

	public:
		/* Logic wanted for the bool */
		void Logic(bool logic);

		/* Turns on the LED */
		void On();

		/* Turns off the LED */
		void Off();

		/* Returns the current state of the LED */
		const bool& GetBool() const;

	private:
		bool m_State = false;
	};
}

