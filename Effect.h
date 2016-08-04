#ifndef EFFECT_H
#define EFFECT_H

class Effect {
public:
	Effect() {};   // Constructor.
	virtual void init(void);
	virtual void update(unsigned long delta);
	virtual void show(void);
};

#endif //EFFECT_H