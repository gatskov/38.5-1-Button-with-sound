#include <QApplication>
#include <iostream>
#include "button.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    auto but = new winButton(nullptr);
    //but->setFixedSize(100, 100);
    but->move(1000, 400);
    QObject::connect(but, &winButton::clicked, [](){
        std::cout << "cliced...\n";
    });

    but->show();

    return app.exec();
}