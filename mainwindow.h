#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QComboBox>
#include <QApplication>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bmr_clicked();

    void on_exit_clicked();


private:
    Ui::MainWindow *ui;
        QLabel *weight;
        QLabel *height;
        QLabel *age;
        QLabel *fmr;
        QLineEdit *weightLineEdit;
        QLineEdit *heightLineEdit;
        QLineEdit *agetLineEdit;
        QComboBox *formulaComboBox;
        QPushButton *bmr;


};
#endif // MAINWINDOW_H
