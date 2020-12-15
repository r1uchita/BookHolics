#include "logo.h"
#include"login.h"
#include "first_page.h"
#include<QTimer>
#include<QSplashScreen>
#include<QApplication>
int main(int argc,char *argv[]) {
    QApplication a(argc,argv);
    logo w;
    first_page f;
    w.show();
    QTimer::singleShot(5000,&w,SLOT(close()));
    QTimer::singleShot(5000,&f,SLOT(show()));
    return a.exec();
}
