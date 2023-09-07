#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "StringConvertor.cpp"
#include "Parser.cpp"
#include "Helper.cpp"
#include <cstring>
#include <cstdio>
#include <QScrollBar>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->CommandLine->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// KEY PRESS EVENT
void MainWindow::keyPressEvent(QKeyEvent *event)
{

}

bool MainWindow::eventFilter(QObject *target, QEvent *event) // https://blog.csdn.net/qq_41488943/article/details/104391200
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *_QKeyEvent = static_cast <QKeyEvent *> (event);

        if (_QKeyEvent->key() == Qt::Key_Return || _QKeyEvent->key() == Qt::Key_Enter)
        {
            // STORE
            this->currentInput = ui->CommandLine->toPlainText().toStdString();

            // MAKE THE CURSOR THE LAST POSITION
            ui->Output->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);

            // CALCULATE & PROCESSING
            forResult();

            // FOR SCROLL BAR
            ui->Output->verticalScrollBar()->setValue(ui->Output->verticalScrollBar()->maximum());
        }
    }

    return QWidget::eventFilter(target,event);
}

void MainWindow::inputCountOutput()
{
    ui->Output->insertPlainText("Input");
    ui->Output->insertPlainText("[");
    ui->Output->insertPlainText(unsignedIntConvert(this->inputCount));
    ui->Output->insertPlainText("]");
    ui->Output->insertPlainText(":");
    ui->Output->insertPlainText(" ");

    ui->InputNotifier->clear();
    ui->InputNotifier->insert("Input");
    ui->InputNotifier->insert("[");
    ui->InputNotifier->insert(unsignedIntConvert(this->inputCount));
    ui->InputNotifier->insert("]");
}

void MainWindow::outputCountOutput()
{
    ui->Output->insertPlainText("Output");
    ui->Output->insertPlainText("[");
    ui->Output->insertPlainText(unsignedIntConvert(this->inputCount));
    ui->Output->insertPlainText("]");
    ui->Output->insertPlainText(":");
    ui->Output->insertPlainText(" ");
}

void MainWindow::forResult()
{

    // OUTPUT THE NUMBER
    ui->Output->insertPlainText(stringConvert(currentInput));
    ui->Output->insertPlainText("\n");
    outputCountOutput();


    // PROCESS THE CURRENT CALCULATION
    std::string parsed = parse(currentInput);

    if (parsed == "EMPTY_STRING")
        ui->Output->insertPlainText("NO CONTENT!");

    else if (parsed == "INVALID_STRING")
        ui->Output->insertPlainText("INVALID INPUT!");

    else if (parsed == "quit()")
    {}

    else if (parsed == "help()")
        getHelp();

    else if (parsed == "clear()")
    {
        ui->CommandLine->clear();
        ui->Output->clear();
    }

    else if (parsed == "lastResult()")
        ui->Output->insertPlainText(stringConvert(this->lastResult));

    else if (parsed == "clipboard()")
        ui->Output->insertPlainText(stringConvert(this->clipboard));

    else if (parsed == "copy(lastResult())")
    {
        clipboard = lastResult;
        ui->Output->insertPlainText("Copied.");
    }

    else if (parsed == "remove(clipboard())")
    {
        clipboard = "0";
        ui->Output->insertPlainText("Removed.\n");
    }

    else if (parsed == "remove(lastResult())")
    {
        lastResult = "0";
        ui->Output->insertPlainText("Removed.");
    }

    else if ((parsed[0] >= 0x30 && parsed[0] <=0x39) || parsed[0]=='-') // EXPRESSION
    {
        ui->Output->insertPlainText(stringConvert(parsed));
        this->lastResult = parsed;
    }
    else
        ui->Output->insertPlainText("INVALID INPUT!\n");

    // PREPARE FOR NEW CALCULATION
    this->inputCount++;
    this->currentInput.clear();
    ui->Output->insertPlainText("\n\n");
    inputCountOutput();

    ui->CommandLine->clear();
}

void MainWindow::on_Keypad1_clicked()
{
    ui->CommandLine->insertPlainText("1");
}


void MainWindow::on_Keypad2_clicked()
{
    ui->CommandLine->insertPlainText("2");
}


void MainWindow::on_Keypad3_clicked()
{
    ui->CommandLine->insertPlainText("3");
}


void MainWindow::on_Keypad4_clicked()
{
    ui->CommandLine->insertPlainText("4");
}


void MainWindow::on_Keypad5_clicked()
{
    ui->CommandLine->insertPlainText("5");
}


void MainWindow::on_Keypad6_clicked()
{
    ui->CommandLine->insertPlainText("6");
}


void MainWindow::on_Keypad7_clicked()
{
    ui->CommandLine->insertPlainText("7");
}


void MainWindow::on_Keypad8_clicked()
{
    ui->CommandLine->insertPlainText("8");
}


void MainWindow::on_Keypad9_clicked()
{
    ui->CommandLine->insertPlainText("9");
}


void MainWindow::on_Keypad0_clicked()
{
    ui->CommandLine->insertPlainText("0");
}


void MainWindow::on_KeypadLeftBracket_clicked()
{
    ui->CommandLine->insertPlainText("[");
}


void MainWindow::on_KeypadRightBracket_clicked()
{
    ui->CommandLine->insertPlainText("]");
}


void MainWindow::on_KeypadDot_clicked()
{
    ui->CommandLine->insertPlainText(".");
}


void MainWindow::on_KeypadPlus_clicked()
{
    ui->CommandLine->insertPlainText("+");
}


void MainWindow::on_KeypadMinus_clicked()
{
    ui->CommandLine->insertPlainText("-");
}


void MainWindow::on_KeypadMultiply_clicked()
{
    ui->CommandLine->insertPlainText("*");
}


void MainWindow::on_KeypadDivide_clicked()
{
    ui->CommandLine->insertPlainText("/");
}

void MainWindow::on_KeypadCalculate_clicked()
{
    // STORE
    this->currentInput = ui->CommandLine->toPlainText().toStdString();

    // MAKE THE CURSOR THE LAST POSITION
    ui->Output->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);

    // CALCULATE & PROCESSING
    forResult();

    // FOR SCROLL BAR
    ui->Output->verticalScrollBar()->setValue(ui->Output->verticalScrollBar()->maximum());
}



void MainWindow::on_CommandLine_textChanged()
{

}


void MainWindow::on_KeypadBackspace_clicked()
{
    // For TextEdit
    QTextCursor cursor = ui->CommandLine->textCursor();
    cursor.deletePreviousChar();
}


void MainWindow::on_KeypadClear_clicked()
{
    ui->CommandLine->clear();
    ui->Output->clear();

    this->currentInput = "";
    inputCountOutput();
}


void MainWindow::on_KeypadLeftParentheses_clicked()
{
    ui->CommandLine->insertPlainText("(");
}


void MainWindow::on_KeypadRightparentheses_clicked()
{
    ui->CommandLine->insertPlainText(")");
}

