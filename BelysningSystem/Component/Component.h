/// <summary>
/// Takes care of every component that we will be using for our circuit.
/// It defines the components attributes and behaviour.
/// </summary>
#pragma once
#include <String>

namespace ComponentSystem {

	/* Every component extends from this class. */
	class Component
	{
	public:
		/* Getters */

		/* Gets the name of the component */
		const std::string& GetName() const;

		/* Gets the id of the component */
		const int32_t& GetId() const;

	protected:
		/* Stops initialization of object. But keeps it available for the inherited classes. */
		Component() = default;

	protected:
		std::string m_Name = "Undefined";
		int32_t m_Id = NULL;
	};
}