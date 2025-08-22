#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include <deque>
#include <stdexcept>

namespace circular_buffer {

template <typename T>
class circular_buffer {
public:
    explicit circular_buffer(size_t size) : m_data(), m_size{ size } {}

    T read() {
        if (m_data.empty())
            throw std::domain_error("circular buffer: read from empty buffer");

        T value = m_data.back();
        m_data.pop_back();
        return value;
    }

    void write(T const & value) {
        if (m_data.size() >= m_size)
            throw std::domain_error("circular buffer: write to full buffer");

        m_data.push_front(value);
    }

    void overwrite(T const & value) {
        if (m_data.size() >= m_size)
            read();

        write(value);
    }

    void clear() { m_data.clear(); }

private:
    std::deque<T> m_data;
    size_t m_size{ 0 };

};

}  // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H