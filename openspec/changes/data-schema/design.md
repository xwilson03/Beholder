## Context

- reflect-cpp and yaml-cpp used for serialization

## Goals / Non-Goals

**Goals:**

- Implement the proposal as defined by the spec

**Non-Goals:**

- Redux store integration
- Any types other than `Money`

## Decisions

### 1. Architecture and Types

- One module per type at `lib/schema/<type>/` containing `<type>.cppm` that exports `beholder.types.<Type>`
- CMake targets namespaced by underscore: `schema_<type>`
- Schema types are pure aggregates

### 2. IO

- Types de/serialize using `rfl::yaml` directly
- Types with special notation such as `1gp = 1 gold` use rflcpp Reflectors

### 3. Testing

- Tests required only for custom logic (i.e., Reflectors, Validators), not for assumptions about the underlying aggregates
- Test suites registered with CTest as `<type>Test`
- `tests/<type>/` contains `test_<type>.cpp` and data file `<type>.yaml`
- Flag added to build script for optionally running tests
