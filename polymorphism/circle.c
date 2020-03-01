#include "circle.h"
#include <stdio.h>

static uint32_t Circle_area_(Shape const * const me)
{
	Circle const * const me_ = (Circle const *)me;

	/* pi is approximated as 3 */
	return 3 * (uint32_t)me_->rad * (uint32_t)me_->rad;
};
static void Circle_draw_(Shape const * const me)
{
	Circle const * const me_ = (Circle const *)me;

	printf("Circle_draw_(x=%d,y=%d,rad=%d)\n",
		Shape_getX(me), Shape_getY(me), me_->rad);
}

void Circle_ctor(Circle * const me, int16_t x, int16_t y,
	uint16_t rad)
{
	static struct ShapeVtbl const vtbl = {
		&Circle_area_,
		&Circle_draw_
	};

	Shape_ctor(&me->super, x, y);
	me->super.vptr = &vtbl;
	me->rad = rad;
};

Shape const *largestShape(Shape const *shapes[], uint32_t nShapes)
{
	Shape const *s = (Shape *)0;
	uint32_t max = 0;
	uint32_t i = 0;
	for (i = 0; i < nShapes; i++)
	{
		uint32_t area = Shape_area(shapes[i]);
		if (area > max)
		{
			max = area;
			s = shapes[i];
		}
	}
	return s;
}

void drawAllShapes(Shape const *shapes[], uint32_t nShapes)
{
	uint32_t i;
	for (i = 0; i < nShapes; ++i) {
		Shape_draw(shapes[i]);
	}
};