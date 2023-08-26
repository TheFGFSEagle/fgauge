#ifndef SINGLETON_HXX
#define SINGLETON_HXX

#include <map>
#include <string>

template<typename Class, typename... Bases>
class Singleton: public Bases... {
	public:
		static Class* instance() {
			static Class* instance = new Class;
			return instance;
		}
		
		static Class* instance(std::string key) {
			static std::map<std::string, Class*> instanceMap;
			if (!instanceMap.contains(key)) {
				instanceMap[key] = new Class;
			}
			return instanceMap[key];
		}
};
#endif

