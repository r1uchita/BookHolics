#include "login.h"
#include "ui_login.h"
#include "admin_panel.h"
#include"student_panel.h"
#include"staff_panel.h"
#include<QMessageBox>
#include<QStatusBar>
#include<QDateTime>
QString captcha;
Login::Login(QWidget *parent,QString member) :
    QDialog(parent),
    ui(new Ui::Login) {
    ui->setupUi(this);
    file_name=member;
    ui->lineEdit_username->setFocus();
    captcha=GetRandomString();
    ui->lineEdit_enter_above_captcha->setText(captcha);
    ui->lineEdit_enter_above_captcha->setReadOnly(true);
}
Login::~Login() {
    delete ui;
}
void Login::on_Login_button_clicked() {
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();
    QString enter_above_captcha=ui->lineEdit_captcha->text();
    if(captcha==enter_above_captcha){
        if(file_name=="student") {
            student_login(username,password);
        }
        else if(file_name=="staff") {
            staff_login(username,password);
        }
        else if(file_name=="librarian") {
            librarian_login(username,password);
        }
    }
    else{
        QMessageBox::information(this,"Login Failure","Check Credetionals....!");
    }
}
void Login::on_reset_button_clicked() {
    ui->lineEdit_username->setText("");
    ui->lineEdit_password->setText("");
    captcha=GetRandomString();
    ui->lineEdit_enter_above_captcha->setText(captcha);
    ui->lineEdit_captcha->setText("");
}
void Login::student_login(QString username,QString password) {
    int flag=0;
    Add_Student stud;
    std::ifstream in;
    QString e;
    in.open("student.txt" ,std::ofstream::in | std::ofstream::app);
    if(!in.fail()){
        while(!in.eof()) {
            in>>stud;
            e=QString::fromStdString(stud.email);
            QString pass=QString::fromStdString(stud.password);
            if(username==e && password==pass) {
                flag=1;
                QMessageBox::information(this,"Login","Student Login Successfully....!");
                student_panel *Student_Panel=new student_panel(this,e,stud.borrow_id);
                Student_Panel->show();
                hide();
            }
            if(flag==1) {
                break;
            }
            else if(flag==0){
                ui->label_message->setText("Invalid UserName or Password");
            }
        }
    }
    else{
        QMessageBox::information(this,"Error","User Not Registered");
    }
}
void Login::staff_login(QString username,QString password) {
    int flag=0;
    add_staff staff;
    std::ifstream in;
    in.open("staff.txt" ,std::ofstream::in | std::ofstream::app);
    if(!in.fail()){
        while(!in.eof()) {
            in>>staff;
            QString email=QString::fromLocal8Bit(staff.email.c_str());
            QString pass=QString::fromLocal8Bit(staff.password.c_str());
            if(username==email && password==pass) {
                flag=1;
                QMessageBox::information(this,"Login","Staff Login Successfully....!");
                hide();
                staff_panel *Staff_Panel=new staff_panel(this,email,staff.borrow_id);
                Staff_Panel->show();
                hide();
            }
            if(flag==1) {
                break;
            }
        }
        if(flag==0) {
            ui->label_message->setText("InValid UserName or Password");
        }
    }
    else{
        QMessageBox::information(this,"Error","User Not Registered");
    }
}
void  Login::librarian_login(QString username,QString password) {
    if(username=="admin" && password=="admin@123") {
        Admin_Panel *admin_panel=new Admin_Panel(this);
        admin_panel->show();
        hide();
    }
    else {
        ui->label_message->setText("InValid UserName or Password");
    }
}
void Login::on_checkBox_stateChanged(int arg1) {
    if(arg1==2){
        ui->lineEdit_password->setEchoMode(ui->lineEdit_password->Normal);
    }
    else if(arg1==0){
         ui->lineEdit_password->setEchoMode(ui->lineEdit_password->Password);
    }
 }
QString Login::GetRandomString() {
    const QString PossibleCharacters("A0B1C2D3E4zFy5G6xHw7vIt8sJr9qK0pLo1nM2mN3lO4kP5jQi6Rh7Sg8fT9eUdVcWXbYZa");
    const int randomStringlength=6;
    QString randomString;
    for(int i=0;i<randomStringlength;++i) {
        uint x=QDateTime::currentMSecsSinceEpoch();
        int index= qrand()%(x % PossibleCharacters.length());
        QChar nextChar=PossibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}
