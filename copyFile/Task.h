#pragma once
class Task
{
public:
	Task(void);
	~Task(void);
	Task(long long,long long);
	Task(const Task &);
	void setOffset(long long);
	long long getOffset();
	void setLength(long long);
	long long getLength();

	Task & operator = ( const Task&);
	bool operator == (const Task&) const;

private:
	long long offset;
	long long length;
};

