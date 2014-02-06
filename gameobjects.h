#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include <QPoint>
#include "math.h"

struct Velocity {
    qreal speed, angle;

    /**
     * @brief apply
     * @param target The QPointF to change
     * @param dt The time delta
     * @param res The resolution of the speed change
     * This function applies the velocity to a QPointF.
     * A smaller resolution gives a more precise calculation at
     * the cost of more computation.
     */
    void apply(QPointF &target, qreal dt = 1.0, qreal res= .1)
    {
        // Calculate each step of the velocity
        for(qreal step = 0.0;step < dt;step+= res)
        {
            target.rx() += speed*cos(angle)*res;
            target.ry() += speed*sin(angle)*res;
        }
    }
};

struct Acceleration {
    qreal acceleration, angle;

    void apply(Velocity &target, qreal dt = 1.0, qreal res = .1)
    {
        qreal sx = target.speed*cos(target.angle);
        qreal sy = target.speed*sin(target.angle);
        for(qreal step = 0.0;step < dt;step+= res)
        {
            sx += acceleration*cos(angle)*res;
            sy += acceleration*sin(angle)*res;
        }
        target.speed = sqrt(pow(sx,2)+pow(sy,2));
        if(!qIsNull(target.speed))
            target.angle = atan2(sy,sx);
    }
};

class Placable
{
protected:
    QPointF m_location;
public:
    int x(){return m_location.x();}
    int y(){return m_location.y();}

    void setX(int x){m_location.setX(x);}
    void setY(int y){m_location.setY(y);}

    void set(QPoint pt){m_location = pt;}
};

class Movable : public Placable
{
protected:
    Velocity m_velocity;
    Acceleration m_accel;
public:
    Movable();

    void doPhysics(qreal dt=1.0,qreal res=0.1)
    {
        for(qreal step=0.0;step< dt;step+= res)
        {
          m_accel.apply(m_velocity,.1);
          m_velocity.apply(m_location,.1);
        }
    }
};

#endif // GAMEOBJECTS_H
