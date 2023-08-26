#ifndef FGAUGE_MAINWINDOW_HXX
#define FGAUGE_MAINWINDOW_HXX

#include <QMainWindow>
#include <osgViewer/Viewer>
#include <osgQOpenGL/osgQOpenGLWidget>

#include "singleton.hxx"

class FGaugeMainWindow: public Singleton<FGaugeMainWindow, QMainWindow> {
	Q_OBJECT
	public:
		FGaugeMainWindow();
		void initUI();
		int load();
		inline static const std::string name {"mainwindow "};
	
	private:
		QWidget* mainWidget;
		osgQOpenGLWidget* widget;
	
	public slots:
		void loadProject();
};

#endif

