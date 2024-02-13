#include <iostream>
#include<math.h>
#include<vector>
#include <stdio.h>
#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Ring {
public:
	Ring(int ringNumber, int cycle) {
		RingNumber = ringNumber;
		Cycle = cycle;
		Counter = 0;
		First = true;
	}

	void change() {
		char a = 198 - (Origin + Destination);
		Origin = Destination;
		Destination = a;
	}
	void print() {
		cout << "Move Ring " << RingNumber << " , " << Origin << "->" << Destination << endl;
	}

	int RingNumber;
	int Counter;
	int Cycle;
	char Origin;
	char Destination;
	bool First;


private:
};


int main()
{
	// Start measuring time
	clock_t start = clock();
	//auto start = high_resolution_clock::now();

	int n = 0;
	cout << "Enter n: ";
	cin >> n;

	int countMove = (pow(2, n) - 1);

	vector<Ring> rings;
	rings.push_back(Ring(0, 0));


	for (int i = 1; i < n + 1; i++)
	{
		rings.push_back(Ring(i, (pow(2, i - 1) - 1)));

		rings[i].Origin = 'A';

		if (n % 2 == 0)
		{
			if (i % 2 == 0)
				rings[i].Destination = 'C';
			else
				rings[i].Destination = 'B';
		}
		else
		{
			if (i % 2 == 0)
				rings[i].Destination = 'B';
			else
				rings[i].Destination = 'C';
		}
	}


	for (int i = 0; i < countMove; i++)
	{

		for (int j = 1; j < rings.size(); j++)
		{
			if (rings[j].Counter == rings[j].Cycle)
			{
				rings[j].print();

				rings[j].Counter = 0;

				rings[j].change();

				if (rings[j].First)
				{
					rings[j].Cycle = (pow(2, j) - 1);
					rings[j].First = false;
				}

			}
			else
			{
				rings[j].Counter++;
			}
		}

	}

	// Stop measuring time and calculate the elapsed time
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	cout << "\n\nrun time : " << elapsed;

	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start);
	//cout << "run time : " << duration.count();


}



//
//void towerOfHanoi(int n, char from_rod, char to_rod,
//    char aux_rod)
//{
//    if (n == 0) {
//        return;
//    }
//    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
//    cout << "Move disk " << n << " from rod " << from_rod
//        << " to rod " << to_rod << endl;
//    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
//}
//
//// Driver code
//int main()
//{
//    // Start measuring time
//    clock_t start = clock();
//
//    // Start measuring time
//    //auto start = high_resolution_clock::now();
//
//        int n = 0;
//    cout << "Enter n: ";
//    cin >> n;
//
//    // A, B and C are names of rods
//    towerOfHanoi(n, 'A', 'C', 'B');
//
//    // Stop measuring time and calculate the elapsed time
//    clock_t end = clock();
//    double elapsed = double(end - start) / CLOCKS_PER_SEC;
//    cout << "run time : " << elapsed;
//
//  /*  auto stop = high_resolution_clock::now();
//
//    auto duration = duration_cast<microseconds>(stop - start);
//
//    cout << "run time : " << duration.count();*/
//    return 0;
//}