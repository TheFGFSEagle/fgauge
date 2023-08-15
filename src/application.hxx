#ifndef SVGAUGE_APPLICATION_HXX
#define SVGAUGE_APPLICATION_HXX

#include <QApplication>

#include <osg/ArgumentParser>

#include "mainwindow.hxx"

class FGaugeApplication: public QApplication {
	public:
		FGaugeApplication(int& argc, char **argv, osg::ArgumentParser*);
		FGaugeApplication(int& argc, char **argv);
		void initUI();
		static FGaugeApplication* instance() {
			return static_cast<FGaugeApplication*>(QApplication::instance());
		}
		
		FGaugeMainWindow* mainWindow;
		osg::ArgumentParser* osgArguments;
};
#endif

