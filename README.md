## Beholder Archive: QtWidgets v1

This branch serves as an archive of Beholder's third iteration, which layed the groundwork of the current QtWidgets approach in a separate now-deleted repo.

### Why the switch?

Moving from QtQuick and Electron, my primary goal was to keep the software architecture as simple as possible, since the app's features would invite enough complexity on their own.

Pursuant to that, I began implementing the same skeleton UI I had created before in both Electron and QtQuick, then scoped out how I wanted to integrate the UI with the data layer among other things.

With the loss of Electron's web-based UI and QtQuick's QML, I also started using Figma for UI iteration and prototyping, which let me scope out much more of the UI design than I had before.

This iteration also cemented a couple of key milestones. Namely:
- Decided on a Model/View/Controller architecture
- Settled on the dependency injection pattern for linking UI components with their backends
- Consolidated state data into a global store similar to the Redux design pattern often used by web applications
  - Later started a spinoff project, [redux-cpp](https://github.com/xwilson03/redux-cpp), to abstract the redux implementation logic away from this project

A significant portion of the work done for this iteration ended up being in Figma, and wasn't being tracked in any issues.

Consequently, after a long period with frustratingly small movement on any tracked issues, this iteration was killed not because it had any critical drawbacks, but because I had confirmed the implementation details enough to have confidence in starting a final version with a fresh slate and a focus on better project management practices.

In the current/final iteration of Beholder (see [main](https://github.com/xwilson03/Beholder/tree/main)), I'll be revisiting the project's goals from the ground up with a focus on better issue usage to make sure that work isn't going untracked for long periods of time.

---
TLDR; this iteration solved the last pieces of the architectural puzzle, and paved the way for the current version of Beholder.

After this, see [main](https://github.com/xwilson03/Beholder/tree/main).
