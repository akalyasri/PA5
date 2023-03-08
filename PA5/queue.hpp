#include "queueNode.hpp"

class Queue {

public: // Member functions

	Queue() {
		pTail = nullptr;
		pHead = nullptr;
	}

	void enqueue(int cusNum, int serTime, int totalT) { // insert


	}

	bool dequeue(int& pcNum, int& psTime, int& ptTime) { // delete head and returning whatever values it holds

		if (pHead == NULL) {
			return false;

		}
		else {
			// TBD
		}

	}

	void printQueue() {

		//	TBD

	}
	

private:
	QueueNode* pHead;
	QueueNode* pTail;

};
