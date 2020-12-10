#include <QtWidgets>
#include "mainwindow.h"
#include "TextWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    infoLabel = new QLabel(tr("<i>Choose a menu option<i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignBottom);

    QTextEdit *newWidget1 = new QTextEdit();
    newWidget1->setText("Example text 1");

    QTextEdit *newWidget2 = new QTextEdit();
    newWidget2->setText("Example text 2");

    QTabWidget *tabWidget = new QTabWidget(this);
    tabWidget->setMovable(true);
    tabWidget->setTabsClosable(true);
    tabWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tabWidget->addTab(newWidget1, "Tab1");
    tabWidget->addTab(newWidget2, "Tab2");
    connect(tabWidget->tabBar(), &QTabBar::tabCloseRequested, tabWidget->tabBar(), &QTabBar::removeTab);


    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(tabWidget);
    layout->addWidget(infoLabel);
    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("Choose a menu option or just enjoy the taskbar");
    statusBar()->showMessage(message);

    setWindowTitle("TxtReader");
    setGeometry(500, 300, 640, 480);
    setMinimumSize(640, 480);
}

void MainWindow::open()
{
    infoLabel->setText(tr("Invoked <b>File|Open</b>"));
}

void MainWindow::about()
{
    infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About TxtReader"),
            tr("Simple Reader of txt files"));
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}

MainWindow::~MainWindow()
{
}

