#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

inline void MainWindow::getHelp()
{
    ui->Output->insertPlainText("\n");

    ui->Output->insertPlainText("Please directly enter the mathematical expression.\n");
    ui->Output->insertPlainText("Using [a/b] for representing the fraction a/b (no need to simplify)\n");
    ui->Output->insertPlainText("The program will return for a fraction value (simplified)\n");

    ui->Output->insertPlainText("\n");

    ui->Output->insertPlainText("Using lastResult() for reviewing the last result, copy() for copying. copy(lastResult()) is allowed for copying the last result.\n");
    ui->Output->insertPlainText("Using remove() for remove the storage. remove(clipboard()) or remove(lastResult()) are all allowed.\n");

    ui->Output->insertPlainText("\n");

    return;
}
