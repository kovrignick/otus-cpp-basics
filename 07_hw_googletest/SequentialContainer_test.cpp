#include <gtest/gtest.h>
#include "SequentialContainer_keywords.cpp"

TEST(SequentialContainer, push_back) {
    ASSERT_TRUE(SequentialArray_push_back());
}

TEST(SequentialContainer, insert_front) {
    ASSERT_TRUE(SequentialArray_insert_front());
}

TEST(SequentialContainer, insert) {
    ASSERT_TRUE(SequentialArray_insert());
}

TEST(SequentialContainer, erase_back) {
    try {
        SequentialArray_erase_back();
        FAIL() << "Expected std::logic_error";
    } catch (std::logic_error const & err) {
        EXPECT_EQ(err.what(), std::string("IndexError"));
    } catch(...) {
        FAIL() << "Expected std::logic_error";
    }
}

TEST(SequentialContainer, erase_front) {
    ASSERT_TRUE(SequentialArray_erase_front());
}

TEST(SequentialContainer, erase) {
    ASSERT_TRUE(SequentialArray_erase());
}

TEST(SequentialContainer, size_increase) {
    ASSERT_TRUE(SequentialArray_size_increase());
}

TEST(SequentialContainer, size_decrease) {
    ASSERT_TRUE(SequentialArray_size_decrease());
}

TEST(SequentialContainer, capacity_increase) {
    ASSERT_TRUE(SequentialArray_capacity_increase());
}

TEST(SequentialContainer, copy_cstor) {
    ASSERT_TRUE(SequentialArray_copy_cstor());
}

TEST(SequentialContainer, move_cstor) {
    ASSERT_TRUE(SequentialArray_move_cstor());
}

TEST(SequentialContainer, copy_assigment) {
    ASSERT_TRUE(SequentialArray_copy_assigment());
}

TEST(SequentialContainer, move_assigment) {
    ASSERT_TRUE(SequentialArray_move_assigment());
}
