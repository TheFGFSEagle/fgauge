#include <iostream>
#include <map>
#include <string>

#include "application.hxx"
#include "commands.hxx"

FGAUGECOMMAND_GEN_IMPL(FGaugeCommandQuit, quit, FGaugeApplication::instance()->exit())

static std::map<std::string, FGaugeCommand*> _commandMap = {
	{"quit", FGaugeCommandQuit::instance()}
};

FGaugeCommand* getCommand(std::string name) {
	if (!_commandMap.contains(name)) {
		std::cout << "No command with name '" << name << "' !" << std::endl;
		return nullptr;
	}
	return _commandMap[name];
}

