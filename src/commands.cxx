#include <iostream>
#include <map>
#include <string>

#include "application.hxx"
#include "commands.hxx"

FGAUGECOMMAND_GEN_IMPL(FGaugeCommandQuit, "quit", FGaugeApplication::instance()->exit())
FGAUGECOMMAND_GEN_IMPL(FGaugeCommandLoadProject, "load-project", FGaugeApplication::instance()->loadProject())

static std::map<std::string, FGaugeCommand*> _commandMap = {
	{"quit", FGaugeCommandQuit::instance()},
	{"load-project", FGaugeCommandLoadProject::instance()},
};

FGaugeCommand* getCommand(std::string name) {
	if (!_commandMap.contains(name)) {
		return nullptr;
	}
	return _commandMap[name];
}

