/*  the simulation of kuramoto model for ocillators */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

#define N 10
#define coupling 0.07
#define P 0.3
#define dt 0.01
#define time_0 5000

/* the main function */

int main()
{
    srand((unsigned int)time(0));       // producing a random number
    int T_R = 0;                        // the relaxition time
    float theta[N][time_0], theta_0[N]; // the phase of ocilators
    float W[N];                         // distribution of natural frequncy
    int Adjmat[N][N];                   // adjancy matrix for i and js

    for (int i = 0; i < N; i++) // this loop is for adjancent matrix
    {
        for (int j = 0; j < i; j++)
        {
            Adjmat[i][j] = 0;
            Adjmat[j][i] = 0;
        }
    }

    ofstream adj("adku.txt");
    int degree = 0;
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < i; j++)
        {

            double r = ((double)rand() / (RAND_MAX));
            if (r < P)
            {
                Adjmat[i][j] = 1;
                Adjmat[j][i] = 1;
            }

            //adj << Adjmat[i][j] << '\t';
            
        }
       // adj << endl;
         
    }
    cout <<"the following is the undirected adjacency matrix"<<endl; 
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cout<< Adjmat[i][j]<<"\t";
            adj<<Adjmat[i][j]<<"\t";
        }
        cout <<endl;
        adj<<endl; 
    }
     
    double ran;
    int B[N][N]; 
    cout << "the follwoing is the directed adjacency matrix" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            double ran = ((double)rand() / (RAND_MAX));
            if (ran < 0.5)
            {
                B[i][j]=Adjmat[i][j];
                B[j][i] = 0;
              
            }
            else 
            {
                B[i][j]=0;
                B[j][i] = Adjmat[j][i];
            }
        
        }
    }

    ofstream ad("ad.txt");
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            cout << B[i][j] << '\t';
            ad << B[i][j] << "\t";
        }
        cout << endl;
        ad << endl;
    }

    return 0;
}