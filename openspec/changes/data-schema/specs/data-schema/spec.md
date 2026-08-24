## ADDED Requirements

### Requirement: Schema types round-trip through YAML

Schema types SHALL be serializable to and deserializable from YAML.
Round-tripping SHALL preserve defined fields and SHALL drop undefined data.
A document containing a field value that cannot be parsed as the field's declared type SHALL fail to load and produce no value.

#### Scenario: Round-trip preserves defined fields
- **WHEN** an instance of a schema type is serialized to YAML and the result is deserialized
- **THEN** the deserialized value equals the original for all defined fields

#### Scenario: Undefined data is dropped
- **WHEN** a document containing an unknown field is loaded and re-serialized
- **THEN** the output succeeds containing only the type's defined fields

#### Scenario: Type mismatch fails to load
- **WHEN** a field value cannot be parsed as its declared type
- **THEN** the load fails and produces no value

### Requirement: Only optional fields may be omitted

A schema type SHALL declare whether each field is required or optional by specifying a default.
Omitting a required field from a YAML document SHALL fail the load.
A sparse document (omits only optional fields) SHALL load successfully, with each omitted field holding the default value as defined by the schema.

#### Scenario: Sparse document loads with defaults
- **WHEN** a document omits one or more optional fields
- **THEN** the load succeeds and each omitted optional field holds the defined default

#### Scenario: Required field omitted fails the load
- **WHEN** a document omits a required field
- **THEN** the load fails
