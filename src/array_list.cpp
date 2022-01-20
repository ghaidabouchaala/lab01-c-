#include <array_list.h>
#include<iostream>

using namespace std;

ssuds::ArrayList::ArrayList() : mData(nullptr), mSize(0)
{
	// that's all
}

void ssuds::ArrayList::append(string new_value) 
{
	if (mSize == 0)
	{
		mData = new string[1];
		mData[0] = new_value;
	}
	else
	{
		string* bigger_array = new string[mSize + 1];
		for (int i = 0; i < mSize; i++)
			bigger_array[i] = mData[i];
		delete[] mData;
		mData = bigger_array;
		mData[mSize] = new_value;
	}
	mSize++;
}

int ssuds::ArrayList::size()
{
	return ssuds::ArrayList::mSize;
}
void ssuds::ArrayList::list()
{
	cout << "[ ";
	for (int i = 0; i < mSize; i++)
		cout << mData[i] << ", ";
	cout << " ]\n";

}

void ssuds::ArrayList::insert(string new_value, int index)
{

	if (index > mSize)
		throw out_of_range("index has exceeded the ArrayList size");
	if (index == mSize)
	{
		append(new_value);
	}
	else if (index == 0) {
		string* bigger_arr = new string[mSize + 1];
		bigger_arr[0] = new_value;
		for (int i = 0, j = 1; i < mSize && j < mSize + 1; i++, j++)
		{
			bigger_arr[j] = mData[i];
		}
		delete[] mData;
		mData = bigger_arr;
		mSize++;
	}
	else {
		string* bigger_array = new string[mSize + 1];
		for (int i = mSize; i > index; i--)
			bigger_array[i] = mData[i - 1];
		bigger_array[index] = new_value;
		for (int i = index-1; i >= 0; i--)
			bigger_array[i] = mData[i];
		delete[] mData;
		mData = bigger_array;
		mSize++;
	}
	
}
void ssuds::ArrayList::clear()
{
	ssuds::ArrayList::mSize = 0;
	ssuds::ArrayList::mData = nullptr;
}

string ssuds::ArrayList::get(int index)
{
	if (index > mSize)
		throw out_of_range("bad index exception");
	return mData[index];
}

int ssuds::ArrayList::find(string value, int start_pos)
{

	int i = start_pos;
	while (i < mSize)
	{
		if (mData[i] == value)
			return i;
		else
			i++;
	}
	
	return -1;
}

void ssuds::ArrayList::remove(int index)
{
	/*
		Instead of using a temporary array that is one element shorter and copying the contents of the initial array 
		wihout the element that we want to remove, I used the original array and moved the elements after the position 
		of the element that will be removed by one unit and then resized the Array, 
		which is a better way in terms of time and memory consumption.
	*/
	  if (index > mSize)
		  throw out_of_range("bad index to remove exception");
	  for (int i = index; i < mSize-1; i++)
		  mData[i] = mData[i + 1];
	  mSize--;
}

int ssuds::ArrayList::remove_all(string value)
{
	int count = 0; int i = 0;
	while (mSize > 0)
	{
		if (find(value) != -1)
		{
			count++;
			remove(find(value));
		}
		else
			return count;
	}

	return count;
}
ssuds::ArrayList::~ArrayList()
{
	if(mData)
		delete[] mData;
} 