
class ListIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    ListNode* position_;

  public:
    ListIterator() : position_(NULL) { }
    ListIterator(ListNode* x) : position_(x) { }

    // Pre-Increment, ++iter
    ListIterator& operator++() {
        if(position_ != nullptr){
            position_ = position_->next;
        }
        return *this;
    }
    
    // Post-Increment, iter++
    ListIterator operator++(int) {
        ListIterator temp = *this;
        if (position_ != nullptr){
            position_ = position_->next;
        }
        return temp;
    }

    // Pre-Decrement, --iter
    ListIterator& operator--() {
        if (position_ != nullptr){
            position_ = position_->prev;
        }
        return *this;
    }

    // Post-Decrement, iter--
    ListIterator operator--(int) {
        ListIterator temp = *this;
        if (position_ != nullptr){
            position_ = position_->prev;
        }
        return temp;
    }

    bool operator!=(const ListIterator& rhs) {
        return position_ != rhs.position_;
    }

    bool operator==(const ListIterator& rhs) {
        return position_ == rhs.position_;
    }

    const T& operator*() {
        return position_->data;
    }

    const T* operator->() {
        return &(position_->data);
    }
};
