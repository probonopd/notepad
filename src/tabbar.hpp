#include <QTabBar>
#include <QMimeData>
#include <QDrag>
#include <QDebug>
#include <QMouseEvent>

class TabBar : public QTabBar
{
public:
    TabBar();
    ~TabBar();
private:
    void mouseMoveEvent(QMouseEvent *event);
};
