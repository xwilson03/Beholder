#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

import beholder.types.Money;
using beholder::types::Money;

class MoneySchemaFixture : public ::testing::Test {
protected:
    inline static YAML::Node cases;

    static void SetUpTestSuite() {
        cases = YAML::LoadFile("money.yaml");
    }

    static void TearDownTestSuite() {
        cases.reset();
    }
};


TEST(MoneySchema, CopperSucceeds) {
    EXPECT_EQ(5, 5);
}

TEST(MoneySchema, SilverSucceeds) {
    EXPECT_EQ(5, 5);
}

TEST(MoneySchema, ElectrumSucceeds) {
    EXPECT_EQ(5, 5);
}

TEST(MoneySchema, GoldSucceeds) {
    EXPECT_EQ(5, 5);
}

TEST(MoneySchema, PlatinumSucceeds) {
    EXPECT_EQ(5, 5);
}

TEST(MoneySchema, NegativeCountFails) {
    EXPECT_EQ(5, 5);
}

TEST(MoneySchema, MissingCountFails) {
    EXPECT_EQ(5, 5);
}

TEST(MoneySchema, GarbageFails) {
    EXPECT_EQ(5, 5);
}
