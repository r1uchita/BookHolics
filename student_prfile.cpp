#include "student_prfile.h"
#include "ui_student_prfile.h"
#include"add_student.h"
#include"change_password.h"
student_prfile::student_prfile(QWidget *parent,QString name) :
    QMainWindow(parent),
    ui(new Ui::student_prfile) {
    ui->setupUi(this);
    ui->lineEdit_borrow->setReadOnly(true);
    ui->lineEdit_dept->setReadOnly(true);
    ui->lineEdit_email->setReadOnly(true);
    ui->lineEdit_fullname->setReadOnly(true);
    ui->lineEdit_gender->setReadOnly(true);
    ui->lineEdit_phone->setReadOnly(true);
    ui->lineEdit_class->setReadOnly(true);

    u_name=name;
    Add_Student stud;
    std::ifstream in;
    QString e;
    in.open("student.txt" ,std::ofstream::in | std::ofstream::app);
    while(!in.eof()) {
        in>>stud;
        e=QString::fromStdString(stud.email);
        if(u_name==e){
            std::replace(stud.name.begin(),stud.name.end(),'_',' ');
            std::replace(stud.dept.begin(),stud.dept.end(),'_',' ');
            std::replace(stud.class_s.begin(),stud.class_s.end(),'_',' ');
            ui->lineEdit_borrow->setText(QString::number(stud.borrow_id));
            ui->lineEdit_fullname->setText(QString::fromStdString(stud.name));
            ui->lineEdit_dept->setText(QString::fromStdString(stud.dept));
            ui->lineEdit_email->setText(QString::fromStdString(stud.email));
            ui->lineEdit_gender->setText(QString::fromStdString(stud.gendre));
            ui->lineEdit_phone->setText(QString ::fromStdString(stud.phone_no));
            ui->lineEdit_class->setText(QString::fromStdString(stud.class_s));
        }
     }
}
student_prfile::~student_prfile() {
    delete ui;
}
void student_prfile::on_chang_password_clicked() {
    Change_Password=new change_password(this,"Student",u_name);
    Change_Password->show();
}
