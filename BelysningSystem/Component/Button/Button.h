/// <summary>
/// Logic for the button. Child of Component
/// </summary>

#pragma once
#include "../Component.h"
namespace ComponentSystem {

	class Button : virtual public Component
	{
	public:
		Button(const std::string& name, int32_t id);
	public:
		/* TODO: Attach it to GPIO to get physical button events */
		/* Updates the state of the bool through click events */
		void Update();

		/* Returns the current state of the bool */
		const bool& GetState() const;

	private:
		bool m_State = false;
	};

}
