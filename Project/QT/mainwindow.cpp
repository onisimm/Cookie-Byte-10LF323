#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createUI();
    setupConnections();

    setWindowTitle("Twixt Game");
    setFixedSize(600, 500);
}

MainWindow::~MainWindow() {}

void MainWindow::onDefaultButtonClicked()
{
    // TODO
}

void MainWindow::onBulldozerButtonClicked()
{
    // TODO
}

void MainWindow::onMinesButtonClicked()
{
    // TODO
}

void MainWindow::createUI()
{
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* verticalLayout = new QVBoxLayout(centralWidget);

    titleLabel = new QLabel("Choose your Twixt gamemode:");
    titleLabel->setFont(QFont("Comic Sans MS", 15));
    titleLabel->setAlignment(Qt::AlignCenter);

    QSpacerItem* verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Maximum, QSizePolicy::Maximum);

    defaultButton = new QPushButton("Default");
    defaultButton->setFont(QFont("Comic Sans MS"));
    defaultButton->setStyleSheet("text-align:center;"); // Center align the button text

    bulldozerButton = new QPushButton("Bulldozer");
    bulldozerButton->setFont(QFont("Comic Sans MS"));
    bulldozerButton->setStyleSheet("text-align:center;"); // Center align the button text

    minesButton = new QPushButton("Mines");
    minesButton->setFont(QFont("Comic Sans MS"));
    minesButton->setStyleSheet("text-align:center;"); // Center align the button text

    verticalLayout->addWidget(titleLabel);
    verticalLayout->addItem(verticalSpacer);
    verticalLayout->addWidget(defaultButton);
    verticalLayout->addWidget(bulldozerButton);
    verticalLayout->addWidget(minesButton);
}


void MainWindow::setupConnections()
{
    connect(defaultButton, SIGNAL(clicked()), this, SLOT(onDefaultButtonClicked()));
    connect(bulldozerButton, SIGNAL(clicked()), this, SLOT(onBulldozerButtonClicked()));
    connect(minesButton, SIGNAL(clicked()), this, SLOT(onMinesButtonClicked()));
}
