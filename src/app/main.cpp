#include <QGuiApplication>
#include <QQuickView>

int main (int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("src/app/ui/main.qml"));

    view.show();
    return app.exec();
}
