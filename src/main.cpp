
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("SlipCut");

    QMainWindow window;
    window.setWindowTitle("SlipCut | Video Editor");
    window.resize(1200, 750);
    window.setMinimumSize(900, 600);

    QWidget *central = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->setContentsMargins(18, 18, 18, 18);
    layout->setSpacing(14);

    // HEADER
    QHBoxLayout *header = new QHBoxLayout;

    QLabel *logo = new QLabel("SLIPCUT");
    logo->setStyleSheet(
        "font-size: 28px;"
        "font-weight: bold;"
        "color: #B58AFF;"
    );

    QLabel *subtitle = new QLabel("Creative Video Editor");
    subtitle->setStyleSheet("color: #AAA4B7;");

    QPushButton *newProject =
        new QPushButton("+ New Project");

    header->addWidget(logo);
    header->addSpacing(12);
    header->addWidget(subtitle);
    header->addStretch();
    header->addWidget(newProject);

    layout->addLayout(header);

    // MAIN WORKSPACE
    QHBoxLayout *workspace = new QHBoxLayout;
    workspace->setSpacing(14);

    // MEDIA PANEL
    QFrame *mediaPanel = new QFrame;
    mediaPanel->setObjectName("panel");
    mediaPanel->setMinimumWidth(220);

    QVBoxLayout *mediaLayout =
        new QVBoxLayout(mediaPanel);

    QLabel *mediaTitle = new QLabel("PROJECT MEDIA");
    mediaTitle->setStyleSheet(
        "color: #C6A7FF;"
        "font-weight: bold;"
    );

    QLabel *mediaText = new QLabel(
        "Your media will appear here.\n\n"
        "Video importing is coming soon."
    );

    mediaText->setWordWrap(true);
    mediaText->setStyleSheet("color: #AAA4B7;");

    mediaLayout->addWidget(mediaTitle);
    mediaLayout->addWidget(mediaText);
    mediaLayout->addStretch();

    // PREVIEW PANEL
    QFrame *previewPanel = new QFrame;
    previewPanel->setObjectName("panel");

    QVBoxLayout *previewLayout =
        new QVBoxLayout(previewPanel);

    QLabel *previewTitle = new QLabel("PREVIEW");
    previewTitle->setStyleSheet(
        "color: #C6A7FF;"
        "font-weight: bold;"
    );

    QLabel *preview = new QLabel(
        "SLIPCUT\n\n"
        "Your creative workspace starts here."
    );

    preview->setAlignment(Qt::AlignCenter);
    preview->setStyleSheet(
        "background: #0B0A0E;"
        "color: #B58AFF;"
        "font-size: 22px;"
        "border: 1px dashed #594174;"
        "border-radius: 10px;"
    );

    previewLayout->addWidget(previewTitle);
    previewLayout->addWidget(preview, 1);

    workspace->addWidget(mediaPanel);
    workspace->addWidget(previewPanel, 1);

    layout->addLayout(workspace, 1);

    // TIMELINE
    QFrame *timelinePanel = new QFrame;
    timelinePanel->setObjectName("panel");
    timelinePanel->setMinimumHeight(160);

    QVBoxLayout *timelineLayout =
        new QVBoxLayout(timelinePanel);

    QLabel *timelineTitle = new QLabel("TIMELINE");
    timelineTitle->setStyleSheet(
        "color: #C6A7FF;"
        "font-weight: bold;"
    );

    QLabel *videoTrack = new QLabel(
        "V1   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
    );

    QLabel *audioTrack = new QLabel(
        "A1   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
    );

    videoTrack->setStyleSheet(
        "background: #302440;"
        "color: #D4BFFF;"
        "padding: 12px;"
        "border-radius: 5px;"
    );

    audioTrack->setStyleSheet(
        "background: #252039;"
        "color: #BBA8E8;"
        "padding: 12px;"
        "border-radius: 5px;"
    );

    timelineLayout->addWidget(timelineTitle);
    timelineLayout->addWidget(videoTrack);
    timelineLayout->addWidget(audioTrack);
    timelineLayout->addStretch();

    layout->addWidget(timelinePanel);

    // DARK PURPLE THEME
    window.setStyleSheet(R"(
        QMainWindow, QWidget {
            background: #111016;
            color: #F5F2FA;
            font-family: Arial;
            font-size: 13px;
        }

        QFrame#panel {
            background: #1B1823;
            border: 1px solid #30283E;
            border-radius: 10px;
        }

        QPushButton {
            background: #8C52E8;
            color: white;
            border: none;
            border-radius: 7px;
            padding: 12px 16px;
            font-weight: bold;
        }

        QPushButton:hover {
            background: #A16DF3;
        }
    )");

    QObject::connect(
        newProject,
        &QPushButton::clicked,
        [&window, &preview]() {
            QMessageBox::information(
                &window,
                "SlipCut",
                "Welcome to SlipCut!\n\n"
                "Project creation is coming soon."
            );
        }
    );

    window.setCentralWidget(central);
    window.show();

    return app.exec();
}
