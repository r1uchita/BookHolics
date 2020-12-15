#include "delete_book.h"
#include "ui_delete_book.h"
#include"add_book.h"
#include<QMessageBox>
#include<iostream>
Delete_Book::Delete_Book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete_Book) {
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    ui->comboBox->addItem("Select");
    ui->comboBox->addItem("Fully damaged");
    ui->comboBox->addItem("Out of Syllabus");
    ui->comboBox->addItem("Missing");
}
Delete_Book::~Delete_Book() {
    delete ui;
}
void Delete_Book::on_pushButton_clicked() {
     QValidator *valid_book_id=new QIntValidator(1,10000,this);
     ui->lineEdit->setValidator(valid_book_id);
     if(!ui->lineEdit->hasAcceptableInput()) {
         QMessageBox::information(this,"Warning","Please Enter valid Book id");
         ui->lineEdit->setPlaceholderText("Enter valid book id");
     }
     else if(ui->comboBox->currentText()=="Select") {
         QMessageBox::information(this,"Warning","Please select valid Reason");
     }
     else{
        int book_id=ui->lineEdit->text().toInt();
        int flag=0;
        if(1==check_book_issue(book_id)){
            QMessageBox::information(this,"Warning","Book Is Issued By Someone");
        }
        else{
            add_book book;
            Delete_Book d_book;
            std::ofstream out_d;
            out_d.open("Deleted_Book.txt",std::ofstream::out | std::ofstream::app);
            std::ifstream in;
            std::ofstream out;
            in.open("book.txt",std::ifstream::in | std::ifstream::app);
            out.open("book_temp.txt",std::ofstream::out);
            while(!in.eof()) {
                in>>book;
                int b_id=book.book_id;
                if(b_id==book_id && book.status=="Available"){
                    d_book.book_id=book.book_id;
                    d_book.book_name=book.book_name;
                    d_book.book_author=book.author;
                    d_book.book_edition=book.edition;
                    d_book.reason=ui->comboBox->currentText().toStdString();
                    std::replace(d_book.reason.begin(),d_book.reason.end(),' ','_');
                    flag=1;
                }
            }
            in.close();
            in.open("book.txt",std::ifstream::in | std::ifstream::app);
            if(flag==1) {
                in>>book;
                while(!in.eof()) {
                    int b_id=book.book_id;
                    if(b_id!=book_id){
                        out<<book;
                    }
                    in>>book;
                }
                in.close();
                out.close();
                remove("book.txt");
                rename("book_temp.txt" , "book.txt");
                QMessageBox::information(this,"Sucess","Book  deleted Sucessfully!!");
                ui->lineEdit->setText("");
            }
            else if(flag==2) {
                QMessageBox::information(this,"Warning","The Given Book id is Issued By someone!");
            }
            else if(flag==0){
                QMessageBox::information(this,"Fail","Given Book Id is Not available in System\nPlease Enter Correct Book ID!!!");
                ui->lineEdit->setText("");
            }
            out_d<<d_book;
            out_d.close();
            ui->comboBox->setCurrentIndex(0);
        }
     }
}
int Delete_Book::check_book_issue(int id){
    add_book book;
    std::ifstream in;
    int flag=0;
    in.open("book.txt",std::ifstream::in);
    if(!in.fail()){
        in>>book;
        while(!in.eof()){
            if(book.book_id==id && book.status=="Issued"){
                flag=1;
                break;
            }
            in>>book;
        }
        in.close();
    }
    if(flag==1){
        return 1;
    }
    else{
        return 0;
    }
}
