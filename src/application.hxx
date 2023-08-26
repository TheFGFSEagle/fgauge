#ifndef FGAUGE_APPLICATION_HXX
#define FGAUGE_APPLICATION_HXX

#include <QApplication>

#include <osg/ArgumentParser>

#include "mainwindow.hxx"

class FGaugeApplication: public QApplication {
	public:
		FGaugeApplication(int& argc, char **argv);
		void initUI();
		static FGaugeApplication* instance() {
			return static_cast<FGaugeApplication*>(QApplication::instance());
		}
		
		osg::ArgumentParser* osgArguments;
};
#endif

