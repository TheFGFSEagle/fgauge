#include <QMenuBar>
#include <QMenu>
#include <QtUiTools>

#include "menus.hxx"

void setupMenus(QMenuBar* menuBar) {
	QUiLoader loader;
	QFile file("res:ui/menus/file.ui");
	file.open(QFile::ReadOnly);
	QMenu *myWidget = qobject_cast<QMenu*>(loader.load(&file, menuBar));
	file.close();
	menuBar->addMenu(myWidget);
}

