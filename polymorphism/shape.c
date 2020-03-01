#include "shape.h"
#include <stddef.h>

void Shape_ctor(Shape * const me, int16_t x, int16_t y)
{
	me->vptr = NULL;
	me->x = x;
	me->y = y;
};

void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy)
{
	me->x += dx;
	me->y += dy;
};

int16_t Shape_getX(Shape * const me)
{
	int16_t ret = 0;
	ret = me->x;
	return ret;
};

int16_t Shape_getY(Shape * const me)
{
	int16_t ret = 0;
	ret = me->y;
	return ret;
};