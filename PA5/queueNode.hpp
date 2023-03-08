#include "data.hpp"

class QueueNode {

public: // Member functions
	

	QueueNode(int cNum, int sTime, int tTime) {

		pData = new Data(cNum, sTime, tTime);
		
	}



	void setPNext(QueueNode* pN) {
		pNext = pN;
	}

	QueueNode* getPNext() {
		return pNext;
	}


	Data* getData() {

		return pData;
	}



private:
	Data* pData;    // The memory for Data will need to be allocated on the heap as well!
	QueueNode * pNext;

};
