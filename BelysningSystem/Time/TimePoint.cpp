#include "TimePoint.h"
namespace TimeSystem {

	/* Operator overloads used to add logic to the LED */
	bool TimePoint::operator==(const TimePoint& other)
	{
		if (other.m_Hour == this->m_Hour &&
			other.m_Minute == this->m_Minute &&
			other.m_Second == this->m_Second)
		{
			return true;
		}
		return false;
	}

	bool TimePoint::operator>(const TimePoint& other)
	{
		if (this->m_Hour >= other.m_Hour &&
			this->m_Minute >= other.m_Minute &&
			this->m_Second >= other.m_Second)
		{
			return true;
		}
		return false;
	}

	bool TimePoint::operator<(const TimePoint& other)
	{
		if (this->m_Hour <= other.m_Hour &&
			this->m_Minute <= other.m_Minute &&
			this->m_Second <= other.m_Second)
		{
			return true;
		}
		return false;
	}
}