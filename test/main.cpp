#include <gtest/gtest.h>
#include "../vector.hpp"

TEST(VectorTest, ConstructorTest)
{
    Vector<int> my_vector;
    EXPECT_EQ(my_vector.get_size(), 0);
    EXPECT_EQ(my_vector.get_capacity(), 1);
}

TEST(VectorTest, DestructorTest)
{
    Vector<int> *my_vector = new Vector<int>();
    my_vector->push_back(1);
    my_vector->push_back(2);
    delete my_vector;

    SUCCEED();
}

TEST(VectorTest, CopyConstructorTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    Vector<int> copy_vector(my_vector);

    EXPECT_EQ(copy_vector.get_size(), 2);
    EXPECT_EQ(copy_vector.get_capacity(), 2);
    EXPECT_EQ(copy_vector.at(0), 1);
    EXPECT_EQ(copy_vector.at(1), 2);
}

TEST(VectorTest, CopyOperatorTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    Vector<int> copy_vector;
    copy_vector = my_vector;

    EXPECT_EQ(copy_vector.get_size(), 2);
    EXPECT_EQ(copy_vector.get_capacity(), 2);
    EXPECT_EQ(copy_vector.at(0), 1);
    EXPECT_EQ(copy_vector.at(1), 2);
}

TEST(VectorTest, MoveConstructorTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    Vector<int> move_vector(std::move(my_vector));

    EXPECT_EQ(move_vector.get_size(), 2);
    EXPECT_EQ(move_vector.get_capacity(), 2);
    EXPECT_EQ(move_vector.at(0), 1);
    EXPECT_EQ(move_vector.at(1), 2);
}

TEST(VectorTest, MoveOperatorTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    Vector<int> move_vector;
    move_vector = std::move(my_vector);

    EXPECT_EQ(move_vector.get_size(), 2);
    EXPECT_EQ(move_vector.get_capacity(), 2);
    EXPECT_EQ(move_vector.at(0), 1);
    EXPECT_EQ(move_vector.at(1), 2);
}

TEST(VectorTest, SelectOperatorTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    EXPECT_EQ(my_vector[0], 1);
    EXPECT_EQ(my_vector[1], 2);
    my_vector[0] = 3;
    EXPECT_EQ(my_vector[0], 3);

    EXPECT_THROW({ my_vector[2]; }, std::out_of_range);
}

TEST(VectorTest, AtOperatorTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    EXPECT_EQ(my_vector.at(0), 1);
    EXPECT_EQ(my_vector.at(1), 2);
    my_vector.at(0) = 3;
    EXPECT_EQ(my_vector.at(0), 3);
    EXPECT_THROW({ my_vector.at(2); }, std::out_of_range);
}

TEST(VectorTest, EqualityOperatorTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    Vector<int> equal_vector;
    equal_vector.push_back(1);
    equal_vector.push_back(2);

    Vector<int> not_equal_vector;
    not_equal_vector.push_back(3);
    not_equal_vector.push_back(4);

    EXPECT_TRUE(my_vector == equal_vector);
    EXPECT_FALSE(my_vector == not_equal_vector);
}

TEST(VectorTest, InequalityOperatorTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    Vector<int> equal_vector;
    equal_vector.push_back(1);
    equal_vector.push_back(2);

    Vector<int> not_equal_vector;
    not_equal_vector.push_back(3);
    not_equal_vector.push_back(4);

    EXPECT_FALSE(my_vector != equal_vector);
    EXPECT_TRUE(my_vector != not_equal_vector);
}

TEST(VectorTest, AssignTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    my_vector.assign(3, 4);

    EXPECT_EQ(my_vector.get_size(), 3);
    EXPECT_EQ(my_vector.get_capacity(), 3);
    EXPECT_EQ(my_vector.at(0), 4);
    EXPECT_EQ(my_vector.at(1), 4);
    EXPECT_EQ(my_vector.at(2), 4);
}

