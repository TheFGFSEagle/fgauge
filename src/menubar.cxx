#include <QMenuBar>
#include <QMenu>
#include <QtUiTools>

#include <pugixml.hpp>

#include "commands.hxx"
#include "menubar.hxx"
#include "uiloader.hxx"
#include "utils.hxx"

template<typename T>
void addMenuItem(T* parent, pugi::xml_node itemNode) {
	QAction* item = parent->addAction(itemNode.child_value("label"));
	const char* iconName = itemNode.child_value("icon");
	if (QIcon::hasThemeIcon(iconName)) {
		item->setIcon(QIcon::fromTheme(itemNode.child_value("icon")));
	} else {
		std::cout << "Warning: no such theme icon '" << iconName << "' in theme " << QIcon::themeName().toStdString() << " !" << std::endl;
	}
	item->setShortcut(QKeySequence(itemNode.child_value("shortcut")));
	QObject::connect(
		item,
		&QAction::triggered,
		getCommand(itemNode.child_value("command")),
		&FGaugeCommand::execute
	);
}

template<typename T>
void addMenu(T* parent, pugi::xml_node menuNode) {
	QMenu* menu = parent->addMenu(menuNode.child_value("label"));
	if (menuNode.child("file")) {
		std::string path = getResourcePath(menuNode.child("file").value());
		pugi::xml_document xml;
		pugi::xml_parse_result result = xml.load_file(path.c_str());
		if (!result) {
			std::cout << "Failed loading menu file '" << path << "': " << result.description() << " !" << std::endl;
			return;
		}
		menuNode = xml.child("menu");
	}
	for (pugi::xml_node submenuNode: menuNode.children("menu")) {
		addMenu(menu, submenuNode);
	}
	for (pugi::xml_node itemNode: menuNode.children("menuitem")) {
		addMenuItem(menu, itemNode);
	}
}

FGaugeMenuBar::FGaugeMenuBar() {
}

void FGaugeMenuBar::initUI() {
	pugi::xml_document xml;
	std::string path = getResourcePath("ui/menubar.xml");
	pugi::xml_parse_result result = xml.load_file(path.c_str());
	if (!result) {
		std::cout << "Failed loading project file '" << path << "': " << result.description() << " !" << std::endl;
	}
	
	pugi::xml_node menubarNode = xml.child("menubar");
	for (pugi::xml_node menuNode: menubarNode.children("menu")) {
		::addMenu(this, menuNode);
	}
	for (pugi::xml_node itemNode: menubarNode.children("menuitem")) {
		::addMenuItem(this, itemNode);
	}
}

