// Obiekt ktory ma mozliwosc zderzenia sie z innym obiektem HTObj

#ifndef HTOBJ_H
#define HTOBJ_H

class HTObj
{
public:
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getW() = 0;
	virtual int getH() = 0;
	virtual bool isMoveable() = 0;
	virtual bool getCollisionState() = 0;
	virtual HTObj *getCollisionTarget() = 0;
	virtual void setCollisionState(bool p_state) = 0;
	virtual void setCollisionTarget(HTObj *p_target) = 0;


private:
	bool m_collisionState;
	HTObj *m_collisionTarget;
};

#endif