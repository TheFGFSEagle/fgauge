#ifndef FGAUGE_MENUBAR_HXX
#define FGAUGE_MENUBAR_HXX

#include <QMenuBar>
#include "singleton.hxx"

class FGaugeMenuBar: public Singleton<FGaugeMenuBar, QMenuBar> {
	Q_OBJECT
	public:
		FGaugeMenuBar();
		void initUI();
		inline static const std::string name {"menubar "};
};

#endif
