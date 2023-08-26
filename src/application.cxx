#include <QDir>
#include <QStandardPaths>
#include <QDebug>

#include <popl.hpp>

#include "application.hxx"
#include "mainwindow.hxx"

FGaugeApplication::FGaugeApplication(int& argc, char **argv):
	QApplication(argc, argv)
{
	osgArguments = new osg::ArgumentParser(&argc, argv);
	QDir::setSearchPaths("res", QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation));
}

void FGaugeApplication::initUI() {
	FGaugeMainWindow* w = FGaugeMainWindow::instance();
	w->initUI();
	w->show();
}

