#ifndef SVGAUGE_MAINWINDOW_HXX
#define SVGAUGE_MAINWINDOW_HXX

#include <QMainWindow>
#include <osgViewer/Viewer>
#include <osgQOpenGL/osgQOpenGLWidget>

class FGaugeMainWindow: public QMainWindow {
	public:
		FGaugeMainWindow();
		void initUI();
		int load();
	
	private:
		QWidget* mainWidget;
		osgQOpenGLWidget* widget;
};

#endif

