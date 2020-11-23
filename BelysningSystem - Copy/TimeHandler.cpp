#include "TimeHandler.h"

void TimePoint::UpdateClock()
{
	/* Uses chrono instead of Sleep() because we don't want to sleep the thread. */
	next = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	if (m_Second == 59) {
		m_Second = 0;
		m_Minute = m_Minute + 1;
		if (m_Minute == 60) {
			m_Minute = 0;
			m_Hour = m_Hour + 1;
			if (m_Hour == 24) {
				m_Hour = 0;
			}
		}
	}

	if ((next - start).count() >= 1000) {
		start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		m_Second++;
		std::cout << m_Hour << ":" << m_Minute << ":" << m_Second << "\n";
	}

}

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
