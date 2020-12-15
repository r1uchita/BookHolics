#include"ids.h"
#include "add_student.h"
#include "ui_add_student.h"
#include<QMessageBox>
#include<QFile>
#include<ostream>
#include<QTextStream>
#include<QString>
#include"library_card.h"
Add_Student::Add_Student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Student) {
    ui->setupUi(this);
    ui->comboBox_class->addItem("Select");
    ui->comboBox_class->addItem("First  Year");
    ui->comboBox_class->addItem("Second  Year");
    ui->comboBox_class->addItem("Third  Year");
    ui->comboBox_class->addItem("Final Year");

    ui->comboBox_dept->addItem("Select");
     ui->comboBox_dept->addItem("General Science Department");
    ui->comboBox_dept->addItem("Computer Science and Engineerinng");
    ui->comboBox_dept->addItem("Mechnical  Engineering");
    ui->comboBox_dept->addItem("Civil Engineering");
    ui->comboBox_dept->addItem("Electrical and Telicommunication Engineering");

    ui->radioButton_female->setText("Female");
    ui->radioButton_male->setText("Male");

    ui->comboBox_div->addItem("Select");
    ui->comboBox_div->addItem("A");
    ui->comboBox_div->addItem("B");

    IDs id;
    int s_id=id.getID("Student");
    ui->lineEdit_borrow_id->setText(QString::number(s_id));
    ui->lineEdit_borrow_id->setReadOnly(true);
}
Add_Student::~Add_Student() {
    delete ui;
}
int  Add_Student::verify_data() {
    int flag=0;
    if(ui->lineEdit_fullname->text().isEmpty()||ui->lineEdit_email->text().isEmpty()||ui->lineEdit_phone->text().isEmpty()||ui->comboBox_class->currentText()=="Select"||ui->comboBox_dept->currentText()=="Select"||ui->comboBox_div->currentText()=="Select")    {
        QMessageBox::information(this,"Warning","Please Enter Valid data\nPlease Select proper Choice");
        flag=1;
    }
    return flag;
}
void Add_Student::on_pushButton_add_student_clicked() {
    int flag=verify_data();
    if(flag==0) {
        int borrow_s=ui->lineEdit_borrow_id->text().toInt();
        std::string name_s=ui->lineEdit_fullname->text().toStdString();
        std::string email_id=ui->lineEdit_email->text().toStdString();
        std::string department=ui->comboBox_dept->currentText().toStdString();
        std::string class_stud=ui->comboBox_class->currentText().toStdString();
        std::string division=ui->comboBox_div->currentText().toStdString();
        std::string phone_no=ui->lineEdit_phone->text().toStdString();
        std::string gendre_s;
        if(ui->radioButton_female->isChecked()) {
            gendre_s="Female";
        }
        else {
            gendre_s="Male";
        }
        std::string pass="student";
        Add_Student std;
        std.add_stud(borrow_s,name_s,gendre_s,email_id,department,class_stud,division,phone_no,pass);
        std::ofstream out;
        out.open("student.txt" ,std::ofstream::out | std::ofstream::app);
        out<<std;
        out.close();
        IDs id;
        id.updateID("Student",borrow_s);
        QMessageBox::information(this,"Add Student","New Student Recored Added Successfully....!");
        QString name=ui->lineEdit_email->text();
        int s_id=id.getID("Student");
        ui->lineEdit_borrow_id->setText(QString::number(s_id));
        ui->lineEdit_fullname->setText("");
        ui->lineEdit_phone->setText("");
        ui->lineEdit_email->setText("");
        ui->comboBox_class->setCurrentIndex(0);
        ui->comboBox_dept->setCurrentIndex(0);
        ui->comboBox_div->setCurrentIndex(0);
        ui->radioButton_female->setCheckable(0);
        ui->radioButton_male->setCheckable(0);

        Library_Card=new library_card(this,name);
        Library_Card->show();
    }
    else{
        QMessageBox::information(this,"Error","Please Enter valid data");
    }
}
