#include "application.hxx"
#include "mainwindow.hxx"

int main(int argc, char *argv[]) {
	SVGaugeApplication app = SVGaugeApplication(argc, argv);
	app.initUI();
	return app.exec();
}

