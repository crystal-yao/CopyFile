#include "Task.h"


Task::Task(void)
{
	offset = 0;
	length= 0;
}


Task::~Task(void)
{
}

Task::Task(long long off, long long step) {
	offset = off;
	length = step;
}

Task::Task(const Task & old) {
	offset = old.offset;
	length = old.length;
}

void Task::setOffset(long long off) {
	offset = off;
}
	long long Task::getOffset() {
		return offset;
	}
	void Task::setLength(long long step) {
		length = step; 
	}
	long long Task::getLength() {
		return length;
	}

	Task & Task::operator = (const Task& old) {
		offset = old.offset;
		length = old.length;
		return *this;
	}

	bool Task::operator == (const Task& old) const {
		return (offset == old.offset) && (length == old.length);
	}