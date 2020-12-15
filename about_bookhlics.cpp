#include "about_bookhlics.h"
#include "ui_about_bookhlics.h"

about_bookhlics::about_bookhlics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::about_bookhlics) {
    ui->setupUi(this);
    player=new QMediaPlayer(this);
    vw=new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);
    QString filename="F:/4th sem/cloth.mp4";
    on_actionStop_triggered();
    player->setMedia(QUrl::fromLocalFile(filename));
    on_actionPlay_triggered();
}
about_bookhlics::~about_bookhlics()
{
    delete ui;
}
void about_bookhlics::on_actionPlay_triggered() {
    player->play();
    ui->statusbar->showMessage("Playing....");
}
void about_bookhlics::on_actionStop_triggered()
{
    player->stop();
    ui->statusbar->showMessage("Stopped...");
}
void about_bookhlics::on_actionOpen_triggered()
{
    QString filename=QFileDialog::getOpenFileName(this,"C.mp4");
    on_actionStop_triggered();
    player->setMedia(QUrl::fromLocalFile(filename));
    on_actionPlay_triggered();


}
