#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
using namespace std;
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap;
  PComparator comp;
  size_t m;



};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  this->m = m;
  comp = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  heap.push_back(item);
  int idx = size() - 1;
  int father;
  while(idx != 0){
    father = (idx - 1) / m;
    if(comp(heap[idx], heap[father])){
      std::swap(heap[idx], heap[father]);
    } else{
      break;
    }
    idx = father;
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return heap.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return heap.size();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap Empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap Empty");

  }

  std::swap(heap[size() - 1], heap[0]);
  heap.pop_back();
  int idx = 0;
  while(true){
    int ex_idx;
    if(idx * m + 1 < size())
      ex_idx = idx * m + 1;
    else
      break;
    for(size_t i = 2; i <= m; i++){
      int n_idx = idx * m + i;
      if(n_idx >= size())
        break;
      if(comp(heap[n_idx], heap[ex_idx]))
        ex_idx = n_idx;
    }
    if(comp(heap[ex_idx], heap[idx]))
      std::swap(heap[ex_idx], heap[idx]);
    else
      break;
    idx = ex_idx;
  }



}



#endif

