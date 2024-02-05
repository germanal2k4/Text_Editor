#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <QByteArray>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionOpen_triggered() {
  QString m_fileName =
      QFileDialog::getOpenFileName(this, "Open file ...", QDir::homePath(),
                                   "Text files (*.txt);;All files (*.*)");
  if (m_fileName.isEmpty()) {
    return;
  }
  QFile m_file(m_fileName);
  if (m_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    m_openedFileName = m_fileName;
    ui->textEdit->setPlainText(m_file.readAll());
    m_file.close();
  } else {
    QMessageBox::warning(
        this, " Error ",
        QString("Could not open file %1 for reading").arg(m_file.fileName()),
        QMessageBox::Ok);
  }
  setWindowTitle(m_openedFileName);
}

void MainWindow::on_actionNew_triggered() {
  m_openedFileName = "Untitled";
  ui->textEdit->clear();
  setWindowModified(false);
  setWindowTitle(m_openedFileName);
}

void MainWindow::on_actionSave_triggered() {
  if (!isWindowModified()) {
    return;
  }
  QString m_fileName =
      QFileDialog::getOpenFileName(this, "Open file ...", QDir::homePath(),
                                   "Text files (*.txt);;All files (*.*)");
  if (m_fileName.isEmpty()) {
    return;
  }
  QFile m_file(m_fileName);
  if (m_file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    m_openedFileName = m_fileName;
    QByteArray m_data;
    m_file.close();
  }
}

void MainWindow::on_actionQt_triggered() { QApplication::aboutQt(); }

void MainWindow::on_actionProgramm_triggered() { QApplication::aboutQt(); }
