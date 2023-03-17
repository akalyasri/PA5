#include "queue.hpp"
#include <Windows.h>


Queue *expressLane;
Queue* normalLane;

int main(void) {

	cout << "Start 24 Hour Simulation:" << endl;
	system("pause");
	system("cls");

	
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

	int timesPrinted = 0;

	QueueNode* epCur = nullptr;
	QueueNode* npCur = nullptr;


	while (elapsedMins <= (24 * 60)) {

		
		// express lane enqueue
		if (elapsedMins == eLaneArrTime) {

			// first calculate total time - ServiceTime + sum of 
			// serviceTimes of customers in line before this customer
			eTotalT = expressLane->calcTotalServiceTime(expressLane->getpHead());

			
			expressLane->enqueue(++eCusNum, eSerTime = rand() % 5 + 1, eTotalT);
			cout << "customer entered the express lane at " << eLaneArrTime << " mins" << endl;

			//int eCurMins = elapsedMins;

			eLaneArrTime = elapsedMins + (rand() % 5 + 1);


			// express lane dequeue
			if (elapsedMins != eTimer && !expressLane->isEmpty()) {

				eTimer = elapsedMins + (expressLane->getpHead()->getData()->getServiceTime());
			}
			else if ((elapsedMins == eTimer) && !(expressLane->isEmpty())) {
				int cNum = 0;
				int sNum = 0;
				int tTime = 0;
				int& ref1 = cNum;
				int& ref2 = sNum;
				int& ref3 = tTime;

			
				if (expressLane->dequeue(ref1, ref2, ref3)) {

					cout << "customer exited the express lane at " << eTimer << " mins" << endl;

					eTimer = elapsedMins + (expressLane->getpHead()->getData()->getServiceTime());
				}
			}


		}


		// normal lane enqueue
		if (elapsedMins == nLaneArrTime) {

			// first calculate total time - ServiceTime + sum of 
			// serviceTimes of customers in line before this customer
			nTotalT = normalLane->calcTotalServiceTime(normalLane->getpHead());

			
			normalLane->enqueue(++nCusNum, nSerTime = rand() % 8 + 3, nTotalT);
			cout << "customer entered the normal lane at " << nLaneArrTime << " mins" << endl;

			//int nCurMins = elapsedMins;

			nLaneArrTime = elapsedMins + (rand() % 8 + 3);


			// normal lane dequeue
			if (elapsedMins != nTimer && !normalLane->isEmpty()) {
				
				nTimer = elapsedMins + (normalLane->getpHead()->getData()->getServiceTime());
				
			}
			else if (elapsedMins == nTimer && !normalLane->isEmpty()) {
				int cNum = 0;
				int sNum = 0;
				int tTime = 0;
				int& ref1 = cNum;
				int& ref2 = sNum;
				int& ref3 = tTime;

				
				if (normalLane->dequeue(ref1, ref2, ref3)) {

					cout << "customer exited the normal lane at " << nTimer << " mins" << endl;

					nTimer = elapsedMins + (normalLane->getpHead()->getData()->getServiceTime());
				}
			}


		}


		//print every 10 mins
		if (elapsedMins % 10 == 0 && elapsedMins != 0) { 

			/*if (timesPrinted == 0) {
				epCur = expressLane->getpHead();
				npCur = normalLane->getpHead();
			}*/
			

			cout << endl;

			cout << "EXPRESS LANE" << endl;
			expressLane->printQueue();

			cout << endl;

			cout << "NORMAL LANE" << endl;
			normalLane->printQueue();

			cout << endl;
		
			/*epCur = expressLane->getpTail();
			npCur = normalLane->getpTail();*/
		
			
			timesPrinted++;
		}

		/*eTimer--;
		nTimer--;*/
		elapsedMins++; // one min has passed

		Sleep(0); // simulating one min
	}



}
