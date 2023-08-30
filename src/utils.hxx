#ifndef FGAUGE_UTILS_HXX
#define FGAUGE_UTILS_HXX

#include <QDir>
#include <string>

std::string getResourcePath(std::string path);

template<typename T>
std::string& string(T& string);

#endif

