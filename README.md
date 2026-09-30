## Beholder Archive: Electron

This branch serves as an archive of Beholder's first iteration, which explored using Electron as the application framework in a separate now-deleted repo.

### Why the switch?

The primary advantage of Electron was that it directly renders web languages via an embedded Chromium browser, which makes UI development extraordinarily fast at the cost of application bulk.

This proved very useful for the early stages of UI prototyping, but as the data layer began to form, Electron's sandboxing invited a lot of friction and ceremony that threatened development velocity.

Since the purpose (and source of complexity) of Beholder is primarily the convenient visualization and editing of Dungeons and Dragons character data, a framework that impedes such a core part of the app is effectively a no-go.

---

TLDR; the UI development speed Electron offered was not enough to outweight its resistance to quick iteration on the complex data layer, plus it was excessively bulky anyways.

After this I moved to [QtQuick](https://github.com/xwilson03/Beholder/tree/archive/qtquick), then [QtWidgets](https://github.com/xwilson03/Beholder/tree/archive/qtwidgets).
