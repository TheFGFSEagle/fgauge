#include "mainwindow.hxx"
#include "menus.hxx"

SVGaugeMainWindow::SVGaugeMainWindow() {
	setWindowTitle("SVGauge");
	setupMenus(menuBar());
	//setCentralWidget(myWidget);
}

