#include "book_transaction.h"
#include "ui_book_transaction.h"
#include "book_issue.h"
#include"book_return.h"
#include "book_returned.h"
#include<QMessageBox>
book_transaction::book_transaction(QWidget *parent,QString member,int id) :
    QMainWindow(parent),
    ui(new Ui::book_transaction) {
    ui->setupUi(this);
    if(member=="Student") {
            ui->issue->setColumnCount(6);
            int i=0;
            book_issue book;
            std::ifstream in;
            in.open("student_issue.txt",std::ifstream::in);
            if(!in.fail()){
                in>>book;
                for(int j=0;!in.eof();j++){
                    if(id==book.borrow_id) {
                        ui->issue->insertRow(i);
                        std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
                        QString b_id=QString::number(book.book_id);
                        QString b_name=QString::fromStdString(book.book_name);
                        QString b_edition=QString::number(book.book_edition);
                        std::replace(book.book_author.begin(),book.book_author.end(),'_',' ');
                        QString b_author=QString::fromStdString(book.book_author);
                        ui->issue->setItem(i,0,new QTableWidgetItem(b_id));
                        ui->issue->setItem(i,1,new QTableWidgetItem(b_name));
                        ui->issue->setItem(i,2,new QTableWidgetItem(b_author));
                        ui->issue->setItem(i,3,new QTableWidgetItem(b_edition));
                        ui->issue->setItem(i,4,new QTableWidgetItem(QString::fromStdString(book.issue_date)));
                        ui->issue->setItem(i,5,new QTableWidgetItem(QString::fromStdString(book.due_date)));
                        i++;
                    }
                    in>>book;
                }
                in.close();
            }
            else{
                QMessageBox::information(this,"Error","Book Not Issued");
            }
    }
    else if(member=="Staff"){
            ui->issue->setColumnCount(6);
            int i=0;
            book_issue book;
            std::ifstream in;
            in.open("staff_issue.txt",std::ifstream::in);
            if(!in.fail()){
                in>>book;
                for(int j=0;!in.eof();j++){
                    if(id==book.borrow_id) {
                        ui->issue->insertRow(i);
                        std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
                        QString b_id=QString::number(book.book_id);
                        QString b_name=QString::fromStdString(book.book_name);
                        QString b_edition=QString::number(book.book_edition);
                        std::replace(book.book_author.begin(),book.book_author.end(),'_',' ');
                        QString b_author=QString::fromStdString(book.book_author);
                        ui->issue->setItem(i,0,new QTableWidgetItem(b_id));
                        ui->issue->setItem(i,1,new QTableWidgetItem(b_name));
                        ui->issue->setItem(i,2,new QTableWidgetItem(b_author));
                        ui->issue->setItem(i,3,new QTableWidgetItem(b_edition));
                        ui->issue->setItem(i,4,new QTableWidgetItem(QString::fromStdString(book.issue_date)));
                        ui->issue->setItem(i,5,new QTableWidgetItem(QString::fromStdString(book.due_date)));
                        i++;
                    }
                    in>>book;
                }
                in.close();
            }
            else{
                QMessageBox::information(this,"Error","Books Not Issued");
            }
    }
    if(member=="Student"){
        ui->return_details->setColumnCount(6);
        int i=0;
        book_return book;
        std::ifstream in;
        in.open("student_return.txt",std::ifstream::in);
        if(!in.fail()){
            in>>book;
            for(int j=0;!in.eof();j++){
                  if(id==book.borrow_id) {
                      ui->return_details->insertRow(i);
                      std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
                      QString b_id=QString::number(book.book_id);
                      QString b_name=QString::fromStdString(book.book_name);
                      QString b_edition=QString::number(book.book_edition);
                      std::replace(book.book_author.begin(),book.book_author.end(),'_',' ');
                      QString b_author=QString::fromStdString(book.book_author);
                      ui->return_details->setItem(i,0,new QTableWidgetItem(b_id));
                      ui->return_details->setItem(i,1,new QTableWidgetItem(b_name));
                      ui->return_details->setItem(i,2,new QTableWidgetItem(b_author));
                      ui->return_details->setItem(i,3,new QTableWidgetItem(b_edition));
                      ui->return_details->setItem(i,4,new QTableWidgetItem(QString::fromStdString(book.return_date)));
                      ui->return_details->setItem(i,5,new QTableWidgetItem(QString::number(book.fine)));
                      i++;
                  }
                  in>>book;
            }
            in.close();
        }
        else{
            QMessageBox::information(this,"Error","Books Not Returned");
        }
    }
    else if(member=="Staff"){
        ui->return_details->setColumnCount(5);
        int i=0;
        book_return book;
        std::ifstream in;
        in.open("staff_return.txt",std::ifstream::in);
        if(!in.fail()){
            in>>book;
            for(int j=0;!in.eof();j++){
                  if(id==book.borrow_id) {
                      ui->return_details->insertRow(i);
                      std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
                      QString b_id=QString::number(book.book_id);
                      QString b_name=QString::fromStdString(book.book_name);
                      QString b_edition=QString::number(book.book_edition);
                      std::replace(book.book_author.begin(),book.book_author.end(),'_',' ');
                      QString b_author=QString::fromStdString(book.book_author);
                      ui->return_details->setItem(i,0,new QTableWidgetItem(b_id));
                      ui->return_details->setItem(i,1,new QTableWidgetItem(b_name));
                      ui->return_details->setItem(i,2,new QTableWidgetItem(b_author));
                      ui->return_details->setItem(i,3,new QTableWidgetItem(b_edition));
                      ui->return_details->setItem(i,4,new QTableWidgetItem(QString::fromStdString(book.return_date)));
                      i++;
                  }
                  in>>book;
            }
            in.close();
        }
        else{
            QMessageBox::information(this,"Error","Book Not Returned");
        }
    }
}
book_transaction::~book_transaction() {
    delete ui;
}
