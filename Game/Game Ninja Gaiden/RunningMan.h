#pragma once
#include "Enemy.h"

enum RUNNINGMAN_STATE
{
	RUNNINGMAN_STATE_WAIT,
	RUNNINGMAN_STATE_RUN
};

enum RUNNINGMAN_ACTION
{
	RUNNINGMAN_ACTION_WAIT,
	RUNNINGMAN_ACTION_RUN
};

class RunningMan :
	public Enemy
{
	RUNNINGMAN_STATE runningManState;
public:
	void setRunningManState(RUNNINGMAN_STATE runningManState);
	void onIntersect(MovableRect* other) override;
	void update(float dt) override;
	RunningMan();
	~RunningMan();
};

