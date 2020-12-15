#include "add_book.h"
#include "ui_add_book.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QValidator>
#include"ids.h"
#include<QFile>
#include<ostream>
#include<QTextStream>
#include<fstream>
#include<iostream>
#include<QString>
#include<QRegularExpression>
#include<QRegularExpressionValidator>
add_book::add_book(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add_book) {
    ui->setupUi(this);
    ui->department->addItem("Select");
    ui->department->addItem("General Science Department");
    ui->department->addItem("Computer Science and Engineering");
    ui->department->addItem("Electrical and Telicommunication Engineering");
    ui->department->addItem("Mechnical Engineering");
    ui->department->addItem("Civil Engineering");
    ui->book_releas_year->addItem("Select");
    for(int i=1998;i<2019;i++) {
        ui->book_releas_year->addItem(QString::number(i));
    }
    ui->book_format->addItem("Select");
    ui->book_format->addItem("CD");
    ui->book_format->addItem("E-Book");
    ui->book_format->addItem("Printed");
    ui->type_of_book->addItem("Select");
    ui->type_of_book->addItem("Reference");
    ui->type_of_book->addItem("Text Book");
    ui->book_edition->addItem("Select");
    for (int i=1;i<10;i++) {
        ui->book_edition->addItem(QString::number(i));
    }
    IDs id;
    int b_id=id.getID("Book");
    ui->book_id->setText(QString::number(b_id));
    ui->book_id->setReadOnly(true);
}
add_book::~add_book() {
    delete ui;
}
int add_book::validation() {
    int flag=0;
    if(ui->book_id->text().isEmpty()||ui->book_name->text().isEmpty()||ui->book_keyword->text().isEmpty()||ui->book_author_1->text().isNull()||ui->book_isbn_no->text().isEmpty()||ui->book_price->text().isEmpty()||ui->book_quantity->text().isEmpty()||ui->book_format->currentText()=="Select"||ui->book_releas_year->currentText()=="Select"||ui->book_edition->currentText()=="Select"||ui->department->currentText()=="Select"||ui->book_format->currentText()=="Select")    {
        QMessageBox::information(this,"Warning","Please insert proper data or\nPlease Select proper Choice");
        flag=1;
    }
    return flag;
}
void add_book::on_button_add_book_clicked() {
   int flag=validation();
   ui->book_author_4->setText(QString::number(flag));
   if(flag==0)  {
    add_book std;
    std::ofstream out;
    out.open("book.txt",std::ofstream::out | std::ofstream::app);
    int  b_id=ui->book_id->text().toInt();
    int b_isbn_no=ui->book_isbn_no->text().toInt();
    for(int i=0;i<ui->book_quantity->text().toInt();i++){
        std::string b_name=ui->book_name->text().toStdString();
        std::string b_key=ui->book_keyword->text().toStdString();
        std::string b_publication=ui->book_publication->text().toStdString();
        std::string b_author=ui->book_author_1->text().toStdString()+" "+ui->book_author_2->text().toStdString()+" "+ui->book_author_3->text().toStdString()+" "+ui->book_author_4->text().toStdString();
        int b_price=ui->book_price->text().toInt();
        std::string b_format=ui->book_format->currentText().toStdString();
        std::string b_type=ui->type_of_book->currentText().toStdString();
        std::string b_dept=ui->department->currentText().toStdString();
        int b_year=ui->book_releas_year->currentText().toInt();
        int b_edition=ui->book_edition->currentText().toInt();
        std::string b_status="Available";
        std.book(b_id,b_name,b_key,b_publication,b_author,b_price,b_format,b_type,b_dept,b_isbn_no,b_year,b_edition,b_status);
        out<<std;
        b_id=b_id+1;
        b_isbn_no++;
    }
    out.close();
    IDs id;
    id.updateID("Book",ui->book_quantity->text().toInt());
    QMessageBox::information(this,"Add Book","New Book Details Added Successfully...!");
    b_id=id.getID("Book");
    ui->book_id->setText(QString::number(b_id));
    ui->book_name->setText("");
    ui->book_author_1->setText("");
    ui->book_author_2->setText("");
    ui->book_author_3->setText("");
    ui->book_author_4->setText("");
    ui->book_isbn_no->setText("");
    ui->book_price->setText("");
    ui->book_publication->setText("");
    ui->book_quantity->setText("");
    ui->book_keyword->setText("");
    ui->book_edition->setCurrentIndex(0);
    ui->book_format->setCurrentIndex(0);
    ui->type_of_book->setCurrentIndex(0);
    ui->book_releas_year->setCurrentIndex(0);
    ui->department->setCurrentIndex(0);
   }
}
