#include "queueNode.hpp"

class Queue {

public: // Member functions

	Queue() {
		pTail = nullptr;
		pHead = nullptr;
	}

	void enqueue(int cusNum, int serTime, int totalT) { // insert at end

		if (pHead == NULL) {
			pHead = new QueueNode(cusNum, serTime, totalT); // allocated memory then set 
			pTail = pHead;
		}
		else { // inset at tail 
			QueueNode* temp = pTail;
			pTail = new QueueNode(cusNum, serTime, totalT);


			//temp->pNext = pTail
			temp->setPNext(pTail);
			
		}

	}

	bool dequeue(int& pcNum, int& psTime, int& ptTime) { // delete head and returning whatever values it holds

		if (pHead == NULL) {
			return false;

		}
		else {
			// TBD
			pcNum = pHead->getData()->getCustomerNumber();
			psTime = pHead->getData()->getServiceTime();
			ptTime = pHead->getData()->getTotalTime();

			QueueNode* temp = pHead;
			pHead = pHead->getPNext();
			delete temp;


			return true;
		}

	}

	void printQueue() {

		//	TBD

	}
	

private:
	QueueNode* pHead;
	QueueNode* pTail;

};
