#include "CVector.h"
#include "Source.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>  
#include "Create.h"
#include "Fabric.h"
#include "CVectorHori.h"
#include "CVectorVert.h"
#include "time.h"
using namespace std;


int main(void)
{
	try {
		int n = 200000;
		vector<double> q;
		vector<double> v;
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			q.push_back(1);
			v.push_back(1);
		}
		CVector0 Q("vert.txt",q, n);
		CVector0 V("vert.txt",v, n);
		cout << Q * V << endl;
		CVector0 R = Q + V;
		CVector0 S = Q - V;
		return 0;
	}
	catch (int err) { printf("error=%d\n", err); }
}




