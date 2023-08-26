#include "project.hxx"

#include <pugixml.hpp>

FGaugeProject::FGaugeProject(std::filesystem::path path): _path(path) {
}

void FGaugeProject::read() {
	pugi::xml_document xml;
	pugi::xml_parse_result result = xml.load_file(_path.c_str());
	if (!result) {
		std::cout << "Failed loading project file '" << _path << "': " << result.description() << " !" << std::endl;
	}
}

void FGaugeProject::write() {
	writeInternal(_path);
}

void FGaugeProject::writeTo(std::filesystem::path path) {
	_path = path;
	writeInternal(_path);
}

void FGaugeProject::writeCopy(std::filesystem::path path) {
	writeInternal(path);
}

void FGaugeProject::writeInternal(std::filesystem::path path) {
}

