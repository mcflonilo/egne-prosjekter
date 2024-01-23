#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>

class IntArray
{
private:
	int m_length{};
	int* m_data{};

public:
	IntArray() = default;

	IntArray(int length)
		: m_length{ length }
		, m_data{ new int[length] {} }
	{

	}

	IntArray(std::initializer_list<int> list) : // allow IntArray to be initialized via list initialization
		IntArray(static_cast<int>(list.size())) // use delegating constructor to set up initial array
	{
		// Now initialize our array from the list
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	~IntArray()
	{
		delete[] m_data;
		// we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
	}

	IntArray(const IntArray&) = delete; // to avoid shallow copies
	IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

	IntArray& operator=(std::initializer_list<int> list)
	{
		// If the new list is a different size, reallocate it
		int length{ static_cast<int>(list.size()) };
		if (length != m_length)
		{
			delete[] m_data;
			m_length = length;
			m_data = new int[length] {};
		}

		// Now initialize our array from the list
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}

		return *this;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const { return m_length; }



	void erase()
	{
		delete[] m_data;

		m_data = nullptr;
		m_length = 0;
	}



	void reallocate(int newLength)
	{
		erase();

		if (newLength <= 0)
			return;

		m_data = new int[newLength];
		m_length = newLength;
	}

	void resize(int newLength)
	{
		if (newLength == m_length)
			return;

		if (newLength <= 0)
		{
			erase();
			return;
		}

		int* data{ new int[newLength] };
		if (m_length > 0)
		{
			int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

			for (int index{ 0 }; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}
		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}

	void insertBefore(int value, int index)
	{
		assert(index >= 0 && index <= m_length);

		int* data{ new int[m_length + 1] };

		for (int before{ 0 }; before < index; ++before)
			data[before] = m_data[before];

		data[index] = value;

		for (int after{ index }; after < m_length; ++after)
			data[after + 1] = m_data[after];

		delete[]m_data;
		m_data = data;
		++m_length;
	}

	void remove(int index)
	{
		assert(index >= 0 && index < m_length);

		if (m_length == 1)
		{
			erase();
			return;
		}

		int* data{ new int[m_length - 1] };

		for (int before{ 0 }; before < index; ++before)
			data[before] = m_data[before];

		for (int after{ index + 1 }; after < m_length; ++after)
			data[after - 1] = m_data[after];

		delete[] m_data;
		m_data = data;
		--m_length;
	}

	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, m_length); }

};
#endif