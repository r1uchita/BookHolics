#ifndef LIBRARY_CARD_H
#define LIBRARY_CARD_H

#include <QMainWindow>
namespace Ui {
class library_card;
}
class library_card : public QMainWindow {
    Q_OBJECT
public:
    explicit library_card(QWidget *parent = 0,QString u_name="");
    QString name;
    void showData(QString U_name="");
    ~library_card();
private slots:
    void on_pushButton_clicked();
private:
    Ui::library_card *ui;
};

#endif // LIBRARY_CARD_H
