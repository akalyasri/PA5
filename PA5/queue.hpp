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

	~Queue() {
		destroyQueue();
	}

	// precondition: Queue must not be empty 
	// code we created in class w Andy
	//string dequeue()
	//{
	//	QueueNode* pTemp = this->pHead;
	//	string data = this->pHead->getData();

	//	// recall: precondition is that the Queue must not be
	//	// empty so if mpHead and mpTail are the same it
	//	// means there's only 1 node in the Queue
	//	if (this->pHead == this->pTail) // one node?
	//	{
	//		// there's one node in the Queue
	//		this->pHead = this->pTail = nullptr;
	//	}
	//	else
	//	{
	//		this->pHead = this->pHead->getPNext();
	//	}

	//	delete pTemp; // invoke the destructor for a Node

	//	return data;
	//}

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

	void destroyQueue()
	{
		while (!isEmpty())
		{
			int cNum = expressLane->getpHead()->getData()->getCustomerNumber();
			int sNum = expressLane->getpHead()->getData()->getServiceTime();
			int tTime = expressLane->getpHead()->getData()->getTotalTime();
			int& ref1 = cNum;
			int& ref2 = sNum;
			int& ref3 = tTime;

			cout << "deleting " << dequeue(ref1, ref2, ref3) << endl;

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
