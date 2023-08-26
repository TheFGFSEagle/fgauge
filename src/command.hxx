#ifndef FGAUGE_COMMAND_HXX
#define FGAUGE_COMMAND_HXX

#include <QObject>

class FGaugeCommand: public QObject {
	Q_OBJECT
	public:
		FGaugeCommand() {};
		virtual ~FGaugeCommand() {};
		virtual void execute() {};
		virtual const std::string name();
};

#define FGAUGECOMMAND_GEN_DEF(classname) \
class classname: public FGaugeCommand { \
	public: \
		classname(); \
		void execute() override; \
		const std::string name() override; \
};

#define FGAUGECOMMAND_GEN_IMPL(classname, stringname, exec_code) \
classname::classname() {}; \
void classname::execute() { \
	exec_code; \
} \
const std::string classname::name() { \
	return #stringname; \
} \

#endif

