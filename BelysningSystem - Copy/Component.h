#pragma once
#include <String>
/// <summary>
/// Takes care of every component that we will be using for our circuit.
/// It defines the components attributes and behaviour.
/// </summary>

namespace ComponentSystem {

	/* Every component extends from this class. */
	class Component
	{
	public:
		/* Getters */
		const std::string& const GetName() const;
		const std::int32_t& const GetId() const;

	protected:
		/* Stops initialization of object. But keeps it for the inherited classes. */
		Component() = default;

	protected:
		std::string m_Name = "Undefined";
		int32_t m_Id = NULL;
	};

	class Button : virtual public Component
	{
	public:
		Button(const std::string& name, int32_t id);
	public:
		void Press();
		void Release();

	private:
		bool m_State = false;
	};

	class LightLED : virtual public Component {
	public:
		LightLED(const std::string& name, int32_t id);
	private:
		bool m_State = false;
	};
}