TEST(VectorTest, PushBackTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    EXPECT_EQ(my_vector.get_size(), 2);
    EXPECT_EQ(my_vector.get_capacity(), 2);
    EXPECT_EQ(my_vector.at(0), 1);
    EXPECT_EQ(my_vector.at(1), 2);
}

TEST(VectorTest, PopBackTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    int value = my_vector.pop_back();

    EXPECT_EQ(value, 2);
    EXPECT_EQ(my_vector.get_size(), 1);
    EXPECT_EQ(my_vector.get_capacity(), 2);
}

TEST(VectorTest, ClearTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    my_vector.clear();

    EXPECT_EQ(my_vector.get_size(), 0);
    EXPECT_EQ(my_vector.get_capacity(), 1);
}

TEST(VectorTest, InsertTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(3);

    my_vector.insert(1, 2);

    EXPECT_EQ(my_vector.get_size(), 3);
    EXPECT_EQ(my_vector.get_capacity(), 4);
    EXPECT_EQ(my_vector.at(0), 1);
    EXPECT_EQ(my_vector.at(1), 2);
    EXPECT_EQ(my_vector.at(2), 3);
}

TEST(VectorTest, ResizeTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    my_vector.resize(5, 3);

    EXPECT_EQ(my_vector.get_size(), 5);
    EXPECT_EQ(my_vector.get_capacity(), 5);
    EXPECT_EQ(my_vector.at(0), 1);
    EXPECT_EQ(my_vector.at(1), 2);
    EXPECT_EQ(my_vector.at(2), 3);
    EXPECT_EQ(my_vector.at(3), 3);
    EXPECT_EQ(my_vector.at(4), 3);
}

TEST(VectorTest, ShrinkToFitTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);
    my_vector.push_back(3);

    my_vector.shrink_to_fit();

    EXPECT_EQ(my_vector.get_size(), 3);
    EXPECT_EQ(my_vector.get_capacity(), 3);
}

TEST(VectorTest, ReserveTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    my_vector.reserve(10);

    EXPECT_EQ(my_vector.get_size(), 2);
    EXPECT_EQ(my_vector.get_capacity(), 10);
}

TEST(VectorTest, EraseTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);
    my_vector.push_back(3);

    my_vector.erase(1);

    EXPECT_EQ(my_vector.get_size(), 2);
    EXPECT_EQ(my_vector.get_capacity(), 4);
    EXPECT_EQ(my_vector.at(0), 1);
    EXPECT_EQ(my_vector.at(1), 3);
}

TEST(VectorTest, SwapTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    Vector<int> other_vector;
    other_vector.push_back(3);
    other_vector.push_back(4);
    other_vector.push_back(5);

    my_vector.swap(other_vector);

    EXPECT_EQ(my_vector.get_size(), 3);
    EXPECT_EQ(my_vector.get_capacity(), 4);
    EXPECT_EQ(my_vector.at(0), 3);
    EXPECT_EQ(my_vector.at(1), 4);
    EXPECT_EQ(my_vector.at(2), 5);

    EXPECT_EQ(other_vector.get_size(), 2);
    EXPECT_EQ(other_vector.get_capacity(), 2);
    EXPECT_EQ(other_vector.at(0), 1);
    EXPECT_EQ(other_vector.at(1), 2);
}

TEST(VectorTest, SizeTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    EXPECT_EQ(my_vector.get_size(), 2);
}

TEST(VectorTest, CapacityTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    EXPECT_EQ(my_vector.get_capacity(), 2);
}

TEST(VectorTest, EmptyTest)
{
    Vector<int> my_vector;

    EXPECT_TRUE(my_vector.empty());

    my_vector.push_back(1);

    EXPECT_FALSE(my_vector.empty());
}

TEST(VectorTest, BeginEndTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);
    my_vector.push_back(3);

    EXPECT_EQ(*my_vector.begin(), 1);
    EXPECT_EQ(*(my_vector.end() - 1), 3);
}

TEST(VectorTest, FrontTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    EXPECT_EQ(my_vector.front(), 1);
}

TEST(VectorTest, BackTest)
{
    Vector<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);

    EXPECT_EQ(my_vector.back(), 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}