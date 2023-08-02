#ifndef SVGAUGE_APPLICATION_HXX
#define SVGAUGE_APPLICATION_HXX

#include <QApplication>

#include "mainwindow.hxx"

class SVGaugeApplication: public QApplication {
	public:
		SVGaugeApplication(int& argc, char* argv[]);
		void initUI();
		SVGaugeMainWindow* mainWindow;
};
#endif

