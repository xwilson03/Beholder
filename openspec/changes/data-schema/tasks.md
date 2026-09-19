## 1. Schema Library

- [x] 1.1 `money.cppm` exporting `beholder.types.Money`
- [x] 1.2 `lib/schema/` CMake wiring and `lib/schema/money/` target `schema_money`

## 2. Testing

- [ ] 2.1 Enable testing; `tests/CMakeLists.txt` with `find_package(GTest)`
- [ ] 2.2 `tests/money/test_money.cpp`: tests serialization of money from special notation
- [ ] 2.3 Register `test_money` and confirm tests pass

## 3. Pipeline Integration

- [ ] 3.2 Clean build with test flag passes all tests
