#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "User.h"
#include "welcomewindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->error_label2->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_register_button_clicked()
{
    QString uUsername = ui->lineEdit_username2->text();
    QString uDay = ui->lineEdit_Day->text();
    QString uYear = ui->lineEdit_year->text();
    QString uPassword = ui->lineEdit_password2->text();
    QString uRpassword = ui->lineEdit_retype->text();
    QString uMonth = ui->comboBox_month->currentText();

    QString errorMsg;  // To store error messages
    bool hasError = false;

    // Check if the entered username is already existing using a loop
    bool usernameExists = false;
    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == uUsername) {
            usernameExists = true;
            break;  // exit the loop early if the username is found
        }
    }

    if (usernameExists) {
        errorMsg += "Username already exists.\n";
        hasError = true;
    }

    // Check if the entered password is not equal to the retyped password
    if (uRpassword != uPassword) {
        errorMsg += "Passwords do not match.\n";
        hasError = true;
    }

    // Check if any of the input fields is not entered by the user
    if (uUsername.isEmpty() || uDay.isEmpty() || uYear.isEmpty() || uPassword.isEmpty() || uRpassword.isEmpty() || uMonth.isEmpty()) {
        errorMsg += "Please fill in all the fields.\n";
        hasError = true;
    }

    // Check if the age is less than 12 (subtract entered year from 2024)
    int enteredYear = uYear.toInt();
    int currentYear = 2024;
    int age = currentYear-enteredYear;

    qDebug() << "Entered Year: " << enteredYear;
    qDebug() << "Current Year: " << currentYear;
    qDebug() << "Calculated Age: " << age;

    if (age < 12) {
        errorMsg += "You must be at least 12 years old.\n";
        hasError = true;
    }

    // Display error messages
    if (hasError) {
        ui->error_label2->setText(errorMsg);
        ui->error_label2->setVisible(true);
    } else {

        if (userCount < 100) {
            users[userCount].username = uUsername;
            users[userCount].password = uPassword;
            users[userCount].age = age;

            // Update the userCount global variable
            userCount++;
        } else {
            qDebug() << "User array is full.";
            // Handle array full, do not add more elements
        }

        // Hide the error label
        ui->error_label2->setVisible(false);

        // Show the WelcomeWindow with the current username and age
        WelcomeWindow *welcomeWindow = new WelcomeWindow(uUsername, age);
        welcomeWindow->show();

        // Close the current registration window
        this->close();
    }
}

