# Beholder — Agent Guide

## Project
A DnD companion app using C++20 + Qt 6.4 (Widgets only). Currently no testing/lint infrastructure

## Build
- Full build: `./build.sh -c`
- Incremental: `./build.sh`

## Architecture
- `app/` is boilerplate for `lib/`
- `lib/` contains all view components as self-contained libraries (no mutual dependencies)
- Entrypoint is `lib/mainwindow` (`MainWindow`):
  - `Topbar` + `QStackedLayout(...)` containing each page
- Current pages:
  - `Map`
    - Owns `MapGraphics{View,Scene}` + floating toolbar for view/scene manipulation

## Naming & Style
- **Classes**: PascalCase (`MapGraphicsView`)
- **Files**: lowercase, matching class (`map.h`)
- **Members**: `m` + PascalCase (`mGraphicsScene`)
- **Params**: `a` + PascalCase (`aEvent`)
- **Locals**: camelCase (`mainLayout`)
- **Enums**: `enum class` + PascalCase values
- **Pointers**: left-aligned (`QWidget* parent`)
- **Braces**: Allman (own line)
- **Header guard**: `#pragma once`

## Includes
- Group by: own header, std libraries, Qt, project headers. Alpha-sort + blank-line separate each group

## Qt Conventions
- Parent-child ownership (no manual delete, no smart pointers for widgets)
- Modern connect syntax: `connect(sender, &Class::signal, this, lambda)`
- AUTOMOC on — `Q_OBJECT` macro in all QObject subclasses

## Design Pattern Preferences
- Keep code simple and minimal
- Dont remove or add comments unless asked.
- Always use const and & unless impossible or unoptimal
- Use variables for magic numbers.
- Use guard clauses to denest if statements when possible
- Mode/state logic lives in the component that uses it (e.g., mode in view, not parent)
