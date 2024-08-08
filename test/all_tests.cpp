#include <gtest.h>
#include <Solution.h>

TEST(SolutionTest, test_1)
{
	int n = 2;
	std::vector<std::pair<int, int>> tasks(n);

	tasks[0] = std::pair<int, int>{ 1, 1 };
	tasks[1] = std::pair<int, int>{ 2, 2 };

	EXPECT_EQ(solution(tasks), 0);
}

TEST(SolutionTest, test_2)
{
	std::vector<std::pair<int, int>> tasks(2);

	tasks[0] = std::pair<int, int>{ 1, 1 };
	tasks[1] = std::pair<int, int>{ 1, 2 };

	EXPECT_EQ(solution(tasks), 1);
}

TEST(SolutionTest, test_3)
{
	std::vector<std::pair<int, int>> tasks;
	
	tasks.push_back({ 2, 1 });
	tasks.push_back({ 1, 2 });

	EXPECT_EQ(solution(tasks), 0);
}

TEST(SolutionTest, test_4)
{
	std::vector<std::pair<int, int>> tasks;

	tasks.push_back({ 2, 2 });
	tasks.push_back({ 1, 1 });
	tasks.push_back({ 6, 10 });
	tasks.push_back({ 4, 2 });
	tasks.push_back({ 3, 1 });

	EXPECT_EQ(solution(tasks), 0);
}

TEST(SolutionTest, test_5)
{
	std::vector<std::pair<int, int>> tasks;
	
	tasks.push_back({ 2, 1 });
	tasks.push_back({ 1, 1 });
	tasks.push_back({ 2, 2 });
	tasks.push_back({ 5, 1 });
	tasks.push_back({ 4, 2 });

	EXPECT_EQ(solution(tasks), 1);
}


TEST(SolutionTest, test_6)
{
	std::vector<std::pair<int, int>> tasks;

	tasks.push_back({ 1, 1 });
	tasks.push_back({ 2, 1 });
	tasks.push_back({ 1, 2 });
	tasks.push_back({ 3, 1 });
	tasks.push_back({ 4, 1 });
	tasks.push_back({ 2, 2 });

	EXPECT_EQ(solution(tasks), 2);
}

TEST(SolutionTest, test_7)
{
	std::vector<std::pair<int, int>> tasks;

	tasks.push_back({ 1, 1 });
	tasks.push_back({ 2, 2 });
	tasks.push_back({ 4, 3 });
	tasks.push_back({ 2, 2 });

	EXPECT_EQ(solution(tasks), 1);
}

TEST(SolutionTest, test_8)
{
	std::vector<std::pair<int, int>> tasks;

	tasks.push_back({ 1, 1 });
	tasks.push_back({ 2, 3 });
	tasks.push_back({ 2, 1 });
	tasks.push_back({ 3, 3 });
	tasks.push_back({ 3, 2 });
	tasks.push_back({ 3, 3 });
	tasks.push_back({ 3, 2 });


	EXPECT_EQ(solution(tasks), 6);
}

TEST(SolutionTest, test_9)
{
	std::vector<std::pair<int, int>> tasks;

	tasks.push_back({ 3, 2 });	// -
	tasks.push_back({ 3, 6 });	// 2
	tasks.push_back({ 3, 3 });	// -
	tasks.push_back({ 4, 4 });	// 3
	tasks.push_back({ 3, 5 });	// 1
	tasks.push_back({ 4, 4 });	// -
	tasks.push_back({ 4, 4 });	// -
	tasks.push_back({ 4, 4 });	// 4
	tasks.push_back({ 4, 4 });	// -

	EXPECT_EQ(solution(tasks), 17);
}

TEST(SolutionTest, test_10)
{
	std::vector<std::pair<int, int>> tasks;

	tasks.push_back({ 2, 2});
	tasks.push_back({ 8, 7});
	tasks.push_back({ 2, 3});
	tasks.push_back({ 5, 4});
	tasks.push_back({ 5, 5});
	tasks.push_back({ 8, 8});
	tasks.push_back({ 3, 3});
	tasks.push_back({ 8, 6});


	EXPECT_EQ(solution(tasks), 0);
}
TEST(SolutionTest, test_11)
{
	std::vector<std::pair<int, int>> tasks;

	int day = 100;
	for (int i = 0; i < day; i++)
		tasks.push_back({ day, 7 });
	tasks.push_back({ day, 3 });


	EXPECT_EQ(solution(tasks), 3);
}