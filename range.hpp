
#ifndef CPPEXAMS_RANGE_HPP
#define CPPEXAMS_RANGE_HPP

#include "vector"
#include "iostream"
#include "ostream"

namespace itertools {
    template<typename T>
    class range {
        T start;
        T end;
        T inc;
    public:
        range(T start, T end) : start(start), end(end) {
            if (end > start) {
                inc = 1;
            } else if (start > end)
                inc = -1;
        };

        class iterator {
            T current, inc;
        public:
            iterator(T current, T inc) : current(current), inc(inc) {};

            iterator &operator++() {
                current += inc;
                return *this;
            }

            iterator operator++(int) {
                iterator temp = *this;
                this->current += inc;
                return temp;
            }

            bool operator!=(iterator other) {
                return this->current != other.current;
            }

            bool operator==(const iterator other) {
                return this->current == other.current;
            }

            T operator*() {
                return current;
            }

            iterator begin() const {
                return {start, inc};
            }

            iterator end() const {
                return {end, inc};
            }
        };
    };
}
#endif
