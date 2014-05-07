#ifndef Q_PIN_BALL_D_STUB_H
#define Q_PIN_BALL_D_STUB_H

#include "../../QDMVC/MVC.h"
#include "../../QDMVC/DMVC.h"
#include "QPinBallUtil.h"

class Map;

class MapTimer : public LoopTimer {
public:
	virtual void loop();
public:
	MapTimer(Map* _map) : map(_map) {}
	virtual ~MapTimer() {}
public:
	Map* map;
};

class Map : public DMVCStubModel {
	Q_OBJECT
public:
	void playerMove(int pid, int vhd) {
		QXmlRpcCall cp("server.playerMove");
		cp.appendArg(pid);
		cp.appendArg(vhd);
		rpc_call(cp);

		//selfChanged();
		return;
	}
	void playerStop(int pid, int vhd) {
		QXmlRpcCall cp("server.playerStop");
		cp.appendArg(pid);
		cp.appendArg(vhd);
		rpc_call(cp);
		
		//selfChanged();
		return;
	}
public:
	int getObjPos(int vid, int posparam) {
		QXmlRpcCall cp("server.getObjPos");
		cp.appendArg(vid);
		cp.appendArg(posparam);
		rpc_call(cp);
		int ret = cp.getReturn().toInt();
		if (vid == 1354)
			qDebug() << ret;
		return ret;
	}
public:
	Map() {
		timer = new MapTimer(this);
		timer->start(20);
	}
	virtual ~Map() {
	}
	MapTimer* timer;
};

#endif