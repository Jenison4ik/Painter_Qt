#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 🎨 Выбор цвета
    connect(ui->btnColor, &QPushButton::clicked, this, [this]() {
        QColor color = QColorDialog::getColor(Qt::black, this, "Выберите цвет");
        if (color.isValid()) {
            ui->canvas->setPenColor(color);
            ui->canvas->setDrawMode(); // 🔹 автоматический выход из режима ластика
        }
    });

    // 🧽 Очистка
    connect(ui->btnClear, &QPushButton::clicked, this, [this]() {
        ui->canvas->clear();
    });

    // ✏️ Карандаш
    connect(ui->btnPen, &QPushButton::clicked, this, [this]() {
        ui->canvas->setDrawMode();
    });

    // 🩹 Ластик
    connect(ui->btnEraser, &QPushButton::clicked, this, [this]() {
        ui->canvas->setEraserMode(true);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
