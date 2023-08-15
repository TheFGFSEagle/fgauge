#include "application.hxx"

int main(int argc, char *argv[]) {
	FGaugeApplication app = FGaugeApplication(argc, argv);
	app.initUI();
	
	return app.exec();
}

