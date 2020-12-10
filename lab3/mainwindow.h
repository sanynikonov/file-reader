#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void open();
    void about();

private:
    void createActions();
    void createMenus();
    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *openAct;
    QAction *aboutAct;
    QLabel *infoLabel;
};
#endif // MAINWINDOW_H
