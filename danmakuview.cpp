#include "danmakuview.h"

#include <QPainter>
#include <QMouseEvent>
#include "scene.h"
#include "bosstemplate.h"
#include "drawable.h"

DanmakuView::DanmakuView(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(480,640);
    setMaximumSize(480,640);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    setMouseTracking(true);

    m_sceneTemplate = SceneTemplate::create();

    m_scene = m_sceneTemplate->run();
}

void DanmakuView::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    p.fillRect(rect(),Qt::black);

    p.setPen(Qt::white);

    p.drawRect(QRect(0,0,479,639));

    // Draw the scene
    if(m_scene)
    {
        foreach(sBoss boss,m_scene->m_lbBosses)
        {
            boss->doPhysics();
            sDrawable draw = boss->m_btTemplate->m_dImage;
            QPointF pos = boss->m_location;

            draw->paint(pos.x(),pos.y(),p);
        }
    }

    p.drawLine(0,m_pMouse.y(),width(),m_pMouse.y());
    p.drawLine(m_pMouse.x(),0,m_pMouse.x(),height());

    QRect text=p.fontMetrics().boundingRect(QString("(X: %1,Y: %2)").arg(m_pMouse.x()).arg(m_pMouse.y()));

    text.moveBottomLeft(QPoint(0,height()));

    p.drawText(text,QString("(X: %1,Y: %2)").arg(m_pMouse.x()).arg(m_pMouse.y()));
}

void DanmakuView::mouseMoveEvent(QMouseEvent *ev)
{
    m_pMouse = ev->pos();

    update();
}
