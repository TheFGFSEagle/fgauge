#include <iostream>
#include <filesystem>

#include <osg/Group>

class FGaugeProject: public osg::Group {
	public:
		FGaugeProject(std::filesystem::path path);
		void read();
		void write();
		void writeTo(std::filesystem::path path);
		void writeCopy(std::filesystem::path path);
		std::filesystem::path getPath() { return _path; }
	
	private:
		void writeInternal(std::filesystem::path path);
		std::filesystem::path _path;
};

