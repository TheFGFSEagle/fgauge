#include <osgQOpenGL/osgQOpenGLWidget>

#include <osgDB/ReadFile>
#include <osgUtil/Optimizer>
#include <osg/CoordinateSystemNode>

#include <osg/Switch>
#include <osg/Types>
#include <osgText/Text>

#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>

#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TerrainManipulator>
#include <osgGA/SphericalManipulator>

#include <osgGA/Device>

#include <QApplication>
#include <QSurfaceFormat>
#include <QMainWindow>
#include <QMenuBar>
#include <QVBoxLayout>

#include <iostream>

#include "application.hxx"
#include "menubar.hxx"
#include "uiloader.hxx"

FGaugeMainWindow::FGaugeMainWindow() {
}

void FGaugeMainWindow::initUI() {
	setWindowTitle("FGauge");
	loadWidgetFromFile<FGaugeMainWindow>("res:ui/mainwindow.ui");
	FGaugeMenuBar::instance()->initUI();
	setMenuBar(FGaugeMenuBar::instance());
	mainWidget = new QWidget();
	QVBoxLayout mainLayout;
	mainWidget->setLayout(&mainLayout);
	widget = new osgQOpenGLWidget(FGaugeApplication::instance()->osgArguments);
	QObject::connect(widget, &osgQOpenGLWidget::initialized, this, &FGaugeMainWindow::load);
	mainLayout.addWidget(widget);
	setCentralWidget(mainWidget);
	statusBar();
}

int FGaugeMainWindow::load() {
	osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> keyswitchManipulator = new osgGA::KeySwitchMatrixManipulator;

	keyswitchManipulator->addMatrixManipulator('1', "Trackball", new osgGA::TrackballManipulator());
	keyswitchManipulator->addMatrixManipulator('2', "Flight", new osgGA::FlightManipulator());
	keyswitchManipulator->addMatrixManipulator('3', "Drive", new osgGA::DriveManipulator());
	keyswitchManipulator->addMatrixManipulator('4', "Terrain", new osgGA::TerrainManipulator());
	keyswitchManipulator->addMatrixManipulator('5', "Orbit", new osgGA::OrbitManipulator());
	keyswitchManipulator->addMatrixManipulator('6', "FirstPerson", new osgGA::FirstPersonManipulator());
	keyswitchManipulator->addMatrixManipulator('7', "Spherical", new osgGA::SphericalManipulator());

	widget->getOsgViewer()->setCameraManipulator(keyswitchManipulator.get());

	widget->getOsgViewer()->addEventHandler(new osgGA::StateSetManipulator(widget->getOsgViewer()->getCamera()->getOrCreateStateSet()));
	widget->getOsgViewer()->addEventHandler(new osgViewer::ThreadingHandler);
	widget->getOsgViewer()->addEventHandler(new osgViewer::WindowSizeHandler);
	widget->getOsgViewer()->addEventHandler(new osgViewer::StatsHandler);
	widget->getOsgViewer()->addEventHandler(new osgViewer::RecordCameraPathHandler);
	widget->getOsgViewer()->addEventHandler(new osgViewer::LODScaleHandler);
	widget->getOsgViewer()->addEventHandler(new osgViewer::ScreenCaptureHandler);
	
	/*osg::ref_ptr<osg::Node> model = osgDB::readRefNodeFile("/media/frederic/WD-5TB/.fg/fgfs-addons/Aircraft/c310-family/Models/c310a.ac");
	if (!model) {
		std::cout << "fail" << std::endl;
		return 1;
	}*/
	
	osgUtil::Optimizer optimizer;
	optimizer.optimize(model);
	
	//widget->getOsgViewer()->setSceneData(model);
	widget->show();
	
	return 0;
}

