//
// Created by Frank Yang on 2023/8/14.
//

#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::welcomeScreen()
{
    ui->Output->append("WELCOME TO FRACNUT🌰 BY FRANK YANG");
    ui->Output->append("To start using this command-line tool, please be following the following instruction:");

    ui->Output->append("1. Use help() for getting help.");
    ui->Output->append("2. Use clear() for clear the screen.");

    ui->Output->append("VER. GUI DEV. BETA 1.0.0");

    ui->Output->append("\n");
}
