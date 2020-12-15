#include "library_card.h"
#include "ui_library_card.h"
#include"add_student.h"
#include<QMessageBox>
#include<QPainter>
#include<QDesktopServices>
#include<QPdfWriter>
#include<QUrl>
library_card::library_card(QWidget *parent,QString u_name) :
    QMainWindow(parent),
    ui(new Ui::library_card) {
    ui->setupUi(this);
    name=u_name;
}
library_card::~library_card() {
    delete ui;
}
void library_card::on_pushButton_clicked() {
    Add_Student stud;
    std::ifstream in;
    QString e;
    in.open("student.txt" ,std::ofstream::in | std::ofstream::app);
    while(!in.eof()) {
        in>>stud;
        e=QString::fromStdString(stud.email);
        if(name==e) {
            std::replace(stud.name.begin(),stud.name.end(),'_',' ');
            std::replace(stud.dept.begin(),stud.dept.end(),'_',' ');
            std::replace(stud.class_s.begin(),stud.class_s.end(),'_',' ');
            ui->lineEdit_borrow_id->setText(QString::number(stud.borrow_id));
            ui->lineEdit_full_name->setText(QString::fromStdString(stud.name));
            ui->lineEdit_dept->setText(QString::fromStdString(stud.dept));
            ui->lineEdit_division->setText(QString::fromStdString(stud.div));
            ui->lineEdit_email->setText(QString::fromStdString(stud.email));
            ui->lineEdit_gender->setText(QString::fromStdString(stud.gendre));
            ui->lineEdit_phone->setText(QString ::fromStdString(stud.phone_no));
            ui->lineEdit_class->setText(QString::fromStdString(stud.class_s));
            ui->label_id->setText("Code######"+QString::number(stud.borrow_id));
        }
    }
    QString library_c=QString::number(stud.borrow_id)+".pdf";
    QPdfWriter pdf(library_c);
    QPainter painter(&pdf);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Times New Romn",12));
    painter.drawPixmap(QRect(3000,100,3500,3000),QPixmap("E:/QT/BOOKHOLICS/book1.jpg"));
    painter.drawText(3000,3500,"BORROW ID :");
    painter.drawText(5000,3500,QString::number(stud.borrow_id));
    painter.drawText(3000,3900,"FULL NAME :");
    painter.drawText(5000,3900,QString::fromStdString(stud.name));
    painter.drawText(3000,4300,"DEPARTMENT :");
    painter.drawText(5000,4300,QString::fromStdString(stud.dept));
    painter.drawText(3000,4700,"CLASS :");
    painter.drawText(5000,4700,QString::fromStdString(stud.class_s));
    painter.drawText(3000,5100,"DIVISION :");
    painter.drawText(5000,5100,QString::fromStdString(stud.div));
    painter.drawText(3000,5500,"GENDER :");
    painter.drawText(5000,5500,QString::fromStdString(stud.gendre));
    painter.drawText(3000,5900,"PHONE :");
    painter.drawText(5000,5900,QString ::fromStdString(stud.phone_no));
    painter.drawText(3000,6300,"EMAIL :");
    painter.drawText(5000,6300,QString::fromStdString(stud.email));
    painter.drawPixmap(QRect(3100,6750,2800,300),QPixmap("E:/QT/BOOKHOLICS/barcode.png"));
    painter.drawText(3500,7250,"Code######"+QString::number(stud.borrow_id));
    painter.drawPixmap(QRect(6700,7750,2900,600),QPixmap("E:/QT/BOOKHOLICS/sign.jpeg"));
    painter.drawText(6900,8600,"SIGNATURE OF LIBRARIAN");
    painter.end();

    in.close();
}
