#include <gtest/gtest.h>
#include "LinkListContainer_keywords.cpp"

TEST(LinkListContainer, push_back) {
    ASSERT_TRUE(LinkList_push_back());
}

TEST(LinkListContainer, insert_front) {
    ASSERT_TRUE(LinkList_insert_front());
}

TEST(LinkListContainer, insert) {
    ASSERT_TRUE(LinkList_insert());
}

TEST(LinkListContainer, erase_back) {
    try {
        LinkList_erase_back();
        FAIL() << "Expected std::logic_error";
    } catch (std::logic_error const & err) {
        EXPECT_EQ(err.what(), std::string("IndexError"));
    } catch(...) {
        FAIL() << "Expected std::logic_error";
    }
}

TEST(LinkListContainer, erase_front) {
    ASSERT_TRUE(LinkList_erase_front());
}

TEST(LinkListContainer, erase) {
    ASSERT_TRUE(LinkList_erase());
}

TEST(LinkListContainer, size_increase) {
    ASSERT_TRUE(LinkList_size_increase());
}

TEST(LinkListContainer, size_decrease) {
    ASSERT_TRUE(LinkList_size_decrease());
}

TEST(LinkListContainer, copy_cstor) {
    ASSERT_TRUE(LinkList_copy_cstor());
}

TEST(LinkListContainer, move_cstor) {
    ASSERT_TRUE(LinkList_move_cstor());
}

TEST(LinkListContainer, copy_assigment) {
    ASSERT_TRUE(LinkList_copy_assigment());
}

TEST(LinkListContainer, move_assigment) {
    ASSERT_TRUE(LinkList_move_assigment());
}
