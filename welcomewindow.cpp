#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QString username, int age, QWidget *parent)
    : QDialog(parent), ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    //Set hello label text
    QString helloText = "Hello " + username + " " + QString::number(age);
    ui->label_hello->setText(helloText);

    QPixmap image(":/Users/boi/Desktop/T2_cslab_ass1/assignment_ahmed_joshua-/images/download.jpg");
    ui->label_image->setPixmap(image.scaled(ui->label_image->size(), Qt::KeepAspectRatio));
}



WelcomeWindow::~WelcomeWindow() {
    delete ui;
}

void WelcomeWindow::on_pushButton_logout_clicked()
{
    hide();
    LoginWindow* loginWindow = new LoginWindow(this);
    loginWindow->show();
}

