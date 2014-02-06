#include "drawable.h"

#include <QPainter>

Drawable::Drawable()
{
}

void Drawable::paint(int x, int y, QPainter &p)
{
    p.setPen(Qt::red);
    p.drawLine(x,y-10,x,y+9);
    p.drawLine(x-10,y,x+9,y);
}
