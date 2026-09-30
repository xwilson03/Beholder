## Beholder Archive: QtQuick

This branch serves as an archive of Beholder's second iteration, which explored using QtQuick as the application framework in a separate now-deleted repo.

### Why the switch?

After deciding against Electron, my focus was on exploring a performant framework that wouldn't obstruct our data layer like Electron's sandboxing did, but would still provide a faster way of iterating on UI development than pure C++.

With those goals in mind, QtQuick was not a difficult choice at all. I had used QtWidgets before, and was familiar with Qt's capability; QtQuick offered the performance of C++ with less churn thanks to its UI markup language, QML.

As I started to rebuild the Electron iteration's UI using QtQuick, though, I realized that the ceremony of integrating QtQuick with CMake was outweighing the speed I was gaining from using QML for my UI.

In addition to that, integrating QML with the data layer was a much larger conceptual barrier than the near-zero mental overhead of using QtWidgets and pure C++.

Since I was already between frameworks, I decided that QtQuick wasn't going to be worth the effort, and that with such little investment I would just switch while I still had the chance.

---
TLDR; QtQuick was a more performant option than Electron that retained some niceties for UI development, but its integration complexity overshadowed the UI dev-candy it offered when compared to QtWidgets.

After this I moved to [QtWidgets](https://github.com/xwilson03/Beholder/tree/archive/qtwidgets).
