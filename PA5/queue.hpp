#include "queueNode.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Queue {

public: // Member functions

	Queue() {
		pTail = nullptr;
		pHead = nullptr;
	}

	bool isEmpty() const{

		return this->pHead == nullptr;

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



	//void enqueueData(Data& newData) {

	//	Data * ptrData = new Data

	//}


	bool dequeue(int& pcNum, int& psTime, int& ptTime) { // delete head and returning whatever values it holds

		if (pHead == NULL) {
			return false;

		}
		else {
			
			pcNum = pHead->getData()->getCustomerNumber();
			psTime = pHead->getData()->getServiceTime();
			ptTime = pHead->getData()->getTotalTime();

			QueueNode* temp = pHead;
			pHead = pHead->getPNext();
			delete temp;


			return true;
		}

	}

	void printQueue(QueueNode *cur) {

		if (cur != nullptr) {
			cout <<"Customer Number: "<< cur->getData()->getCustomerNumber() << endl;
			printQueue(cur->getPNext());
		}

	}

	QueueNode* getpHead(void) {

		return pHead;
	}

	QueueNode* getpTail(void) {

		return pTail;
	}
	
	int calcTotalServiceTime(QueueNode* pNext) {

		int totalTime = 0;

		while (pNext != nullptr) {

			totalTime += pNext->getData()->getServiceTime();

			pNext = pNext->getPNext();
			
		}

		return totalTime;
	}


private:
	QueueNode* pHead;
	QueueNode* pTail;

};
