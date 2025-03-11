#include <cstdlib>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main (int argc, char *argv[]) {

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath(QML_DIR);
    const QUrl url(QStringLiteral(QML_DIR "/main.qml"));
    engine.load(url);

    if (engine.rootObjects().size() == 0) {
        exit(EXIT_FAILURE);
    }

    return app.exec();
}
