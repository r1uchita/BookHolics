#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include"admin_panel.h"
#include"student_panel.h"
#include"staff_panel.h"
#include"add_student.h"
namespace Ui {
class Login;
}
class Login : public QDialog {
    Q_OBJECT
public:
    explicit Login(QWidget *parent = 0,QString file_name="");
    ~Login();
    QString file_name;
    QString GetRandomString();
private slots:
    void  student_login(QString,QString);
    void staff_login(QString,QString);
    void librarian_login(QString,QString);
    void on_Login_button_clicked();
    void on_reset_button_clicked();
    void on_checkBox_stateChanged(int arg1);
private:
    Ui::Login *ui;
};

#endif // LOGIN_H
