#include <cmath> // contiene floor
#include <iostream>
#include <numeric> // contiene iota
#include <iostream>
#include <sstream>
#include <chrono> // https://en.cppreference.com/w/cpp/chrono

#include "SortingAlgorithm.hpp"
using namespace std;
using namespace SortLibrary;


int main(int argc, char *argv[])
{

    cout << "argc: " << argc << endl;
    for(int a = 0; a < argc; a++)
        cout << argv[a] << " ";
    cout << endl;

    size_t m = 10;
    if(argc > 1)
    {
        istringstream convert(argv[1]);
        convert >> m;
        cout << "use value: "  << m << endl;
    }
    else
        cerr << "use default value: "  << m << endl;

    vector<int> v1(m);
    iota(v1.begin(), v1.end(), -4); // l'ultimo argomento è il valore di partenza

    srand(2);
    vector<double> v2(m);
    for(size_t i = 0; i < m; i++)
        v2[i] = rand() / ((double)RAND_MAX);

    vector<int> v3(m, 0);
    for(size_t i = floor(m * 0.5) + 1; i < m; i++)
        v3[i] = rand() % 1000;

    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());


    unsigned int num_experiment = 100;

    double time_elapsed_selection_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        BubbleSort<int>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_selection_v1 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_selection_v1 /= num_experiment;

    cout << "Bubble Sort - v1: " << time_elapsed_selection_v1 << endl;

    double time_elapsed_selection_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        BubbleSort<double>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_selection_v2 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_selection_v2 /= num_experiment;

    cout << "Bubble Sort - v2: " << time_elapsed_selection_v2 << endl;


    double time_elapsed_selection_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        BubbleSort<int>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_selection_v3 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_selection_v3 /= num_experiment;

    cout << "Bubble Sort - v3: " << time_elapsed_selection_v3 << endl;

    double time_elapsed_insertion_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        HeapSort<int>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_insertion_v1 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v1 /= num_experiment;

    cout << "Heap Sort - v1: " << time_elapsed_insertion_v1 << endl;

    double time_elapsed_insertion_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        HeapSort<double>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_insertion_v2 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v2 /= num_experiment;

    cout << "Heap Sort - v2: " << time_elapsed_insertion_v2 << endl;


    double time_elapsed_insertion_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        HeapSort<int>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_insertion_v3 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v3 /= num_experiment;

    cout << "Heap Sort - v3: " << time_elapsed_insertion_v3 << endl;


    return 0;
}

