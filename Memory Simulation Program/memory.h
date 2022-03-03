#include <cstdlib>
#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

#define REQUEST_INTERVAL 10
#define MIN_LEASE 40
#define MAX_LEASE 70
#define MIN_SIZE 50
#define MAX_SIZE 350
#define TIME_LIMIT 1000
#define MEMORY_SIZE 1000


struct range 
{
	int start; // the starting address of the range
	int size; // size of the range
};

struct freeNode 
{
	struct range hole;
    struct freeeNode *next;
};

struct allocNode {
	struct range allocated;
	int leaseExpiry; // time at which this block will be returned to free list
    struct allocNode *next;
};

struct compare_alloc {
	bool operator()(allocNode &x, allocNode &y) {
	return x.leaseExpiry > y.leaseExpiry;
	}
};

typedef priority_queue <freeNode, vector<freeNode>,compare_free> FREE;
typedef priority_queue <allocNode, vector<allocNode>,compare_alloc> ALLOC;