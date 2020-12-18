#include <sstream>
#include "TimePoint.h"
#define TimePointToSeconds(timepoint) ((timepoint.m_Hour * hoursToSeconds) + (timepoint.m_Minute * minutesToSeconds) + timepoint.m_Second)

namespace TimeSystem {
	/* Better than using magic numbers */
	static constexpr int hoursToSeconds = 3600;
	static constexpr int minutesToSeconds = 60;

	int32_t TimePoint::ToSeconds()
	{
		return TimePointToSeconds((*this));
	}

	/* Operator overloads used to add logic to the LED */
	bool TimePoint::operator==(const TimePoint& other)
	{
		if (TimePointToSeconds((*this)) == TimePointToSeconds(other)) {
			return true;
		}
		return false;
	}

	bool TimePoint::operator>(const TimePoint& other)
	{
		if (TimePointToSeconds((*this)) > TimePointToSeconds(other)) {
			return true;
		}
		return false;
	}

	bool TimePoint::operator>=(const TimePoint& other)
	{
		if (TimePointToSeconds((*this)) >= TimePointToSeconds(other)) {
			return true;
		}
		return false;
	}

	bool TimePoint::operator<(const TimePoint& other)
	{
		if (TimePointToSeconds((*this)) < TimePointToSeconds(other)) {
			return true;
		}
		return false;
	}

	bool TimePoint::operator<=(const TimePoint& other)
	{
		if (TimePointToSeconds((*this)) <= TimePointToSeconds(other)) {
			return true;
		}
		return false;

	}
	TimePoint TimePoint::operator+(const TimePoint& other)
	{
		/* Sets all time to seconds */
		int tempTotalSec = TimePointToSeconds((*this)) + TimePointToSeconds(other);
		/* Converts the seconds to H:M:S */
		TimePoint re((tempTotalSec / hoursToSeconds) % 24, (tempTotalSec / minutesToSeconds) % 60, tempTotalSec % 60);
		return re;
	}
	TimePoint TimePoint::operator-(const TimePoint& other)
	{
		/* Sets all time to seconds */
		int tempTotalSec = TimePointToSeconds((*this)) - TimePointToSeconds(other);
		/* Converts the seconds to H:M:S */
		TimePoint re((tempTotalSec / hoursToSeconds) % 24, (tempTotalSec / minutesToSeconds) % 600, tempTotalSec % 60);
		return re;
	}
	std::ostream& operator<<(std::ostream& os, const TimePoint& other)
	{
		os << other.m_Hour << ":" << other.m_Minute << ":" << other.m_Second;
		return os;
	}
	TimePoint::operator std::string()
	{
		std::stringstream os;
		os << *this;
		return os.str();
	}
}