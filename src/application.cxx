#include <QDir>
#include <QStandardPaths>
#include <QDebug>

#include <popl.hpp>

#include "application.hxx"
#include "mainwindow.hxx"

SVGaugeApplication::SVGaugeApplication(int& argc, char* argv[]): QApplication(argc, argv) {
	QDir::setSearchPaths("res", QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation));
}

void SVGaugeApplication::initUI() {
	mainWindow = new SVGaugeMainWindow(); 
	mainWindow->show();
}

