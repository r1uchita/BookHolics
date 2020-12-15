#ifndef LOGO_H
#define LOGO_H

#include <QMainWindow>

namespace Ui {
class logo;
}
class logo : public QMainWindow {
    Q_OBJECT
public:
    explicit logo(QWidget *parent = 0);
    ~logo();
private:
    Ui::logo *ui;
};

#endif // LOGO_H
