#include <iostream>
#include <vector>
using namespace std;

struct HeapElem
{
    int value; //ключ (значение)
    int index; //индекс
};

//класс Max-кучи
class CHeap
{
public:
    void insert(HeapElem value );
    void pop(void);
    HeapElem max(void);
    void siftDown( int i);
private:

    vector<HeapElem> buffer;
};

void CHeap::insert( HeapElem value )
{
    buffer.push_back( value );
    int i = buffer.size() - 1;
    while( buffer[i].value > buffer[(i - 1) / 2].value && i > 0 )
    {
        std::swap( buffer[i], buffer[(i - 1) / 2] );
        i = (i - 1) / 2;
    }
}

HeapElem CHeap::max()
{
    return buffer[0];
}
//просеивает элемент с индексом index на свое место в куче array
void CHeap::siftDown(int i)
{
    int maxChild = 0;
    int indexMaxChild = 0;
    while( 2 * i + 1 < buffer.size() )
    {
        if( 2 * i + 1 == buffer.size() - 1 )
        {
            maxChild = buffer[2 * i + 1].value;
            indexMaxChild = 2 * i + 1;
        }
        else
        {
            if( buffer[2 * i + 1].value < buffer[2 * i + 2].value )
            {
                maxChild = buffer[2 * i + 2].value;
                indexMaxChild = 2 * i + 2;
            }
            else
            {
                maxChild = buffer[2 * i + 1].value;
                indexMaxChild = 2 * i + 1;
            }
        }
        if( buffer[i].value < maxChild )
            std::swap(buffer[i], buffer[indexMaxChild]);
        else
            break;
        i = indexMaxChild;
    }
}

void CHeap::pop()
{
    std::swap( buffer[0], buffer[ buffer.size() - 1 ] );
    buffer.pop_back();
    siftDown(0);
}

int main()
{
    int n = 0;
    cin >> n;
    HeapElem *Arr = new HeapElem[n];

    for( int i = 0; i < n; i++ )
    {
        cin >> Arr[i].value;
        Arr[i].index = i;
    }
  //размер окна
    int k = 0;
    cin >> k;
    CHeap WHeap;

    for( int i = 0; i < k; i++ )
        WHeap.insert( Arr[i] );

    cout << WHeap.max().value << " ";
    for(int i = k; i<n; ++i)
    {
        WHeap.insert( Arr[i] );
        while( WHeap.max().index <= ( i - k ) )
            WHeap.pop();
        cout << WHeap.max().value << " ";
    }
    delete[] Arr;
    return 0;
}
