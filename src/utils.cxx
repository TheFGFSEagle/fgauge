#include "utils.hxx"

std::string getResourcePath(std::string path) {
	QFile resolver(("res:" + path).c_str());
	return resolver.fileName().toStdString();
}

template<typename T>
std::string string(T& other) {
	return {other};
}

