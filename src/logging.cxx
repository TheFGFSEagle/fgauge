#include "logging.hxx"

std::string string(FGaugeLogger::LogLevel level) {
	switch (level) {
		case FGaugeLogger::LogLevel::DEBUG:
			return {"DEBUG"};
		case FGaugeLogger::LogLevel::INFO:
			return {"INFO"};
		case FGaugeLogger::LogLevel::WARNING:
			return {"WARNING"};
		case FGaugeLogger::LogLevel::ERROR:
			return {"ERROR"};
		case FGaugeLogger::LogLevel::FATAL:
			return {"FATAL"};
		default:
			return {"UNKNOWN"};
	}
}

std::ostream& operator<<(std::ostream& s, FGaugeLogger::LogLevel level) {
	s << string(level);
	return s;
}

