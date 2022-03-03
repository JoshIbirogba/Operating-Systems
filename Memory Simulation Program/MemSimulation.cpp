/* Author: Joshua Ibirogba 
Course: CS3790
Student ID: 5073203
*/

#include "memory.h"


int total_number_requests;         // total number of requests
int SatisfiedNum;              // number of requests satisfied
int UnsatisfiedNum;            // number of requests unsatisfied
int smallest_blocksize = MAX_SIZE; // smallest blocksize requested
int largest_blocksize;             // largest blocksize requested
vector<int> blocksize;             // to hold the values of the blocksizes 
float avg_blocksize;           // average blocksize requested
int shortest_lease = MAX_LEASE;    // shortest lease duration
int longest_lease;                 // longest lease duration
vector<int> leaseTime;             // to hold the lease times
float average_lease;               // average lease duration
int MergedNum;                 // number of times merging was done

int size, lease, time;

     FREE freeList;
     ALLOC allocList;

bool compare_free (freeNode &x, freeNode &y)
{
	return x.hole.start > y.hole.start;
}

void dump() 
{
     

	cout << "         FREE LIST       \n";

	while (!(freeList.empty())) 
    {
		cout << "Start: " << freeList.top().hole.start << " "
		<< "Size: " << freeList.top().hole.size <<endl;
		freeList.pop();
	}

	cout << "      ALLOCATED LIST      \n";

	while (!allocList.empty())
    {
		cout << "Lease Expiry: " << allocList.top().leaseExpiry << " "
		<< "Start: " << allocList.top().allocated.start << " "
		<< "Size: " << allocList.top().allocated.size << "\n";
		allocList.pop();
	}

	cout << "\n";
	cout << "Total Number of Requests: " << total_number_requests;
	cout << "\nNumber Satisfied: " << SatisfiedNum;
	cout << "\nNumber Unsatisfied: " << UnsatisfiedNum;
	cout << "\nSmallest Blocksize: " << smallest_blocksize;
	cout << "\nLargest Blocksize: " << largest_blocksize;

	for (int i = 0; i < blocksize.size(); i++) avg_blocksize = blocksize[i] + avg_blocksize;
	avg_blocksize = avg_blocksize / blocksize.size();

	cout << "\nAverage Blocksize: " << avg_blocksize;
	cout << "\nShortest Lease: " << shortest_lease;
	cout << "\nLongest Lease: " << longest_lease;

	for (int i = 0; i < leaseTime.size(); i++) average_lease = leaseTime[i] + average_lease;
	average_lease = average_lease / leaseTime.size();

	cout << "\nAverage Lease: " << average_lease;
	cout << "\nNumber Merged: " << MergedNum << "\n";
}

int main()
{
     FREE freelist;
     ALLOC allocList;

	srand(time(NULL));

	freeNode p = {{0, 1000}};
	freeList.push(p);

	for (int clock = 0; clock < TIME_LIMIT; clock++)
    {
		FREE tmp;

		if (clock % REQUEST_INTERVAL == 0)
        {
		
			size = rand() % (MAX_SIZE - MIN_SIZE) + MIN_SIZE;
			blocksize.push_back(size);
			if (size <= smallest_blocksize) smallest_blocksize = size;
			if (size > largest_blocksize) largest_blocksize = size;

			lease = rand() % (MAX_LEASE - MIN_LEASE) + MIN_LEASE;
			leaseTime.push_back(lease);
			if (lease < shortest_lease) shortest_lease = lease;
			if (lease > longest_lease) longest_lease = lease;

			while (!freeList.empty() && freeList.top().hole.size < size){
				tmp.push(freeList.top());
				freeList.pop();
			}

			if (freeList.empty())
            {
				MergedNum++;
				while (!tmp.empty())
                {
					freeNode p = tmp.top();
					tmp.pop();
					if (p.hole.start + p.hole.size == tmp.top().hole.start)
                    {
						p.hole.size += tmp.top().hole.size;
						tmp.pop();
						tmp.push(p);
						MergedNum++;
					} 
                    else freeList.push(p);
				}	
			}
			total_number_requests++;
		}
		
		while (!freeList.empty() && freeList.top().hole.size < size)
        {
			tmp.push(freeList.top());
			freeList.pop();
		}

		if (freeList.empty())
        {
			freeList = tmp;
		} 
        else 
        {
			freeNode p = {{freeList.top().hole.start+size, freeList.top().hole.size-size}};
			allocNode q = {{freeList.top().hole.start,size}, time + lease};
			freeList.pop();
			freeList.push(p);
			allocList.push(q);
			SatisfiedNum++; // allocated

			while (!tmp.empty())
            {
				freeList.push(tmp.top());
				tmp.pop();
			}
		}
	}
	// check if a lease has expired
	while ((!allocList.empty()) && (allocList.top().leaseExpiry) == (&time))
    {
		freeNode p = {allocList.top().allocated.start, allocList.top().allocated.size};
		freeList.push(p);
		allocList.pop();
		if (allocList.top().leaseExpiry < shortest_lease) shortest_lease = allocList.top().leaseExpiry;
		if (allocList.top().leaseExpiry > longest_lease) longest_lease = allocList.top().leaseExpiry;
	}

	dump();

	return 0;
}
