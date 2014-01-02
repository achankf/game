#ifndef _database_hpp_
#define _database_hpp_

class Transaction {
	void finish();
protected:
	bool aborted = false;

	virtual int commit() = 0;
public:
	virtual ~Transaction() {}
	virtual int rollback() = 0;
};
#endif
