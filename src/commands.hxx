#ifndef FGAUGE_COMMANDS_HXX
#define FGAUGE_COMMANDS_HXX

#include "command.hxx"

FGaugeCommand* getCommand(std::string name);

FGAUGECOMMAND_GEN_DEF(FGaugeCommandQuit)

#endif

