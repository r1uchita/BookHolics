#include "about_us.h"
#include "ui_about_us.h"
#include"about_bookhlics.h"
about_us::about_us(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::about_us) {
    ui->setupUi(this);
}
about_us::~about_us() {
    delete ui;
}
void about_us::on_pushButton_clicked() {
    about_bookhlics *book=new about_bookhlics(this);
    book->show();
}
