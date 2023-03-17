#include "queue.hpp"



void run24Simulation(void) {
	

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