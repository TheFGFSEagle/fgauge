#ifndef FGAUGE_LOGGING_HXX
#define FGAUGE_LOGGING_HXX

#include <iostream>
#include <string>
#include <sstream>

#include "singleton.hxx"
#include "utils.hxx"

class FGaugeLogger: public Singleton<FGaugeLogger> {
	public:
		enum class LogLevel: short {
			DEBUG = 0,
			INFO = 1,
			WARNING = 2,
			ERROR = 3,
			FATAL = 4,
		};
		
		FGaugeLogger() {};
		
		template<typename T>
		void log(LogLevel level, const T& msg) {
			if (level >= _level) {
				if (level >= LogLevel::WARNING) {
					std::cerr << "[" << level << "] " << msg << std::endl;
				} else {
					std::cout << "[" << level << "] " << msg << std::endl;
				}
			}
		}
		friend std::ostream& operator<<(std::ostream&, FGaugeLogger::LogLevel);
	
	private:
		LogLevel _level {LogLevel::DEBUG};
};

std::ostream& operator<<(std::ostream& s, const FGaugeLogger::LogLevel level);

std::string string(FGaugeLogger::LogLevel level);

#define LOG(level, expr) \
	std::stringstream ss; \
	ss << expr; \
	std::string str = ss.str(); \
	FGaugeLogger::instance()->log(FGaugeLogger::LogLevel::level, ss.str());

#endif

