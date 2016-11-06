#include <iostream>
#include <vector>
using namespace std;

//класс Max-кучи
class Heap
{
public:
    typedef struct
    {
        int value;
        int index;
    } HeapElem;
    void insert(HeapElem value );
    void pop(void);
    HeapElem max(void);
    void sift_down( int i);
private:

    vector<HeapElem> buffer;
};

void Heap::insert( HeapElem value )
{
    buffer.push_back( value );
    int i = buffer.size() - 1;
    while( buffer[i].value > buffer[(i - 1) / 2].value && i > 0 )
    {
        std::swap( buffer[i], buffer[(i - 1) / 2] );
        i = (i - 1) / 2;
    }
}

Heap::HeapElem Heap::max()
{
    return buffer[0];
}

void Heap::sift_down(int i)
{
    int index_max = 0;
    int left;
    while( (left = 2 * i + 1) < buffer.size() )
    {
        if( left == buffer.size() - 1 )
            index_max = left;
        else
            index_max = (buffer[left].value < buffer[left+1].value) ?
                                    (left+1) : (left);

        if( buffer[i].value < buffer[index_max].value )
            std::swap(buffer[i], buffer[index_max]);
        else
            break;
        i = index_max;
    }
}

void Heap::pop()
{
    std::swap( buffer[0], buffer[ buffer.size() - 1 ] );
    buffer.pop_back();
    sift_down(0);
}

int main()
{
    int n = 0;
    cin >> n;
    Heap::HeapElem *Arr = new Heap::HeapElem[n];

    for( int i = 0; i < n; i++ )
    {
        cin >> Arr[i].value;
        Arr[i].index = i;
    }
    int k = 0;
    cin >> k;
    Heap my_heap;

    for( int i = 0; i < k; i++ )
        my_heap.insert( Arr[i] );

    cout << my_heap.max().value << " ";
    for(int i = k; i<n; ++i)
    {
        my_heap.insert( Arr[i] );
        while( my_heap.max().index <= ( i - k ) )
            my_heap.pop();
        cout << my_heap.max().value << " ";
    }
    delete[] Arr;
    return 0;
}
