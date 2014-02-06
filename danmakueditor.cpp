#include "danmakueditor.h"

#include "danmakuview.h"
#include "scenebox.h"
#include <QMenuBar>
#include <QMenu>
#include <QDockWidget>

DanmakuEditor::DanmakuEditor(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(new DanmakuView);

    QDockWidget *dw = new QDockWidget();
    dw->setWidget(new SceneBox);

    addDockWidget(Qt::RightDockWidgetArea,dw);

    QMenu *m = menuBar()->addMenu("File");
    m->addAction("New");
    m->addAction("Open ...");
    m->addAction("Save");
    m->addAction("Save As ...");

    m->addSeparator();

    m->addAction("Quit",this,SLOT(close()));
}

DanmakuEditor::~DanmakuEditor()
{

}
