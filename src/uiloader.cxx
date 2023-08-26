#include <QFile>

#include "mainwindow.hxx"
#include "menubar.hxx"
#include "uiloader.hxx"

QWidget* FGaugeUiLoader::createWidget(const QString& widgetName, QWidget* parentWidget, const QString& name) {
	QWidget* w;
	if (widgetName == "FGaugeMenuBar") {
		w = FGaugeMenuBar::instance();
	} else if (widgetName == "FGaugeMainWindow") {
		w = FGaugeMainWindow::instance();
	} else {
		return QUiLoader::createWidget(widgetName, parentWidget, name);
	}
	w->setObjectName(name);
	w->setParent(parentWidget);
	return w;
}

