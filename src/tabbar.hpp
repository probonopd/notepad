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
    bool cardClicked = false;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};
