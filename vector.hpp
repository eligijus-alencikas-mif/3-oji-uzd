#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <limits>

template <typename T>
class Vector
{
    size_t size;
    size_t capacity;
    std::unique_ptr<T[]> data;

public:
    Vector() : size(0), capacity(1), data(new T[1]) {}
    ~Vector()
    {
        size = 0;
        capacity = 0;
        data.release();
    }

    Vector(const Vector<T> &other)
    {
        size = other.size;
        capacity = other.capacity;
        data.reset(new T[capacity]);
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    Vector<T> &operator=(const Vector<T> &other)
    {
        if (this != &other)
        {
            size = other.size;
            capacity = other.capacity;
            data.reset(new T[capacity]);
            for (size_t i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    Vector(Vector<T> &&other) noexcept
    {
        size = std::move(other.size);
        capacity = std::move(other.capacity);
        data = std::move(other.data);
    }

    Vector<T> &operator=(Vector<T> &&other) noexcept
    {
        if (this != &other)
        {
            size = std::move(other.size);
            capacity = std::move(other.capacity);
            data = std::move(other.data);
        }
        return *this;
    }

    T &operator[](const size_t index)
    {
        if (index < size)
        {
            return data[index];
        }

        throw std::out_of_range("operator[] index out of range");
    }

    bool operator==(const Vector<T> &other)
    {
        if (size != other.size)
        {
            return false;
        }

        for (size_t i = 0; i < size; i++)
        {
            if (data[i] != other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector<T> &other)
    {
        if (size != other.size)
        {
            return true;
        }

        for (size_t i = 0; i < size; i++)
        {
            if (data[i] != other.data[i])
            {
                return true;
            }
        }
        return false;
    }

    void assign(const size_t count, const T &value)
    {
        this->resize(count);
        for (size_t i = 0; i < count; i++)
        {
            data[i] = value;
        }
    }

    void push_back(const T &value)
    {
        if (size >= capacity)
        {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            std::unique_ptr<T[]> new_data(new T[capacity]);
            for (size_t i = 0; i < size; i++)
            {
                new_data[i] = data[i];
            }
            data.swap(new_data);
        }
        data[size++] = value;
    }

    T pop_back()
    {
        if (size > 0)
        {
            return data[--size];
        }
        throw std::out_of_range("pop_back() called on empty vector");
    }

    void clear()
    {
        size = 0;
        capacity = 1;
        data.reset(new T[capacity]);
    }

    void resize(size_t new_size, const T &value = {})
    {
        if (new_size > capacity)
        {
            capacity = new_size;
        }

        std::unique_ptr<T[]> new_data(new T[capacity]);
        for (size_t i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }
        for (size_t i = size; i < new_size; i++)
        {
            new_data[i] = value;
        }

        size = new_size;
        data.swap(new_data);
    }

    void reserve(size_t new_capacity)
    {
        if (new_capacity < size)
        {
            throw std::out_of_range("reserve() new capacity is less than current size");
        }

        std::unique_ptr<T[]> new_data(new T[new_capacity]);
        for (size_t i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }
        data.swap(new_data);
        capacity = new_capacity;
    }

    void erase(size_t index)
    {
        if (index < size)
        {
            for (size_t i = index; i < size - 1; i++)
            {
                data[i] = data[i + 1];
            }
            size--;
        }
        else
        {
            throw std::out_of_range("erase() index out of range");
        }
    }

    void insert(size_t index, const T &value)
    {
        if (index < size)
        {
            if (size >= capacity)
            {
                capacity = (capacity == 0) ? 1 : capacity * 2;
                std::unique_ptr<T[]> new_data(new T[capacity]);
                for (size_t i = 0; i < size; i++)
                {
                    new_data[i] = data[i];
                }
                data.swap(new_data);
            }

            for (size_t i = size - 1; i >= index; i--)
            {
                data[i + 1] = data[i];
            }
            size++;
            data[index] = value;
        }
        else
        {
            throw std::out_of_range("insert() index out of range");
        }
    }

    T &at(const size_t index)
    {
        if (index < size)
        {
            return data[index];
        }

        throw std::out_of_range("at() index out of range");
    }

    void shrink_to_fit()
    {
        std::unique_ptr<T[]> new_data(new T[size]);
        for (size_t i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }
        data.swap(new_data);
        capacity = size;
    }

    void swap(Vector<T> &other)
    {
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
        data.swap(other.data);
    }

    T &front() const
    {
        if (size > 0)
        {
            return data[0];
        }
        throw std::out_of_range("front() called on empty vector");
    }

    T &back() const
    {
        if (size > 0)
        {
            return data[size - 1];
        }
        throw std::out_of_range("back() called on empty vector");
    }

    size_t get_size() const
    {
        return size;
    }

    size_t get_capacity() const
    {
        return capacity;
    }

    T *begin() const
    {
        return data.get();
    }

    T *end() const
    {
        return data.get() + size;
    }

    T *get_data() const
    {
        return data.get();
    }

    bool empty() const
    {
        return size == 0;
    }

    size_t max_size() const
    {
        return std::numeric_limits<size_t>::max();
    }
};
#endif // VECTOR_HPP
