#include "testCase.hpp"

test::test(){
}

test::~test(){
}


void test::testCaseEmptyEnqueue(void) {

	cout << "Test Case: Enqueue with an Empty Queue" << endl;

	Queue* emptyList;
	emptyList = new Queue;

	emptyList->enqueue(1,2,3);

	if (emptyList->getpHead()->getData()->getCustomerNumber() != 1) {
		cout << "Check enqueue function." << endl;
	}
	else {
		cout << "Enqueue works for emoty queue" << endl;
	}



}


void test::testCaseOneNodeEnqueue(void) {

	cout << "Test Case: Enqueue on a Queue with One Node" << endl;

	Queue* oneNodeList;
	oneNodeList = new Queue;

	oneNodeList->enqueue(1, 2, 3);
	oneNodeList->enqueue(4, 5, 6);

	if (oneNodeList->getpHead()->getData()->getCustomerNumber() != 4) {
		cout << "Check enqueue function." << endl;
	}
	else {
		cout << "Enqueue works for one node queue" << endl;
	}


}

void test::testCaseOneNodeDequeue(void) {

	cout << "Test Case: Dequeue on a Queue with One Node" << endl;

	Queue* oneNodeList;
	oneNodeList = new Queue;


	int num1 = 1, num2 = 2, num3 = 3;
	int& ref1 = num1, & ref2 = num2, & ref3 = num3;
	oneNodeList->enqueue(num1, num2, num3);
	oneNodeList->dequeue(ref1, ref2, ref3);

	if (oneNodeList->getpHead() != nullptr) {
		cout << "Check dequeue function." <<  endl;
	}else{
		cout << "Dequeue works for one node queue" << endl;
	}



}


void test::testCaseTwoNodesDequeue(void) {

	cout << "Test Case: Dequeue on a Queue with Two Nodes" << endl;

	Queue* twoNodeList;
	twoNodeList = new Queue;


	int num1 = 1, num2 = 2, num3 = 3;
	int& ref1 = num1, & ref2 = num2, & ref3 = num3;

	twoNodeList->enqueue(4, 5, 7);

	twoNodeList->enqueue(num1, num2, num3);
	twoNodeList->dequeue(ref1, ref2, ref3);

	if (twoNodeList->getpHead()->getData()->getCustomerNumber()!=4) {
		cout << "Check dequeue function." << endl;
	}
	else {
		cout << "Dequeue works for a two node queue" << endl;
	}


}

void test::runTestSimulation(void) {

	cout << "Test Case: 24 hour simulation" << endl;

	

	Queue* expressLane;
	Queue* normalLane;
	expressLane = new Queue;
	normalLane = new Queue;

	srand(time(0));
	int elapsedMins = 0;

	int eLaneArrTime = rand() % 5 + 1;
	int nLaneArrTime = rand() % 8 + 3;


	int eCusNum = 0;
	int nCusNum = 0;

	int eSerTime = 0;
	int nSerTime = 0;

	int eTotalT = 0;
	int nTotalT = 0;

	int eTimer = rand() % 5 + 1;
	int nTimer = rand() % 8 + 3;


	QueueNode* epCur = nullptr;
	QueueNode* npCur = nullptr;


	while (elapsedMins < (24 * 60)) {


		// express lane enqueue
		if (elapsedMins == eLaneArrTime) {

			// first calculate total time - ServiceTime + sum of ServiceTimes of customers in line before this customer
			eTotalT = expressLane->calcTotalServiceTime(expressLane->getpHead());


			expressLane->enqueue(++eCusNum, eSerTime = rand() % 5 + 1, eTotalT);
			cout << "customer entered the express lane at " << eLaneArrTime << " mins" << endl;

			//int eCurMins = elapsedMins;

			eLaneArrTime = elapsedMins + (rand() % 5 + 1);





		}
		// express lane dequeue
		if (eTimer < 0 && !expressLane->isEmpty()) {

			eTimer = (expressLane->getpHead()->getData()->getServiceTime());
		}

		if ((eTimer == 0) && !(expressLane->isEmpty())) {
			int cNum = 0;
			int sNum = 0;
			int tTime = 0;
			int& ref1 = cNum;
			int& ref2 = sNum;
			int& ref3 = tTime;


			if (expressLane->dequeue(ref1, ref2, ref3)) {

				cout << "customer exited the express lane at " << elapsedMins << " mins" << endl;


			}
			else {
				cout << "Queue empty" << endl; // for decoding
			}
		}


		// normal lane enqueue
		if (elapsedMins == nLaneArrTime) {

			// first calculate total time - ServiceTime + sum of serviceTimes of customers in line before this customer
			nTotalT = normalLane->calcTotalServiceTime(normalLane->getpHead());


			normalLane->enqueue(++nCusNum, nSerTime = rand() % 8 + 3, nTotalT);
			cout << "customer entered the normal lane at " << nLaneArrTime << " mins" << endl;

			//int nCurMins = elapsedMins;

			nLaneArrTime = elapsedMins + (rand() % 8 + 3);





		}

		// normal lane dequeue
		if (nTimer < 0 && !normalLane->isEmpty()) {

			nTimer = (normalLane->getpHead()->getData()->getServiceTime());

		}

		if (nTimer == 0 && !normalLane->isEmpty()) {
			int cNum = 0;
			int sNum = 0;
			int tTime = 0;
			int& ref1 = cNum;
			int& ref2 = sNum;
			int& ref3 = tTime;


			if (normalLane->dequeue(ref1, ref2, ref3)) {

				cout << "customer exited the normal lane at " << elapsedMins << " mins" << endl;


			}
			else {
				cout << "Queue empty" << endl; // for decoding
			}
		}


		//print every 10 mins
		if (elapsedMins % 10 == 0 && elapsedMins != 0) {

			cout << endl;

			cout << "EXPRESS LANE" << endl;
			expressLane->printQueue();

			cout << endl;

			cout << "NORMAL LANE" << endl;
			normalLane->printQueue();

			cout << endl;


		}

		eTimer--;
		nTimer--;
		elapsedMins++; // one min has passed

		Sleep(0); // simulating one min
	}



}

