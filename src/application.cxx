#include <QDir>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDebug>

#include <argparse/argparse.hpp>

#include "application.hxx"
#include "logging.hxx"
#include "mainwindow.hxx"

FGaugeApplication::FGaugeApplication(int& argc, char **argv):
	QApplication(argc, argv)
{
	LOG(INFO, "info message");
	osgArguments = new osg::ArgumentParser(&argc, argv);
	QDir::setSearchPaths("res", QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation));
}

void FGaugeApplication::initUI() {
	FGaugeMainWindow* w = FGaugeMainWindow::instance();
	w->initUI();
	w->showMaximized();
}

void FGaugeApplication::loadProject() {
	std::string filename = QFileDialog::getOpenFileName(nullptr, "Open project", QDir::currentPath(), "FGauge projects (*.fgauge)").toStdString();
	std::cout << "loadProject " << filename<< std::endl;
}

