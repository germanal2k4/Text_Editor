#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_actionOpen_triggered();

  void on_actionNew_triggered();

  void on_actionSave_triggered();

  void on_actionQt_triggered();

  void on_actionProgramm_triggered();

private:
  Ui::MainWindow *ui;
  QString m_openedFileName;
};
#endif // MAINWINDOW_H
