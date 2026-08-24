## Why

Beholder needs a foundation for its data-model before we implement the full schema.
This change adds a proof-of-concept vertical slice to cement the schema library structure, (de)serialization conventions, and testing pipeline.

## What Changes

- Adds schema library with one self-contained module per type
- Adds a simple `Money` type to the schema
- Establishes setup for testing schema library
- Wires testing pipeline into build

## Capabilities

### New Capabilities

- `data-schema`: per-type schema definitions, (de)serialization, and unit testing

### Modified Capabilities

- (none)

## Impact

- new library `lib/schema/money/`
- new tests `tests/schema/`
