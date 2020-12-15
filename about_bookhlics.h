#ifndef ABOUT_BOOKHLICS_H
#define ABOUT_BOOKHLICS_H

#include <QMainWindow>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QProgressBar>
#include<QSlider>
#include<QFileDialog>
namespace Ui {
class about_bookhlics;
}

class about_bookhlics : public QMainWindow {
    Q_OBJECT
public:
    explicit about_bookhlics(QWidget *parent = 0);
    ~about_bookhlics();
private slots:
    void on_actionPlay_triggered();
    void on_actionStop_triggered();
    void on_actionOpen_triggered();

private:
    Ui::about_bookhlics *ui;
    QMediaPlayer *player;
    QVideoWidget *vw;
    QProgressBar *bar;
    QSlider *slider;
};
#endif // ABOUT_BOOKHLICS_H
