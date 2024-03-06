#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "welcomewindow.h"
#include "registerwindow.h"
#include "User.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->errorlabel->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString enteredUsername = ui->lineEdit_username->text();
    QString enteredPassword = ui->lineEdit_password->text();

    bool found = false;
    for (int i = 0; i < userCount; i++) {
        if (users[i].password == enteredPassword && users[i].username == enteredUsername) {
            found = true;

            // Successful login
            hide();
            WelcomeWindow* welcomeWindow = new WelcomeWindow(enteredUsername, users[i].age, this);
            welcomeWindow->show();

            break;
        }
    }

    if (!found) {
        // Wrong username or password
        ui->errorlabel->setText("Wrong username or password");
        ui->errorlabel->setVisible(true);
    }
}



void LoginWindow::on_pushButton_register_clicked()
{
    hide();
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->show();

}

