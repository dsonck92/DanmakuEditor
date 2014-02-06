#ifndef DRAWABLE_H
#define DRAWABLE_H

class QPainter;

class Drawable
{
public:
    Drawable();

    void paint(int x,int y,QPainter &p);
};

#endif // DRAWABLE_H
