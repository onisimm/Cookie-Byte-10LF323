#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createUI();
    setupConnections();

    setWindowTitle("Twixt Game");
    setFixedSize(600, 500);  // Adjust the size as needed
}

MainWindow::~MainWindow()
{
    // Destructor
}

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
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    titleLabel = new QLabel("Choose your Twixt gamemode:", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setFont(QFont("Comic Sans MS", 15));

    defaultButton = new QPushButton("Default", this);
    defaultButton->setFont(QFont("Comic Sans MS"));

    bulldozerButton = new QPushButton("Bulldozer", this);
    bulldozerButton->setFont(QFont("Comic Sans MS"));

    minesButton = new QPushButton("Mines", this);
    minesButton->setFont(QFont("Comic Sans MS"));

    layout->addWidget(titleLabel);
    layout->addSpacerItem(new QSpacerItem(20, 40));
    layout->addWidget(defaultButton);
    layout->addWidget(bulldozerButton);
    layout->addWidget(minesButton);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::setupConnections()
{
    connect(defaultButton, SIGNAL(clicked()), this, SLOT(onDefaultButtonClicked()));
    connect(bulldozerButton, SIGNAL(clicked()), this, SLOT(onBulldozerButtonClicked()));
    connect(minesButton, SIGNAL(clicked()), this, SLOT(onMinesButtonClicked()));
}
