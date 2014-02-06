#ifndef DANMAKUVIEW_H
#define DANMAKUVIEW_H

#include <classes.h>
#include <QWidget>

class DanmakuView : public QWidget
{
    Q_OBJECT

    QPoint m_pMouse;

    sSceneTemplate m_sceneTemplate;
    sScene m_scene;

    void paintEvent(QPaintEvent *);

    void mouseMoveEvent(QMouseEvent *ev);
public:
    explicit DanmakuView(QWidget *parent = 0);

signals:

public slots:

};

#endif // DANMAKUVIEW_H
