
#include "../../QDMVC/MVC.h"
#include "../../QDMVC/DMVC.h"

#include "QPinBallDStub.h"
#include "QPinBallView.h"

int main(int argc, char *argv[])
{
	MVCApp* app = new MVCApp(argc, argv);

	Map model;
	bool ret = model.connectToHost();
	if(!ret) 
		app->exit();

	MapView view(&model);
	
	app->addItem(&view);
	app->setFixedSize(803, 603);
	app->show();

	view.setFocus();

	return app->exec();
}
