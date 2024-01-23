/*int main()
{
	std::cout << "start where ?";
	int start{};
	std::cin >> start;
	std::cout << "how many ?";
	int length{};
	std::cin >> length;
	srand(time(0));
	int multiplier{ (rand() % 10) + 1 };
	std::cout << "i generated " << length << "square numbers. do you know ehat each number is after multiplying by" << multiplier << "\n";
	std::vector<int> list{};
	list.resize(length);
	for (int count{}; count < length; ++count) {
		list[count] = start + count;
	}
	for (int count{}; count < length; ++count)
	{
		std::cout << count + 1 << " number is ? " << "\n";
		int guess{};
		std::cin >> guess;
		int answer{ (list[count] * list[count] * multiplier) };
		if (guess == (list[count] * list[count]) * multiplier)
			std::cout << "correct !!" << "\n";
		else if (guess > (answer - 4) && guess < (answer + 4))
			std::cout << "close, try " << answer << " next time" << "\n";
		else {
			std::cout << "wrong" << "\n";
			break;
		}
	}

	return 0;
}*/