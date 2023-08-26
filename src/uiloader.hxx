#ifndef FGAUGE_UILOADER_HXX
#define FGAUGE_UILOADER_HXX

#include <iostream>

#include <QUiLoader>
#include <QFile>

class FGaugeUiLoader: public QUiLoader {
	public:
		QWidget* createWidget(const QString &widgetName, QWidget* parentWidget, const QString &name);
};


template<typename T>
T* loadWidgetFromFile(const char* path) {
	std::cout << "loading widget from file: " << path << std::endl;
	FGaugeUiLoader loader;
	QFile file(path);
	file.open(QFile::ReadOnly);
	T* w = qobject_cast<T*>(loader.load(&file));
	file.close();
	
	return w;
}

#endif

